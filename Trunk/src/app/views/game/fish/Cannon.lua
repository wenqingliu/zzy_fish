local Cannon = class("Cannon",cc.Node)

function Cannon:ctor()
end

function Cannon:init(param)
	params = param or {}
	self.kind = param.kind or 0
	self.isSelf = param.isSelf or false
	self.chairId = param.chairId or 1
	self.multiple = 1000
	self:initView()
end

function Cannon:initView()
	self.bg = display.newSprite("#cannon_board.png"):addTo(self)
	self.bg:setScale(0.9)
	local size = self.bg:getContentSize()

	if self.chairId == 1 then
		self.bg:setPosition(display.width/4 + 55,size.height/2*0.9)
	else
		self.bg:setPosition(display.width*3/4 + 100,size.height/2*0.9)
	end

	self.labelMultiple = cc.LabelTTF:create("","Arial",28):addTo(self.bg,1)
	self.labelMultiple:setPosition(152,23)

	self.labelScore = cc.LabelTTF:create("","Arial",28):addTo(self.bg,1)
	self.labelScore:setPosition(378,23)

	self.gun = display.newSprite(CannonConfig.GUN_RES[self.kind]):addTo(self.bg)
	self.gun:setPosition(150,55)

	if self.isSelf == true then
		self.btnAdd = ccui.Button:create("bt_add.png","bt_add_down.png","bt_add_down.png",1)
		self.btnAdd:addTo(self.bg)
		self.btnAdd:setPosition(254,26)
	    self.btnAdd:addTouchEventListener(handler(self,self.onBtnAddClick))

	    self.btnSub = ccui.Button:create("bt_sub.png","bt_sub_down.png","bt_sub_down.png",1)
		self.btnSub:addTo(self.bg)
		self.btnSub:setPosition(45,26)
	    self.btnSub:addTouchEventListener(handler(self,self.onBtnSubClick))
	end
end

function Cannon:onBtnAddClick(ref, type)
	if type == 0 then --begin
	elseif type == 1 then --moved
	elseif type == 2 then --release
		-- local cannonManger = FishGameManager:getCannonManager()
		-- cannonManger:setGun(self.chairId,2)

		self:changeMultiple(1)

		-- FishGameManager.gameView:switchScene(1)
		-- FishGameManager:testFish()

	elseif type == 3 then --cancle
	end
end

function Cannon:onBtnSubClick(ref, type)
	if type == 0 then
	elseif type == 1 then
	elseif type == 2 then
		-- local cannonManger = FishGameManager:getCannonManager()
		-- cannonManger:setGun(self.chairId,1)
		self:changeMultiple(-1)
		-- FishGameManager.gameView:switchScene(0)
	elseif type == 3 then
	end
end

function Cannon:changeMultiple(changeFlag)
	local chairId = FishGameManager:getChairId()
    local minMultiple = FishGameManager.m_nMin_bullet_multiple
    local maxMultiple = FishGameManager.m_nMax_bullet_multiple
    local bulletKindCount = BULLET_KIND_COUNT / 2
    local unitScale = 10
    local sectionBase = {}
	local sectionCount = 4
	for i = 1,sectionCount do sectionBase[i] = 0 end
    sectionBase[1] = minMultiple

    for i = 2, sectionCount do
        sectionBase[i] = sectionBase[i - 1] * unitScale
    end

    local bulletLevel = self.kind / bulletKindCount
    local currentBulletKind = 0

	local multiple = self.multiple

	-- 减炮
	if changeFlag == -1 then
    	if multiple == minMultiple then
	        multiple = maxMultiple
	        currentBulletKind = bulletKindCount
    	else
	        for i = 1, sectionCount do
				currentBulletKind = i
	            local scale = multiple / sectionBase[i]
	            if (scale > 0) and (scale <= unitScale) then
	                break
	            end
	        end
	        multiple = multiple - sectionBase[currentBulletKind]
	        if multiple / sectionBase[currentBulletKind] == 0 then
	            currentBulletKind = currentBulletKind - 1
	        end
	    end
	end

	-- 加炮
	if changeFlag == 1 then
        if multiple == maxMultiple then
            multiple = minMultiple
            currentBulletKind = 1
        else
            for i = 1, sectionCount do
				currentBulletKind = i
                local scale = multiple / sectionBase[i]
                if (scale >= 0) and (scale < unitScale) then
                    break
                end
            end
            multiple = multiple + sectionBase[currentBulletKind]
            if multiple / sectionBase[currentBulletKind] == unitScale then
                currentBulletKind = currentBulletKind + 1
            end
        end
	end

    self.kind = currentBulletKind + bulletKindCount * bulletLevel
	if self.kind > BULLET_KIND_COUNT - 1 then self.kind = BULLET_KIND_COUNT - 1 end

	-- local baseScore = 100
	-- local multipleIdx = self.currentMultiple/baseScore
	--
	-- local chairId = FishGameManager:getChairId()
	--
	-- if changeFlag == 1 then --加倍
	-- 	multipleIdx = multipleIdx + 1
	-- 	if multipleIdx > 10 then multipleIdx = 1 end
	-- elseif changeFlag == -1 then --减倍
	-- 	multipleIdx = multipleIdx - 1
	-- 	if multipleIdx < 1 then multipleIdx = 10 end
	-- end
	--
	-- local multiple = multipleIdx*baseScore
	--
	-- if self.kind > BULLET_KIND_COUNT - 1 then self.kind = BULLET_KIND_COUNT - 1 end

    -- 设置倍数
    FishGameManager:getCannonManager():switch(chairId,self.kind)
    FishGameManager:getCannonManager():setCannonMulriple(chairId, multiple)

    --播放声效
	audio.playSound("music/sound_switch")
end

function Cannon:setGun(bulletKind)
	if self.kind == bulletKind then return end
	self.kind = bulletKind
	self.gun:setSpriteFrame(display.newSpriteFrame(CannonConfig.GUN_RES[self.kind]))
end

function Cannon:setScore(score)
	self.labelScore:setString(""..score)
end

function Cannon:setMultiple(multiple)
	self.multiple = multiple

	local str = multiple..""
    if (multiple >= 10000) then
        str = (multiple / 10000).."万"
    end
    if (multiple >= 100000000) then
        str = (multiple / 100000000).."亿"
    end

	self.labelMultiple:setString(""..str)
end

return Cannon
