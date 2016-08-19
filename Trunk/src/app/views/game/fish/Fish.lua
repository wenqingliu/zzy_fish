local Fish = class("Fish")

local scheduler   = import("app/library/scheduler.lua")
local BoundingBox = import("app.views.game.fish.BoundingBox.lua")

local deg = math.deg

function Fish:ctor()

end

--初始化鱼
function Fish:init(params)
	params = params or {}
	-- fishKind, fishId, fishMultiple, fishSpeed, boundingBoxWidth, boundingBoxHeight, hitRadius
	self.kind = params.fishKind or 0--params.kind or 0
	self.isActive = false
	self.traceIdx = 1
	-- self.fishSpeed = params.fishSpeed
	self.id = params.fishId
	self.status = "swim"
	self.res = FishConfig.RES[self.kind]
	self.boxWidth = FishConfig.BOUNDINGBOX[self.kind].w
	self.boxHeight = FishConfig.BOUNDINGBOX[self.kind].h
	self.sp = display.newSprite("#"..self.res.."/"..self.res.."_y/"..self.res.."_y_1.png")
	-- self.sp:setContentSize(cc.p(2*self.boxWidth,2*self.boxHeight))

	-- local body = cc.PhysicsBody:createBox(cc.size(self.boxWidth,self.boxHeight), cc.PhysicsMaterial(0, 0, 0));
	-- body:setGravityEnable(false)
	-- body:setCategoryBitmask(1)
	-- body:setContactTestBitmask(2)
	-- body:setCollisionBitmask(0)
	-- self.sp:setPhysicsBody(body)

	-- self.sp:setBlendFunc(cc.blendFunc(0x0,0x0))

	self.shadow = display.newSprite("#"..self.res.."/"..self.res.."_y/"..self.res.."_y_1.png")
	self.shadow:setScale(0.9)
	self.shadow:setColor(cc.c3b(0,0,0)):setOpacity(128)

	-- local shaderProgram = cc.GLProgram:createWithFilenames("shaders/shadow.vsh", "shaders/shadow.fsh")
	-- -- shaderProgram:use()
	-- -- shaderProgram:setUniformsForBuiltins()
	-- -- shaderProgram:updateUniforms()
	-- self.shadow:setGLProgram(shaderProgram)

	self.angle = 0
	self.curX = 0
	self.curY = 0
	self.stopCount = 0
	-- self.sp = cc.Sprite3D:create(self.res)
	-- self.sp:setScale(1.5)
	-- self.sp:addTo(self)
	-- self.sp:setGlobalZOrder(2)

	-- self.sp:setRotation3D(cc.vec3(0, -90, 0))
	-- self.sp:setRotation3D(cc.vec3(90, 0, -90)) --(前后转，左右转，时针转) 相对鱼的模型 (x固定为90，y跟随z变化(0-45)，z根据运动方向转)

	-- self.lastX = 0
	-- self.lastY = 0
	-- self.lastRotate = 0
	-- self:initAnimation3D()
	-- self:scheduleUpdateWithPriorityLua(handler(self,self.update),1/30)
	return self
end

--死了就要删除
function Fish:onRemove()
	-- self.actionSwim:release()
	-- self.actionDie:release()
	FishGameManager:getFishManager():removeFish(self.id)
end

--鱼的状态
function Fish:setStatus(status)
	if self.status == "die" then return end
	self.status = status
	if status == "swim" then
		self:playAnimation("swim")
	elseif status == "die" then
		self:playAnimation("die")
	end
end

function Fish:getStatus()
	return self.status
end

function Fish:setFishActive(isActive)
	self.isActive = isActive
	self.status = "swim"
end

function Fish:setId(id)
	self.id = id
end

function Fish:getId()
	return self.id
end

function Fish:getKind()
	return self.kind
end

-- function Fish:getFishSpeed()
-- 	return self.fishSpeed
-- end

function Fish:setTraceType(tt)
	self.traceType = tt
end

function Fish:getTraceType()
	return self.traceType
end

function Fish:setTrace(trace)
	self.trace = trace
	-- self.traceLength = #self.trace
	self.traceLength = self.trace:getCount()
end

function Fish:getPosition()
	return cc.p(self.curX,self.curY)
end

function Fish:setPosition(p)
	self.sp:setPosition(p)
end

