MathAide = MathAide or {}

local rad  = math.rad
local deg  = math.deg
local sin  = math.sin
local cos  = math.cos
local asin = math.asin
local acos = math.acos
local tan  = math.tan
local atan = math.atan
local pow  = math.pow
local abs  = math.abs
local sqrt = math.sqrt
local pi   = math.pi
local pi2  = pi/2

-- local sinf = function(i) return rad(sin(i)) end
-- local cosf = function(i) return rad(cos(i)) end
-- local acosf = function(i) return rad(acos(i)) end
-- local tanf = function(i) return rad(tan(i))end
-- local atanf = function(i) return rad(atan(i))end

local logger = zzy.Logger.new("MathAide")

function Factorial(n) --function 声明一个函数 函数名
	if n == 0 then
		return 1
	else
		return n * Factorial(n-1)
	end
end

function MathAide.CalcDistance(x1, y1, x2, y2)
	return sqrt(pow(x1-x2,2) + pow(y1 - y2,2))
end

function MathAide.Combination(count, r)
	return Factorial(count) / (Factorial(r) * Factorial(count - r))
end

function MathAide.CalcAngle(x1, y1, x2, y2)
	local distance = MathAide.CalcDistance(x1, y1, x2, y2)
	if distance == 0 then return 0 end
	local cosValue = (x1 - x2) / distance
	local angle = acos(cosValue)
	if (y1 > y2) then
		angle = 2 * pi - angle
	end
	angle = angle + pi2
	return angle
end

function MathAide.CalcRadian(x1, y1, x2, y2)
	local distance = MathAide.CalcDistance(x1, y1, x2, y2)
	if distance == 0 then return 0 end
	local sinValue = (x1 - x2) / distance
	local radian = asin(sinValue)
	return radian
end

function MathAide.CalcDegree(x1, y1, x2, y2)
	local dx = x1 - x2
	local dy = y1 - y2
	local t = dx/dy
	local at = atan(t)
	local degree = at/pi*180
	return degree
end

function MathAide.BuildCircle(centerX,centerY,radius,fishCount)
	if fishCount <= 0 then return end

	local cellRadian = 2 * pi / fishCount

	local fishPos = {}

	for i = 1, fishCount do
		fishPos[i] = {}
		fishPos[i].x = centerX + radius * cos(i*cellRadian)
		fishPos[i].y = centerY + radius * sin(i*cellRadian)
	end

	return fishPos
end

function MathAide.BuildCircle2(centerX, centerY, radius, fishCount, rotate, rotateSpeed)

	local fishPos = {}
	local cellRadian = 2 * pi / fishCount
	local lastPos = {}
	-- 这里计算好像有问题
	for i = 1, fishCount do
		lastPos.x = centerX + radius * cos(i * cellRadian + rotate - rotateSpeed)
		lastPos.y = centerY + radius * sin(i * cellRadian + rotate - rotateSpeed)

		fishPos[i] = {}
		fishPos[i].x = centerX + radius * cos(i * cellRadian + rotate)
		fishPos[i].y = centerY + radius * sin(i * cellRadian + rotate)
		local tempDis = MathAide.CalcDistance(fishPos[i].x, fishPos[i].y, lastPos.x, lastPos.y)
		if tempDis ~= 0 then
			local tempValue = (fishPos[i].x - lastPos.x) / tempDis
			if (fishPos[i].y - lastPos.y) >= 0 then
				fishPos[i].angle = acos(tempValue)
			else
				fishPos[i].angle = -acos(tempValue)
			end
		else
			fishPos[i].angle = pi2
		end
		-- logger:log("i = "..i..",fishPos[i].angle = "..fishPos[i].angle)
	end

	return fishPos
end

