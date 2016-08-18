local BaseScene = import("app/views/scene/BaseScene")
local SceneLogin = class("SceneLogin",BaseScene)

local LoginView       = import("app/views/scene/login/LoginView.lua")
local LoadingDownload = import("app/views/animate/LoadingDownload.lua")

local UserData         = import("app/models/data/UserData")
local CMD_Server_Logon = import("app/cmd/loginSever/CMD_Server_Logon.lua")

local SDKControlHandler = import("app/handler/SDKControlHandler.lua")
local URLLoaderHandler  = import("app/handler/URLLoaderHandler.lua")
local update            = import("update.lua")
local scheduler         = import("app/library/scheduler.lua")
local Timer             = import("app/library/Timer.lua")
local json              = import("app/library/cjson")

function SceneLogin:onCreate()
    self.logonCount = 0
    self.logonData = nil
    self.isLoading = false
    GameManager:setGameDelegate(nil)
    CC_DESIGN_RESOLUTION.setRequestedOrientation(0)

    --启动游戏服务监听
    self.listenersList = {}
    self.roomManager = GameManager:getRoomServer()

    self.gameView = LoginView:create(self):addTo(self)
    --    self:initUpdateView()
end

function SceneLogin:setLogonData(logonData)
    if self.logonData ~= nil then
        self.logonData:release()
    end
    self.logonData = logonData
    if self.logonData ~= nil then
        self.logonData:retain()
    end
end

function SceneLogin:onEnter()
    --游戏音乐
    audio.playMusic("music/bgm_hall.mp3",true)
    self:initEvent()
    self:initServer()
end

function SceneLogin:initEvent()
    --
    -- if cc.UserDefault:getInstance():getStringForKey("LOGIN_ADDRESS","") ~= "" then
    --     local ip = cc.UserDefault:getInstance():getStringForKey("LOGIN_ADDRESS")
    --     --        jt.CFrameData:getInstance():setLoginAddress(ip)
    --     GameManager:getProject().LoginAddress = ip
    -- end
    jt.CFrameData:getInstance():setLoginAddress(GameManager:getProject().LoginAddress)
    jt.CFrameData:getInstance():setLoginPort(GameManager:getProject().LoginPort)


    --默认关闭
    GameManager:getGameServer():destroy()
    GameManager:getRoomServer():destroy()

    --注册SDK监听
    self.sdk = jt.SDKControl:getInstance()
    SDKControlHandler:getInstance():addSelector(self.sdk,SDKControlHandler.RecipientsList.ccNd_Platform_LogonResult,handler(self,self.onRequstLogin))
    SDKControlHandler:getInstance():addSelector(self.sdk,SDKControlHandler.RecipientsList.ccNd_Platform_LogonLoading,handler(self,self.onLoadUser))

    CFrameDataHandler:getInstance():addNotifyListener(self)
end

function SceneLogin:initUpdateView()
    if self.loadingDownload ~= nil then
        self.loadingDownload:removeFormParent()
    end
    self.loadingDownload = LoadingDownload:create(self):addTo(self)
    self.curProgress = 0
    self.totalProgress = 0
    self.proScheduler = scheduler.scheduleUpdateGlobal(handler(self,self.onUpdate))
    --    self:startUpdate()
end

function SceneLogin:startUpdate()
    if self.uEngine ~= nil then
        self.uEngine:destrory()
        self.uEngine = nil
    end

    --创建更新引擎
    self.uEngine = update:getInstance()
    self.uEngine:start()
    self.currentV = ""
    self.uEngine:setDelegate(self)
    self.uEngine:startUpdate()
end

