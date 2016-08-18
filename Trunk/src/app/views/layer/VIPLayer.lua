--喇叭层
local BaseLayer = import("app/views/layer/BaseLayer.lua")
local VIPLayer = class("VIPLayer",BaseLayer)
local CMD_Server_VIP = import("src/app/cmd/loginSever/CMD_Server_VIP.lua")
local ShopLayer = import("app/views/layer/ShopLayer.lua")

VIPLayer.events = {
    ccNd_VIP_INFO = "ccNd_VIP_INFO",            --VIP信息
    ccNd_VIP_GetReward = "ccNd_VIP_GetReward"   --VIP奖励领取
}
VIPLayer.rechargeNum = {6,30,88,258,380,650,7000,30000,50000}
function VIPLayer:ctor()
    self.super.ctor(self)
    self.root = Resources:createNodeAndDoLayout("layer/layer_VIP/layer_VIP.csb"):addTo(self)
    self.panel = self.root:getChildByName("panel")
    local spr = self.panel:getChildByName("spr_bg")
    self:setRootBg(spr)
    self.pageView = self.panel:getChildByName("page")
    
    Resources:setClippingEnabled(self.pageView)

    self.pageView:addEventListener(handler(self,self.pageTurning))
    self.pageView:setCustomScrollThreshold(50)
    local function openShop(sender,eventType)
        BtnGroup:onTouchButton(sender,eventType)
        if eventType == 2 then
            ShopLayer:create(GameManager:getUserSelf()):addTo(self:getParent())
            self:hide()
        end
    end
    self.recharge_Btn = self.panel:getChildByName("recharge_btn")
    self.recharge_Btn:addTouchEventListener(openShop)

    self.lingqu_btn = self.panel:getChildByName("lingqu_btn")
    self.lingqu_btn:addTouchEventListener(handler(self,self.getVIPReward))
    self.lingqu_btn:setTouchEnabled(false)
    self.lingqu_btn:setBright(false)

