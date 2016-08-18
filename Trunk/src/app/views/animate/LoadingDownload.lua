local BaseLayer = import("app/views/layer/BaseLayer.lua")
local LoadingDownload = class("LoadingNiu",BaseLayer)
local scheduler = import("app/library/scheduler.lua")
local Timer = import("app/library/Timer.lua")
function LoadingDownload:ctor()
    LoadingDownload.super.ctor(self)
    
    self.moveCount = 0
    
    local pCache = cc.SpriteFrameCache:getInstance()
    pCache:addSpriteFrames("animate/animate_loading_download.plist");

--    self.bg = cc.Sprite:createWithSpriteFrameName("niu__anim_pro_bg.png");  
--    self.bg:move(display.center):addTo(self)
    
    local pos = cc.p(display.center.x,40)
    self.sprProBg = cc.Sprite:createWithSpriteFrameName("niu__anim_pro_bg.png"):addTo(self):move(pos.x,pos.y + 100)
    self.sprPro = cc.Sprite:createWithSpriteFrameName("niu_anim_pro.png"):move(self.sprProBg:getPosition())

    local clip = cc.ClippingNode:create()
    self.clipPro = clip
    clip:addTo(self)
    clip:setPosition(self.sprPro:getPosition())

    local circle = cc.Sprite:createWithSpriteFrameName("niu_anim_pro.png")--:addTo(self):move(pos.x,pos.y + 100)
    circle:setPosition(cc.p(0,0))
    self.sprPro:setPosition(cc.p(-self.sprPro:getContentSize().width,0))
    clip:addChild(self.sprPro)--添加要被遮罩遮挡的内容
    clip:setStencil(circle)--设置模板
    clip:setInverted(false)--false圆形区域可见
    clip:setAlphaThreshold(0)--透明度为0的不可见
    
    --效果
    self.sprLight = cc.Sprite:createWithSpriteFrameName("niu__anim_xiaoguo.png")
    self.sprLight:move(clip:convertToWorldSpace(cc.p(circle:getPosition()))):addTo(self)
    self.sprLightDot = cc.Sprite:createWithSpriteFrameName("niu__anim_yidong.png")
    self.sprLightDot:move(self.sprLight:getPosition()):addTo(self)
    
    self.startY = self.sprLightDot:getPositionY()
    self.isUp = true
    
    
    self.txt_pro = cc.Label:createWithSystemFont("","fonts/qnhgjch.TTF",32)
    self.txt_pro:setTextColor(cc.c4b(244,210,23,255))
    self.txt_pro:addTo(self):move(cc.p(clip:getPositionX(),clip:getPositionY()+50))
    
    self.txt_total = cc.Label:createWithSystemFont("","fonts/qnhgjch.TTF",32)
    self.txt_total:setTextColor(cc.c4b(244,210,23,255))
    self.txt_total:addTo(self):move(cc.p(clip:getPositionX(),clip:getPositionY()-50))
    
    self:setProgress(0)
    self.scheduler = scheduler.scheduleUpdateGlobal(handler(self,self.onUpdate))
end

function LoadingDownload:show()
    
end

function LoadingDownload:setTitle(str)
    self.txt_total:setString(str)
end

function LoadingDownload:setTotalSize(str)
    self.txt_total:setString("本次更新大小" .. str)
end

function LoadingDownload:setProgress(percent)
    local pro = -self.sprPro:getContentSize().width + (self.sprPro:getContentSize().width) * percent / 100
    self.sprPro:setPosition(cc.p(pro,self.sprPro:getPositionY()))
    
    local pro2 = pro + self.sprPro:getContentSize().width/2-16
    pro2 = pro2 <= -260 and -260 or pro2
    self.sprLight:move(self.clipPro:convertToWorldSpace(cc.p(pro2,self.sprPro:getPositionY())))
    self.sprLightDot:setPositionX(self.sprLight:getPositionX())
    
    self.txt_pro:setString("当前下载进度"..math.floor(percent).."%")
    
--    local progress = string.format("正在下载文件:%s(%d%%)", self.currentV, percent)
--    print(progress)
end

function LoadingDownload:onUpdate(event)
    if self.isUp then
        self.moveCount = self.moveCount + 2
    end
    if self.moveCount >= 35 then
        self.isUp = false
    end
    if not self.isUp then
        self.moveCount = self.moveCount - 2
    end
    if self.moveCount <= -40 then
        self.isUp = true
    end
    self.sprLightDot:setPositionY(self.startY + self.moveCount)
end

function LoadingDownload:onKeyboard(keyCode,event)
--    event:stopPropagation()
end

function LoadingDownload:onCleanup()
    scheduler.unscheduleGlobal(self.scheduler)
end

return LoadingDownload