local BaseScene = import("app/views/scene/BaseScene")
local LanuchScene = class("LanuchScene",BaseScene)
local SDKControlHandler = import("app/handler/SDKControlHandler.lua")

function LanuchScene:onCreate()
    self.currentCount = 0
    self:loadResoucre()
    self:initView()
    self:initConfig()
    self:initSDK()
end

local CMD_GAME_FISH = import("app/cmd/game/fish/CMD_GAME_FISH")
function LanuchScene:onEnter()

    -- local file = io.open("res/trace/zuhe0.yq", "rb")
    -- assert(file)
    -- local data = file:read("*all") -- 读取所有内容
    -- data = string.gsub(data, "\r\n", "\n")
    -- print("data = "..data)
    -- file:close()
    -- --
    --
    -- local byteArray = jt.ByteArray:createWithNotify(data)
    -- local trace = CMD_GAME_FISH.CMD_S_Trace:createWithNotify(data)
    -- dump(trace)

    -- local traceCount = notify:getSize()/CMD_GAME_FISH.CMD_S_Trace:getSize()
    --
    -- for i = 1, traceCount do
    --     local fishTrace = CMD_GAME_FISH.CMD_S_Trace:create()
    --     fishTrace:readFormByteArray(byteArray)
    -- end

    -- local tab = {10,2,3,4,5,6,7,8,9}
    -- local r1,r2 = next(tab)
    -- dump(r1)
    -- dump(r2)
    -- tab[r1] = nil
    -- local r1,r2 = next(tab)
    -- dump(r1)
    -- dump(r2)
end

function LanuchScene:loadResoucre()
    audio.preloadMusic("music/background.mp3")
    display.addSpriteFrames("common.plist","common.png")
end

function LanuchScene:initView()

    --FPS
    -- if device.platform ~= "ios" then
    -- if not jt.SDKControl:getInstance():isCocosDebug() then
    --     CC_SHOW_FPS = false
    --     cc.Director:getInstance():setDisplayStats(false)
    -- else
    --     CC_SHOW_FPS = true
    --     cc.Director:getInstance():setDisplayStats(true)
    --     print=release_print --打印输出
    -- end
    -- end

    local bgLayer = cc.LayerColor:create();
    bgLayer:setColor(cc.c3b(255,255,255));
    bgLayer:setOpacity(255);
    bgLayer:setCascadeOpacityEnabled(true)
    self:addChild(bgLayer,-1);

    self.spr_bg = cc.Sprite:create():addTo(self):move(display.center)--:setScaleX(1.33)
    self.spr_bg:setOpacity(255);
    self.spr_bg:setCascadeOpacityEnabled(true)

    self.spr_bg:setTexture("scene/launch/launchFinish.png")
    if jt.SDKControl:getInstance():isAppDebug() then
        --调试版,直接跳过动画
        self:runAction(MotionUtil:delayCallFunc(0.1, handler(self,self.playComplete)))
    else
        local blackLayer = cc.LayerColor:create():addTo(self)
        blackLayer:setColor(cc.c3b(255,255,255));
        blackLayer:setOpacity(255)
        blackLayer:runAction(cc.Sequence:create(cc.FadeOut:create(0.6),MotionUtil:delayCallFunc(0.8, handler(self,self.playComplete))))
    end

end

function LanuchScene:initSDK()
    --获取平台数据
    self.sdk = jt.SDKControl:getInstance()

    if device.platform == "ios" then
        --获取登录按钮可见性
        local list = jt.SDKControl.LogonBtn_List
        local enum = GameManager:getProject().LogonType_Enum

        local visible = jt.SDKControl:getInstance():getValueFromPlatform(6,"") --微信
        jt.SDKControl.LogonBtn_List[enum.LogonType_WeChat+1] = visible == 1 and true or false

        local visible = jt.SDKControl:getInstance():getValueFromPlatform(7,"") --QQ
        jt.SDKControl.LogonBtn_List[enum.LogonType_QQ+1] = true--visible == 1 and true or false

        --获取版本名称
        local versionName = jt.SDKControl:getInstance():getStringFromPlatform(4,"")
        jt.SDKControl:getInstance():setVersion(versionName)
        self.currentCount = self.currentCount + 1
    else
        SDKControlHandler:getInstance():addSelector(self.sdk,SDKControlHandler.RecipientsList.ccNd_Version,handler(self,self.onReceiveVersion))
        SDKControlHandler:getInstance():addSelector(self.sdk,SDKControlHandler.RecipientsList.ccNd_PlatForm_LogonType,handler(self,self.onLoginType))
        SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCLoginType)
        SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCVerision)
    end
end

function LanuchScene:initConfig()

    --写入登录类型
    jt.SDKControl.LogonBtn_List = GameManager:getProject().LogonBtn_List
    if device.platform ~= "ios" and not jt.SDKControl:getInstance():isAppDebug() then
        --发行版,安卓屏蔽游客登录
        jt.SDKControl.LogonBtn_List[GameManager:getProject().LogonType_Enum.LogonType_Tourist+1] = false
        if jt.SDKControl:getInstance().getSDKPlatform == nil then
            --兼容旧版本，默认开启QQ登录
            jt.SDKControl.LogonBtn_List[GameManager:getProject().LogonType_Enum.LogonType_QQ+1] = true
        end
    elseif device.platform ~= "android" then
        --IOS默认开启QQ登录
        jt.SDKControl.LogonBtn_List[GameManager:getProject().LogonType_Enum.LogonType_QQ+1] = true
    end

    --游戏局数
    GameManager.gameCount = cc.UserDefault:getInstance():getIntegerForKey("gameCount",0)
    print("GameManager.gameCount:",GameManager.gameCount)

    audio.setMusicVolume(cc.UserDefault:getInstance():getFloatForKey("MUSIC_VOLUME",1))
    audio.setSoundsVolume(cc.UserDefault:getInstance():getFloatForKey("SOUND_VOLUME",1))
end

-------
-- 获取登录类型
function LanuchScene:onLoginType(event)
    local map = event._userData
    local type = map.loginType
    local visible = map.visible
    jt.SDKControl.LogonBtn_List[type+1] = visible
end

-------
-- 获取版本号
function LanuchScene:onReceiveVersion(event)
    local map = event._userData
    local version = map.version
    jt.SDKControl:getInstance():setVersion(version)
    self.currentCount = self.currentCount + 1
    if self.currentCount >= 2 then
        self:loadComplete()
    end
end

function LanuchScene:playComplete()
    self.currentCount = self.currentCount + 1
    if self.currentCount >= 2 then
        self:loadComplete()
    elseif device.platform == "windows" then
        self:loadComplete()
    end
end

function LanuchScene:loadComplete(target)
    self:removeAllChildren()
    -- Resources:removeUnusedAllRes()
    self:getApp():enterScene("scene/LoginScene")
end

function LanuchScene:onCleanup()
    SDKControlHandler:getInstance():removeSelectors(SDKControlHandler.RecipientsList.ccNd_Version)
    SDKControlHandler:getInstance():removeSelectors(SDKControlHandler.RecipientsList.ccNd_PlatForm_LogonType)
end

return LanuchScene