function SceneLogin:initServer()

    --获取控制信息
    if GameManager.transferState == -1 then
        GameManager.transferState = 0
        local transferKey = "transfer_"..device.platform.."_"..jt.SDKControl:getInstance():getVersion()
        GameManager.transferState = cc.UserDefault:getInstance():getIntegerForKey(transferKey,GameManager.transferState)

        print("onControlURL",GameManager.transferState)
        if GameManager.transferState == 0 --and device.platform == "ios"
        then
            --获取控制
            local ver = jt.SDKControl:getInstance():getVersion()
            ver = ver == "" and GameManager:getProject().AppVersions or ver
            local platform = device.platform == "ios" and 0 or 1
            local markettype = 0
            if device.platform == "ios" then
                local v = jt.SDKControl:getInstance():getValueFromPlatform(8,"") --获取渠道类型
                if v == 1 then
                    markettype = 12
                elseif v == 2 then
                    markettype = 13
                end
            end
            local url = GameManager:getProject():getTransfer(0,platform,markettype,ver)
            print("onControlURL",url)
            URLLoaderHandler:load(url,function(urlData)
                if urlData:getStatusCode() == URLLoaderHandler.STATUS_CODES.SUCCESS then
                    local data = json.decode(urlData:getData())
                    cc.UserDefault:getInstance():setIntegerForKey(transferKey,data.state)
                    cc.UserDefault:getInstance():flush()
                    GameManager.transferState = data.state
                    print("onTransfer-data.state:",data.state)
                end
                print("onTransfer:",GameManager.transferState)
            end)
        else
            GameManager.transferState = 1
        end
    end

end

function SceneLogin:OnTCPWithDataLoad(notify)
    if notify:getMainType() ~= CMD_Server_Logon.MDM_MB_LOGON then
        return false
    end

    local sub = notify:getSubType()
    if sub == CMD_Server_Logon.SUB_MB_LOGON_SUCCESS then
        return self:OnSocketSubLogonSuccess(notify)
    elseif sub == CMD_Server_Logon.SUB_MB_LOGON_FAILURE then
        return self:OnSocketSubLogonFailure(notify)
    elseif sub == CMD_Server_Logon.SUB_MB_UPDATE_NOTIFY then
        return self:onVersionUpdate(notify)
    end
    return true
end

----------
-- 版本更新
function SceneLogin:onVersionUpdate(notify)
    --    local notify = event._userData
    local pFrame = notify:getObject()
    GameManager:hideLoading()
    self:stopAction(self.delayAction)
    self.isLoading = false
    local cmd = jt.CMD_MB_UpdateNotifyRef:createWithNotify(notify)
    if cmd:cbMustUpdate() == 1 then
        pFrame:setSocketClose(true)
        GameManager.logonCFrame = nil
        self:startDownAPK()
    elseif cmd:cbAdviceUpdate() == 1 then--建议升级
        GameManager.cbAdviceUpdate = 1
    else
        local szHotVer = cmd:szHotVer()
        local verList = {GameManager:getProject():getVersionList(szHotVer)}
        local function onClick(result)
            if result == RT_SUCCESS then
                --启动热更新
                self:startUpdate()
                self:initUpdateView()
            end
        end
        GameManager:showAlertSystem(self,"检测到游戏有更新内容，点击进行在线更新？",onClick):setBtnVisible(true,true)
        pFrame:setSocketClose(true)
        GameManager.logonCFrame = nil
        --进入游戏
        --        GameManager:getRoomServer():onLoginHall(self:getApp())
    end
    return true
end


