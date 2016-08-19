local LockManager = class("LockManager",cc.Layer)

local kLockLineInterval = 64

local kRotateAngle = 10 * math.pi / 180

local logger = zzy.Logger.new("LockManager")

function LockManager:ctor()

	self.rotateAngle = 0
	self.lockLineTrace = {{},{}}
	self.lockFishId = {}
	self.lockFishKind = {}
	for  i = 1, nf.playerNum do
		self.lockFishId[i] = -1
		self.lockFishKind[i] = -1
	end
	self:initView()
end

function LockManager:initView()
	self.lockLineBatch = display.newBatchNode("fishgame/fishgame.png"):addTo(self)
	self.lockFlag = {}
	for i = 1,nf.playerNum do
		self.lockFlag[i] = display.newSprite("#lock_flag_"..i..".png"):addTo(self.lockLineBatch)--:hide()
	end
end

function LockManager:updateLockTrace(chairId, fishPosX, fishPosY)

	self.lockLineTrace[chairId] = {}

	local cannonPos = FishGameManager:getCannonManager():getCannonPos(chairId)
	local x = {}
	local y = {}
	x[1] = cannonPos.x
	y[1] = cannonPos.y
	x[2] = fishPosX
	y[2] = fishPosY
	self.lockLineTrace[chairId] = MathAide.BuildLinear(x, y, 2, kLockLineInterval)
end

function LockManager:clearLockTrace(chairId)
	self.lockLineTrace[chairId] = {}
	self.lockFishId[chairId] = -1
    self.lockFishKind[chairId] = -1
    self.lockLineBatch:hide()
end

function LockManager:setLockFishId(chairId,fishId)
	logger:log("fishId = "..fishId)
	self.lockFishId[chairId] = fishId
end


function LockManager:setLockFishKind(chairId,fishKind)
	logger:log("fishKind = "..fishKind)
	self.lockFishKind[chairId] = fishKind
end

function LockManager:getLockPos(chairId)
	local trace = self.lockLineTrace[chairId]
	if #trace == 0 then
		return cc.p(0,0)
	else
		local p = trace[#trace]
		return cc.p(p.x, p.y)
	end
end

function LockManager:getLockFishId(chairId)
	return self.lockFishId[chairId]
end

function LockManager:getLockFishKind(chairId)
	return self.lockFishKind[chairId]
end

function LockManager:onFrame(dt)
	--设置炮桶方向
	local cannonManager = FishGameManager:getCannonManager()

	for i = 1, nf.playerNum do
		repeat --这层repeat until true 是为了实现lua的continue功能
			if self.lockFishId[i] == -1 then
				self.lockFlag[i]:hide()
				-- self.lockLineBatch:hide()
				break
			end


			self.lockFlag[i]:show()
			self.lockLineBatch:show()
			local cannonPos = cannonManager:getCannonPos(i)
			local lockPos = self:getLockPos(i)
			-- logger:log("lockPos.x = "..lockPos.x..",lockPos.y = "..lockPos.y)
			self.lockFlag[i]:setPosition(lockPos)
			if not self.lockFlag[i]:getParent() then self:addChild(self.lockFlag[i]) end

			--添加路线标记
	        local count = #self.lockLineTrace[i]
	        for j = 1,count do
	        	local line = self.lockLineBatch:getChildByTag(i*100 + j)
	        	if not line then
	        		line = display.newSprite("#lock_line.png")
	        		line:setTag(i*100 + j)
	        		self.lockLineBatch:addChild(line)
	        	end

	            local point = self.lockLineTrace[i][j]
	            -- logger:log("point.x = "..point.x..",point.y = "..point.y)
	            line:setPosition(cc.p(point.x, point.y))
	        end

	        --删除多余line标记
	        count = count + 1
	        local line = self.lockLineBatch:getChildByTag(i*100+count)

	        while(line)
			do
				line:removeFromParent()
				count = count + 1
				line = self.lockLineBatch:getChildByTag(i*100+count)
			end

			local angle = MathAide.CalcAngle(lockPos.x, lockPos.y, cannonPos.x, cannonPos.y)
			cannonManager:setCurrentAngle(i, angle)
		until true
	end

	self.rotateAngle = self.rotateAngle + kRotateAngle
	if self.rotateAngle > math.pi * 2 then
		self.rotateAngle = self.rotateAngle - math.pi * 2
	end
end

return LockManager