--    self.content_txt = self.panel:getChildByName("content_text")
    self.progress_txt = self.panel:getChildByName("progress")
    self.btnList = {}
    self.btnList[#self.btnList + 1] = self.panel:getChildByName("close_btn")
    self.btnList[#self.btnList + 1] = self.panel:getChildByName("FAQ_btn")

    self.leftArrow = self.panel:getChildByName("arrow_left"):setVisible(false)
    self.rightArrow = self.panel:getChildByName("arrow_right"):setVisible(true)
--    self:pageTuringTips(false,true)
    self.btnList[#self.btnList + 1] = self.leftArrow
    self.btnList[#self.btnList + 1] = self.rightArrow
    self.lastPage = 0
    self:show()
--    self:setEffect()
    self.panelChoose = 0

    CFrameDataHandler:getInstance():VIPInfo(0)

    CFrameDataHandler:getInstance():addEventListener(VIPLayer.events.ccNd_VIP_INFO,handler(self,self.OnVipInfo))
    CFrameDataHandler:getInstance():addEventListener(VIPLayer.events.ccNd_VIP_GetReward,handler(self,self.OnVipReward))

end

function VIPLayer:setEffect()
    local cilpNode_ = cc.ClippingNode:create(cc.Sprite:createWithSpriteFrameName("layer_vip/vip_jianyin.png")):addTo(self.panel)
    cilpNode_:setAnchorPoint(0.5,0.5)
    cilpNode_:setPosition(-5,263)
    cilpNode_:setAlphaThreshold(0)
    local img_1 = cc.Sprite:createWithSpriteFrameName("layer_vip/vip_light.png"):addTo(cilpNode_):setPosition(-220,0)
    local function func()
        img_1:setPosition(-220,0)
        local title = cc.Sprite:createWithSpriteFrameName("layer_vip/vipkuang.png"):addTo(self.panel):setPosition(-5,260)
        title:runAction(cc.Sequence:create(cc.Spawn:create(cc.ScaleBy:create(0.8,1.2),cc.MoveBy:create(0.8,cc.p(0,20)),cc.FadeOut:create(1)),cc.CallFunc:create(function()
            title:removeFromParent()
        end)))
    end
    img_1:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.MoveBy:create(1,cc.p(400,0)),cc.CallFunc:create(func),cc.DelayTime:create(2))))
end
function VIPLayer:OnVipInfo(event)
    local notify = event._userData
    if notify:getSize() ~= 0 then
        local cmd = CMD_Server_VIP.CMD_MB_S_UserVipInfo:createWithNotify(notify)
        local nowMoney = 0
        local nextMoney = 0

        if cmd.info.lVipNextExp <= 0 then
            self.progress_txt:setPercent(0)
        else
            self.progress_txt:setPercent(cmd.info.lVipExperience/cmd.info.lVipNextExp*100)
            local nowExp_str = tostring(cmd.info.lVipExperience/10000).."W.Exp"
            local nextExp_str = tostring(cmd.info.lVipNextExp/10000).."W.Exp"
            nowMoney = tostring(cmd.info.lVipExperience/10000)
            nextMoney = tostring(cmd.info.lVipNextExp/10000)
            self.panel:getChildByName("progress_txt"):setString(nowExp_str.." / "..nextExp_str)
        end
        if cmd.info.wVipLevel == 9 then             --VIP满级
            self.progress_txt:setPercent(100)
        end
        local vipLevel = self.panel:getChildByName("vip_level")
        if not cmd.info.bIsVip then
            vipLevel:setString("0")
        else
            vipLevel:setString(tostring(cmd.info.wVipLevel))
            if cmd.info.wTodayDraw == 0 then
                self.lingqu_btn:setTouchEnabled(true)
                self.lingqu_btn:setBright(true)
            end
            self.pageView:scrollToPage(cmd.info.wVipLevel - 1)
            for i=1, cmd.info.wVipLevel do
                self.pageView:getChildByName("page_"..i):getChildByName("lock_spr"):removeFromParent()
            end
        end
        local vip_str = 1
        local vip_recharge = VIPLayer.rechargeNum[1]
        if cmd.info.wVipLevel == 9 then
--            self.panel:getChildByName("content_text"):setString("")
        else
            vip_str = cmd.info.wVipLevel + 1
            vip_recharge = VIPLayer.rechargeNum[cmd.info.wVipLevel + 1]
--            self.panel:getChildByName("content_text"):setString( )
            local nextLabel = cc.Label:createWithSystemFont("仅需充值"..tostring(nextMoney - nowMoney).."元就能成为VIP"..tostring(vip_str),"",30,cc.size(380,0)):setAnchorPoint(0,0.5)
--            local nextLabel = cc.Label:createWithSystemFont("仅需充值6000元就能成为VIP"..tostring(vip_str),"",30,cc.size(380,0)):setAnchorPoint(0,0.5)
            nextLabel:addTo(self.panel):setPosition(-150,-240):setColor(cc.c3b(255,255,0))
        end

    end
end

function VIPLayer:getVIPReward(sender,eventType)
    BtnGroup:onTouchButton(sender,eventType)
    if eventType == 2 then
        CFrameDataHandler:getInstance():VIPInfo(1)
    end
end
function VIPLayer:OnVipReward(event)
    local notify = event._userData
    if notify:getSize() ~= 0 then
        local cmd = CMD_Server_VIP.CMD_MB_VipUserReward:createWithNotify(notify)
        if cmd.info.wStateCode == 0 then
            GameManager:showAlertSystem(self,cmd.info.szDescReward)
            GameManager:getUserSelf():setScore(GameManager:getUserSelf():getScore() + cmd.info.stuVipGetReward.lUserScore)
            GameManager:getUserSelf():setVIPHornNum(GameManager:getUserSelf():getVIPHornNum() + cmd.info.stuVipGetReward.lFreeHorn)
            if GameManager:getGameDelegate() ~= nil then
                GameManager:getGameDelegate():updateGameView()
            end
            self.lingqu_btn:setTouchEnabled(false)
            self.lingqu_btn:setBright(false)
        elseif cmd.info.wStateCode == 1 then
            GameManager:showAlertSystem(self,cmd.info.szDescReward)
        end
    end
end

function VIPLayer:pageTurning(sender,type)
    if type == 0 then
        if self.lastPage == sender:getCurPageIndex() then
        	return
        end

        if sender:getCurPageIndex() == 0 then
            self.rightArrow:setVisible(true)
            self.leftArrow:setVisible(false)
--            self:pageTuringTips(false,true)
        elseif sender:getCurPageIndex() == 8 then
            self.rightArrow:setVisible(false)
            self.leftArrow:setVisible(true)
--            self:pageTuringTips(true,false)
        else
            self.leftArrow:setVisible(true)
            self.rightArrow:setVisible(true)
--            self:pageTuringTips(true,true)
        end
        self.lastPage = sender:getCurPageIndex()
    end
end

function VIPLayer:pageTuringTips(left,right)
    self.rightArrow:stopAllActions()
    self.leftArrow:stopAllActions()
	if left then
		self.leftArrow:runAction(cc.RepeatForever:create(cc.Blink:create(1,1)))
	end
	if right then
		self.rightArrow:runAction(cc.RepeatForever:create(cc.Blink:create(1,1)))
	end
end

function VIPLayer:onTouch(event)
    BtnGroup:onTouchLayer(event,self.btnList)
    self.super.onTouch(self,event)

    if event.name ~= "ended" then return true end

    return true
end

function VIPLayer:onClick(event)
    if MotionUtil:checkPointToNode(self.panel:getChildByName("close_btn"),event) then
        self:hide()
    elseif MotionUtil:checkPointToNode(self.leftArrow,event) then
        self.pageView:scrollToPage(self.lastPage - 1)
    elseif MotionUtil:checkPointToNode(self.rightArrow,event) then
        self.pageView:scrollToPage(self.lastPage + 1)
    elseif MotionUtil:checkPointToNode(self.panel:getChildByName("FAQ_btn"),event) then
        self:choosePanel()
    end
    return true
end

--显示帮助还是显示VIP列表
function VIPLayer:choosePanel()
    if self.panelChoose == 1 then
        self.panelChoose = 0
        self.panel:getChildByName("FAQ_btn"):setSpriteFrame("layer_vip/wenhao.png")
        self.panel:getChildByName("faq_panel"):setVisible(false)
        self.panel:getChildByName("light_spr"):setVisible(true)
        self.pageView:setVisible(true)
        if self.lastPage == 0 then
            self.rightArrow:setVisible(true)
            self.leftArrow:setVisible(false)
        elseif self.lastPage == 8 then
            self.rightArrow:setVisible(false)
            self.leftArrow:setVisible(true)
        else
            self.leftArrow:setVisible(true)
            self.rightArrow:setVisible(true)
        end

    elseif self.panelChoose == 0 then
        self.panelChoose = 1
        self.panel:getChildByName("FAQ_btn"):setTexture("image/return.png")
        self.panel:getChildByName("faq_panel"):setVisible(true)
        self.panel:getChildByName("light_spr"):setVisible(false)
        self.pageView:setVisible(false)
        self.leftArrow:setVisible(false)
        self.rightArrow:setVisible(false)
    end
end
function VIPLayer:onCleanup()
    CFrameDataHandler:getInstance():removeEventListenerByList(self.events)
end

--//

return VIPLayer
