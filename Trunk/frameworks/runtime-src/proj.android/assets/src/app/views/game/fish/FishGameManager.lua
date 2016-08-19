FishGameManager = {}

local FishManager   = import("app.views.game.fish.FishManager.lua")
local CannonManager = import("app.views.game.fish.CannonManager.lua")
local BulletManager = import("app.views.game.fish.BulletManager.lua")
local LockManager   = import("app.views.game.fish.LockManager.lua")
local CoinManager   = import("app.views.game.fish.CoinManager.lua")
local FishTrace     = import("app.views.game.fish.FishTrace.lua")
local CMD_GAME_FISH = import("app/cmd/game/fish/CMD_GAME_FISH")
local logger        = zzy.Logger.new("FishGameManager")

--渲染层级
local ZORDER_SCENE  = 0 --游戏场景
local ZORDER_FISH   = 1 --鱼
local ZORDER_BULLET = 2	--子弹
local ZORDER_CANNON = 4	--炮桶
local ZORDER_NET    = 5	--网
local ZORDER_COIN   = 6	--金币层
local ZORDER_LOCK   = 5	--锁定层

local GAME_STATUS_FREE = 0
local GAME_STATUS_PLAY = 100
local GAME_STATUS_END  = 101

function FishGameManager:ctor()
end

function FishGameManager:getOffsetPos()
	local winSize = cc.Director:getInstance():getWinSize()
	local scaleX = winSize.width / 1280
	local scaleY = winSize.height / 720

	local RESOLUTIONPOSOFFSET = {x=0,y=0}
	if scaleX > scaleY then	-- 分辨率偏移
		RESOLUTIONPOSOFFSET.x = RESOLUTIONPOSOFFSET.x + (winSize.width - 1280) / 2
	else
		RESOLUTIONPOSOFFSET.y = RESOLUTIONPOSOFFSET.y + (winSize.height - 720) / 2
	end
	return RESOLUTIONPOSOFFSET
end

function FishGameManager:init(view)
	self.m_nExchange_ratio_fishscore = 0
	self.m_nExchange_ratio_userscore = 0
	self.m_nExchange_count           = 0
	self.m_nMin_bullet_multiple      = 0
	self.m_nMax_bullet_multiple      = 0
	self.m_nCurrent_bullet_mulriple  = 0
	self.m_eCurrent_bullet_kind      = 0
	self.m_lExchange_fish_score      = {0,0,0,0}
	self.m_fBomb_range_width         = 0
	self.m_fBomb_range_height        = 0
	self.m_nFish_Multiple            = {}
	self.m_fFish_Speed               = {}
	self.m_fFish_Bounding_BoxWidth   = {}
	self.m_fFish_Bounding_BoxHeight  = {}
	self.m_fFish_HitRadius           = {}
	self.m_fBullet_Speed             = {}
	self.m_fNet_Radius               = {}
	self.m_vFish_trace_info_buffer   = {}

	--分帧激活鱼
	self.lastActiviteIdx = 0
	self.fishBuffIdx = 0
	self.fishBuff = {}

	self.gameView = view
	self.isLock = false
	--鱼管理
	self.fishManager = FishManager.new()
	self.gameView:addChild(self.fishManager, ZORDER_FISH)
	--炮台管理
	self.cannonManager = CannonManager.new()
	self.gameView:addChild(self.cannonManager, ZORDER_CANNON)
	--子弹管理
	self.bulletManager = BulletManager.new()
	self.gameView:addChild(self.bulletManager, ZORDER_BULLET)
	--锁定管理
	-- self.lockManager = LockManager.new()
	-- self.gameView:addChild(self.lockManager, ZORDER_LOCK)
	--锁定管理
	self.coinManager = CoinManager.new()
	self.gameView:addChild(self.coinManager, ZORDER_COIN)
	-- self:runTest()
	-- self:runTraceTest(4)

	-- coroutine.resume(gameCoroutine,self.fishTraceBuff)

	-- self:initPhysics()
	self.gameView:doFrame()
end