--播放动作
function Fish:playAnimation(animationName)
	if animationName == "swim" then
		-- self.sp:runAction(self.actionSwim)

		if self.kind == FishConfig.KIND.QIE or self.kind == FishConfig.KIND.HETUN then --企鹅有个转身动作

			local rand = math.random(4,10)
			local swimAnimate = display.getAnimationCache(self.kind.."swim")
			local turnAnimate = display.getAnimationCache(self.kind.."turn")
			local actions1 = {}
			local actions2 = {}
			for i = 1, rand - 1 do
				actions1[i] = cc.Animate:create(swimAnimate)
				actions2[i] = cc.Animate:create(swimAnimate)
			end
			actions1[rand] = cc.Animate:create(turnAnimate)
			actions2[rand] = cc.Animate:create(turnAnimate)
			local action1 = cc.RepeatForever:create(cc.Sequence:create(actions1))
			local action2 = cc.RepeatForever:create(cc.Sequence:create(actions2))
			self.sp:runAction(action1)
			self.shadow:runAction(action2)
		else
			local animate = display.getAnimationCache(self.kind.."swim")
			self.sp:playAnimationForever(animate)
			self.shadow:playAnimationForever(animate)
		end

	elseif animationName == "die" then
		self.shadow:stopAllActions()
		self.shadow:removeFromParent()
		self.sp:stopAllActions()
		-- self.sp:setPhysicsBody(nil)
		local dieAction
		if self.kind < FishConfig.KIND.SHAYU then
			dieAction = cc.Spawn:create(cc.RotateBy:create(1,540),cc.FadeOut:create(1.5),cc.ScaleTo:create(1,0))
		else
			self.sp:setScale(1.4)
			local dieCall = function() local rotation = math.random(0,360) self.sp:setRotation(rotation) end
			local delayTime = 0.12
			dieAction = cc.Sequence:create(
				cc.CallFunc:create(dieCall),
				cc.DelayTime:create(delayTime),
				cc.CallFunc:create(dieCall),
				cc.DelayTime:create(delayTime),
				cc.CallFunc:create(dieCall),
				cc.DelayTime:create(delayTime),
				cc.CallFunc:create(dieCall),
				cc.DelayTime:create(delayTime),
				cc.CallFunc:create(dieCall),
				cc.DelayTime:create(delayTime),
				cc.CallFunc:create(dieCall),
				cc.DelayTime:create(delayTime),
				cc.CallFunc:create(dieCall),
				cc.DelayTime:create(delayTime),
				cc.CallFunc:create(dieCall),
				cc.DelayTime:create(delayTime),
				cc.CallFunc:create(dieCall),
				cc.DelayTime:create(delayTime)
			)
		end
		local action = cc.Sequence:create(dieAction,cc.CallFunc:create(function() self:onRemove() end))
		self.sp:runAction(action)

		-- self.shadow:stopAllActions()
		-- self.shadow:runAction(cc.Sequence:create(cc.Animate:create(display.getAnimationCache(self.kind.."die")),cc.CallFunc:create(function()self.shadow:removeFromParent() end)))
		--
		-- --transition.execute(self.sp,self.actionDie,{onComplete = function()self.removeFromParent()end})
		-- -- self.sp:runAction(self.actionDie)
		-- self.sp:stopAllActions()
		-- -- self.sp:playAnimationOnce(display.getAnimationCache("die"),{onComplete = handler(self,self.onRemove)})
		-- local action = cc.Sequence:create(cc.Animate:create(display.getAnimationCache(self.kind.."die")),cc.CallFunc:create(function()self:onRemove()end))
		-- self.sp:runAction(action)
	end
end

--检测自己是否中弹！
function Fish:isBulletHit(bullet)
	if not self.isActive then return false end
	local bulletX = bullet.sp:getPositionX()
	local bulletY = bullet.sp:getPositionY()

	if math.abs(bulletX - self.curX) > self.boxWidth then return end
	if math.abs(bulletY - self.curY) > self.boxHeight then return end
	local box = BoundingBox.new()
	box:createBoundingBox(self.boxWidth + bullet.netRadius, self.boxHeight + bullet.netRadius, self.curX, self.curY, 2*math.pi-self.angle)
	if (box:computeCollision(bulletX,bulletY)) then
		return true
	end
	return false
end

--检测自己是否被网中
function Fish:isNetHit(bullet)
	if not self.isActive then return false end
	local bulletX = bullet.sp:getPositionX()
	local bulletY = bullet.sp:getPositionY()

	if math.abs(bulletX - self.curX) > self.boxWidth then return end
	if math.abs(bulletY - self.curY) > self.boxHeight then return end

	local box = BoundingBox.new()
	box:createBoundingBox(self.boxWidth + bullet.netRadius, self.boxHeight + bullet.netRadius, self.curX, self.curY, 2*math.pi-self.angle)
	if (box:computeCollision(bulletX,bulletY)) then
		return true
	end
	return false
end

function Fish:setBingo(chairId,score)
	--TODO
end

