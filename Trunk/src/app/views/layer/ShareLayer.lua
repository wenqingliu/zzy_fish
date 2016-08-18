--分享
local BaseLayer = import("app/views/layer/BaseLayer.lua")
local ShareLayer = class("ShareLayer",BaseLayer)
local SDKControlHandler = import("app/handler/SDKControlHandler.lua")

function ShareLayer:ctor(ShopLayer)
    ShareLayer.super.ctor(self)
--    self:enableNodeEvents()

    -- share_btn_qq.png
    -- share_btn_qqz_dis.png
    -- share_btn_sina.png
    -- share_btn_sms.png
    -- share_btn_wechat.png
    display.addSpriteFrames("share_btns.plist","share_btns.png")

    self.panel = display.newSprite("#alert_bg.png"):addTo(self):setPosition(display.cx,display.cy - 10)
    self:setRootBg(self.panel)
    local size = self.panel:getContentSize()
    self.node = display.newNode():addTo(self.panel):setPosition(0,0)

    display.newSprite("label_share_type.png"):addTo(self.panel):setPosition(705/2,406)

    self.labelContent = cc.Label:create():addTo(self.panel):setPosition(705/2,200):setSystemFontSize(40):setDimensions(540,230)

    self.btns = {}
    self.btns[1] = ccui.Button:create("share_btn_qq.png","share_btn_qq.png","share_btn_qq.png",1):addTo(self.panel):setPosition(705/2-200,250)
    self.btns[2] = ccui.Button:create("share_btn_qqz_dis.png","share_btn_qqz_dis.png","share_btn_qqz_dis.png",1):addTo(self.panel):setPosition(705/2,250)
    self.btns[3] = ccui.Button:create("share_btn_sina.png","share_btn_sina.png","share_btn_sina.png",1):addTo(self.panel):setPosition(705/2 + 200,250)
    self.btns[4] = ccui.Button:create("share_btn_wechat.png","share_btn_wechat.png","share_btn_wechat.png",1):addTo(self.panel):setPosition(705/2 - 200,110)
    self.btns[5] = ccui.Button:create("share_btn_sms.png","share_btn_sms.png","share_btn_sms.png",1):addTo(self.panel):setPosition(705/2,110)
    self.btns[1]:addTouchEventListener(handler(self,self.onBtnClick))
    self.btns[2]:addTouchEventListener(handler(self,self.onBtnClick))
    self.btns[3]:addTouchEventListener(handler(self,self.onBtnClick))
    self.btns[4]:addTouchEventListener(handler(self,self.onBtnClick))
    self.btns[5]:addTouchEventListener(handler(self,self.onBtnClick))

    local visible = jt.SDKControl:getInstance():getValueFromPlatform(7,"") --QQ
    if tonumber(visible) == 0 then
        self.btns[2]:setTouchEnabled(false)
        self.btns[2]:setColor(cc.c3b(110,110,110))
    end

    local wechat = GameManager:getProject().LogonType_Enum.LogonType_WeChat --微信5
    if not jt.SDKControl.LogonBtn_List[wechat+1] then
        self.btns[4]:setTouchEnabled(false)
        self.btns[4]:setColor(cc.c3b(110,110,110))
        self.btns[5]:setTouchEnabled(false)
        self.btns[5]:setColor(cc.c3b(110,110,110))
    end


    local handle1,tag1 = SDKControlHandler:getInstance():addSelector(jt.SDKControl:getInstance(),SDKControlHandler.RecipientsList.ccNd_Share,handler(self,self.shareResult))
    self.listenersList = {tag1}
    self:show()
    --事件层
    --    self.touchLayer = display.newLayer()
    --        :onTouch(handler(self, self.onTouch))
    --        :onClick(handler(self, self.onClick))
    --        :addTo(self)
end

function ShareLayer:onTouch(event)
    ShareLayer.super.onTouch(self,event)
    return true
end

function ShareLayer:onBtnClick(ref,eventType)
    if eventType == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif eventType == 1 then --moved
    elseif eventType == 2 then
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        audio.playSound("music/click")

        for i = 1, 5 do
            if ref == self.btns[i] then
                if ref.enabled then
        	       self:CCShare(i-1)
                end
                break
            end
        end

    elseif eventType == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function ShareLayer:CCShare(index)
    local map = {}
    map.type = index
    map.title = "皇家游戏"
    map.content = "皇家游戏是一款为玩家精心准备的棋牌休闲游戏，挑战智慧与运气的极限。"
    map.link = "http://www.zzy1314.com/niuniu.html"
    map.imageLink = "http://www.zzy1314.com/images/300.png"
    SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCShare,map)
end

function ShareLayer:shareResult(event)
    local map = event._userData
    if map.result == 1 then
        local shareSuccessPlatform = map.platform
        local serverPlatfrom = -1

        --服务器值: 4:QQ空间,2:微信朋友圈，0：新浪微博
        if shareSuccessPlatform == 1 then
            serverPlatfrom = 4
        elseif shareSuccessPlatform == 2 then
            serverPlatfrom = 0
        elseif shareSuccessPlatform == 4 then
            serverPlatfrom = 2
        else
            GameManager:showAlertSystem(self,"分享到QQ空间、微信朋友圈、微博才可以获得奖励哦")
            return
        end
        GameManager:showAlertSystem(self,"分享成功！")
        self.isShareSuccessful = false
        CFrameDataHandler:getInstance():shareSuccess(serverPlatfrom)
    else
        GameManager:showAlertSystem(self,"分享失败！")
        print(map.message)
    end
end

function ShareLayer:onCleanup()
    display.removeSpriteFramesWithFile("share_btns.plist","share_btns.png")
    SDKControlHandler:getInstance():removeSelectors(SDKControlHandler.RecipientsList.ccNd_Share)
end

return ShareLayer
