local RoomEntryView = class("RoomEntryView", function()
	return display.newNode()
end)

local logger = zzy.Logger.new("RoomEntryView")

local FRONT_SCALE = 1
local BACK_SCALE = 0.8

local FRONT_ZORDER = 2
local BACK_ZORDER = 1

local roomNum = 0

function RoomEntryView:ctor()
    self:initData()
	if roomNum < 1 then return end
    self:setupView()

	-- local rectWidth,rectHeight = 800,300
	-- self.rect = cc.rect(display.cx - rectWidth/2,display.cy - rectHeight/2,rectWidth,rectHeight)
	self:setupTouchEvent()
end

function RoomEntryView:initData()
	self.roomList = GameManager:getRoomServer():getRoomList()
    roomNum = #self.roomList
end

function RoomEntryView:setupView()
	self.midIdx = 1
	local midIdx = self.midIdx
	local leftIdx = -1
	local rightIdx = -1

	if roomNum == 1 then
		leftIdx = -1
		rightIdx = -1
	elseif roomNum == 2 then
		leftIdx = ((midIdx - 1) > 0) and midIdx - 1 or -1
		rightIdx = ((midIdx + 1) > roomNum) and -1 or midIdx + 1
	else
		leftIdx = ((midIdx - 1) > 0) and midIdx - 1 or roomNum
		rightIdx = ((midIdx + 1) > roomNum) and 1 or midIdx + 1
	end


	self.leftIdx = leftIdx
	self.rightIdx = rightIdx

	self.btns = {}
	local res = {"btn_room1.png","btn_room2.png","btn_room3.png"}
    for i = 1,roomNum do
        self.btns[i] = display.newSprite("#btn_room"..i..".png"):addTo(self) --ccui.Button:create(res[i],res[i],res[i],1):addTo(self)--
        -- self.btns[i]:addTouchEventListener(handler(self,self.onBtnRoomClick))

        if i == midIdx then
            self.btns[i]:setScale(FRONT_SCALE)
            self.btns[i]:setLocalZOrder(FRONT_ZORDER)
            self.btns[i]:setPosition(display.cx, display.cy)
        elseif i == leftIdx then
            self.btns[i]:setScale(BACK_SCALE)
            self.btns[i]:setLocalZOrder(BACK_ZORDER)
            self.btns[i]:setPosition(display.cx-380, display.cy)
        elseif i == rightIdx then
            self.btns[i]:setScale(BACK_SCALE)
            self.btns[i]:setLocalZOrder(BACK_ZORDER)
            self.btns[i]:setPosition(display.cx+380, display.cy)
        else
            self.btns[i]:setVisible(false)
        end
    end

    local touchWidth,touchHight = 1000,400
    self.touchLayer = cc.LayerColor:create(cc.c4b(0,0,0,0)):addTo(self)
    :setPosition(display.cx - touchWidth/2,display.cy - touchHight/2)
    self.touchLayer:setContentSize(touchWidth,touchHight)
end

function RoomEntryView:setupTouchEvent()
    local lis = cc.EventListenerTouchOneByOne:create()

    -- touch began
    lis:registerScriptHandler(function (touch, event)
        self.isTouchStart = true
        self.isMove = false
        -- self.isTouchEnd = false
        if self.isRunningAction == true then return false end
        local node = self.touchLayer
            -- if not node:getVisible() then return false end
        local size = node:getContentSize()
        local rect = cc.rect(0,0,size.width,size.height)
        local point = node:convertTouchToNodeSpace(touch)
        if not cc.rectContainsPoint(rect,point) then
            return false
        end

        local location = touch:getLocation()
        self.beganX = location.x
        -- self.beganY = location.y
        return true
        end,cc.Handler.EVENT_TOUCH_BEGAN )

    --touch move
    lis:registerScriptHandler(function (touch, event)
        if self.isTouchStart == false then return false end
        if self.isRunningAction == true then return false end
        local location = touch:getLocation()
        local curX = location.x
        local beganX = self.beganX

		if math.abs(curX - beganX) > 5 then
			self.isMove = true
		end

        if math.abs(curX - beganX) > 10 then
            self.isTouchStart = false -- avoid keep move on after running action over still scroll
            if curX > beganX then
                self:moveRight()
            else
                self:moveLeft()
            end
        end

        end, cc.Handler.EVENT_TOUCH_MOVED)

    --touch end
    lis:registerScriptHandler(function (touch, event)
        if self.isMove == false then
            for i = 1, #self.btns do
                local node = self.btns[i]
                -- if not node:getVisible() then return false end
                local size = node:getContentSize()
                local rect = cc.rect(0,0,size.width,size.height)
                local point = node:convertTouchToNodeSpace(touch)
                if cc.rectContainsPoint(rect,point) then
                    if i == self.midIdx then
						audio.playSound("music/click")
                        local item = self:getParent().roomManager:getRoomByName(self.roomList[i]:szServerName())
                        self:getParent().gameScene:loginRoom(item)
                    elseif i == self.leftIdx then
                        self:moveRight()
                    elseif i == self.rightIdx then
                        self:moveLeft()
                    end
                    break
                end
            end
        end
        self.isMove = false
        self.isTouchStart = false
        end, cc.Handler.EVENT_TOUCH_ENDED)
    local eventDispatcher = self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(lis, self.touchLayer)
end

