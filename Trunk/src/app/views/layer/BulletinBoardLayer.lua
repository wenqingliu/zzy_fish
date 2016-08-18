--游戏公告
local BaseLayer = import("app/views/layer/BaseLayer.lua")
local BulletinBoardLayer = class("BulletinBoardLayer",BaseLayer)

local SDKControlHandler = import("app/handler/SDKControlHandler.lua")

function BulletinBoardLayer:ctor(which)
    self.super.ctor(self)
    
    self.spr_bg = display.newSprite("scene/login/bg_gonggaotu.jpg"):addTo(self):move(display.center)
--    self:setRootBg(self.spr_bg)
    
    self.spr_close = display.newSprite("scene/login/_btn_close.png"):addTo(self)
        :move(self.spr_bg:getPositionX() + self.spr_bg:getContentSize().width / 2
            ,self.spr_bg:getPositionY() + self.spr_bg:getContentSize().height / 2)
    
    self.btnList = {self.spr_close}
end

function BulletinBoardLayer:onTouch(event)
    BulletinBoardLayer.super.onTouch(self,event)
    BtnGroup:onTouchLayer(event,self.btnList)
    
    if event.name ~= "ended" then return true end
    print(">>>>>")
    if MotionUtil:checkPointToNode(self.spr_bg,event) then
        if device.platform == "ios" then
            local map = {}
            map.kindid = 2010
            SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCOpenApp,map)
        else
            local url = GameManager:getProject():getBulletinURL()
            local map = {}
            map.url = url
            SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCOpenBrowser,map)
        end
    end
    
    if MotionUtil:checkPointToNode(self.spr_close,event) then
        self:hide()
    end
    
end

return BulletinBoardLayer