-----------
--大厅登录结果
function SceneLogin:OnSocketSubLogonSuccess(notify)
    --    local notify = event._userData
    GameManager:hideLoading()
    self:stopAction(self.delayAction)
    self.isLoading = false
    --    if notify:getResult() == RT_SUCCESS then

        cc.UserDefault:getInstance():setStringForKey("LOGIN_ADDRESS",jt.CFrameData:getInstance():getLoginAddress())
        GameManager:getProject().LoginAddress = jt.CFrameData:getInstance():getLoginAddress()
        GameManager:getProject().LoginPort = jt.CFrameData:getInstance():getLoginPort()

        --        local suc = jt.CMD_MB_LogonSuccessRef:createWithNotify(notify)
        local cmd = CMD_Server_Logon.CMD_MB_LogonSuccess:createWithNotify(notify)
        local user = GameManager:getUserSelf()
        if user == nil then
            user = UserData:create()
        end
        user:setNickName(cmd.szNickName)
        user.userID = cmd.dwUserID
        user.gameID = cmd.dwGameID
        user.gender = cmd.cbGender
        user.score = cmd.lUserScore
        user.faceURL = cmd.szFaceURL
        user.diamond = cmd.lUserDaimond
        GameManager:setUserSelfID(cmd.dwUserID)
        GameManager:getUserManager():setUserItem(user)

        if jt.CFrameData.setUserID ~= nil then
            jt.CFrameData:getInstance():setUserID(cmd.dwUserID)
            jt.CFrameData:getInstance():setGameID(cmd.dwGameID)
            jt.CFrameData:getInstance():setGenderID(cmd.cbGender)
        end

        self:initServer()
        print("登录成功:userID",user.userID,"user.gameID:",user.gameID)

        --保存登录信息
        local map = {}
        map.tags = {user.gameID..""}
        SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCSetJPushTag,map)
        if device.platform == "android" then
            SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCSaveLogin)
        end

        --启动游戏服务监听
        GameManager:getRoomServer():start()
        GameManager:getGameServer():start()

        --进入游戏
        GameManager:getRoomServer():onLoginHall(self:getApp())

    --获取房间列表
    CFrameDataHandler:getInstance():sendPacketWithLoadRoomServer()
    --    else
    --        local err = jt.CMD_MB_LogonFailureRef:createWithNotify(notify)
    --        self:onLoginError(err:szDescribeString())
    --        return
    --    end
    return true
end

function SceneLogin:OnSocketSubLogonFailure(notify)
    local err = jt.CMD_MB_LogonFailureRef:createWithNotify(notify)
    self:onLoginError(err:szDescribeString())
    notify:getObject():setSocketClose()
    return true
end

function SceneLogin:onLoginClose(event)
    self.isLoading = false
    self:stopAction(self.delayAction)
    GameManager:hideLoading()
    GameManager.logonCFrame = nil
    self:onLoginError("服务器连接异常，请稍候再尝试登录。")
end

function SceneLogin:onLoginError(content)
    local function onClick(result)
        if result == RT_SUCCESS then
            --注销
            if GameManager:getTransitionScene() ~= nil then
                GameManager:getTransitionScene():showPrevScene()
            end
        end
    end
    local jobj = {}
    jobj.loginType = GameManager.accountType
    SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCGameLogout,jobj)
    self.logonCount = 0
    self.isLoading = false
    self:setLogonData(nil)
    print(content)
    local alert = GameManager:showAlertSystem(self,content,onClick)
end

function SceneLogin:onNetError(event)
    self.isLoading = false
    local notify = event._userData
    if jt.SDKControl:getInstance():getWifiState() == 3 and notify:getResult() == RT_SUCCESS then
        self:stopAction(self.delayAction)
    elseif notify:getResult() == RT_FAILURE then
    --        if self.logonCount <= 1 then
    --            GameManager:showLoading(self)
    --            self:onTimerOut()
    --        end
    end
end

