--过渡场景
local BaseScene       = import("app/views/scene/BaseScene")
local TransitionScene = class("TransitionScene",BaseScene)
local LoadingUtil     = import("app/library/LoadingUtil.lua")
local Timer           = import("app/library/Timer.lua")
local LoadingWord     = import("app/models/data/LoadingWordData.lua")
local scheduler       = import("app/library/scheduler.lua")

TransitionScene.events = {
    ccNd_Socket_ConnectResult = "ccNd_Socket_ConnectResult"--网络连接
}

function TransitionScene:onCreate(sceneData,releaseComplete)
--    TransitionScene.super.ctor(self)
    GameManager:setTransitionScene(self)
    self.isShowNext = false

    display.addSpriteFrames("transition.plist","transition.png")

    self:setupView()
    -- self.root = Resources:createNodeAndDoLayout("scene/transition/scene_transition.csb"):addTo(self)

    self.loadingUtil = LoadingUtil:create()
    -- self:changeWord()
    -- self:playAnimation()
    self:registerScriptHandler(handler(self,self.onSceneEventHandler))--场景事件

    local handler,listeners = CFrameDataHandler:getInstance():addEventListener(self.events.ccNd_Socket_ConnectResult,handler(self,self.onNetError))
    self.listeners = listeners
end

function TransitionScene:onTimerOut()
    GameManager:showAlert(self,"提示","载入超时",handler(self,self.showPrevScene))
end

