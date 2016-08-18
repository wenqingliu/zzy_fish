local Bullet = class("Bullet")

function Bullet:ctor()
    self.helper = jt.CalcHelper:create()
    self.helper:retain()
    local helperDelegate = jt.CalcHelperDelegate:create()
    helperDelegate:retain()
    self.helper:setDelegate(helperDelegate)
    self.helper:setWinSize(display.width,display.height)
    ScriptHandlerMgr:getInstance():registerScriptHandler(helperDelegate,handler(self,self.onCalcBulletPos),cc.Handler.CALLFUNC)
end

function Bullet:init(params)
    params = params or {}

    self.id             = params.bulletId
    self.kind           = params.bulletKind
    self.bulletId       = params.bulletId
    self.bulletMulriple = params.bulletMulriple
    self.chairId        = params.chairId
    self.netRadius      = params.netRadius
    self.fishId         = -1
    self.status         = "flying"
    self.speed          = 15--params.bulletSpeed or 10
    self.angle          = params.angle or 0

    local kind = self.kind
    if CannonConfig.BULLET_ANI_TYPE[kind] == CannonConfig.ANI_TYPE.NORMAL then
        self.sp = display.newSprite(CannonConfig.BULLET_RES[kind])
    elseif CannonConfig.BULLET_ANI_TYPE[kind] == CannonConfig.ANI_TYPE.ARMATURE then
        self.sp =  display.newSprite()
        self.armature = ccs.Armature:create(CannonConfig.BULLET_RES[kind][2])
        self.armature:addTo(self.sp)
        ArmatureManager:playArmature(self.armature, CannonConfig.BULLET_RES[kind][3])
    end

    -- local body = cc.PhysicsBody:createBox(cc.size(10,10), cc.PhysicsMaterial(0, 0, 0));
    -- body:setGravityEnable(false)
    -- body:setCategoryBitmask(2)
    -- body:setContactTestBitmask(1)
    -- body:setCollisionBitmask(0)

    -- self.sp.fatherObj = self
    -- self.sp:setPhysicsBody(body)
    -- self.sp:setTag(1000)

    self:setAngle(self.angle)
    return self
end

function Bullet:setId(id)
    self.id = id
end

function Bullet:getId()
    return self.id
end

function Bullet:setLockFishId(lockFishId)
    self.lockFishId = lockFishId
end

function Bullet:getLockFishId()
    return self.lockFishId
end

function Bullet:setFishId(id)
    self.fishId = id
end

function Bullet:getFishId()
    return self.fishId
end

function Bullet:setStatus(status)
    self.status = status
end

function Bullet:setTraceIndex(idx)
    self.traceIdx = idx
end

function Bullet:setSpeed(bulletSpeed)
    self.speed = bulletSpeed
end

function Bullet:setPosition(p)
    self.sp:setPosition(p)
end

function Bullet:setAngle(angle)
    self.angle = angle
    self.sp:setRotation((angle*180/math.pi))
end

function Bullet:setTraceIdx(idx)
    self.traceIdx = idx
end

function Bullet:getChairId()
    return self.chairId
end

function Bullet:getKind()
    return self.kind
end

function Bullet:getMulriple()
    return self.bulletMulriple
end

