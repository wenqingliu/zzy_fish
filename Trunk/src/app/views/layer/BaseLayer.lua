local BaseLayer = class("BaseLayer",cc.load("mvc").ViewBase)

function BaseLayer:ctor()

	--重写
    self.root = nil --根结点
    self.panel = nil --主面板
    --//

    self:enableBGColor(true)
    self:enableNodeEvents()
    self:initEvent()

end

function BaseLayer:initEvent()

    --屏蔽底层事件
    self.listener = cc.EventListenerTouchOneByOne:create()
    self.listener:setSwallowTouches(true);
    self.listener:registerScriptHandler(handler(self,self.onTouchTop),cc.Handler.EVENT_TOUCH_BEGAN)
    cc.Director:getInstance():getEventDispatcher():
        addEventListenerWithSceneGraphPriority(self.listener,self)
    --//

    --返回键处理
    self.keyboard = cc.EventListenerKeyboard:create()
    self.keyboard:registerScriptHandler(handler(self,self.onKeyboard),cc.Handler.EVENT_KEYBOARD_RELEASED)
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithSceneGraphPriority(self.keyboard,self)
    --//

    --触摸层
    self.touchLayer = display.newLayer()
        :onTouch(handler(self, self.onTouch))
        :onClick(handler(self, self.onClick))
        :addTo(self)
    --//
end

---------------------------
-- 设置root背景,启用触摸非root背景区域隐藏功能
--@param self
--@param
--@return
function BaseLayer:setRootBg(node)
    self._rootBG = node
end

---------------------------
-- 启用背景颜色
function BaseLayer:enableBGColor(bool)
    if bool and self.bgLayer == nil then
        local bgLayer = cc.LayerColor:create();
        bgLayer:setColor(cc.c3b(0,0,0));
        bgLayer:setOpacity(180);
        bgLayer:setScale(1.5);
        self:addChild(bgLayer,-1);
        self.bgLayer = bgLayer
    elseif self.bgLayer ~= nil then
            self.bgLayer:removeFromParent()
            self.bgLayer = nil
    end
end

function BaseLayer:onTouchTop(touch,event)
    print("BaseLayer:onTouchTop(touch,event)")
    return true
end

function BaseLayer:onTouch(event)
    if event.name ~= "began" then return end

    if self._rootBG ~= nil then
        if not MotionUtil:checkPointToNode(self._rootBG,event)then
            self:removeCall()
            self:hide()
        end
    end
    return true
end

function BaseLayer:onClick(event)

end

function BaseLayer:removeCall()

end

function BaseLayer:onKeyboard(keyCode,event)
    event:stopPropagation()
    local bool = keyCode == cc.KeyCode.KEY_ESCAPE or keyCode == 6
    if device.platform ~= "windows" then
        bool = keyCode == cc.KeyCode.KEY_BACKSPACE and true or bool
    end
    if bool then
        self:hide()
    end
end

--------
--缓动展示
function BaseLayer:show()
    self._isShow = true

    if self.panel ~= nil then
        --缓动：界面放大显示
        self.panel:setScale(0.1)
        self.panel:setOpacity(0)
        self.panel:setVisible(true)
        local action1 = cc.Spawn:create(cc.ScaleTo:create(0.15,1.15),cc.FadeTo:create(0.15,255))
        local action  = cc.Sequence:create(action1,cc.ScaleTo:create(0.1,1.0),cc.CallFunc:create(handler(self,self.showCallBack)))
        self.panel:runAction(action)
    end

--    local oldY = self.root:getPositionY()
--    self.root:setPositionY(display.top)
--    local move = cc.MoveTo:create(0.2,{x=self.root:getPositionX(),y=oldY});
--    self.root:runAction(cc.EaseOut:create(move,1))
    return self
end

function BaseLayer:showCallBack()

end

function BaseLayer:hide()
    if self._isShow and self.panel ~= nil then
        --界面缩小隐藏
        self.panel:setVisible(true)
        local action1 = cc.ScaleTo:create(0.1,1.15)
        local action2 = cc.Spawn:create(cc.ScaleTo:create(0.12,0.1),cc.FadeTo:create(0.12,0))
        local action3 = cc.Hide:create()
        local func = cc.CallFunc:create(handler(self,self.destroy))
        local seq  = cc.Sequence:create(action1,action2,action3,func)
        self.panel:runAction(seq)
    else
        --延迟销毁，否则无法屏蔽onTouch事件
        self:runAction(MotionUtil:delayCallFunc(0.01,handler(self,self.destroy)))
    end
end

function BaseLayer:destroy()
--    self:onCleanup()
    self:removeFromParent(true)
    self.root = nil --根结点
    self.panel = nil --主面板
    self._rootBG = nil --背景面板
    print("BaseLayer:destroy()")
end

function BaseLayer:onExit()
    cc.Director:getInstance():getEventDispatcher():removeEventListenersForTarget(self,true)
end

---------------------------
-- 清理事件
--@param
--@return
function BaseLayer:onCleanup()

end

return BaseLayer