function TransitionScene:setupView()

    self.root = cc.LayerColor:create(cc.c4b(0,0,0,255)):addTo(self)
    -- cc.LabelTTF:create("加载中...请稍候...","Arial",60):addTo(self,10):setPosition(display.cx,display.cy)
    local bgTips = display.newScale9Sprite("transtion_label_bg.png",1,cc.size(display.width,104),cc.rect(77/2,104/2,2,2)):addTo(self):setPosition(display.cx,display.top - 90)
    display.newSprite("#transtion_icon_warning.png"):addTo(bgTips):setPosition(120,52)
    cc.Label:create():addTo(bgTips):setPosition(display.cx,52):setString("为了维护健康的娱乐环境，请勿私下进行游戏买卖！"):setSystemFontSize(38):setTextColor(cc.c4b(96,171,195,255)):setAnchorPoint(0.5,0.5)

    -- local spWave1 = display.newSprite("#transtion_wave.png"):addTo(self,1):setPosition(display.cx-30,100)

    local spWave1Node = display.newNode():addTo(self,2):setPosition(display.width + 473,100)
    local spWave1 = {}
    for i = 1, 10 do
        spWave1[i] = display.newSprite("#transtion_wave.png"):addTo(spWave1Node)
        if i%2 == 0 then spWave1[i]:setFlippedX(true) end
        spWave1[i]:setPosition(-473*i,0)
    end

    local spWave2Node = display.newNode():addTo(self,3):setPosition(display.width + 573,10)
    local spWave2 = {}
    for i = 1, 15 do
        spWave2[i] = display.newSprite("#transtion_wave.png"):addTo(spWave2Node)
        if i%2 == 0 then spWave2[i]:setFlippedX(true) end
        spWave2[i]:setPosition(-473*i,0)
    end


    local spShark = display.newSprite("#transtion_icon_shark.png"):addTo(self,2):setPosition(display.cx,320)

    local function makeVertexs(radius,params)
        local segments = params.segments or 80
        local startRadian = 0
        local endRadian = math.pi * 2
        local posX = params.x or 0
        local posY = params.y or 0
        if params.startAngle then
            startRadian = math.angle2radian(params.startAngle)
        end
        if params.endAngle then
            endRadian = startRadian + math.angle2radian(params.endAngle)
        end
        local radianPerSegm = 2 * math.pi / segments
        local points = {}
        for i = 1, segments do
            local radii = startRadian + i * radianPerSegm
            if radii > endRadian then break end
            points[#points + 1] = {posX + radius * math.cos(radii), posY + radius * math.sin(radii)}
        end
        return points
    end

    -- 半径 抖的幅度     分段 越大频率越高
    local points1 = makeVertexs(5,{segments = 80})
    -- local points2 = makeVertexs(4,{segments = 90})
    local points3 = makeVertexs(10,{segments = 120})

    pIdx1 = 0
    spWave1Node:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(1/60),cc.CallFunc:create(function()
        pIdx1 = pIdx1 + 1
        if pIdx1 > #points1 then pIdx1 = 1 end
        spWave1Node:setPosition(display.width + 573 + points1[pIdx1][1], 120 + points1[pIdx1][2])
    end))))

    -- spWave1:runAction(cc.RepeatForever:create(cc.Spawn:create(cc.MoveBy:create(3,cc.p(-100,0)),cc.Sequence:create(cc.MoveBy:create(1.5,cc.p(0,50)),cc.MoveBy:create(1.5,cc.p(0,-50))))))
    spWave2Node:runAction(cc.RepeatForever:create(cc.Spawn:create(cc.MoveBy:create(1.2,cc.p(100,0)),cc.Sequence:create(cc.MoveBy:create(0.6,cc.p(0,20)),cc.MoveBy:create(0.6,cc.p(0,-20))))))

    -- pIdx2 = 0
    -- spWave2:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(1/60),cc.CallFunc:create(function()
    --     pIdx2 = pIdx2 - 1
    --     if pIdx2 < 1 then pIdx2 = #points2 end
    --     -- if pIdx2 > #points2 then pIdx2 = 1 end
    --     spWave2:setPosition(display.cx+60 + points2[pIdx2][1], 30 + points2[pIdx2][2])
    -- end))))

    pIdx3 = 0
    spShark:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(1/60),cc.CallFunc:create(function()
        pIdx3 = pIdx3 - 1
        if pIdx3 < 1 then pIdx3 = #points3 end
        -- if pIdx2 > #points2 then pIdx2 = 1 end
        spShark:setPosition(display.cx + points3[pIdx3][1], 320 + points3[pIdx3][2])
    end))))


    local spLabel = display.newSprite("#transtion_label.png"):addTo(self,4):setPosition(display.cx - 80,65/2 + 22)
    local spDot   = {}
    spDot[1] = display.newSprite("#transtion_dot.png"):addTo(self,4):setPosition(display.cx - 80 + 409/2 + 20,37)
    spDot[2] = display.newSprite("#transtion_dot.png"):addTo(self,4):setPosition(display.cx - 80 + 409/2 + 76,37)
    spDot[3] = display.newSprite("#transtion_dot.png"):addTo(self,4):setPosition(display.cx - 80 + 409/2 + 132,37)

    self.dotTick = -1
    self.dotSchedulerHandler = scheduler.scheduleGlobal(function()
        self.dotTick = self.dotTick + 1
        if self.dotTick > 3 then self.dotTick = 0 end
        if self.dotTick == 0 then
            for i = 1 , 3 do spDot[i]:setVisible(false) end
        elseif self.dotTick == 1 then
            spDot[1]:setVisible(true)
        elseif self.dotTick == 2 then
            spDot[2]:setVisible(true)
        elseif self.dotTick == 3 then
            spDot[3]:setVisible(true)
        end
    end,0.5)
end

function TransitionScene:setTimer()
    self.lestTime = 26
    self.labelTimer = cc.LabelTTF:create(self.lestTime,"Arial",100):addTo(self,10):setPosition(display.cx,display.cy)
    self.timerSchedulerID = cc.Director:getInstance():getScheduler():scheduleScriptFunc(handler(self,self.timerTick),1,false)
    -- self:getCo()
end


-- local threads = {}
-- function TransitionScene:getCo(data)
-- 	local co = coroutine.create(function ()
--         if self.loadFunc then
--             self.loadFunc(handler(self,self.onLoadComplete))
--         else
--             self.loadingUtil:loadResource(self.sceneData.plistList,self.sceneData.picList,
--                 self.sceneData.musicList,self.sceneData.soundList,handler(self,self.onLoadComplete))
--         end
-- 	end)
-- 	table.insert(threads,co)
-- end

