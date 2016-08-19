local FishLoader = class("FishLoader")

local logger = zzy.Logger.new("FishLoader")


function FishLoader:ctor()

end

function FishLoader:load(onComplete)
    self.onComplete = onComplete
    self.loadCount = 0

    audio.preloadSound("music/sound_fire")
    audio.preloadSound("music/sound_net")
    self:loadImage()
end

function FishLoader:loadImage()
    display.addSpriteFrames("fishgame/fishgame.plist","fishgame/fishgame.png",handler(self,self.onAddComplete))
    display.addSpriteFrames("fishgame/net1.plist","fishgame/net1.png",handler(self,self.onAddComplete))
    display.addSpriteFrames("fishgame/coin.plist","fishgame/coin.png",handler(self,self.onAddComplete))
    display.addSpriteFrames("fishgame/coin_boss.plist","fishgame/coin_boss.png",handler(self,self.onAddComplete))
    display.addSpriteFrames("fishgame/wave.plist","fishgame/wave.png",handler(self,self.onAddComplete))
end

function FishLoader:onAddComplete()
    self.loadCount = self.loadCount + 1
    if self.loadCount == 5 then
        self:loadAnimate(function()
            self:loadTrace()
        end)

    end
end

function FishLoader:loadAnimate(callback)
	--加载帧动画和骨骼动画
    logger:log("---------------------------------  load animate ------------------------")

    display.addSpriteFrames("fish.plist","fish.png",function()
        AnimateManager:loadAllFishAnimate()
        ArmatureManager:loadAllBulletArmature()
        AnimateManager:loadAllNetAnimate()
        AnimateManager:loadAllCoinAnimate()
        callback()
    end)

	-- AnimateManager:loadAllFishRes(function()
    --     AnimateManager:loadAllFishAnimate()
    --     ArmatureManager:loadAllBulletArmature()
    --     AnimateManager:loadAllNetAnimate()
    --     AnimateManager:loadAllCoinAnimate()
    --     callback()
    -- end) --先加载图片资源
end

function FishLoader:loadTrace()
    --加载路线
	if not nf.traceLoad then
        logger:log("---------------------------------  load trace ------------------------")
		self.helper = jt.FishHelper:create()
		self.helper:retain()
		local helperDelegate = jt.FishHelperDelegate:create()
		helperDelegate:retain()
		self.helper:setDelegate(helperDelegate)
		ScriptHandlerMgr:getInstance():registerScriptHandler(helperDelegate,handler(self,self.onLoadTrace),cc.Handler.CALLFUNC)

        local helperDelegate2 = jt.FishHelperDelegate2:create()
		helperDelegate2:retain()
		self.helper:setDelegate2(helperDelegate2)
		ScriptHandlerMgr:getInstance():registerScriptHandler(helperDelegate2,handler(self,self.onBuildTrace),cc.Handler.CALLFUNC)

		--加载鱼类路线
		for _, v in pairs(FishConfig.KIND) do
			local res = FishConfig.RES[v]
			if res == "jingui" or res == "jinsha" or res == "diwangxie" then --3种boss统一用一套路线
				res = "boss"
			end
			local count = FishConfig.TRACE_COUNT[v]
			if count ~= 0 then
				self.helper:loadTrace(res,v,count)
			end
	    end

		--加载鱼潮路线
		local size = cc.Director:getInstance():getWinSize()
		self.helper:loadGroupTrace(size.width,size.height)

		-- ScriptHandlerMgr:getInstance():registerScriptHandler(helperDelegate,handler(self,self.onBuildTrace),cc.Handler.CALLFUNC)
		-- self.helper:setThreadFlag(true)
		-- self.helper:runThread()
		 nf.traceLoad = true
     else
         logger:log("---------------------------------  load complete !! ------------------------")
         self.onComplete()
     end
end

function FishLoader:onBuildTrace(data)
    --when load fished then callback
    -- data:release()
    local delegate = self.helper:getDelegate()
    delegate:release()
    local delegate2 = self.helper:getDelegate2()
    delegate2:release()
    self.helper:release()
    logger:log("---------------------------------  load complete !! ------------------------")
    self.onComplete()
end

function FishLoader:onLoadTrace(data)
	local count = data:getCount()
	local traceId =  data:getTraceId()
	local fishKind = data:getFishKind()
	-- local fishTrace = {}
	-- for i = 1,count do
	-- 	local idx = i - 1
	-- 	fishTrace[i] = {}
	-- 	fishTrace[i].x =  data:getX(idx)
	-- 	fishTrace[i].y =  data:getY(idx)
	-- 	fishTrace[i].angle =  data:getAngle(idx)
	-- end
	-- data:release()
	FishConfig.TRACE[fishKind][traceId] = {}
	FishConfig.TRACE[fishKind][traceId] = data--fishTrace
end

return FishLoader