function Fish:catchFish(chairId, score)
	--设置鱼死亡
	self:setStatus("die")

	-- FishConfig.RES[FishConfig.KIND.HUANGQIYU]
	local kind = self.kind
	if kind == FishConfig.KIND.QIE or kind == FishConfig.KIND.SHAYU or kind == FishConfig.KIND.MEIRENYU
			or kind == FishConfig.KIND.DIWANGXIE or kind == FishConfig.KIND.JINGUI
			or kind == FishConfig.KIND.JINSHA  or kind == FishConfig.KIND.MOGUIYU then
		audio.playSound("music/fish/"..FishConfig.RES[self.kind])
	end

	-- 显示得分
	self:setBingo(chairId, score)

	--屏幕抖动
	local isShake = false
	if self.kind >= FishConfig.KIND.DIWANGXIE then
		isShake = true
	end

	-- 定屏
	if self.kind == FishConfig.KIND.QIE then
		audio.playSound("music/sound_ice")

		local sprite = display.newSprite("freeze.png"):addTo(FishGameManager.gameView,2):setOpacity(0):setScale(0):setPosition(display.cx,display.cy)
		sprite:runAction(cc.Spawn:create(cc.ScaleTo:create(0.2,nf.bgScale),cc.FadeIn:create(1)))
		FishGameManager:setLock(true)
		scheduler.performWithDelayGlobal(10,function()
			if sprite then
				sprite:runAction(cc.Sequence:create(cc.FadeOut:create(0.5),cc.CallFunc:create(function()sprite:removeFromParent()end)))
				FishGameManager:setLock(false)
			end
		end)
	end

	if isShake then
		local actions = {}
		local strength = 8
		for i = 1, 10 do
			local random = math.random(-strength,strength)
			local move_1 = cc.MoveBy:create(0.03,cc.p(random,random))
			local move_2 = move_1:reverse()
			table.insert(actions,move_1)
			table.insert(actions,move_2)
		end
		local action = cc.Sequence:create(actions)
		FishGameManager.gameView:runAction(action)
	end
end

function Fish:setStop()
	self.isStop = true
	self.stopCount = 50
end

function Fish:onFrame(dt,isLock)
	if not self.isActive or self.status == "die" then return true end

	self.stopCount = self.stopCount - 1
	if self.stopCount > 0 then
		return true
	end

	local trace = self.trace
	local traceLength = self.traceLength
	local traceIdx = self.traceIdx
	if traceIdx < traceLength then
		-- if not isLock then
			-- local point = trace[traceIdx]
			local idx = traceIdx - 1
			self.curX = trace:getX(idx)--point.x
			self.curY = display.height - trace:getY(idx)--display.height -point.y
			self.angle = trace:getAngle(idx)--point.angle
			-- local lastX = self.lastX
			-- local lastY = self.lastY
			-- local lastRotate = self.lastRotate

			self.angle = self.angle or 0
			self.sp:setPosition(self.curX, self.curY)
			self.sp:setRotation(deg(self.angle))
			self.shadow:setPosition(self.curX - 30, self.curY - 30)
			self.shadow:setRotation(deg(self.angle))

			self.traceIdx = self.traceIdx + 1
			-- local z = 0
			-- local dis = MathAide.CalcDistance(curX, curY, lastX, lastY)
			--
			-- if dis ~= 0 then
			-- local tempValue = math.abs((curX - lastX) / dis)
			-- if curY == lastY then --向左或向右
			-- if curX > lastX then
			-- z = -90
			-- else
			-- z = 90
			-- end
			-- elseif curX == lastX then --向上或向下
			-- if curY > lastY then
			-- z = 180
			-- else
			-- z = 0
			-- end
			-- elseif curY > lastY and curX > lastX then --第一象限
			-- z = - 90 - acosf(tempValue)
			-- elseif curY > lastY and curX < lastX then --第二象限
			-- z = 90 + acosf(tempValue)
			-- elseif curY < lastY and curX < lastX then --第三象限
			-- z = 90 - acosf(tempValue)
			-- elseif curY < lastY and curX > lastX then --第四象限
			-- z = - 90 + acosf(tempValue)
			-- end
			-- end

			-- z = self:getRotation3D().z

			-- local i = math.mod(math.abs(z),180)
			-- local y = 0
			-- if i > 90 then
			-- y = (180 - i)/2
			-- else
			-- y = i/2
			-- end
			--
			-- if curX < lastX then
			-- y = -y
			-- end

			-- self.lastX = curX
			-- self.lastY = curY

			-- self.sp:setRotation3D(cc.vec3(90, 0, z))
		-- end
	else
		-- self:setStatus("die")
		self:onRemove()
		self.shadow:removeFromParent() --因为死亡动画不一定同步，所以要单独删除
	end
	return true
end

--初始化鱼的3D动画
-- function Fish:initAnimation3D()
-- self.animation = cc.Animation3D:create(self.res)
--
-- if self.animation then
-- local actionSwim1 = cc.Animate3D:createWithFrames(self.animation, FishConfig.SWIM_ANIM_FRAME[self.kind][1], FishConfig.SWIM_ANIM_FRAME[self.kind][2],24)
-- local actionSwim2 = cc.Animate3D:createWithFrames(self.animation, FishConfig.SWIM_ANIM_FRAME[self.kind][3], FishConfig.SWIM_ANIM_FRAME[self.kind][4],24)
-- local actionSwim = cc.Sequence:create(actionSwim1,actionSwim2)
-- self.actionSwim = cc.RepeatForever:create(actionSwim)
--
-- self.actionSwim:retain()
-- local actionDie= cc.Animate3D:createWithFrames(self.animation,FishConfig.DIE_ANIM_FRAME[self.kind][1], FishConfig.DIE_ANIM_FRAME[self.kind][2],24)
-- self.actionDie = cc.Sequence:create(
-- actionDie,
-- cc.CallFunc:create(function()self:onRemove()end))
-- self.actionDie:retain()
-- end
-- end

return Fish
