local FishGameView = class("",cc.load("mvc").ViewBase)
-- local scheduler = import("app/library/scheduler.lua")

function FishGameView:ctor(gameScene)
    FishGameView.super.ctor(self)
    self.gameScene = gameScene
    cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A4444)
    -- cc.Director:getInstance():setAnimationInterval(1/40)
    -- cc.Director:getInstance():setProjection(cc.DIRECTOR_PROJECTION3_D)
    -- display.addSpriteFrames("fishgame.plist","fishgame.png")--,handler(self,self.onSpriteFrameLoad))
    -- display.addSpriteFrames("net1.plist","net1.png")
    -- display.addSpriteFrames("coin.plist","coin.png")
    -- display.addSpriteFrames("coin_boss.plist","coin_boss.png")
    self:onSpriteFrameLoad()
end

function FishGameView:onSpriteFrameLoad()
    self:initView()
end

function FishGameView:initView()
    self:setBg()
    self.isLock = false
    -- self.btnLock = ccui.Button:create("bt_lock.png","bt_lock.png","bt_lock.png",1)
    -- self.btnLock:addTo(self,6)
    -- self.btnLock:setPosition(display.right - 100,display.cy + 60)
    -- self.btnLock:addTouchEventListener(handler(self,self.onBtnLockClick))
    --
    -- self.btnUnLock = ccui.Button:create("bt_unlock.png","bt_unlock.png","bt_unlock.png",1)
    -- self.btnUnLock:addTo(self,6):hide()
    -- self.btnUnLock:setPosition(display.right - 100,display.cy + 60)
    -- self.btnUnLock:addTouchEventListener(handler(self,self.onBtnLockClick))

    self.isFreeze = false
    -- self.btnHide = ccui.Button:create("bt_hide.png","bt_hide.png","bt_hide.png",1)
    -- self.btnHide:addTo(self,6)
    -- self.btnHide:setPosition(display.right - 100,display.cy - 60)
    -- self.btnHide:addTouchEventListener(handler(self,self.onBtnHideClick))

    self.btnBack = ccui.Button:create("bt_back.png","bt_back.png","bt_back.png",1)
    self.btnBack:addTo(self,6)
    self.btnBack:setPosition(display.right - 100,display.cy + 60)
    self.btnBack:addTouchEventListener(handler(self,self.onBtnBack))
end

function FishGameView:onBtnBack(ref, type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        self.gameScene:onGameBack()
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function FishGameView:setBg(sceneKind)
    if self.bg then self.bg:removeFromParent() self.bg = nil end
    sceneKind = sceneKind or 0
    local bgRes = "bg_game"..(sceneKind+1)..".jpg"
    cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888)
    self.bg = display.newSprite(bgRes):addTo(self):setPosition(display.cx,display.cy):setScale(nf.bgScale)
    cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A4444)
end

function FishGameView:setBgm(sceneKind)

    audio.stopAllSounds()
    local idx = sceneKind%3 + 1
    local res = "music/bgm_scene_"..idx..".mp3"
    audio.playMusic(res,true)
end

function FishGameView:switchScene(sceneKind)
    FishGameManager.isSwitchingScene = true
    local bgRes,waveRes,waveFrameNum
    local bgRes = "bg_game"..(sceneKind+1)..".jpg"
    -- if sceneKind == 0 then
        waveRes =  "wave1_"
        waveFrameNum = 8
    -- else
    --     waveRes =  "wave2_"
    --     waveFrameNum = 12
    -- end

    cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A8888)
    local newBg = display.newSprite(bgRes):addTo(self,3):setPosition(display.cx + display.width,display.cy):setScale(nf.heightScale)
    cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2_D_PIXEL_FORMAT_RGB_A4444)
    local waveFrame = display.newFrames(waveRes.."%d.png",1,waveFrameNum)
        local waveAnimation = display.newAnimation(waveFrame,1/12)
        local sp = display.newSprite("#"..waveRes.."1.png"):addTo(newBg):setPosition(80,display.cy):setScale(nf.heightScale)
        sp:runAction(cc.RepeatForever:create(cc.Animate:create(waveAnimation)))
        local move = cc.MoveBy:create(8,cc.p(-display.width,0))
        transition.execute(newBg,move,{onComplete = function()
            self.bg:removeFromParent()
            sp:removeFromParent()
            self.bg = newBg
            self.bg:setLocalZOrder(0)
            FishGameManager.isSwitchingScene = false
        end})

    self:setBgm(sceneKind)
end

function FishGameView:onBtnLockClick(ref, type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        transition.scaleTo(ref, {time = 0.05, scale = 1})

        if not self.isLock then
            local locakManager = FishGameManager:getLockManager()
            local fishManager  = FishGameManager:getFishManager()
            local fishId,fishKind = fishManager:lockFish(locakManager:getLockFishId(-1),locakManager:getLockFishKind(-1))
            locakManager:setLockFishId(1,fishId)
            locakManager:setLockFishKind(1,fishKind)
            if fishId ~= -1 then
                 self.btnUnLock:show()
                self.btnLock:hide()
                self.isLock = not self.isLock
            end
        else
            self.btnUnLock:hide()
            self.btnLock:show()
            local locakManager = FishGameManager:getLockManager()
            locakManager:clearLockTrace(1)

            self.isLock = not self.isLock
        end
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function FishGameView:onBtnHideClick(ref, type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        self.isFreeze = not self.isFreeze
        FishGameManager:setLock(self.isFreeze)

    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end

end

function FishGameView:doFrame()
    self:scheduleUpdateWithPriorityLua(handler(self,self.onFrame),0)
    -- local scheduler = cc.Director:getInstance():getScheduler()
    -- self.schedulerID = scheduler:scheduleScriptFunc(self.onFrame,0.025,false)
end

function FishGameView:onFrame(dt)
    FishGameManager:onFrame(dt)
end

----------
-- 系统消息
function FishGameView:onSubSystemMessage(szString,system,vipLevel)
end

function FishGameView:onUpdateScore()
    FishGameManager:onUpdateScore()
end

function FishGameView:updateGameView(pUser)
    FishGameManager:updateGameView(pUser)
end

function FishGameView:onCleanup()
    cc.Texture2D:setDefaultAlphaPixelFormat(cc.TEXTURE2_D_PIXEL_FORMAT_BGR_A8888)
    self:removeAllChildren()
    FishGameManager:dispose()
    display.removeSpriteFramesWithFile("fishgame/fishgame.plist","fishgame/fishgame.png")
    display.removeSpriteFramesWithFile("fishgame/net1.plist","fishgame/net1.png")
    display.removeSpriteFramesWithFile("fishgame/coin.plist","fishgame/coin.png")
    display.removeSpriteFramesWithFile("fishgame/coin_boss.plist","fishgame/coin_boss.png")
    display.removeSpriteFramesWithFile("fishgame/wave.plist","fishgame/wave.png")
    display.removeSpriteFramesWithFile("fish.plist","fish.png")
end

return FishGameView