function SceneLogin:startDownAPK()
    GameManager:showAlertSystem(self,"游戏已更新，当前版本已不能使用，去下载最新版本？",function(result)
        if result == RT_SUCCESS then
            local map = {}
            if device.platform == "ios" then
                map.kindid = GameManager:getProject().AppId
                map.appurl = GameManager:getProject():getAppURL()
                jt.SDKControl:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCOpenApp,map)
            else

                local isNull = false
                if jt.SDKControl:getInstance().getSDKPlatform == nil then
                    isNull = true
                end

                --获取渠道信息进行更新APK
                local platform = jt.SDKControl:getInstance():getSDKPlatform()
                if jt.SDKControl:getInstance():getVersionCode() >= 20160629 then --兼容性
                    platform = platform .. "_" .. jt.SDKControl:getInstance():getStringFromPlatform(0,"getPackageName")
                end

                local data = cc.FileUtils:getInstance():fullPathForFilename("platform/"..platform.."/platform.json")
                local word = cc.FileUtils:getInstance():getStringFromFile(data)
                if word == "" then
                    isNull = true
                end

                if isNull then
                    local url = GameManager:getProject():getGameWebSite()
                    map.url = url
                    jt.SDKControl:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCOpenBrowser,map)
                    return
                end

                local jobj = json.decode(word)
                map.url = jobj.url
                jt.SDKControl:getInstance():sendMessage("CCUpdate",map)
                if self.sdk.ccNd_Progress ~= nil then
                    return
                end
                self.sdk.ccNd_Progress = true
                local currentTime = 0
                local handle,tag = SDKControlHandler:getInstance():addSelector(self.sdk,"ccNd_Progress",function(event)
                    local map = event._userData
                    local pro = tonumber(map:getString("progress"))
                    if pro == 0 then
                        local cur = os.time()
                        if math.abs(currentTime - cur) <= 2 then
                            return
                        end
                        if self.loadingDownload == nil then
                            self.loadingDownload = LoadingDownload:create():addTo(self)
                            self.loadingDownload:setTitle("皇家游戏apk")
                            self.loadingDownload:show()
                        end
                        currentTime = os.time()
                    end
                    if self.loadingDownload ~= nil then
                        if  pro == 1 or pro == -1 then
                            self.loadingDownload:hide()
                            self.loadingDownload = nil
                            currentTime = os.time()
                            self:runAction(MotionUtil:delayCallFunc(0.1,function()
                                SDKControlHandler:getInstance():removeSelectorsBySDK(self.sdk,"ccNd_Progress")
                            end))
                        else
                            self.loadingDownload:setProgress(pro*100)
                        end
                    end
                end)
            end
        end
    end):setBtnVisible(true,true)
end

-------------------------------------------
-- 热更新

function SceneLogin:playGame(isChange)
    print("进入游戏")
    self.isPlayGame = isChange
    self:runAction(MotionUtil:delayCallFunc(0.1,function()
        self.uEngine:destrory()
    end))
    if isChange == false then
        GameManager:showAlertSystem(self,"当前已经是最新版本",function()
            self:getApp():enterScene("scene/LoginScene")
        end)
        return
    elseif isChange == nil then
        scheduler.unscheduleGlobal(self.proScheduler)
        self.proScheduler = nil
        self:getApp():enterScene("scene/LoginScene")
    end

--    self:onProgress(100)
--    self:getApp():enterScene("scene/LoginScene")
end

function SceneLogin:onProgress(percent)
    self.totalProgress = percent
    --    self.loadingDownload:setProgress(percent)
    local progress = string.format("正在下载文件:%s(%d%%)", self.currentV, percent)
    print(progress)
end

function SceneLogin:onUpdate()
    --平滑过渡
    if self.curProgress < self.totalProgress then
        self.curProgress = self.curProgress + 1
        self.loadingDownload:setProgress(self.curProgress)
    end
    if self.curProgress == 100 and self.isPlayGame == true then
        scheduler.unscheduleGlobal(self.proScheduler)
        self.proScheduler = nil
        self:getApp():enterScene("scene/LoginScene")
    end
end

function SceneLogin:onSuccess()
    print("onSuccess 自动更新完毕")
--    self:getApp():enterScene("scene/LoginScene")
end

function SceneLogin:onDownload(notify)
    self.currentV = notify:getMainString()
    local downfile = string.format("正在下载文件:%s(0%%)", notify:getSubString())
    print(downfile)
end

function SceneLogin:onUncompress(notify)
    local uncompress = string.format("正在解压文件:%s", notify:getMainString())
    print(uncompress)
end

