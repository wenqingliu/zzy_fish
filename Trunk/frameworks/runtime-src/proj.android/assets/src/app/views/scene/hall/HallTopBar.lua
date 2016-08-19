local HallTopBar = class("HallTopBar", function()
	return display.newNode()
end)

local ShopLayer = import("app/views/layer/ShopLayer.lua")
local PersonInfoLayer    = import("app/views/layer/PersonInfoLayer.lua")

function HallTopBar:ctor()
    self:setupView()
	self:setHeadTouch()
	self:runAnimate()
end

function HallTopBar:setupView()
    self.userInfoBg = display.newSprite("#user_info_bg.png"):addTo(self):setPosition(0,0)

    self.userHead = display.newNode():addTo(self.userInfoBg):setPosition(41,45)
    self.userHead.faceURL = "default"

    -- self.userHead = jt.SpriteURL:create(user:getFaceURL(),defaultPic,tostring(user:getGameID())):addTo(parentNode,order)

    display.newSprite("#head_board.png"):addTo(self.userInfoBg,1):setPosition(41,45)

    self.labelName = cc.LabelTTF:create("捕鱼达人","Arial",28):addTo(self.userInfoBg,1):setPosition(158,32)

    self.moneyNode = display.newSprite("#coin_value_bg.png"):addTo(self):setPosition(320,-10)
    self.spCoin = display.newSprite("#icon_coin.png"):addTo(self.moneyNode,1):setPosition(5,25)
    self.labelCoin = cc.LabelTTF:create("1234567890","Arial",28):addTo(self.moneyNode,1):setPosition(120,25)

    self.btnRecharge1 = ccui.Button:create("btn_recharge.png","btn_recharge.png","btn_recharge.png",1)
    self.btnRecharge1:addTo(self.moneyNode,1)
    self.btnRecharge1:setPosition(250,25)
    self.btnRecharge1:addTouchEventListener(handler(self,self.onBtnRechargeClick))

    self.diamondNode = display.newSprite("#coin_value_bg.png"):addTo(self):setPosition(660,-10)
    self.spDiamond = display.newSprite("#icon_diamond.png"):addTo(self.diamondNode,1):setPosition(20,25)
    self.labelDiamond = cc.LabelTTF:create("1234567890","Arial",28):addTo(self.diamondNode,1):setPosition(125,25)

    self.btnRecharge2 = ccui.Button:create("btn_recharge.png","btn_recharge.png","btn_recharge.png",1)
    self.btnRecharge2:addTo(self.diamondNode,1)
    self.btnRecharge2:setPosition(250,25)
    self.btnRecharge2:addTouchEventListener(handler(self,self.onBtnRechargeClick))
end

