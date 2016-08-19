local BaseLayer = import("app/views/layer/BaseLayer.lua")
local RegisterPermissionLayer = class("RegisterPermissionLayer",BaseLayer)

function RegisterPermissionLayer:ctor()
    self.super.ctor(self)
    
    self.root = Resources:createNodeAndDoLayout("layer/layer_permission/layer_register_permission.csb"):addTo(self)
    self.panel = self.root:getChildByName("panel")
    self.alert_title = self.panel:getChildByName("alert_title")
    self.alert_content = self.panel:getChildByName("alert_content")
     
    self.alert_ok = self.panel:getChildByName("alert_ok")
    self.alert_ok:addTouchEventListener(BtnGroup:getHandler())
    self.alert_ok:addClickEventListener(handler(self,self.onClick))
    
    self.alert_cancel = self.panel:getChildByName("alert_cancel")
    self.alert_cancel:addTouchEventListener(BtnGroup:getHandler())
    self.alert_cancel:addClickEventListener(handler(self,self.onClick))
    
end

function RegisterPermissionLayer:onTouch(event)
    return true
end

function RegisterPermissionLayer:onKeyboard(keyCode,event)
    event:stopPropagation()
end

function RegisterPermissionLayer:onClick(target)
    if self.callback ~= nil then
        if target == self.alert_ok then
            self.callback(RT_SUCCESS,self.param)
        elseif target == self.alert_cancel then
            self.callback(RT_FAILURE,self.param)
        end
    end
end

function RegisterPermissionLayer:show(title,content,callback,param)
	self.alert_title:setString(title)
    self.alert_content:setString(content)
    self:setCallBack(callback)
    self.param = param
    
    self:setOpacity(0)
    self:setVisible(true)  
    local action = cc.FadeTo:create(0.1,255)
    self:runAction(action)
    return self
end

--设置按钮
function RegisterPermissionLayer:setBtnVisible(bOk,bCancel)
    if bOk then
        self.alert_ok:setVisible(true)
    end
    if bCancel then
        self.alert_cancel:setVisible(true)
    end
    
    if bOk and bCancel then
        local y = self.alert_ok:getPositionY()
        self.alert_ok:setPosition(cc.p(self.alert_cancel:getContentSize().width/2+55,y))
        self.alert_cancel:setPosition(cc.p(-self.alert_cancel:getContentSize().width/2-55,y))
    end
    
end

function RegisterPermissionLayer:destroy()
    self.super.destroy(self)
    print("RegisterPermissionLayer:destroy()")
	self.callback = nil
end

function RegisterPermissionLayer:getParam()
    return self.param
end

function RegisterPermissionLayer:setCallBack(callback)
    self.callback = callback
end

function RegisterPermissionLayer:onCleanup()
    print("RegisterPermissionLayer:onCleanup()")
end


return RegisterPermissionLayer