function SceneLogin:onError(errorCode)
    local function onClick()
        self:playGame()
    end
    if errorCode == update.ErrorCode.NO_NEW_VERSION then
        print("已经是最新版本")
    elseif errorCode == URLLoaderHandler.STATUS_CODES.NOT_FOUND then
        GameManager:showAlertSystem(self,"网络中断，请检测网络后再次打开，更多疑问请联系客服QQ:33836594",onClick)
    elseif errorCode == update.ErrorCode.NETWORK then
        GameManager:showAlertSystem(self,"网络中断，请检测网络后再次打开，更多疑问请联系客服QQ:33836594",onClick)
    elseif errorCode == update.ErrorCode.UNDOWNED then
        GameManager:showAlertSystem(self,"网络中断，请检测网络后再次打开，更多疑问请联系客服QQ:33836594",onClick)
    elseif errorCode == update.ErrorCode.UNCOMPRESS then
        GameManager:showAlertSystem(self,"网络中断，请检测网络后再次打开，更多疑问请联系客服QQ:33836594",onClick)
    end
end

-----------------------//


function SceneLogin:onTimerOut()
    --    if jt.SDKControl:getInstance():isCocosDebug() then
    --        GameManager:hideLoading()
    --        self:onLoginError("服务器响应超时")
    --        return
    --    end
    --    self:onLoginError("服务器响应超时，用其它账号登录？")

    self.logonCount = self.logonCount + 1
    local list = GameManager:getProject().addressList
    if self.logonCount > #list or list[self.logonCount].LoginAddress == nil then
        self.isLoading = false
        GameManager:hideLoading()
        GameManager.logonCFrame = nil
        GameManager:showAlertSystem(self,"网络中断，请检测网络后再次打开，更多疑问请联系客服QQ:33836594")
        return
    end

    local LoginAddress = list[self.logonCount].LoginAddress
    jt.CFrameData:getInstance():setLoginAddress(LoginAddress)
    jt.SDKControl:getInstance():printInfo("尝试换ip登录:",LoginAddress)
    GameManager.logonCFrame:setSocketClose()
    GameManager.logonCFrame = jt.CFrameData:createFrameData()
    GameManager.logonCFrame:sendPacketWithUserLogon(self.logonData)
    --    jt.CFrameData:getInstance():sendPacketWithUserLogon(self.logonData)
    self.delayAction = MotionUtil:delayCallFunc(4,handler(self,self.onTimerOut))
    self:runAction(self.delayAction)--服务器连接超时关闭重连
    --    self.isLoading = true
end

---------
-- 获取用户资料
function SceneLogin:onLoadUser(event)
--    GameManager:showLoading(self)
--    GameManager:getRoomServer():onLoginHall(self:getApp())
end

function SceneLogin:onRequstLogin(event)
    local jobj = event._userData

    if jobj.result ~= RT_SUCCESS then
        self:onLoginError("获取用户资料失败，请尝试用其它账号登录。")
        return
    end

    self:setLogonData(jt.CLogonData:create())
    self.logonData:setNickName(jobj.acccount)
    if jobj.accountType == 0 and GameManager.transferState == 0 then
        self.logonData:setNickName("Guest")
    end
    self.logonData:setGender(jobj.gender)
    self.logonData:setUUID(jobj.uuid)
    self.logonData:setDeviceid(jobj.szMachineID)
    if jobj.bigFace ~= "" then
        self.logonData:setAvatarURL(jobj.bigFace)
    else
        self.logonData:setAvatarURL("")
    end
    self.logonData:setPasswd("")
    self.logonData:setLogonType(jobj.accountType)
    GameManager.accountType = jobj.accountType

    if string.len(self.logonData:getDeviceid()) == 0 or
        string.len(self.logonData:getNickName()) == 0 then
        self:onLoginError("获取用户资料失败，请尝试用其它账号登录。")
        return
    end
    self.delayAction = MotionUtil:delayCallFunc(2,function()
        local niu,timer = GameManager:showLoading(self)
        self.delayAction = MotionUtil:delayCallFunc(3,handler(self,self.onTimerOut))
        self:runAction(self.delayAction)--服务器连接超时关闭重连
    end)
    self:runAction(self.delayAction)
    self.isLoading = true
    self.logonCount = 1
    --    jt.CFrameData:getInstance():sendPacketWithUserLogon(self.logonData)
    if GameManager.logonCFrame ~= nil then
        GameManager.logonCFrame:setSocketClose()
        GameManager.logonCFrame = nil
    end
    GameManager.logonCFrame = jt.CFrameData:createFrameData()
    GameManager.logonCFrame:sendPacketWithUserLogon(self.logonData)