-- function TransitionScene:dispatcher()
-- 	local n = table.getn(threads)
-- 	if n == 0 then return end    -- no more threads to run
-- 	local status = coroutine.status(threads[1])
-- 	if status == "suspended" or status == "normal" then
--         print("suspended")
-- 		coroutine.resume(threads[1])
-- 	elseif status == "running" then
--         print("running")
-- 	elseif status == "dead" then
--         print("dead")
-- 		table.remove(threads, 1)
-- 	end
-- end


function TransitionScene:stopTimer()
    cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.timerSchedulerID)
    self.lestTime = 0
end

function TransitionScene:timerTick()
    self.lestTime = self.lestTime - 1
    if self.lestTime < 0 then
        self:stopTimer()
    end
    self.labelTimer:setString(self.lestTime)
end

function TransitionScene:onEnter()
    --横竖屏转换布局
    self.root:setContentSize(cc.Director:getInstance():getOpenGLView():getVisibleSize())
    ccui.Helper:doLayout(self.root)
    self.delaySchedulerHandler = scheduler.performWithDelayGlobal(30,handler(self,self.onTimerOut))
end

function TransitionScene:start(sceneData,releaseComplete)
    self.sceneData = sceneData
    self.releaseComplete = releaseComplete
    self.sceneData:onEnter()
end

function TransitionScene:playAnimation()
    local spParent = self.root:getChildByName("Panel_1")
    self:addTime(spParent)
    for i = 1,10 do
        local sp = spParent:getChildByTag(i)
        local move_ = function()
            local aniMoveRepeat = cc.Sequence:create(cc.DelayTime:create(2),cc.MoveBy:create(0.2,cc.vec3(0,30,0)),cc.MoveBy:create(0.2,cc.vec3(0,-30,0)))
            sp:runAction(cc.RepeatForever:create(aniMoveRepeat))
        end
        local aniMove = cc.Sequence:create(cc.MoveBy:create(0.2,cc.vec3(0,30,0)),cc.MoveBy:create(0.2,cc.vec3(0,-30,0)))
        sp:runAction(cc.Sequence:create(cc.DelayTime:create(0.2*i),aniMove,cc.CallFunc:create(move_)))
    end

end

function TransitionScene:addTime(parentNode)
    local timeLabel = jt.CustomLabel:createWithCharMap("scene/transition/transition_number.png",57.3,64,"0")
    parentNode:addChild(timeLabel)
    timeLabel:setTag(9)
    timeLabel:setString(LoadingWord:getLoadingTime())
    timeLabel:setPosition(210,47)
    self.time_ = nil
    local function timer1()
        local timeStr = timeLabel:getString()
        local timeNum = tonumber(timeStr)
        timeNum = timeNum - 1
        timeLabel:setString(timeNum)
        if timeNum <= 0 then
            self.time_:stop()
            GameManager:showAlert(self,"提示","进入房间超时",handler(self,self.showPrevScene))
        end
    end

    self.time_ = Timer:create(timeLabel,timer1,1):start()
end

function TransitionScene:changeWord()
    local word = LoadingWord:getWordByRandom()
    print(word)
    local spParent = self.root:getChildByName("Panel_3")

    local word_ = spParent:getChildByName("wordLabel")
    word_:setAnchorPoint(0.5,0.5)
    word_:setPosition(0,word_:getPositionY())
    word_:setFontSize(30)
    word_:setScale(1)
    word_:setString(word)
    word_:setFontName("fonts/qnhgjch.TTF")
    local gantan = spParent:getChildByName("Sprite_10"):setPositionX(word_:getPositionX() - word_:getContentSize().width*0.5 - 20)  --感叹号
    gantan:setScaleY(0.8)
end