function HallTopBar:runAnimate()
	local stencil1 = display.newSprite("#stencil_coin.png")
	local cpNode1 = cc.ClippingNode:create()
	cpNode1:setPosition(28,32)
	cpNode1:addTo(self.spCoin)
	cpNode1:setInverted(false)      --设置底板可见
	cpNode1:setAlphaThreshold(0)   --设置绘制底板的Alpha值为0
	cpNode1:setStencil(stencil1)

	local spFlash1 = display.newSprite("#flash_coin.png"):addTo(cpNode1):setPosition(-50,0)
	spFlash1:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.MoveBy:create(1.5,cc.p(100,0)),cc.CallFunc:create(function()	spFlash1:setPosition(-50,0)end),cc.DelayTime:create(1))))
	local spShine1 = display.newSprite("#shine_coin.png"):addTo(self.spCoin):setPosition(53,42):setVisible(false)
	local posxShine1 = {8,3,13,51,39,47}
	local posyShine1 = {50,27,7,42,58,10}
	spShine1:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(2),
						cc.CallFunc:create(function() spShine1:setVisible(true) spShine1:setScale(0) end),
						cc.Spawn:create(cc.Sequence:create(cc.ScaleTo:create(0.75,1.2),cc.ScaleTo:create(0.75,0)),cc.RotateBy:create(1.5,30)),
						cc.CallFunc:create(function() spShine1:setVisible(false)
							local rand = math.random(1, 6)
							spShine1:setPosition(posxShine1[rand],posyShine1[rand])
						end))))

	local stencil2 = display.newSprite("#stencil_diamond.png")
	local cpNode2 = cc.ClippingNode:create()
	cpNode2:setPosition(33,33)
	cpNode2:addTo(self.spDiamond)
	cpNode2:setInverted(false)      --设置底板可见
	cpNode2:setAlphaThreshold(0)   --设置绘制底板的Alpha值为0
	cpNode2:setStencil(stencil2)

	local spFlash2 = display.newSprite("#flash_diamond.png"):addTo(cpNode2):setPosition(-50,0)
	spFlash2:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.MoveBy:create(1.4,cc.p(100,0)),cc.CallFunc:create(function()	spFlash2:setPosition(-50,0)end),cc.DelayTime:create(1))))
	local spShine2 = display.newSprite("#shine_diamond.png"):addTo(self.spDiamond):setPosition(61,40):setVisible(false)
	local posxShine2 = {47,19,1,18,43,61}
	local posyShine2 = {56,60,40,35,30,40}
	spShine2:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(2),
						cc.CallFunc:create(function() spShine2:setVisible(true) spShine2:setScale(0) end),
						cc.Spawn:create(cc.Sequence:create(cc.ScaleTo:create(0.75,1.2),cc.ScaleTo:create(0.75,0)),cc.RotateBy:create(1.5,30)),
						cc.CallFunc:create(function() spShine2:setVisible(false)
							local rand = math.random(1, 6)
							spShine2:setPosition(posxShine2[rand],posyShine2[rand])
						end))))
end

function HallTopBar:onClick(event)
	PersonInfoLayer:create(GameManager:getUserSelf()):addTo(self:getParent(),1)
end

function HallTopBar:setHeadTouch()
    local lis = cc.EventListenerTouchOneByOne:create()
    lis:registerScriptHandler(function (touch, event)
        return true
        end,cc.Handler.EVENT_TOUCH_BEGAN )

    lis:registerScriptHandler(function (touch, event)
        end, cc.Handler.EVENT_TOUCH_MOVED)

    lis:registerScriptHandler(function (touch, event)
		local node = self.userInfoBg
		-- if not node:getVisible() then return false end
		local size = node:getContentSize()
		local rect = cc.rect(0,0,size.width,size.height)
		local point = node:convertTouchToNodeSpace(touch)

		if cc.rectContainsPoint(rect,point) then
	        PersonInfoLayer:create(GameManager:getUserSelf()):addTo(self:getParent(),1)
	    end

        end, cc.Handler.EVENT_TOUCH_ENDED)

    local eventDispatcher = self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(lis, self.userInfoBg)
end

function HallTopBar:setUserName(name)
    self.labelName:setString(name)

    -- 限制长度 TODO
    -- if self.labelName:getContentSize().width > 210 then
    --     self.labelName:setFontSize(28)
    --     MotionUtil:cutLabel(self.labelName,200)
    -- end
end

function HallTopBar:setUserCoin(coin)
    self.labelCoin:setString(coin)
    -- 限制长度 TODO
end

function HallTopBar:setUserDiamond(coin)
    self.labelDiamond:setString(coin)
    -- 限制长度 TODO
end

function HallTopBar:setUserHead(user,faceURL)
    if self.userHead.faceURL ~= faceURL then
        self.userHead = MotionUtil:RepleaceWithURLPic(self.userHead,user,cc.size(68,68),nil,true)
        self.userHead.faceURL = faceURL
    end
end

function HallTopBar:onBtnRechargeClick(ref, type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        if self.btnRecharge1 == ref then
            ShopLayer:create(GameManager:getUserSelf(),1):addTo(self:getParent(),1)
        elseif self.btnRecharge2 == ref then
            ShopLayer:create(GameManager:getUserSelf(),2):addTo(self:getParent(),1)
        end
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

return HallTopBar
