local BoundingBox = class("BoundingBox")

local sinf = math.sin
local cosf = math.cos

local logger = zzy.Logger.new("BoundingBox")

function BoundingBox:ctor()
    self.p1 = {}
    self.p2 = {}
    self.p3 = {}
    self.p4 = {}
end

function BoundingBox:createBoundingBox(boxWidth, boxHeight, centerX, centerY, angle)
    boxWidth = boxWidth / 2
	boxHeight = boxHeight / 2

	local sint = sinf(angle)
	local cost = cosf(angle)
	local hotX1 = -boxWidth
	local hotY1 = -boxHeight
	local hotX2 = boxWidth
	local hotY2 = boxHeight

	self.p1.x = hotX1 * cost - hotY1 * sint + centerX
	self.p1.y = hotX1 * sint + hotY1 * cost + centerY
	self.p2.x = hotX2 * cost - hotY1 * sint + centerX
	self.p2.y = hotX2 * sint + hotY1 * cost + centerY
	self.p3.x = hotX2 * cost - hotY2 * sint + centerX
	self.p3.y = hotX2 * sint + hotY2 * cost + centerY
	self.p4.x = hotX1 * cost - hotY2 * sint + centerX
	self.p4.y = hotX1 * sint + hotY2 * cost + centerY
    return self
end

function multiply(p1,p2,p0)
    return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y))
end

function BoundingBox:computeCollision(x, y)
    local p = {x = x, y = y}
    local p1 = self.p1
    local p2 = self.p2
    local p3 = self.p3
    local p4 = self.p4

    if (multiply(p, p1, p2) * multiply(p,p4, p3) <= 0 and multiply(p, p4, p1) * multiply(p, p3, p2) <= 0) then
        return true
    end
    return false
end

return BoundingBox