--场景事件处理
function TransitionScene:onSceneEventHandler(eventType)

    if eventType == "enter" then
        if self.onEnter then self:onEnter() end
    end

    if eventType == "exit" then
        if self.onExit then self:onExit() end
    end

    if eventType == "enterTransitionFinish" then
        if self.onExit then self:onEnterTransitionDidFinish() end
    end

end

function TransitionScene:onEnterTransitionDidFinish(eventType)
    --    print("当前内存:资源释放前",cc.Director:getInstance():getTextureCache():getCachedTextureInfo())
    --延迟一帧释放
    scheduler.performWithDelayGlobal(0.05,handler(self,self.releaseResource))
end

function TransitionScene:releaseResource(parameters)
    -- scheduler:unscheduleGlobal(self.schedulerID)

--    print("当前内存:资源释放前",cc.Director:getInstance():getTextureCache():getCachedTextureInfo())

    Resources:removeUnusedAllRes()

--    print("当前内存:资源释放后",cc.Director:getInstance():getTextureCache():getCachedTextureInfo())

    --加载下一个场景资源
    if self.loadFunc then
        self.loadFunc(handler(self,self.onLoadComplete))
    else
        self.loadingUtil:loadResource(self.sceneData.plistList,self.sceneData.picList,
            self.sceneData.musicList,self.sceneData.soundList,handler(self,self.onLoadComplete))
    end
end

function TransitionScene:onLoadComplete()
    self.loadFunc = nil
    --是否直接返回上个场景
    if self.isShowPrve then
        self:getApp():enterScene(self.sceneData.prevSceneName)
        return
    end

    local function createScene()
        self.targetScene = self:getApp():createView(self.sceneData.targetScene)
        self.targetScene:retain()--避免释放
        self.releaseComplete()

        --直接进入下个场景
        if self.isShowNext then
            self:showNextScene()
        end
    end

    CC_DESIGN_RESOLUTION.setRequestedOrientation(self.sceneData:getOrientation())
    if self.sceneData:getOrientation() == 1 then
        self:runAction(MotionUtil:delayCallFunc(0.01,function()
            createScene()
        end))
    else
        createScene()
    end
end

function TransitionScene:onNetError(event)
    local notify = event._userData
    local result = notify:getResult()
    if result == RT_FAILURE then
        if self.time_ ~= nil then
            self.time_:stop()
        end
        LoadingUtil:removeAllLoad()
        GameManager:showAlert(self,"网络异常","未能成功连接上服务器",handler(self,self.showPrevScene))
    end
end

------
--进入场景
function TransitionScene:showNextScene()
    if self.targetScene ~= nil then
        self.targetScene:showWithScene()
        self.targetScene:release()--与上面retain对应
--        print("当前内存:进入场景后",cc.Director:getInstance():getTextureCache():getCachedTextureInfo())
    else
        self.isShowNext = true
    end
end

--------
-- 返回上一个场景
function TransitionScene:showPrevScene()
--    LoadingUtil:removeAllLoad()
    print("showPrevScene")
    if self.targetScene ~= nil then
        --清理
        if self.targetScene:getParent() == nil then
            self.targetScene:removeAllChildren()
            self.targetScene:onCleanup()
        else
            self.targetScene:removeFromParent()
        end
        self.targetScene:release()
    else
        LoadingUtil:removeAllLoad()
    end
    Resources:removeUnusedAllRes()
    self:getApp():enterScene(self.sceneData.prevSceneName)
end

function TransitionScene:onExit()
    self.targetScene = nil
    GameManager:setTransitionScene(nil)
    -- CFrameDataHandler:getInstance():removeEventListenersByEvent(self.events.ccNd_Socket_ConnectResult)
    CFrameDataHandler:getInstance():removeEventListener(self.listeners)

    scheduler.unscheduleGlobal(self.delaySchedulerHandler)
    scheduler.unscheduleGlobal(self.dotSchedulerHandler)
    display.removeSpriteFramesWithFile("transition.plist","transition.png")
end

return TransitionScene