function FishGameManager:initPhysics()
	cc.Director:getInstance():getRunningScene():getPhysicsWorld():setGravity(cc.p(0, 0))
	local function onContactBegin(contact)
			local a = contact:getShapeA():getBody():getNode()
			local b = contact:getShapeB():getBody():getNode()
			local bullet
			if a:getTag() == 1000 then
				bullet = a
			elseif b:getTag() == 1000 then
				bullet = b
			end
			bullet.fatherObj:castingNet()
			return true
		end

	local contactListener = cc.EventListenerPhysicsContact:create();
	contactListener:registerScriptHandler(onContactBegin, cc.Handler.EVENT_PHYSICS_CONTACT_BEGIN);
	local eventDispatcher = self.bulletManager:getEventDispatcher()
	eventDispatcher:addEventListenerWithSceneGraphPriority(contactListener, self.bulletManager);
end

function FishGameManager:onLoadTrace(data)
	local count = data:getCount()
	local traceId =  data:getTraceId()
	local fishKind = data:getFishKind()
	local fishTrace = {}
	for i = 1,count do
		local idx = i - 1
		fishTrace[i] = {}
		fishTrace[i].x =  data:getX(idx)
		fishTrace[i].y =  data:getY(idx)
		fishTrace[i].angle =  data:getAngle(idx)
	end
	data:release()
	FishConfig.TRACE[fishKind][traceId] = {}
	FishConfig.TRACE[fishKind][traceId] = fishTrace
end

function FishGameManager:onBuildTrace(data)
	local count = data:getCount()
	local fishId =  data:getFishId()
	local fishTrace = {}
	for i = 1,count do
		local idx = i - 1
		fishTrace[i] = {}
	    fishTrace[i].x =  data:getX(idx)
	    fishTrace[i].y =  data:getY(idx)
	    fishTrace[i].angle =  data:getAngle(idx)
	end
	local fishKind =  data:getFishKind()
	-- data:release()

	-- if fishKind > 10 then fishKind = 10 end --TODO
	-- if fishKind < 1 then fishKind = 1 end
	local fish = self.fishManager:activeFish(fishKind,fishId,
												self.m_nFish_Multiple[fishKind],
												self.m_fFish_Speed[fishKind],
												self.m_fFish_Bounding_BoxWidth[fishKind],
												self.m_fFish_Bounding_BoxHeight[fishKind],
												self.m_fFish_HitRadius[fishKind])

	fish:setTrace(fishTrace)
	-- fish.sp:retain()
	-- fish:setPosition(cc.p(fishTrace[1].x,fishTrace[1].y))
	fish:setFishActive(true)
	self.fishManager:addFish(fish)
end

function FishGameManager:onGameMessageWithScene(status,notify)
	local cmd = CMD_GAME_FISH.CMD_S_GameStatus:createWithNotify(notify)
	self.m_cbGameStatus = status
	if status == GAME_STATUS_PLAY or status == GAME_STATUS_FREE then
		for i = 1, GAME_PLAYER do
			self.cannonManager:setFishScore(i,cmd.fish_score[i])
			self.m_lExchange_fish_score[i] = cmd.exchange_fish_score[i]
		end
		self.chairId = GameManager:getUserSelf():getChairID() + 1
		self.gameView:setBg(cmd.scene_kind)
		self.gameView:setBgm(cmd.scene_kind)
		-- GameManager:getUserManager():searchUserByTableInfo(GameManager:getUserSelf():getTableID(),self.gameScene.m_wCurrentBanker)
	end
end

