--闪烁的小丁丁
--用例：zzy.ui.BlinkStar.new({starSrc = "#star_light.png", batchSrc = "common.png", num = 8, duration = 1, minX = -150, maxX = 170, minY = -70, maxY = 120})
--      :show()
--      :addTo(self.pigArmature,100)

local BlinkStar = class("BlinkStar", function()
    return display.newNode()
end)

function BlinkStar:ctor(param)
    self.starSrc = param.starSrc
    self.batchSrc = param.batchSrc
    self.num = param.num
    self.duration = param.duration or 2
    self.minX = param.minX
    self.maxX = param.maxX
    self.minY = param.minY
    self.maxY = param.maxY
    self.isRepeat = param.isRepeat or false
    self.interval = param.interval or 5

    self:setup()
end

function BlinkStar:setup()
    self.batch = display.newBatchNode(self.batchSrc):addTo(self)
    self.starSp = {}
end

function BlinkStar:onBlink(target)
    local delay = math.random(1,self.interval)/10
    local ranX = math.random( self.minX,  self.maxX)
    local ranY = math.random( self.minY, self.maxY)
    target:setPosition(ranX,ranY)
    transition.execute(target, cc.Sequence:create(cc.ScaleTo:create(0.8,1), cc.ScaleTo:create(0.8,0)),{delay = delay, onComplete = function ()
            self:onBlink(target)
    end})
end

function BlinkStar:show()
    for i = 1, self.num do
        self.starSp[i] = display.newSprite(self.starSrc):addTo(self.batch):setScale(0)
        self:onBlink(self.starSp[i])
    end

    if not self.isRepeat then
        self.scheduleid_ = zzy.Scheduler:delayGlobal(function()
            self:hide()
        end, self.duration)
    end

    return self
end

function BlinkStar:hide()
    self:removeFromParent()
end

function BlinkStar:onCleanup()
    if self.scheduleid_ then
        zzy.Scheduler:unscheduleGlobal(self.scheduleid_)
    end
end

return BlinkStar
