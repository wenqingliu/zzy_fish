local FishManager = class("FishManager",cc.Layer)

local Fish      = import("app.views.game.fish.Fish.lua")
local scheduler = import("app/library/scheduler.lua")

local logger = zzy.Logger.new("FishManager")

function FishManager:ctor()
    self.fishArray = {}
    -- self.fishIdxCounter = 0
end

function FishManager:dispose()
    self.fishArray = nil
end

function FishManager:addFish(fish)
    -- self.fishIdxCounter = self.fishIdxCounter + 1
    -- param.father = self
    -- local fish = Fish.new():init(param)

    fish.shadow:addTo(self)
    fish.sp:addTo(self)

    -- local zorder =  math.random(1, 50)
    -- fish.shadow:setPosition3D({x=0,y=0,z=zorder})
    -- fish.shadow:setGlobalZOrder(2 + self.fishIdxCounter)
    -- fish.sp:setPosition3D({x=0,y=0,z=zorder})
    -- fish.sp:setGlobalZOrder(2 + self.fishIdxCounter)

    -- fish:setId(self.fishIdxCounter)
    fish:setStatus("swim")
    self.fishArray[fish.id] = fish
end

function FishManager:catchFish(chairId,fishId,score)
	local fish = self.fishArray[fishId]
	if fish == nil then return nil end

	fish:catchFish(chairId, score)

	--添加金币
	local cannonPos = FishGameManager:getCannonManager():getCannonPos(chairId)
	-- local pointAngle = fish.traceTable[fish.traceIdx]
	local pointAngle = {x = fish.trace:getX(fish.traceIdx-1),y=fish.trace:getY(fish.traceIdx-1)}
    local kind = fish.kind

	FishGameManager:getCoinManager():buildCoin(pointAngle, cannonPos, score, kind)

    --定屏
	-- if (fish->getFishKind() == FISH_KIND_9)
	-- {
	-- 	FishGameManager::GetInstance()->set_lock(true, fish);
	-- }

    return fish
end

function FishManager:catchSweepFishResult(chairId, fishId, score, catchFishId, catch_fish_count)
    self:catchFish(chairId,fishId,score)

    for i = 1, catch_fish_count do
        local fish = self.fishArray[catchFishId[i]]
    	if fish then
            fish:catchFish(chairId, 0)
        end
    end
end

function FishManager:activeFish(fishKind, fishId)--, fishMultiple, fishSpeed)
    local param = {fishKind = fishKind, fishId =fishId}
    local fish = Fish.new():init(param)
    return fish
end

function FishManager:removeFish(fishIdx)
    self.fishArray[fishIdx].sp:removeFromParent()
    self.fishArray[fishIdx] = nil
end

function FishManager:getFish(fishIdx)
    return self.fishArray[fishIdx]
end

function FishManager:isBulletHit(bullet)
    for _,fish in pairs(self.fishArray) do
        if fish:getStatus() ~= "die" and fish.isActive then
            if fish:isBulletHit(bullet) then
                return true
            end
        end
    end
    return false
end

function FishManager:isNetHit(bullet)
    local myChairId = FishGameManager:getChairId()
    if myChairId ~= bullet:getChairId() then return false end
    local catchCount = 0
    for _,fish in pairs(self.fishArray) do
        if fish.status ~= "die" and fish:isNetHit(bullet) then
            fish.sp:setColor(cc.c3b(255,0,0))
            local resetFishColor = function()
                if not tolua.isnull(fish.sp) then
                    fish.sp:setColor(cc.c3b(255,255,255))
                end
            end
            -- scheduler.performWithDelayGlobal(0.4,resetFishColor)

            zzy.Scheduler:delayGlobal(resetFishColor, 0.4)

            if bullet:getId() <= 0 then
                bullet:setFishId(fish:getId())
            else
                FishGameManager:sendCatchFish(fish:getId(),bullet:getChairId(),bullet:getId(),bullet:getKind(),bullet:getMulriple())
            end
            -- fish:setStatus("die")
            catchCount = catchCount + 1
            if catchCount >= MAX_FISH_CATCH_COUNT then return true end
        end
    end
    return false
end

function FishManager:isInsideScreen(pos)
    if pos.x > 0 and pos.x < display.width and pos.y > 0 and pos.y < display.height then
        return true
    end
    return false
end

function FishManager:lockFish(lastFishId, lastFishKind)
    local lockFishKind = -1
    lastFishId         = lastFishId   or -1
    lastFishKind       = lastFishKind or -1
    local nextFishKind = lastFishKind
    local existKind    = {}

    for _,fish in pairs(self.fishArray) do
        if fish:getStatus() ~= "die" then
            if lastFishId ~= fish.id then
                -- logger:log("existKind.kind = "..fish.kind)
                existKind[fish.kind] = true
            end
        end
    end

    local kindCount = FISH_KIND_COUNT
    for i = kindCount - 1, 0,-1 do
        nextFishKind = i
        if existKind[nextFishKind] then
            -- logger:log("nextFishKind = "..nextFishKind)
             for _, fish in pairs(self.fishArray) do
                local p = fish:getPosition()
                if  self:isInsideScreen(p) then
                    -- logger:log("nextFishKind = "..nextFishKind..",fish.kind = "..fish.kind )
                    if nextFishKind == fish.kind then
                        if lastFishId ~= fish.id then
                            return fish.id,fish.kind
                        end
                    end
                end
            end
        end
    end

    return -1,-1
end

function FishManager:onFrame(dt,isLock)
    local switchLock = false
    local myChairId = FishGameManager:getChairId()
    --TODO local lockManager  = FishGameManager:getLockManager()

    for _,fish in pairs(self.fishArray) do
        fish:onFrame(dt,isLock)
        -- if fish:getStatus() == "die" then
        --     for i = 1, GAME_PLAYER do
        --         if lockManager:getLockFishId(i) == fish:getId() then
        --             lockManager:clearLockTrace(i)
        --             if  i == myChairId then
        --                 switchLock = true
        --             end
        --         end
        --     end
        -- else
        --     for i = 1, GAME_PLAYER do
        --         if lockManager:getLockFishId(i) == fish:getId() then
        --             local p = fish:getPosition()
        --             if not self:isInsideScreen(p) then
        --                 lockManager:clearLockTrace(i)
        --                 if i == myChairId then
        --                     switchLock = true
        --                 end
        --             else
        --                 lockManager:updateLockTrace(i, p.x, p.y)
        --             end
        --         end
        --     end
        -- end
    end

    -- if switchLock then
    --     local lockFishId,lockFishKind = self:lockFish(lockManager:getLockFishId(1),lockManager:getLockFishKind(1))
    --     lockManager:setLockFishId(myChairId,lockFishId)
    --     lockManager:setLockFishKind(myChairId,lockFishKind)
    -- end
end

return FishManager
