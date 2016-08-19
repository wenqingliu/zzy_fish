local BulletManager = class("BulletManager",cc.Layer)

local Bullet = import("app.views.game.fish.Bullet.lua")

local logger = zzy.Logger.new("Bullet")

function BulletManager:ctor()
	self.bulletArray = {}
	self.bulletBufArray = {}
    self.bulletCount = {0,0} --每个玩家都有一个子弹计数
end

function BulletManager:init()

end

function BulletManager:fire(srcPosX,srcPosY,angle,chairId,bulletKind,bulletId,bulletMulriple,bulletSpeed,netRadius,lockFishId)

	if self.bulletCount[chairId] >= MAX_BULLET_FIRE_COUNT then return end

	local bullet = Bullet.new()
	bullet:init({bulletKind = bulletKind, bulletId = bulletId, bulletMulriple = bulletMulriple, chairId = chairId, netRadius = netRadius,bulletSpeed = bulletSpeed,angle = angle})

	bullet:setLockFishId(lockFishId)
	bullet:setStatus("flying")

	local initPosX = { srcPosX }
	local initPosY = { srcPosY }
	local lockSuccess = false

	-- if not lockSuccess then
	-- 	initPosX[1] =  srcPosX
	-- 	initPosY[1] =  srcPosY
	--
	-- 	initPosX[2], initPosY[2] = self:getTargetPoint(chairId, srcPosX, srcPosY, angle)
    --     bullet.traceVector = MathAide.BuildLinear(initPosX, initPosY, 2, bulletSpeed)
    -- end
    -- bullet:setTraceIndex(1)
    -- bullet:setPosition(cc.p(bullet.traceVector[1].x, bullet.traceVector[1].y))
    bullet:setPosition(cc.p(srcPosX, srcPosY))

    self.bulletCount[chairId] = self.bulletCount[chairId] + 1

    self:addChild(bullet.sp)
    table.insert(self.bulletArray,bullet)

	self.isPlayFireSound = true
    return bullet
end

