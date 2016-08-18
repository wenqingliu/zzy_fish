local BaseScene = class("BaseScene",cc.load("mvc").ViewBase)
function BaseScene:ctor(app, name)
    BaseScene.super.ctor(self,app, name)
    
    --注册键盘事件
    self.keyboard = cc.EventListenerKeyboard:create();
    self.keyboard:registerScriptHandler(handler(self,self.onKeyboard),cc.Handler.EVENT_KEYBOARD_RELEASED);
    local eventDispatcher = cc.Director:getInstance():getEventDispatcher();
    eventDispatcher:addEventListenerWithSceneGraphPriority(self.keyboard, self);
end

function BaseScene:onKeyboard(keyCode,event)
    -- 按R重新加载代码
    if jt.SDKControl:getInstance():isCocosDebug()  then
        if keyCode == 141 or keyCode == 18 then
            --清理数据
            jt.CFrameData:getInstance():setSocketClose(true)
            
            --清理当前场景
            self:removeAllChildren()
            self:stopAllActions()
            self:onCleanup()
            GameManager:destroy()
    
            --释放图片资源
            Resources:removeUnusedAllRes()
            local HotSwap = import("app/library/HotSwap.lua")
            
            --重新加载app文件夹代码
            HotSwap:reloadScriptFiles_app()
            --重启App
            HotSwap:restartApp()
        end
    end
end

return BaseScene