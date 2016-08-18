local BaseLayer = import("app/views/layer/BaseLayer.lua")
local LoadingNiu = class("LoadingNiu",BaseLayer)

function LoadingNiu:ctor()
    LoadingNiu.super.ctor(self)
    --    local pCache = cc.SpriteFrameCache:getInstance()
    --    pCache:addSpriteFrames("animate/animate_loading_niu.plist");
    --
    --    self.bg = cc.Sprite:createWithSpriteFrameName("_progress_bg.png");
    --    self.bg:move(display.center):addTo(self)
    --
    --    self.niuNode = display.newNode():move(display.center):addTo(self)
    --    self.niuniu = cc.Sprite:createWithSpriteFrameName("_progress_ico_1.png");
    --    self.niuniu:addTo(self.niuNode)
    --    self.niuniu:setCascadeOpacityEnabled(true)
    --    self.niuNode:setCascadeOpacityEnabled(true)

    self.loading = cc.Sprite:create("loading.png")
    self.loading:addTo(self):move(display.center)

    self.loading2 = cc.Sprite:create("loading.png")
    self.loading2:addTo(self):move(display.center)
    self.loading2:setRotation(180)
end

function LoadingNiu:show()

    local rotain = cc.RotateBy:create(1,360,360)
    local func = cc.CallFunc:create(function()
        self.loading:setRotation(0)
    end)
    self.loading:runAction(cc.RepeatForever:create(cc.Sequence:create(rotain,func)))

    local rotain2 = cc.RotateBy:create(1,360,360)
    local func2 = cc.CallFunc:create(function()
        self.loading2:setRotation(180)
    end)
    self.loading2:runAction(cc.RepeatForever:create(cc.Sequence:create(rotain2,func2)))
end

function LoadingNiu:enableBGColor(bool)

end

function LoadingNiu:stop()
--    self.niuNode:stopAllActions()
end

function LoadingNiu:onKeyboard(keyCode,event)
  event:stopPropagation()
end

return LoadingNiu