function FishGameManager:onGameMessageWithCmdID(sub,notify)
	if sub ~= CMD_GAME_FISH.SUB_S_USER_FIRE and sub ~= CMD_GAME_FISH.SUB_S_FISH_TRACE then
		logger:log("------------------------------  sub = "..sub.." ------------------------------")
	end
	if sub == CMD_GAME_FISH.SUB_S_GAME_CONFIG then --1712	游戏配置
		self:onSubGameConfig(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_FISH_TRACE then --1711	出鱼和路线
		self:onSubFishTrace(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_SCENE_END then	--1700
	elseif sub == CMD_GAME_FISH.SUB_S_STOCK_OPERATE_RESULT  then	--1701
	elseif sub == CMD_GAME_FISH.SUB_S_SWITCH_SCENE then	--1702	切换场景
		self:onSubSwitchScene(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_HIT_FISH_LK then	--1703
		self:onSubHitFishLK(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_CATCH_SWEEP_FISH_RESULT then	--1704
		self:onSubCatSweepFishResult(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_CATCH_SWEEP_FISH then	--1705
		self:onSubCatSweepFish(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_LOCK_TIMEOUT then	--1706
		self:onSubLockTimeout()
	elseif sub == CMD_GAME_FISH.SUB_S_BULLET_ION_TIMEOUT then	--1707
		self:onSubBulletIonTimeout(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_CATCH_FISH then	--1708	打死鱼
		self:onSubCatchFish(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_USER_FIRE then	--1709	有人开枪！！
		self:onSubUserFire(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_EXCHANGE_FISHSCORE then	--1710
		self:onSubExchangeFishScore(notify)
	elseif sub == CMD_GAME_FISH.SUB_S_FISH_GROUP then	--1714
		self:onSubFishGroup(notify)
	end
end

function FishGameManager:onSubGameConfig(notify) --1712
	local game_config = CMD_GAME_FISH.CMD_S_GameConfig:createWithNotify(notify)
	local hscale = 1 --nf.heightScale

	self.m_nExchange_ratio_fishscore = game_config.exchange_ratio_fishscore
	self.m_nExchange_ratio_userscore = game_config.exchange_ratio_userscore
	self.m_nExchange_count           = game_config.exchange_count
	self.m_nMin_bullet_multiple      = game_config.min_bullet_multiple
	self.m_nMax_bullet_multiple      = game_config.max_bullet_multiple
	self.baseScore                  = game_config.baseScore
	self.m_nCurrent_bullet_mulriple  = self.m_nMin_bullet_multiple
	self.m_eCurrent_bullet_kind      = 0

	self.chairId = GameManager:getUserSelf():getChairID() + 1
	self.cannonManager:init()

	for i = 1, 2 do
		self.m_lExchange_fish_score[i] = 0
		self.cannonManager:switch(i, self.m_eCurrent_bullet_kind)
		self.cannonManager:setCannonMulriple(i, self.m_nCurrent_bullet_mulriple)
	end

	self.cannonManager:setBaseScore(self.baseScore)

	self.m_fBomb_range_width = game_config.bomb_range_width
	self.m_fBomb_range_height = game_config.bomb_range_height

	for i = 0, FISH_KIND_COUNT-1 do
		self.m_nFish_Multiple[i] = game_config.fish_multiple[i]
		self.m_fFish_Speed[i] = game_config.fish_speed[i] * hscale
		self.m_fFish_Bounding_BoxWidth[i] = game_config.fish_bounding_box_width[i] * hscale
		self.m_fFish_Bounding_BoxHeight[i] = game_config.fish_bounding_box_height[i] * hscale
		self.m_fFish_HitRadius[i] = game_config.fish_hit_radius[i] * hscale
	end

	for i = 0, BULLET_KIND_COUNT-1 do
		self.m_fBullet_Speed[i] = game_config.bullet_speed[i] * hscale
		self.m_fNet_Radius[i] = game_config.net_radius[i] * hscale
	end
end

function FishGameManager:onSubFishTrace(notify) --1711
	local byteArray = jt.ByteArray:createWithNotify(notify)
	local fishTraceCount = notify:getSize()/CMD_GAME_FISH.CMD_S_FishTrace:getSize()

	-- local traceInfoBuff = jt.TraceInfoBuff:create()
    -- traceInfoBuff:retain()
	for i = 1, fishTraceCount do
		local fishTrace = CMD_GAME_FISH.CMD_S_FishTrace:create()
		fishTrace:readFormByteArray(byteArray)
		-- local fishTraceInfo = {}
		-- fishTraceInfo.init_x_pos = {}
		-- fishTraceInfo.init_y_pos = {}
		-- fishTraceInfo.init_count = fishTrace.init_count
		-- -- traceInfoBuff:pushBackTraceInfo()
		-- -- traceInfoBuff:setInitCount(fishTraceInfo.init_count)
		-- for j = 1, fishTraceInfo.init_count do
		-- 	local offsetPos = self:getOffsetPos()
		-- 	if fishTrace.init_pos[j].x < 0 then
		-- 		fishTraceInfo.init_x_pos[j] = fishTrace.init_pos[j].x - offsetPos.x
		-- 	else
		-- 		fishTraceInfo.init_x_pos[j] = fishTrace.init_pos[j].x + offsetPos.x
		-- 	end
		-- 	if fishTrace.init_pos[j].y < 0 then
		-- 		fishTraceInfo.init_y_pos[j] = fishTrace.init_pos[j].y - offsetPos.y
		-- 	else
		-- 		fishTraceInfo.init_y_pos[j] = fishTrace.init_pos[j].y + offsetPos.y
		-- 	end
		-- 	-- traceInfoBuff:setPosX(j-1,fishTraceInfo.init_x_pos[j])
		-- 	-- traceInfoBuff:setPosY(j-1,fishTraceInfo.init_y_pos[j])
		-- end
		-- traceInfoBuff:setSpeed(4)
		-- traceInfoBuff:setTraceType(fishTrace.trace_type)
		-- traceInfoBuff:setFishId(fishTrace.fish_id)
		-- traceInfoBuff:setFishKind(fishTrace.fish_kind)
		local fishKind = fishTrace.fish_kind --math.random(0,20)--
		local traceId = fishTrace.trace_id --math.random(1,FishConfig.TRACE_COUNT[fishKind])--
		-- self.helper:getTrace(fishKind - 1,fishTrace.fish_id,fishKind)

		--凤姐的坑，我来填
		if traceId < 1 then traceId = 1 end
		if traceId > FishConfig.TRACE_COUNT[fishKind] then traceId = 1 end

		local fishId = fishTrace.fish_id
		-- if fishKind < 4 or fishKind == FishConfig.KIND.DIANMAN or fishKind == FishConfig.KIND.QIE then
			self.fishBuffIdx = self.fishBuffIdx + 1
			self.fishBuff[self.fishBuffIdx] = {fishId = fishId, fishKind = fishKind,traceId = traceId,traceKind = fishKind}
		-- end
		-- fish:setFishActive(true)
		-- self.fishManager:addFish(fish)
	end
	-- self.helper:pushBackTraceInfo(traceInfoBuff)
end

function FishGameManager:onFrameActiveFish()
	for i = self.lastActiviteIdx + 1, self.lastActiviteIdx + 3 do

		local fish = self.fishBuff[i]
		if fish == nil then break end
		local fishId = fish.fishId
		local fishKind = fish.fishKind
		local traceId = fish.traceId
		local traceKind = fish.traceKind

		if fishKind > FishConfig.KIND.MEIRENYU then
			audio.playSound("music/sound_warning")
		end

		local fish = self.fishManager:activeFish(fishKind,fishId)--,self.m_nFish_Multiple[fishKind],self.m_fFish_Speed[fishKind])

		-- logger:log("traceKind = "..traceKind..", traceId = "..traceId)
		fish:setTrace(FishConfig.TRACE[traceKind][traceId])
		-- fish.sp:retain()
		-- fish:setPosition(cc.p(fishTrace[1].x,fishTrace[1].y))

		fish:setFishActive(true)
		self.fishManager:addFish(fish)
		-- self.fishBuff[i] = nil
		self.lastActiviteIdx = i
	end
end

function FishGameManager:onSubFishGroup(notify) --1714
	local fishGroup = CMD_GAME_FISH.CMD_S_FishGroup:createWithNotify(notify)

	local groupId = fishGroup.group_id
    local fishStartId = fishGroup.fish_id_start
    local fishEndId = fishGroup.fish_id_end

	if groupId ~= 104 then return end

	for i = 0, FishConfig.TRACE_COUNT[groupId] - 1  do
		local fishKind = 0
		local fishId = fishStartId + i

		self.fishBuffIdx = self.fishBuffIdx + 1
		self.fishBuff[self.fishBuffIdx] = {fishId = fishId, fishKind = fishKind,traceId = i,traceKind = groupId}
		-- local fish = self.fishManager:activeFish(fishKind,fishId,
		-- 											self.m_nFish_Multiple[fishKind],
		-- 											self.m_fFish_Speed[fishKind],
		-- 											self.m_fFish_Bounding_BoxWidth[fishKind],
		-- 											self.m_fFish_Bounding_BoxHeight[fishKind],
		-- 											self.m_fFish_HitRadius[fishKind])
		--
		-- fish:setTrace(FishConfig.TRACE[groupId][i])
		-- fish:setFishActive(true)
		-- self.fishManager:addFish(fish)
	end
end

local testFishId = 9999999
function FishGameManager:testFish()
	local traceKind = 104
	for i = 0, FishConfig.TRACE_COUNT[traceKind] - 1  do
		local fishKind = 0
		testFishId = testFishId+1
		self.fishBuff[#self.fishBuff + 1] = {fishId = testFishId, fishKind = fishKind,traceId = i,traceKind = 104}
		-- local fish = self.fishManager:activeFish(fishKind,fishId,
		-- 											self.m_nFish_Multiple[fishKind],
		-- 											self.m_fFish_Speed[fishKind],
		-- 											self.m_fFish_Bounding_BoxWidth[fishKind],
		-- 											self.m_fFish_Bounding_BoxHeight[fishKind],
		-- 											self.m_fFish_HitRadius[fishKind])
		--
		-- fish:setTrace(FishConfig.TRACE[traceKind][i])
		-- -- fish.sp:retain()
		-- -- fish:setPosition(cc.p(fishTrace[1].x,fishTrace[1].y))
		-- fish:setFishActive(true)
		-- self.fishManager:addFish(fish)
	end
end


function FishGameManager:onSubSwitchScene(notify)
	-- CMD_S_SwitchScene *switch_scene = static_cast<CMD_S_SwitchScene *>(data);
	-- m_eLast_scene_kind = switch_scene->scene_kind;
    -- m_pGameScene->SetSwitchSceneStyle(m_eLast_scene_kind);
	local switchScene = CMD_GAME_FISH.CMD_S_SwitchScene:createWithNotify(notify)
	local sceneKind = switchScene.scene_kind
	self.gameView:switchScene(sceneKind)
end

function FishGameManager:onSubHitFishLK(notify)
    -- assert(data_size == sizeof(CMD_S_HitFishLK));
    -- if (data_size != sizeof(CMD_S_HitFishLK)) return false;
	-- CMD_S_HitFishLK* hit_fish = static_cast<CMD_S_HitFishLK*>(data);
	-- m_pFishManager->HitFishLK(hit_fish->chair_id, hit_fish->fish_id, hit_fish->fish_mulriple);
end

function FishGameManager:onSubCatSweepFish(notify)
	local catSweep = CMD_GAME_FISH.CMD_S_CatchSweepFish:createWithNotify(notify)
	local fishId = catSweep.fish_id
	local chairId = catSweep.chair_id
	local fish = self.fishManager.fishArray[fishId]
	if fish then
		if fish.kind == FishConfig.KIND.DIANMAN then
			--电鳗的闪电
			local lightingCount = 0
			local sweepFishId = {}
			for _,v in pairs(self.fishManager.fishArray) do
				if v.kind <= FishConfig.KIND.SHUIMU and v.isActive then
					audio.playSound("music/sound_thunder")
					v:setStop()
					local lighting = ens.ClightningBoltNode.new(nil)
					lighting:init("lightingSeg.png",cc.p(fish.curX, fish.curY), cc.p(v.curX, v.curY))
					lighting:addTo(FishGameManager.gameView,2)
					lighting:runFlashActionOnce()
					lightingCount = lightingCount + 1

					sweepFishId[#sweepFishId + 1] = v.id
					if lightingCount > 5 then break end
					-- end
				end
			end
			self:sendCatchSweepFish(fishId, chairId, lightingCount,sweepFishId)
		end
	end
end

function FishGameManager:onSubCatSweepFishResult(notify)
	local sweepResult      = CMD_GAME_FISH.CMD_S_CatchSweepFishResult:createWithNotify(notify)
	local fish_id          = sweepResult.fish_id
	local chair_id         = sweepResult.chair_id
	local fish_score       = sweepResult.fish_score
	local catch_fish_count = sweepResult.catch_fish_count

    local catch_fish_id = {}
    for  i = 1, catch_fish_count do
        catch_fish_id[i] = sweepResult.catch_fish_id[i]
    end

	self.fishManager:catchSweepFishResult(chair_id + 1, fish_id, fish_score, catch_fish_id, catch_fish_count)
    self.cannonManager:setFishScore(chair_id + 1, fish_score)
end

function FishGameManager:onSubLockTimeout()
	self.isLock = false
end

function FishGameManager:onSubBulletIonTimeout(notify)
    -- if (data_size != sizeof(CMD_S_BulletIonTimeout)) return false;
    -- CMD_S_BulletIonTimeout *bullet_timeout = static_cast<CMD_S_BulletIonTimeout *>(data);
    -- const int bulletCount = BULLET_KIND_COUNT / 2;
    -- const int bulletKind = m_pCannonManager->m_eCurrentBulletKind[bullet_timeout->chair_id] % bulletCount;
    -- BulletKind kind = static_cast<BulletKind>(bulletKind);
    -- m_pCannonManager->Switch(bullet_timeout->chair_id, kind);
    -- if (bullet_timeout->chair_id == getChairID()) {
    --     m_eCurrent_bullet_kind = kind;
    -- }
end

function FishGameManager:onSubCatchFish(notify)
	local catchFish = CMD_GAME_FISH.CMD_S_CatchFish:createWithNotify(notify)
	local chairId = catchFish.chair_id + 1
	local fishId = catchFish.fish_id
	local fishScore = catchFish.fish_score
	self.fishManager:catchFish(chairId,fishId,fishScore)

	self.cannonManager:setFishScore(chairId,fishScore)

	if catchFish.bullet_ion then
		local bulletCount = BULLET_KIND_COUNT/2
		local bulletKind = self.cannonManager.currentMultiple[chairId]%bulletCount
		local kind = 0 --TODO bulletKind + bulletCount
		self.cannonManager:switch(chairId,kind)
		if chairId == self:getChairId() then
			self.m_eCurrent_bullet_kind = kind
		end
	end
end

function FishGameManager:onSubUserFire(notify)
	local user_fire = CMD_GAME_FISH.CMD_S_UserFire:createWithNotify(notify)

	local angle = user_fire.angle

	local lockFishId = user_fire.lock_fishid
	local chairId = user_fire.chair_id + 1
	local bulletKind = user_fire.bullet_kind
	local bulletMulriple = user_fire.bullet_mulriple
	local fishScore = user_fire.fish_score
	local bulletId = user_fire.bullet_id
	local androidChairId = user_fire.android_chairid

	-- if (lockFishId > 0) then
	-- 	local fish = self.fishManager:getFish(lockFishId)
	-- 	if (fish == nil) then
	-- 		self.lockManager:setLockFishId(chairId, 0)
	-- 		self.lockManager:setLockFishKind(chairId, FISH_KIND_COUNT)
    --     else
	-- 		self.lockManager:setLockFishKind(chairId, fish:getKind())
	-- 		if (lockFishId == -1 and lockFishId > 0) then
	--
	-- 			local mousePos = self.lockManager:getLockPos(chairId)
    --             local cannonPos = self.cannonManager:getCannonPos(chairId)
    --             angle = MathAide.CalcAngle(mousePos.x, mousePos.y, cannonPos.x, cannonPos.y)
	-- 		end
	-- 	end
	-- 	self.lockManager:setLockFishId(chairId, lockFishId)
	-- end

	if (chairId ~= self.chairId) then   -- 其他玩家(包括NPC) 发炮
        self.cannonManager:switch(chairId, bulletKind)
		self.cannonManager:setCannonMulriple(chairId, bulletMulriple)
		self.cannonManager:setFishScore(chairId, fishScore)
		self.cannonManager:fire(chairId, bulletKind)
		--设置炮桶角度
		self.cannonManager:setCurrentAngle(chairId, angle)
		local cannonPos = self.cannonManager:getCannonPos(chairId)
		self.bulletManager:fire(cannonPos.x, cannonPos.y, angle,chairId, bulletKind,bulletId, bulletMulriple, self.m_fBullet_Speed[bulletKind],self.m_fNet_Radius[bulletKind], lockFishId)
	else
		local key,bullet = next(self.bulletManager.bulletBufArray)
		if bullet ~= nil then
			bullet:setId(bulletId)
			if bullet:getFishId() > 0 then
				self:sendCatchFish(bullet:getFishId(), bullet:getChairId(), bullet:getId(), bullet:getKind(), bullet:getMulriple())
			end
			self.bulletManager.bulletBufArray[key] = nil
		end
	end
end

function FishGameManager:onSubExchangeFishScore(notify)
	local exchangeFishScore = CMD_GAME_FISH.CMD_S_ExchangeFishScore:createWithNotify(notify)
	self.cannonManager:setFishScore(exchangeFishScore.chair_id+1, exchangeFishScore.swap_fish_score)
end

function FishGameManager:sendUserFire(bullet_kind, angle, bullet_mulriple, lock_fishid)
	local userFire = CMD_GAME_FISH.CMD_C_UserFire:create()
	userFire.bullet_kind     = bullet_kind;
	userFire.angle           = angle;
	userFire.bullet_mulriple = bullet_mulriple;
	userFire.lock_fishid     = lock_fishid;
	CFrameDataHandler:getInstance():SendSocketData(CMD_GAME_FISH.MDM_GF_GAME,CMD_GAME_FISH.SUB_C_USER_FIRE,userFire)
end

function FishGameManager:sendCatchFish(fish_id, firer_chair_id, bullet_id, bullet_kind, bullet_mulriple)
	local catchFish           = CMD_GAME_FISH.CMD_C_CatchFish:create()
	catchFish.chair_id        = firer_chair_id - 1
	catchFish.bullet_id       = bullet_id
	catchFish.bullet_kind     = bullet_kind
	catchFish.fish_id         = fish_id
	catchFish.bullet_mulriple = bullet_mulriple
	CFrameDataHandler:getInstance():SendSocketData(CMD_GAME_FISH.MDM_GF_GAME,CMD_GAME_FISH.SUB_C_CATCH_FISH,catchFish)
end

function FishGameManager:sendCatchSweepFish(fish_id, chair_id, catch_fish_count,catch_fish_id)
	local catchSweep            = CMD_GAME_FISH.CMD_C_CatchSweepFish:create()
	catchSweep.fish_id          = fish_id
	catchSweep.chair_id         = chair_id
	catchSweep.catch_fish_count = catch_fish_count
	catchSweep.catch_fish_id    = catch_fish_id
	CFrameDataHandler:getInstance():SendSocketData(CMD_GAME_FISH.MDM_GF_GAME,CMD_GAME_FISH.SUB_C_CATCH_SWEEP_FISH,catchSweep)
end

function FishGameManager:sendExchangeFishScore(increase)
	local userSelf = GameManager:getUserSelf()
	local meChairId = self:getChairId()
	local exchangeFishScore = CMD_GAME_FISH.CMD_C_ExchangeFishScore:create()
	exchangeFishScore.increase = increase

	local user_leave_score = userSelf:getScore() - self.m_lExchange_fish_score[meChairId] * self.m_nExchange_ratio_userscore / self.m_nExchange_ratio_fishscore
	local exchange_count = user_leave_score * self.m_nExchange_ratio_fishscore / self.m_nExchange_ratio_userscore
	if increase == true then
		if (exchange_count<0)  then return end

		self.cannonManager:setFishScore(meChairId, exchange_count)
		self.m_lExchange_fish_score[meChairId] = self.m_lExchange_fish_score[meChairId] + exchange_count
	end

	CFrameDataHandler:getInstance():SendSocketData(CMD_GAME_FISH.MDM_GF_GAME,CMD_GAME_FISH.SUB_C_EXCHANGE_FISHSCORE,exchangeFishScore)
end

function FishGameManager:updateGameView(pUser)

end

--用户分数
function FishGameManager:onUpdateScore()

end


-- local buildNum = 0
-- function FishGameManager:buildTrace(fishTraceInfo,fishManager)
-- 	for i,v in pairs(fishTraceInfo) do
-- 		if fishTraceInfo[i].fish:getTraceType() == TRACE_LINEAR then
-- 			local trace = MathAide.BuildLinear(fishTraceInfo[i].init_x_pos,fishTraceInfo[i].init_y_pos,fishTraceInfo[i].init_count,fishTraceInfo[i].fish:getFishSpeed())
-- 			fishTraceInfo[i].fish:setTrace(trace)
-- 		else
-- 			local trace = MathAide.BuildBezier(fishTraceInfo[i].init_x_pos,fishTraceInfo[i].init_y_pos,fishTraceInfo[i].init_count,fishTraceInfo[i].fish:getFishSpeed())
-- 			fishTraceInfo[i].fish:setTrace(trace)
-- 		end
-- 		fishTraceInfo[i].fish:setFishActive(true)
--         if fishTraceInfo[i].fish.traceLength > 0 then
-- 			local point = {}
-- 			point.x = fishTraceInfo[i].fish.traceTable[1].x
-- 			point.y = fishTraceInfo[i].fish.traceTable[1].y
-- 			fishTraceInfo[i].fish:setPosition(point)
--         end
-- 		fishManager:addFish(fishTraceInfo[i].fish)
-- 		-- fishTraceInfo[i] = nil
-- 		-- buildNum = buildNum + 1
-- 		coroutine.yield(curThread)
-- 	end
-- end

-- local threads = {}
-- function FishGameManager:getCo(data)
-- 	 local co = coroutine.create(function ()
-- 		-- local fishTraceInfo = self.m_vFish_trace_info_buffer
-- 		-- self.m_vFish_trace_info_buffer = {}
-- 		FishGameManager:onAddFish(data)
-- 	end)
-- 	table.insert(threads,co)
-- end
-- function FishGameManager:dispatcher()
-- 	local n = table.getn(threads)
-- 	if n == 0 then return end    -- no more threads to run
-- 	local status = coroutine.status(threads[1])
-- 	if status == "suspended" or status == "normal" then
-- 		coroutine.resume(threads[1])
-- 	elseif status == "running" then
-- 	elseif status == "dead" then
-- 		table.remove(threads, 1)
-- 	end
-- end

function FishGameManager:onFrame(dt)
	self:onFrameActiveFish()
	self.fishManager:onFrame(dt,self.isLock)
	self.cannonManager:onFrame(dt,false)
	self.bulletManager:onFrame(dt,false)
	-- self.lockManager:onFrame(dt)
	-- self:dispatcher()
end

function FishGameManager:setLock(isLock)
	if isLock then
		self.isLock = true
    else
		self.isLock = false
    end
end

function FishGameManager:getChairId()
	return self.chairId
end

function FishGameManager:getFishManager()
	return self.fishManager
end

function FishGameManager:getCannonManager()
	return self.cannonManager
end

function FishGameManager:getBulletManager()
	return self.bulletManager
end

function FishGameManager:getLockManager()
	return self.lockManager
end

function FishGameManager:getCoinManager()
	return self.coinManager
end

function FishGameManager:dispose()

	logger:log("----------------------------- FishGameManager:dispose() -----------------------------")
	AnimateManager:removeAllFishAnimate()
	AnimateManager:removeAllNetAnimate()
	-- AnimateManager:removeAllFishRes()
	AnimateManager:removeAllCoinAnimate()
	ArmatureManager:removeAllBulletArmature()

	-- self.helper:setThreadFlag(false)
	-- local delegate = self.helper:getDelegate()
	-- delegate:release()
	-- self.helper:release()

	self.gameView = nil
end
