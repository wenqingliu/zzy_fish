local CoinManager = class("CoinManager",cc.Layer)
local scheduler = import("app/library/scheduler.lua")

function CoinManager:ctor()
end

function CoinManager:buildCoin(pointAngle, cannonPos, score, fishKind)
    -- fishKind = FishConfig.KIND.JINSHA
    audio.playSound("music/sound_coin")
    local coinKind = 1
    if fishKind >= FishConfig.KIND.HUANGQIYU and fishKind <= FishConfig.KIND.HEIDIAOYU then --三颗一排金币
        coinKind = 3
        local pos = {}
        pos[1] = cc.p(pointAngle.x - 110, display.height - pointAngle.y - 13)
        pos[2] = cc.p(pointAngle.x, display.height - pointAngle.y)
        pos[3] = cc.p(pointAngle.x + 110, display.height - pointAngle.y + 13)
        for i = 1, 3 do
            self:playCoinAnimate(coinKind,pos[i],cannonPos,0.6,0.4)
        end
    elseif fishKind >= FishConfig.KIND.SHUIMU and fishKind <= FishConfig.KIND.WUZEI then
        coinKind = 3
        local pos = {}
        pos[1] = cc.p(pointAngle.x, display.height - pointAngle.y - 54)
        pos[2] = cc.p(pointAngle.x - 110, display.height - pointAngle.y - 50)
        pos[3] = cc.p(pointAngle.x + 110, display.height - pointAngle.y - 47)
        pos[4] = cc.p(pointAngle.x - 60, display.height - pointAngle.y + 55)
        pos[5] = cc.p(pointAngle.x + 60, display.height - pointAngle.y + 50)
        for i = 1, 5 do
            self:playCoinAnimate(coinKind,pos[i],cannonPos,0.6,0.4)
        end
    elseif fishKind >= FishConfig.KIND.HAIGUI and fishKind <= FishConfig.KIND.QIE then
        coinKind = 2
        local pos = {}
        pos[1] = cc.p(pointAngle.x - 266, display.height - pointAngle.y + 65)
        pos[2] = cc.p(pointAngle.x - 183, display.height - pointAngle.y + 43)
        pos[3] = cc.p(pointAngle.x - 88, display.height - pointAngle.y + 21)
        pos[4] = cc.p(pointAngle.x, display.height - pointAngle.y)
        pos[5] = cc.p(pointAngle.x + 88, display.height - pointAngle.y + 21)
        pos[6] = cc.p(pointAngle.x + 183, display.height - pointAngle.y + 43)
        pos[7] = cc.p(pointAngle.x + 266, display.height - pointAngle.y + 65)
        local time1 = {0.48,0.50,0.52,0.54,0.56,0.58,0.6}
        local time2 = {0.4,0.4,0.4,0.4,0.4,0.4,0.4}
        for i = 1, 7 do
            self:playCoinAnimate(coinKind,pos[i],cannonPos,time1[i],time2[i],true)
        end
    elseif fishKind >= FishConfig.KIND.SHIZIYU and fishKind <= FishConfig.KIND.MOGUIYU then
        coinKind = 2
        local pos = {}
        pos[1] = cc.p(pointAngle.x, display.height - pointAngle.y)
        pos[2] = cc.p(pointAngle.x, display.height - pointAngle.y + 120)
        pos[3] = cc.p(pointAngle.x, display.height - pointAngle.y - 120)
        pos[4] = cc.p(pointAngle.x + 120, display.height - pointAngle.y)
        pos[5] = cc.p(pointAngle.x - 120, display.height - pointAngle.y)
        pos[6] = cc.p(pointAngle.x + 88, display.height - pointAngle.y - 78)
        pos[7] = cc.p(pointAngle.x + 88, display.height - pointAngle.y + 78)
        pos[8] = cc.p(pointAngle.x - 88, display.height - pointAngle.y + 78)
        pos[9] = cc.p(pointAngle.x - 88, display.height - pointAngle.y - 78)
        for i = 1, 9 do
            self:playCoinAnimate(coinKind,pos[i],cannonPos,0.6,0.4)
        end
    elseif fishKind >= FishConfig.KIND.SHAYU and fishKind <= FishConfig.KIND.MEIRENYU then
        coinKind = 1
        local pos = {}
        pos[1] = cc.p(pointAngle.x - 266, display.height - pointAngle.y + 65)
        pos[2] = cc.p(pointAngle.x - 183, display.height - pointAngle.y + 43)
        pos[3] = cc.p(pointAngle.x - 88, display.height - pointAngle.y + 21)
        pos[4] = cc.p(pointAngle.x, display.height - pointAngle.y)
        pos[5] = cc.p(pointAngle.x + 88, display.height - pointAngle.y + 21)
        pos[6] = cc.p(pointAngle.x + 183, display.height - pointAngle.y + 43)
        pos[7] = cc.p(pointAngle.x + 266, display.height - pointAngle.y + 65)

        pos[8] = cc.p(pointAngle.x - 190, display.height - pointAngle.y + 133)
        pos[9] = cc.p(pointAngle.x - 95, display.height - pointAngle.y + 111)
        pos[10] = cc.p(pointAngle.x, display.height - pointAngle.y + 90)
        pos[11] = cc.p(pointAngle.x + 95, display.height - pointAngle.y + 111)
        pos[12] = cc.p(pointAngle.x + 190, display.height - pointAngle.y + 133)
        for i = 1, 12 do
            self:playCoinAnimate(coinKind,pos[i],cannonPos,0.6,0.4)
        end
    else    --Boss --尼玛这么大不预加载了
        -- coinKind = 1
        local coinFrames = display.newFrames("coin4".."_%d.png",1,16)
        local coinAnimation = display.newAnimation(coinFrames,1/24)
        local sp = display.newSprite("#coin4_1.png"):addTo(self):setPosition(pointAngle.x, display.height - pointAngle.y)
        local sequence = cc.Sequence:create(cc.Animate:create(coinAnimation),cc.CallFunc:create(function()sp:removeFromParent()end))
        sp:runAction(sequence)
    end

end

function CoinManager:playCoinAnimate(coinKind,fromPos,toPos,time1,time2,isDelay)
    local res = "#coin1_"..coinKind..".png"
    local sp = display.newSprite(res):addTo(self)
    -- self.sp:setRotation(90)
    local coinAnimate = display.getAnimationCache("coin"..coinKind)

    if isDelay then
        local delay = math.random(0,2)/10
        scheduler.performWithDelayGlobal(delay,function()
            sp:playAnimationForever(coinAnimate)
        end)
    else
        sp:playAnimationForever(coinAnimate)
    end

    sp:setPosition(fromPos.x,fromPos.y)
    local actionMove1 = cc.MoveBy:create(time1, cc.p(0,30))
    local actionScale1 = cc.ScaleTo:create(time1,1.3)
    local acitonSpawn1 = cc.Spawn:create(actionMove1,actionScale1)

    local actionMove2 = cc.MoveTo:create(time2, toPos)
    local actionScale2= cc.ScaleTo:create(time2,0.2)
    local acitonSpawn2 = cc.Spawn:create(actionMove2,actionScale2)

    local actionSequence = cc.Sequence:create(acitonSpawn1,acitonSpawn2)

    transition.execute(sp,actionSequence,{onComplete = function()
        sp:removeFromParent()
    end})
end

return CoinManager
