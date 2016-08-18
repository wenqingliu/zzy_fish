local CannonManager = class("CannonManager",cc.Layer)

local Cannon = import("app.views.game.fish.Cannon.lua")

function CannonManager:ctor()
end

function CannonManager:init()
    self:removeAllChildren()
    local mychairId = FishGameManager:getChairId()

    self.isFire            = false
    self.fishScore         = {}
    self.cannon            = {}
    self.currentMultiple   = {}
    self.currentAngle      = {}
    self.cannonPos         = {}
    self.currentBulletKind = {}

    for i = 1, 2 do
        self.fishScore[i] = 0
        local isself = false
        if mychairId == i then
            isself = true
        end
        self.cannon[i] = Cannon.new():addTo(self)
        self.cannon[i]:init({kind = 1,chairId = i,isSelf = isself})
        self.currentMultiple[i] = 1000
        self.cannonPos[i] = {}
        self.cannonPos[i] = self:getCannonPos(i)
        self.currentAngle[i] = 0
        self.currentBulletKind[i] = 0
    end

    self:setupTouchEvent()
end

function CannonManager:setGun(chairId,bulletKind)
    self.cannon[chairId]:setGun(bulletKind)
    self.currentBulletKind[chairId] = bulletKind
    self.cannonPos[chairId] = self:getCannonPos(chairId)
end

function CannonManager:setupTouchEvent()
    --Listener
    local lis = cc.EventListenerTouchOneByOne:create()
    lis:registerScriptHandler(function (touch, event)
        if FishGameManager.isSwitchingScene then return false end
        self.selectorPoint = touch:getLocation()
        self.isFire = true
        return true
        end,cc.Handler.EVENT_TOUCH_BEGAN )

    lis:registerScriptHandler(function (touch, event)
        if FishGameManager.isSwitchingScene then return false end
        self.selectorPoint = touch:getLocation()
        end, cc.Handler.EVENT_TOUCH_MOVED)

    lis:registerScriptHandler(function (touch, event)
        self.isFire = false
        end, cc.Handler.EVENT_TOUCH_ENDED)

    local eventDispatcher = self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(lis, self)
end

function CannonManager:setCannonMulriple(chairId, mulriple)
	self.currentMultiple[chairId] = mulriple
    self.cannon[chairId]:setMultiple(mulriple)
end

function CannonManager:setBaseScore(baseScore)
    self.baseScore = baseScore
end

function CannonManager:setCurrentAngle(chairId, angle)
	self.currentAngle[chairId] = angle
    local pi = math.pi
    local rotation = (angle*180/pi)
    self.cannon[chairId].gun:setRotation(rotation)
end

function CannonManager:setFishScore(chairId, swapFishScore)
    if chairId > 2 then return end -- TODO
	self.fishScore[chairId] = self.fishScore[chairId] + swapFishScore

	--设置金币分数
    self.cannon[chairId]:setScore(self.fishScore[chairId])
end

function CannonManager:getFishScore(chairId)
	return self.fishScore[chairId]
end

function CannonManager:getCannonPos(chairId)

    local posX = self.cannon[chairId].gun:getPositionX()
    local posY = self.cannon[chairId].gun:getPositionY()
    local pos = self.cannon[chairId].bg:convertToWorldSpace(cc.p(posX, posY))
    return pos
end

function CannonManager:getCurrentAngle(chairId)
	return self.currentAngle[chairId]
end

function CannonManager:fire(chairId, bullet_kind)
	--播放发炮声效
	--local handle;
	-- GameSoundManager::GetSoundManager()->FishSoundManager(handle,"FishSounds/effect/ion_casting.wav",PLAY_EFFECT);
	self.currentBulletKind[chairId] = bullet_kind

    --TODO 打炮时炮台的动画
end

function CannonManager:switch(chairId, bulletKind)
    if chairId > 2 then return end
	self.currentBulletKind[chairId] = bulletKind
    self:setGun(chairId, bulletKind)
end

local fireTime = 0.2
function CannonManager:onFrame(dt,isLock)
    --用户开火
    fireTime = fireTime + dt
    if (self.isFire and fireTime >= 0.2) then
        fireTime = 0

		--开火倍数
        local gameManager = FishGameManager
        local bulletManager = FishGameManager:getBulletManager()
        local cannonManager = FishGameManager:getCannonManager()

		local chairId = FishGameManager:getChairId()
		local meFishScore = self:getFishScore(chairId)

        -- 是否锁定 TODO
        -- local lockManager  = FishGameManager:getLockManager()
        -- if lockManager:getLockFishId(chairId) ~= -1 then
        --     self.selectorPoint = lockManager:getLockPos(chairId)
        -- end

        gameManager.m_nCurrent_bullet_mulriple = self.currentMultiple[chairId]
        gameManager.m_eCurrent_bullet_kind = self.currentBulletKind[chairId]

		if (gameManager.m_nCurrent_bullet_mulriple  <  gameManager.m_nMin_bullet_multiple)
            or (gameManager.m_nCurrent_bullet_mulriple  > gameManager.m_nMax_bullet_multiple) then
			gameManager.m_nCurrent_bullet_mulriple = gameManager.m_nMin_bullet_multiple
			gameManager.m_eCurrent_bullet_kind = gameManager.m_eCurrent_bullet_kind / 4 * 4
			-- self:switch(chairId , gameManager.m_eCurrent_bullet_kind)
			self:setCannonMulriple(chairId , gameManager.m_nCurrent_bullet_mulriple)
		end

		local bulletScore = gameManager.m_nCurrent_bullet_mulriple * gameManager.baseScore

		if (meFishScore >= bulletScore) then
            --控制子弹不超过15颗
            if bulletManager.bulletCount[chairId] >= MAX_BULLET_FIRE_COUNT then
                return
            end
            local cannonPos = self.cannonPos[chairId]
            local angle =  MathAide.CalcAngle(self.selectorPoint.x, self.selectorPoint.y, cannonPos.x, cannonPos.y)
            self:setCurrentAngle(chairId , angle)

            local bulletKind = self.currentBulletKind[chairId]
            local multiple = self.currentMultiple[chairId]
            local speed = FishGameManager.m_fBullet_Speed[bulletKind]
			--设置积分
			self:setFishScore(chairId , -bulletScore)
			--开火动画
			-- self:fire(chairId , self.currentBulletKind[chairId])

			--设置子弹
            -- srcPosX,srcPosY,angle,chairId,bulletKind,
            --bulletId,bulletScore,bulletSpeed,
            -- netRadius,lockFishId

            local netRadius = FishGameManager.m_fNet_Radius[bulletKind]
            local bullet = bulletManager:fire(cannonPos.x,cannonPos.y, angle, chairId, bulletKind,
                -1, multiple, speed,
                netRadius, -1)
            table.insert(bulletManager.bulletBufArray,bullet)

            gameManager:sendUserFire(bulletKind, self:getCurrentAngle(chairId), multiple, -1)--lockManager:getLockFishId(chairId))

            -- if (self.fishScore[chairId ] < self.currentMultiple[chairId ]) then
            --     CSpriteAlert* pAlert=CSpriteAlert::spriteAlert("系统提示", "分数不足，不能继续捕鱼！")
            --     pAlert:show(0, true)
            --     pAlert:setSelectorEnded(this, callfuncN_selector(CCannonManager::exitGame))
            -- end
        else
            GameManager:showAlertSystem(self,"分数不足，不能继续捕鱼！")
            audio.playSound("music/sound_needmore")
        end
    end

end

return CannonManager
