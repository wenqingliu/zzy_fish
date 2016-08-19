--
-- Author: Wenqing
-- Date: 2016-04-25 17:42:58
--
local AnimateManager = class("AnimateManager")
local logger = zzy.Logger.new("AnimateManager")

function AnimateManager:ctor()
end

-----------------------------------------------------------------

local COIN_KIND = {1,2,3}

function AnimateManager:loadAllCoinAnimate()
    for _,v in ipairs(COIN_KIND) do
        self:loadCoinAnimate(v)
    end
end

function AnimateManager:loadCoinAnimate(coinKind)
    local res = "coin"..coinKind
    local coinFrames = display.newFrames(res.."_%d.png",1,15)
    local coinAnimation = display.newAnimation(coinFrames,1/24)
    display.setAnimationCache("coin"..coinKind,coinAnimation)
end

function AnimateManager:removeAllCoinAnimate()
    for _, v in pairs(COIN_KIND) do
        self:removeFishAnimate(v)
    end
end

function AnimateManager:removeCoinAnimate(coinKind)
    display.removeAnimationCache("coin"..coinKind)
end

-----------------------------------------------------------------

function AnimateManager:loadAllFishRes(callback)
    if callback then self.onFishLoadComplete = callback end
    self.fishLoadCount = 0
    for _, v in pairs(FishConfig.KIND) do
        self:loadFishRes(v)
    end
end

function AnimateManager:loadFishRes(fishKind)
    local res = "fish/"..FishConfig.RES[fishKind]
    logger:log(res)
    display.addSpriteFrames(res..".plist",res..".png",handler(self,self.onAddFishFrame))
end

function AnimateManager:onAddFishFrame()
    self.fishLoadCount = self.fishLoadCount + 1
    if self.fishLoadCount == FISH_KIND_COUNT then
        if self.onFishLoadComplete then
            self.onFishLoadComplete()
        end
    end
end

function AnimateManager:removeAllFishRes()
    for _, v in pairs(FishConfig.KIND) do
        self:removeFishRes(v)
    end
end

function AnimateManager:removeFishRes(fishKind)
    local res = "fish/"..FishConfig.RES[fishKind]
    display.removeSpriteFramesWithFile(res..".plist",res..".png")
end


function AnimateManager:loadAllFishAnimate()
    for _, v in pairs(FishConfig.KIND) do
        self:loadFishAnimate(v)
    end
end

function AnimateManager:loadFishAnimate(fishKind)
    local res = FishConfig.RES[fishKind]
    logger:log(res)
    local swimFrames = display.newFrames(res.."/"..res.."_y/"..res.."_y_%d.png", FishConfig.SWIM_ANIM_FRAME[fishKind][1], FishConfig.SWIM_ANIM_FRAME[fishKind][2])
    local swimAnimation = display.newAnimation(swimFrames, 1/FishConfig.SWIM_ANIM_FRAME[fishKind][3])
    display.setAnimationCache(fishKind.."swim", swimAnimation)

    -- local dieFrames = display.newFrames(res.."_s/"..res.."_s_%d.png", FishConfig.DIE_ANIM_FRAME[fishKind][1], FishConfig.DIE_ANIM_FRAME[fishKind][2])
    -- local dieAnimation = display.newAnimation(dieFrames, 1/FishConfig.DIE_ANIM_FRAME[fishKind][3])
    -- display.setAnimationCache(fishKind.."die", dieAnimation)

    if fishKind == FishConfig.KIND.QIE then --企鹅有个转身动作
        local zsFrames = display.newFrames(res.."/"..res.."_zs/"..res.."_zs_%d.png", 1, 20)
        local zsAnimation = display.newAnimation(zsFrames, 1/12)
        display.setAnimationCache(fishKind.."turn", zsAnimation)
    elseif fishKind == FishConfig.KIND.HETUN then
        local zsFrames = display.newFrames(res.."/"..res.."_zs/"..res.."_zs_%d.png", 1, 12)
        local zsAnimation = display.newAnimation(zsFrames, 1/12)
    end
end

function AnimateManager:removeAllFishAnimate()
    for _, v in pairs(FishConfig.KIND) do
        self:removeFishAnimate(v)
    end
end

function AnimateManager:removeFishAnimate(fishKind)
    display.removeAnimationCache(fishKind.."swim")
    display.removeAnimationCache(fishKind.."die")

    if fishKind == FishConfig.KIND.QIE or fishKind == FishConfig.KIND.HETUN then
        display.removeAnimationCache(fishKind.."turn")
    end
end

function AnimateManager:loadAllNetAnimate()
    for _, v in pairs(CannonConfig.KIND) do
    	if CannonConfig.NET_ANI_TYPE[v] == CannonConfig.ANI_TYPE.FRAME then
    		self:loadNetAnimate(v)
    	end
    end
end

function AnimateManager:loadNetAnimate(netKind)
    local res = CannonConfig.NET_RES[netKind][1]
    local netFrames = display.newFrames(res.."_%d.png", CannonConfig.NET_RES[netKind][2], CannonConfig.NET_RES[netKind][3])
    local netAnimation = display.newAnimation(netFrames, 1/CannonConfig.NET_RES[netKind][4])
    display.setAnimationCache(netKind.."net", netAnimation)
end

function AnimateManager:removeAllNetAnimate()
    for _, v in pairs(CannonConfig.KIND) do
        if CannonConfig.NET_ANI_TYPE[v] == CannonConfig.ANI_TYPE.FRAME then
            self:removeNetAnimate(v)
        end
    end
end

function AnimateManager:removeNetAnimate(netKind)
    display.removeAnimationCache(netKind.."net")
end

return AnimateManager
