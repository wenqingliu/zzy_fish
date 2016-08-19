local BaseLayer = import("app/views/layer/BaseLayer.lua")
local PopupLayer = class("PopupLayer",BaseLayer)
local scheduler = import("app/library/scheduler.lua")

function PopupLayer:ctor()
    self.super.ctor(self)

    display.addSpriteFrames("common.plist","common.png")

    self.panel = display.newSprite("#alert_bg.png"):addTo(self):setPosition(display.cx,display.cy - 10)
    self:setRootBg(self.panel)
    local size = self.panel:getContentSize()
    self.node = display.newNode():addTo(self.panel):setPosition(0,0)

    display.newSprite("#alert_title.png"):addTo(self.panel):setPosition(705/2,406)

    self.labelContent = cc.Label:create():addTo(self.panel):setPosition(705/2,200):setSystemFontSize(40):setDimensions(540,230)

    self.btnConfirm = ccui.Button:create("btn_confirm_normal.png","btn_confirm_pressed.png","btn_confirm_pressed.png",1)
        :addTo(self.panel)
        :setPosition(705/2,63)
        :setScale(0.7)
    self.btnConfirm:addTouchEventListener(handler(self,self.onBtnClick))

    self.btnCancel = ccui.Button:create("btn_cancel_normal.png","btn_cancel_pressed.png","btn_cancel_pressed.png",1)
        :addTo(self.panel)
        :setPosition(120,63)
        :setScale(0.7)
        :setVisible(false)
    self.btnCancel:addTouchEventListener(handler(self,self.onBtnClick))

end

function PopupLayer:onTouch(event)
    return true
end

function PopupLayer:onKeyboard(keyCode,event)
    event:stopPropagation()
end

function PopupLayer:onBtnClick(target,eventType)
    if eventType == 2 then
        audio.playSound("music/click")
        if self.callback ~= nil then
            local callback = self.callback
            self.callback = nil
            local param = self.param
            if target == self.btnConfirm then
                scheduler.performWithDelayGlobal(0.01,function()
                    callback(RT_SUCCESS,param)
                end)
            elseif target == self.btnCancel then
                scheduler.performWithDelayGlobal(0.01,function()
                    callback(RT_FAILURE,param)
                end)
            end
        end
        GameManager:hideAlert()--关闭弹窗
    end
end

function PopupLayer:show(title,content,callback,param)
    self.labelContent:setString(content)
    self:setCallBack(callback)
    self.param = param
    self.super.show(self)
end

--添加节点内容
function PopupLayer:addNodeContent(node)
    node:addTo(self.panel)
end

--设置按钮
function PopupLayer:setBtnVisible(bOk,bCancel)
    if bOk then
        self.btnConfirm:setVisible(true)
    end
    if bCancel then
        self.btnCancel:setVisible(true)
    end

    if bOk and bCancel then
        self.btnConfirm:setPositionX(586)
        self.btnCancel:setPositionX(120)
    end

end

function PopupLayer:destroy()
    self.super.destroy(self)
    print("PopupLayer:destroy()")
	self.callback = nil
end

function PopupLayer:getParam()
    return self.param
end

function PopupLayer:setCallBack(callback)
    self.callback = callback
end

function PopupLayer:onCleanup()
    print("PopupLayer:onCleanup()")
end


return PopupLayer