function Bullet:castingNet()
	self:setStatus("casting_net")

    local kind = self.kind

    FishGameManager:getBulletManager().isPlayNetSound = true

    -- self.sp:setPhysicsBody(nil)
    --子弹是静态的
    if CannonConfig.BULLET_ANI_TYPE[kind] == CannonConfig.ANI_TYPE.NORMAL then
        --网是静态的
        if CannonConfig.NET_ANI_TYPE[kind] == CannonConfig.ANI_TYPE.NORMAL then
            local frame =  display.newSpriteFrame(CannonConfig.NET_RES[kind])
            self.sp:setSpriteFrame(frame)
            transition.execute(self.sp,cc.ScaleTo:create(0.2,0.5),{easing = "backout",onComplete = function() self:setStatus("invalid") end})
        end
    --子弹是骨骼
    elseif CannonConfig.BULLET_ANI_TYPE[kind] == CannonConfig.ANI_TYPE.ARMATURE then
        --网是静态的
        if CannonConfig.NET_ANI_TYPE[kind] == CannonConfig.ANI_TYPE.NORMAL then
            self.armature:removeFromParent()
            -- self.sp:removeFromParent()
            -- self.sp = nil
            local frame =  display.newSpriteFrame(CannonConfig.NET_RES[kind])
            self.sp:setSpriteFrame(frame)
            -- self.sp = display.newSprite(CannonConfig.NET_RES[kind])
            transition.execute(self.sp,cc.ScaleTo:create(0.2,0.5),{easing = "backout",onComplete = function() self:setStatus("invalid") end})
        --网是帧动画
        elseif CannonConfig.NET_ANI_TYPE[kind] == CannonConfig.ANI_TYPE.FRAME then
            self.armature:removeFromParent()
            local action = cc.Sequence:create(cc.Animate:create(display.getAnimationCache(kind.."net")),cc.CallFunc:create(function()
                                self:setStatus("invalid")
                            end))
            self.sp:runAction(action)
        end
    end

    FishGameManager:getFishManager():isNetHit(self)
end

function Bullet:onRemove()
    self.sp:removeFromParent()
    local delegate = self.helper:getDelegate()
    delegate:release()
    self.helper:release()
end

function Bullet:onFrame(dt)
    if (self.status == "invalid") then return end
    if self.status == "flying" then
        self:updateNormal(dt)
    end
    -- self:nomalupdate(dt)
    -- --无效状态
    -- if (self.status == "invalid") then return end
    --
    -- local traceVector = self.traceVector
    -- local traceIdx = self.traceIdx
    --
    -- --飞行状态
    -- if self.status == "flying" then
    -- 	--当前坐标
    -- 	if traceIdx <= #traceVector then
    --         local curX = traceVector[traceIdx].x
    --         local curY = traceVector[traceIdx].y
    -- 		self.sp:setPosition(cc.p(curX, curY))
    -- 		traceIdx = traceIdx + 1
    --         self.traceIdx = traceIdx
    --         self.curX = curX
    --         self.curY = curY
    --     else
    -- 		--重构路径
    -- 		FishGameManager:getBulletManager():reboundBullet(self)
    -- 	end
    -- end
end

function Bullet:updateNormal(dt)
    local dir = self.sp:getRotation()
    local curX = self.sp:getPositionX()
    local curY = self.sp:getPositionY()
    local speed = self.speed
    self.helper:nextBulletPos(curX,curY,dir,dt,speed)
    -- local posAngle =

    -- local angle = (90-dir)/180*math.pi
    -- local s = math.sin(angle)
    -- local c = math.cos(angle)
    -- local dtx = self.speed*c*dt*100
    -- local dty = self.speed*s*dt*100

    --
    -- curX = curX + dtx
    -- curY = curY + dty
    --
    -- self.sp:setPosition(curX,curY)
    --
    -- --到边了反弹
    -- if curX > display.width - 10 then --右
    --     self.sp:setRotation(-dir)
    --     self.sp:setPosition(display.width - 11,curY)  --跳出旋转条件 防止到边上刷新慢了 子弹会不停地旋转
    -- elseif curX < 10 then --左
    --     self.sp:setRotation(-dir)
    --     self.sp:setPosition(11,curY)
    -- elseif curY >  display.height - 10 then --上
    --     self.sp:setRotation(180 - dir)
    --     self.sp:setPosition(curX,display.height - 11)
    -- elseif curY < 10 then --下
    --     self.sp:setRotation(180 - dir)
    --     self.sp:setPosition(curX,11)
    -- end
end

function Bullet:onCalcBulletPos(posAngle)
    self.sp:setRotation(posAngle:getAngle())
    self.sp:setPosition(posAngle:getX(),posAngle:getY())
end

return Bullet