function BulletManager:reboundBullet(bullet)
    --锁定鱼反弹时，取消目标
    bullet:setLockFishId(1)
    if not next(bullet.traceVector) then return end
    local pointBack = bullet.traceVector[#bullet.traceVector]
    local pointFront = bullet.traceVector[1]

    local initPosX = { pointBack.x }
    local initPosY = { pointBack.y }

	local screenWidth = display.width --nf.resolutionWidth
	local screenHeight = display.height -- nf.resolutionHeight
	local chairId = 1
	local angle = 0
	if (initPosX[1] == screenWidth) and (initPosY[1] > 0) and (initPosY[1] < screenHeight) then --右
		if pointFront.y > pointBack.y then
			angle = MathAide.CalcAngle(pointFront.x, pointFront.y - (pointFront.y - pointBack.y) * 2, pointBack.x, pointBack.y)
		else
			angle = MathAide.CalcAngle(pointFront.x, pointFront.y + (pointBack.y - pointFront.y) * 2, pointBack.x, pointBack.y)
		end
	elseif initPosY[1] == screenHeight then --上
		if pointFront.x > pointBack.x then
			angle = MathAide.CalcAngle(pointFront.x - (pointFront.x - pointBack.x) * 2, pointFront.y, pointBack.x, pointBack.y)
		else
			angle = MathAide.CalcAngle(pointFront.x + (pointBack.x - pointFront.x) * 2, pointFront.y, pointBack.x, pointBack.y)
		end
	elseif (initPosX[1] == 0) and (initPosY[1] > 0) and (initPosY[1] < screenHeight) then --左
		if pointFront.y > pointBack.y then
			angle = MathAide.CalcAngle(pointFront.x, pointFront.y - (pointFront.y - pointBack.y) * 2, pointBack.x, pointBack.y)
		else
			angle = MathAide.CalcAngle(pointFront.x, pointFront.y + (pointBack.y - pointFront.y) * 2, pointBack.x, pointBack.y)
		end
	else --下
		if pointFront.x > pointBack.x then
			angle = MathAide.CalcAngle(pointFront.x - (pointFront.x - pointBack.x) * 2, pointFront.y, pointBack.x, pointBack.y)
		else
			angle = MathAide.CalcAngle(pointFront.x + (pointBack.x - pointFront.x) * 2, pointFront.y, pointBack.x, pointBack.y)
		end
	end

	initPosX[2], initPosY[2] = self:getTargetPoint(chairId, initPosX[1], initPosY[1], angle)

    bullet.traceVector = MathAide.BuildLinear(initPosX, initPosY, 2,  bullet.speed)

    bullet:setAngle(angle)
    bullet:setTraceIdx(1)
end


function BulletManager:getTargetPoint(chairId, srcPosX, srcPosY, angle)
	local targetPosX = 0
	local targetPosY = 0

	local screenWidth = display.width --nf.resolutionWidth
	local screenHeight = display.height --nf.resolutionHeight

	local pi = math.pi
	local pi2 = math.pi/2

	local tan = math.tan
	local atan = math.atan

	local srcAngle = 2 * pi + pi2 - angle

	if srcAngle <= pi2 then --第一象限
		local angle1 = srcAngle
		local tempAngle = atan((screenHeight-srcPosY)/(screenWidth-srcPosX))
		if angle1 <= tempAngle then
			targetPosX = screenWidth
			targetPosY = (screenWidth-srcPosX)*tan(angle1) + srcPosY
		else
			targetPosY = screenHeight
			targetPosX = (screenHeight-srcPosY)*tan(pi2-angle1) + srcPosX
		end
    elseif srcAngle>pi2 and srcAngle<=pi then --第二象限
    	local angle2 = pi-srcAngle
    	local tempAngle = atan((screenHeight-srcPosY)/srcPosX)

    	if angle2 <= tempAngle then
    		targetPosX = 0
    		targetPosY = srcPosX*tan(angle2) + srcPosY
    	else
    		targetPosY = screenHeight
    		targetPosX = srcPosX - (screenHeight-srcPosY)*tan(pi2-angle2)
    	end
	elseif srcAngle>pi and srcAngle<=3*pi2 then--第三象限
		local angle3 = srcAngle - pi
		local tempAngle = atan(srcPosY/srcPosX)

		if angle3 <= tempAngle then
			targetPosX = 0
			targetPosY = srcPosY - srcPosX*tan(angle3)
		else
			targetPosY = 0
			targetPosX = srcPosX - srcPosY*tan(pi2-angle3)
		end
	else --第四象限
		local angle4 = 2 * pi - srcAngle
		local tempAnlge = atan(srcPosY/(screenWidth-srcPosX))
		if angle4 <= tempAnlge then
			targetPosX = screenWidth
			targetPosY = srcPosY - (screenWidth-srcPosX)*tan(angle4)
		else
			targetPosY = 0
			targetPosX = srcPosY*tan(pi2-angle4) + srcPosX
		end
	end

	return targetPosX,targetPosY
end

local fireTime = 0
local castNetTime = 0

function BulletManager:onFrame(dt,isLock)

	fireTime = fireTime + dt
	castNetTime = castNetTime + dt

	if self.isPlayFireSound then
		if fireTime > 0.2 then
			audio.playSound("music/sound_fire")
			fireTime = 0
			self.isPlayFireSound = false
		end
	end

	if self.isPlayNetSound then
		if castNetTime > 0.2 then
			audio.playSound("music/sound_net")
			castNetTime = 0
			self.isPlayNetSound = false
		end
	end

    --子弹管理
    for _, bullet in pairs(self.bulletArray) do
    	bullet:onFrame(dt)
        --删除无效子弹
        if (bullet.status == "invalid") then
			bullet:onRemove()
        	self.bulletCount[bullet.chairId] =  self.bulletCount[bullet.chairId] - 1
        	for k,v in pairs(self.bulletArray) do
        		if v == bullet then
        			table.remove(self.bulletArray,k)
        			break
        		end
        	end
        end

		if (bullet.status == "flying") then
			local fishManager = FishGameManager:getFishManager()
			if fishManager:isBulletHit(bullet) then
				bullet:castingNet()
			end
		end

    end
end

return BulletManager
