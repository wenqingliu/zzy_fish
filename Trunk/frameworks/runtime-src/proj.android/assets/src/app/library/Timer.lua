local MotionUtil = import("app/library/MotionUtil.lua")

local Timer = class("Timer",function(node,handler, interval,repeatCount)
    local t = {}
    return t
end)


----------------------
-- 创建计时器
function Timer:create(node,handler, interval,repeatCount)
    local t = Timer.new(node,handler, interval,repeatCount)
    return t
end

local function getAction(interval,callBack)
--    local delay = cc.DelayTime:create(interval)
--    local sequence = cc.Sequence:create({delay,cc.CallFunc:create(callBack)})
    local delay = MotionUtil:delayCallFunc(interval,callBack)
    local rep = cc.RepeatForever:create(delay)
    return rep
end

function Timer:init(node,handler,interval,repeatCount)
    
    self.currentCount = 0
    self.repeatCount = 9999999999
    self.isAlwaysLoop = true
    self.interval = 0
    self.running = false
    self.node = nil
    self.handler = nil
    self.action = nil

    self.node = node
    self.handler = handler
    if repeatCount ~= nil then
        self.repeatCount = repeatCount
        self.isAlwaysLoop = false
    end
    self.interval = interval
end

function Timer:ctor(node,handler, interval,repeatCount)
    self:init(node,handler, interval,repeatCount)
end

function Timer:start()
    
    local function timerHandler()
        if self.currentCount >= self.repeatCount and self.isAlwaysLoop == false then
            self:stop()
            return
        end
        self.currentCount = self.currentCount + 1
        self.handler(self)
    end
    
    if self.action == nil then
        self.action = getAction(self.interval,timerHandler)
    end
    
--    local scheduler = cc.Director:getInstance():getScheduler()
--    self.schedulerID = scheduler:scheduleScriptFunc(timerHandler,self.interval,false)
    
    self.node:runAction(self.action)
	self.running = true
	return self
end

function Timer:stop()
--    cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.schedulerID)
    self.node:stopAction(self.action)
    self.action = nil
    self.running = false
end

function Timer:reset()
    self:stop()
    self.currentCount = 0
    self:init(self.node,self.handler,self.interval,self.repeatCount)
    self:start()
    return self
end

function Timer:setTag(tag)
    self.tag = tag
end

function Timer:getTag()
    return self.tag
end

return Timer