end

function SceneLogin:onLogin(type)
    --    print("self.isLoading",self.isLoading)
    if self.isLoading == true then
        --避免连击
        GameManager:showLoading(self)
        return
    end
    --    self.isLoading = true

    GameManager.accountType = type
    --    local update = import("app/library/HotSwap.lua")
    --游客登录
    if device.platform ~= "windows" then
        -- GameManager:showLoading(self)
        --为方便测试，安卓游客模式直接跳过SDK登录
        if ( jt.SDKControl:getInstance():isAppDebug() and
            device.platform == "android" and type == GameManager:getProject().LogonType_Enum.LogonType_Tourist) then
            type = 1
        else
            local jobj = {}
            jobj.loginType = type
            SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCGameLogin,jobj)
            return
        end
    end
    self.delayAction = MotionUtil:delayCallFunc(2,function()
        local niu,timer = GameManager:showLoading(self)
        self.delayAction = MotionUtil:delayCallFunc(3,handler(self,self.onTimerOut))
        self:runAction(self.delayAction)--服务器连接超时关闭重连
    end)
    self:runAction(self.delayAction)

    --模拟数据登录
    --    GameManager:getRoomServer():onLoginHall(self:getApp())
    self:setLogonData(jt.CLogonData:create())
    self.logonData:setNickName("九天")
    self.logonData:setGender(GENDER_FEMALE)
    --腾讯测试账号-147Nick:DA6430CBD86F94238051C3C96FDFE1CE,Test-DA6430CBD86F94238051C3C96FDFE1CE-5
    --茂茂:01454D3FCF831EB6E33049D05782DAA1
    --九天:7164DC202AEAAEB841D97F0E78A68DC4
    --TEST：FJDHFJKHE3HH4J,E601DE8092844710F316E5A69021D916
    if device.platform == "windows" then
        self.logonData:setUUID("Test-DA6430CBD86F94238051C3C96FDFE1CE-2")
    else
        self.logonData:setUUID("Test-DA6430CBD86F94238051C3C96FDFE1CE-1")
    end
    self.logonData:setAvatarURL("https://www.baidu.com/img/bd_logo.png")
    self.logonData:setPasswd("")
    self.logonData:setLogonType(type)
    self.logonData:setDeviceid("714662659")
    self.logonCount = 1
    if GameManager.logonCFrame ~= nil then
        GameManager.logonCFrame:setSocketClose()
        GameManager.logonCFrame = nil
    end
    GameManager.logonCFrame = jt.CFrameData:createFrameData()
    GameManager.logonCFrame:sendPacketWithUserLogon(self.logonData)
end

function SceneLogin:onKeyboard(keyCode,event)
    SceneLogin.super.onKeyboard(self,keyCode,event)
    if keyCode == cc.KeyCode.KEY_ESCAPE or keyCode == cc.KeyCode.KEY_BACKSPACE
        or keyCode == 6 then
        event:stopPropagation()
        SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCQueryExitGame)--离开游戏?
    end
end

function SceneLogin:onCleanup()
    self:setLogonData(nil)
    CFrameDataHandler:getInstance():removeNotifyListener(self)

    if self.proScheduler then
        scheduler.unscheduleGlobal(self.proScheduler)
        self.proScheduler = nil
    end

    SDKControlHandler:getInstance():removeSelectors(SDKControlHandler.RecipientsList.ccNd_Platform_LogonResult)
    SDKControlHandler:getInstance():removeSelectors(SDKControlHandler.RecipientsList.ccNd_Platform_LogonLoading)
end

return SceneLogin