function MathAide.BuildLinear(initX, initY, initCount, speed)
	local traceTable = {}
	if initCount < 2 then return end
	if speed <= 0 then return end

	-- for idx = 2 , initCount do --打开这个for可计算多条直线
	local idx = 2 --写死最多只有两个点
	local distanceTotal = MathAide.CalcDistance(initX[idx], initY[idx],initX[idx - 1],initY[idx - 1])
	if distanceTotal <= 0 then return end

	local cosValue = abs(initY[idx] - initY[idx - 1]) / distanceTotal
	local tempAngle = acos(cosValue)

	local tempTableNum = 0

	local point = {}
	point.x = initX[idx - 1]
	point.y = initY[idx - 1]
	point.angle = 1
	tempTableNum = tempTableNum + 1
	traceTable[#traceTable + 1] = point
	local tempDistance = 0

	local tempPos = {x = 0,y = 0,angle = 0}

	local size = {}
	while (tempDistance < distanceTotal)
		do
		size = tempTableNum
		local point = {}
		if initX[idx] < initX[idx - 1] then
			point.x = initX[idx - 1] - sin(tempAngle) * (speed * size)
		else
			point.x = initX[idx - 1] + sin(tempAngle) * (speed * size)
		end

		if initY[idx] < initY[idx - 1] then
			point.y = initY[idx - 1] - cos(tempAngle) * (speed * size)
		else
			point.y = initY[idx - 1] + cos(tempAngle) * (speed * size)
		end
		local tempDis = MathAide.CalcDistance(point.x, point.y, tempPos.x, tempPos.y)
		if tempDis ~= 0 then
			local tempValue = (point.x - tempPos.x) / tempDis
			if (point.y - tempPos.y) >= 0 then
				point.angle = acos(tempValue)
			else
				point.angle = -acos(tempValue)
			end
		else
			point.angle = 1
		end

		tempPos.x = point.x
		tempPos.y = point.y
		-- logger:log("point.x = "..point.x..",point.y = "..point.y)
		tempTableNum = tempTableNum + 1

		traceTable[#traceTable + 1] = point
		tempDistance = MathAide.CalcDistance(point.x, point.y, initX[idx - 1], initY[idx - 1])
	end
	-- end
	traceTable[#traceTable] = {x = initX[initCount], y = initY[initCount]}
	return traceTable
end

function MathAide.BuildBezier(initX, initY, initCount, speed)
	local traceTable = {}
	local pos1 = { x = initX[1], y = initY[1], angle = 1 }
	traceTable[#traceTable+1] = pos1
	local index = 1
	local tempPos0 = { x=0, y=0, angle = 0}
	local t = 0
	local count = initCount
	local tempDistance = speed/4

	local tempValue = 0

	while (t < 1)
		do
		local tempPos = { x=0, y=0 ,angle = 0}
		index = 1
		while (index <= count)
			do
				tempValue = pow(t, index) * pow(1 - t, count - index) * MathAide.Combination(count, index)
				tempPos.x = tempPos.x + initX[index] * tempValue
				tempPos.y = tempPos.y + initY[index] * tempValue
				index = index + 1
			end
			local posSpace = 0
			if #traceTable > 0 then
				local backPos = traceTable[#traceTable]
				posSpace = MathAide.CalcDistance(backPos.x, backPos.y, tempPos.x, tempPos.y)
			end

			if posSpace >= tempDistance then --or #traceTable == 0
				-- if #traceTable > 0 then
				local tempDis = MathAide.CalcDistance(tempPos.x, tempPos.y, tempPos0.x, tempPos0.y)
				-- if tempDis ~= 0 then
				local tempValue = (tempPos.x - tempPos0.x) / tempDis
				if (tempPos.y - tempPos0.y) >= 0 then
					tempPos.angle = acos(tempValue)
				else
					tempPos.angle = -acos(tempValue)
				end
				-- else
				-- tempPos.angle = 1
				-- end
				-- else
				-- tempPos.angle = 1
				-- end

				-- logger:log("tempPos.x = "..tempPos.x..",tempPos.y = "..tempPos.y)
				traceTable[#traceTable + 1] = tempPos
				tempPos0.x = tempPos.x
				tempPos0.y = tempPos.y
			end
			t = t + 0.001
		end
				-- logger:log("traceTable[1].x = "..traceTable[1].x..",traceTable[1].y = "..traceTable[1].y)
				-- logger:log("traceTable[2].x = "..traceTable[2].x..",traceTable[2].y = "..traceTable[2].y)
	return traceTable
end

return MathAide