function RoomEntryView:moveLeft()
    logger:log("-------------moveLeft------------------")
    if self.isRunningAction then return  end

	local leftIdx = self.leftIdx
    local rightIdx = self.rightIdx
    local midIdx = self.midIdx

	if roomNum == 1 then return	end		--只有一个不用动了
	if rightIdx == -1 then return end	--右边都没有了，不能往左移动

    local newMidIdx = rightIdx
    local newLeftIdx = midIdx

	local newRightIdx = -1
	if roomNum > 2 then
    	newRightIdx = ((rightIdx + 1) > roomNum) and 1 or rightIdx + 1
	end

	self.isRunningAction = true
    --中间移到左边
    local actionMove1 = cc.MoveTo:create(0.2,cc.p(display.cx - 380,display.cy))
    local actionScale1 = cc.ScaleTo:create(0.2,BACK_SCALE)
    local actionSpawn1 = cc.Spawn:create(actionMove1,actionScale1)
    transition.execute(self.btns[midIdx],actionSpawn1,{onComplete = function()
		self.btns[midIdx]:setLocalZOrder(BACK_ZORDER)
	end})

    --右边移到中间
    local actionMove2 = cc.MoveTo:create(0.2,cc.p(display.cx,display.cy))
    local actionScale2 = cc.ScaleTo:create(0.2,FRONT_SCALE)
    local actionSpawn2 = cc.Spawn:create(actionMove2,actionScale2)
    transition.execute(self.btns[rightIdx],actionSpawn2,{onComplete = function()
		self.btns[rightIdx]:setLocalZOrder(FRONT_ZORDER)
		self.isRunningAction = false
	end})

    --左边移到右边 or 消失
	if leftIdx ~= -1 then
	    if leftIdx == newRightIdx then
	        local actionMove3 = cc.MoveTo:create(0.2,cc.p(display.cx + 380,display.cy))
	        local actionScale3 = cc.ScaleTo:create(0.2,BACK_SCALE)
	        local actionSpawn3 = cc.Spawn:create(actionMove3,actionScale3)
	        transition.execute(self.btns[leftIdx],actionSpawn3,{onComplete = function()
				self.btns[leftIdx]:setLocalZOrder(BACK_ZORDER)
			end})
	    else
	        self.btns[leftIdx]:setVisible(false)
	        self.btns[newRightIdx]:setVisible(true)
	        self.btns[newRightIdx]:setScale(BACK_SCALE)
	        self.btns[newRightIdx]:setPosition(display.right + 300,display.cy)
	        transition.execute(self.btns[newRightIdx],cc.MoveTo:create(0.2,cc.p(display.cx + 380,display.cy)),{onComplete = function()
				self.btns[newRightIdx]:setLocalZOrder(BACK_ZORDER)
			end})
	    end
	end

    self.leftIdx = newLeftIdx
    self.rightIdx = newRightIdx
    self.midIdx = newMidIdx
end

function RoomEntryView:moveRight()
    logger:log("-------------moveRight------------------")
    if self.isRunningAction then return  end

    local leftIdx = self.leftIdx
    local rightIdx = self.rightIdx
    local midIdx = self.midIdx

	if roomNum == 1 then return	end		--只有一个不用动了
	if leftIdx == -1 then return end	--左边都没有了，不能往右移动

    local newMidIdx = leftIdx
	local newLeftIdx = -1
	local newRightIdx = midIdx

	if roomNum > 2 then
		if leftIdx - 1 > 0 then
			newLeftIdx = leftIdx - 1
		else
			newLeftIdx = roomNum
		end
	end

	self.isRunningAction = true
    --中间移到右边
    local actionMove1 = cc.MoveTo:create(0.2,cc.p(display.cx + 380,display.cy))
    local actionScale1 = cc.ScaleTo:create(0.2,BACK_SCALE)
    local actionSpawn1 = cc.Spawn:create(actionMove1,actionScale1)
    transition.execute(self.btns[midIdx],actionSpawn1,{onComplete = function() self.btns[midIdx]:setLocalZOrder(BACK_ZORDER) end})

    --左边移到中间
    local actionMove2 = cc.MoveTo:create(0.2,cc.p(display.cx,display.cy))
    local actionScale2 = cc.ScaleTo:create(0.2,FRONT_SCALE)
    local actionSpawn2 = cc.Spawn:create(actionMove2,actionScale2)
    transition.execute(self.btns[leftIdx],actionSpawn2,{onComplete = function() self.btns[leftIdx]:setLocalZOrder(FRONT_ZORDER) self.isRunningAction = false end})

    --右边移到左边 or 消失
	if rightIdx ~= -1 then
	    if rightIdx == newLeftIdx then
	        local actionMove3 = cc.MoveTo:create(0.2,cc.p(display.cx - 380,display.cy))
	        local actionScale3 = cc.ScaleTo:create(0.2,BACK_SCALE)
	        local actionSpawn3 = cc.Spawn:create(actionMove3,actionScale3)
	        transition.execute(self.btns[rightIdx],actionSpawn3,{onComplete = function()
				self.btns[rightIdx]:setLocalZOrder(BACK_ZORDER) end})
	    else
	        self.btns[rightIdx]:setVisible(false)
	        self.btns[newLeftIdx]:setVisible(true)
	        self.btns[newLeftIdx]:setScale(BACK_SCALE)
	        self.btns[newLeftIdx]:setPosition(display.left - 300,display.cy)
	        transition.execute(self.btns[newLeftIdx],cc.MoveTo:create(0.2,cc.p(display.cx - 380,display.cy)),{onComplete = function()
				self.btns[newLeftIdx]:setLocalZOrder(BACK_ZORDER) end})
	    end
	end

    self.leftIdx = newLeftIdx
    self.rightIdx = newRightIdx
    self.midIdx = newMidIdx
end

return RoomEntryView
