--[[

Copyright (c) 2011-2014 chukong-inc.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

]]

local Layer = cc.Layer

function Layer:onTouch(callback, isMultiTouches, swallowTouches)
    if type(isMultiTouches) ~= "boolean" then isMultiTouches = false end
    if type(swallowTouches) ~= "boolean" then swallowTouches = false end
    self.touchhandler__ = true
    local began = nil
    self:registerScriptTouchHandler(function(state, ...)
        local args = {...}
        local event = {name = state}
        if isMultiTouches then
            args = args[1]
            local points = {}
            for i = 1, #args, 3 do
                local x, y, id = args[i], args[i + 1], args[i + 2]
                points[id] = {x = x, y = y, id = id}
            end
            event.points = points
        else
            event.x = args[1]
            event.y = args[2]
        end
        local bool = callback(event)
        
        --自定义添加点击事件 by 庆茂 2016/04/20
        if self.clickCallBack ~= nil then
            if state == "began" then
                began = event
            end
            if state == "ended" then
                local offset = 20
                if cc.rectContainsPoint(cc.rect(began.x-offset,began.y-offset,began.x+offset,began.y+offset),event) then
                    self.clickCallBack(event)
                end
            end
        end
        return bool
--        return callback(event)--引擎BUG修复
    end, isMultiTouches, 0, swallowTouches)
    self:setTouchEnabled(true)
    return self
end

function Layer:onClick(callback)
    self.clickCallBack = callback
    if not self.touchhandler__ then
        self:onTouch(function(event)
            return true
        end)
    end
    return self
end

function Layer:removeTouch()
    self:unregisterScriptTouchHandler()
    self:setTouchEnabled(false)
    return self
end

function Layer:onKeypad(callback)
    self:registerScriptKeypadHandler(callback)
    self:setKeyboardEnabled(true)
    return self
end

function Layer:removeKeypad()
    self:unregisterScriptKeypadHandler()
    self:setKeyboardEnabled(false)
    return self
end

function Layer:onAccelerate(callback)
    self:registerScriptAccelerateHandler(callback)
    self:setAccelerometerEnabled(true)
    return self
end

function Layer:removeAccelerate()
    self:unregisterScriptAccelerateHandler()
    self:setAccelerometerEnabled(false)
    return self
end
