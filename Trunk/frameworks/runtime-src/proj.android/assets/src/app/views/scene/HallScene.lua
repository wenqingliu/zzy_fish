local GameDelegate      = import("app/views/deleage/GameDelegate.lua")
local HallScene         = class("HallScene",GameDelegate)
local Timer             = import("app/library/Timer.lua")
local LuaUtil           = import("app/library/LuaUtil")
local json              = import("app/library/cjson")
local scheduler         = import("app/library/scheduler.lua")
local VIPLayer          = import("app/views/layer/VIPLayer.lua")
local ShopLayer         = import("app/views/layer/ShopLayer.lua")
local GameHelpLayer     = import("app/views/layer/GameHelpLayer.lua")
local ActivityLayer     = import("app/views/layer/ActivityLayer.lua")
local HallView          = import("app/views/scene/hall/HallView.lua")
local LoadingDownload   = import("app/views/animate/LoadingDownload.lua")
local URLLoaderHandler  = import("app/handler/URLLoaderHandler.lua")
local SDKControlHandler = import("app/handler/SDKControlHandler.lua")
local ChatRecordPool    = import("app/manager/ChatRecordPool.lua")
local SceneData         = import("app/models/data/SceneData.lua")

local CMD_Server_Logon   = import("app/cmd/loginSever/CMD_Server_Logon.lua")
local CMD_Server_Bank    = import("app/cmd/loginSever/CMD_Server_Bank.lua")
local GCMD_Sever_Friends = import("app/cmd/loginSever/CMD_Sever_Friends.lua")
local CMD_Server_Shop    = import("app/cmd/loginSever/CMD_Server_Shop.lua")
local CMD_Server_Mail    = import("app/cmd/loginSever/CMD_Server_Mail.lua")
local GCMD_Sever_Friends = import("app/cmd/loginSever/CMD_Sever_Friends.lua")

local update = import("update.lua")

function HallScene:onCreate()
    GameManager:setGameDelegate(self)
    CC_DESIGN_RESOLUTION.setRequestedOrientation(0)

    self.hallView = HallView:create(self):addTo(self)

    self.btnList = {}
    self.roomManager = GameManager:getRoomServer()
    ChatRecordPool:getInstance():start()
    CFrameDataHandler:getInstance():addNotifyListener(self)
end

function HallScene:onEnter()
    --游戏音乐
    audio.stopAllSounds()
    audio.playMusic("music/bgm_hall.mp3",true)
    --还在游戏房间中，直接进入游戏
    --    GameManager:showAlertSystem(self,"上次游戏未正常退出，点击重新进入游戏房间",function()
    if self.roomManager.playingRoom ~= nil then
        local room = self.roomManager.playingRoom
        GameManager:getRoomServer().playingRoom = nil--清除
        local item = self.roomManager:getRoomByName(room)
        if item ~= nil then
            self:loginRoom(item)
            return
        end
        self:runAction(MotionUtil:delayCallFunc(0.01,function()
            GameManager:showAlertSystem(self,"游戏房间未开启，登录失败",handler(self.roomManager,self.roomManager.onBackLogin))
        end))
    else
        --查询复活金
        local total = GameManager:getUserSelf():getScore() +  GameManager:getUserSelf():getInsureScore()
        if total < 10000 then
            scheduler.performWithDelayGlobal(0.04,function()
                GameManager:ReceiveResurrection(0)
            end)
        end

        if GameManager.cbAdviceUpdate == 1 then
            GameManager.cbAdviceUpdate = nil
            GameManager:showAlertSystem(self,"检测到有新版本更新，建议升级到最新版本",function(result)
                if result == RT_SUCCESS then
                    local map = {}
                    if device.platform == "ios" then
                        map.kindid = GameManager:getProject().AppId
                        SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCOpenApp,map)
                    else

                        local isNull = false
                        if jt.SDKControl:getInstance().getSDKPlatform == nil then
                            isNull = true
                        end

                        --获取渠道信息进行更新APK
                        local platform = jt.SDKControl:getInstance():getSDKPlatform()
                        local data = cc.FileUtils:getInstance():fullPathForFilename("platform/"..platform.."/platform.json")
                        local word = cc.FileUtils:getInstance():getStringFromFile(data)
                        if word == "" then
                            isNull = true
                        end

                        if isNull then
                            local url = GameManager:getProject():getGameWebSite()
                            map.url = url
                            SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCOpenBrowser,map)
                            return
                        end

                        local jobj = json.decode(word)
                        map.url = jobj.url
                        SDKControlHandler:getInstance():sendMessage("CCUpdate",map)
                        self.sdk = jt.SDKControl:create():addTo(self)
                        local handle,tag = SDKControlHandler:getInstance():addSelector(self.sdk,"ccNd_Progress",function(event)
                            local map = event._userData
                            local pro = tonumber(map.progress)
                            if pro == 0 then
                                if self.loadingDownload == nil then
                                    self.loadingDownload = LoadingDownload:create():addTo(self)
                                    self.loadingDownload:setTitle("皇家游戏apk")
                                    self.loadingDownload:show()
                                end
                            end
                            if self.loadingDownload ~= nil then
                                if  pro == 1 then
                                    self.loadingDownload:hide()
                                    self.loadingDownload = nil
                                    SDKControlHandler:getInstance():removeSelectorsBySDK(self.sdk,"ccNd_Progress")
                                else
                                    self.loadingDownload:setProgress(pro)
                                end
                            end
                        end)
                    end
                end
            end):setBtnVisible(true,true)
        else

            local function showPage()
                --VIP每日奖励
                local vip_day = cc.UserDefault:getInstance():getIntegerForKey("vip_day",0)
                local day = tonumber(os.date("%d"))
                if vip_day ~= day then
                	--首次进入游戏，显示游戏帮助
                    self.activity = ActivityLayer:create():addTo(self)
                    -- self.activity:setOnExitCallBack(function()
                    --     VIPLayer:create():addTo(self)
                    --     cc.UserDefault:getInstance():setIntegerForKey("vip_day",day)
                    --     cc.UserDefault:getInstance():flush()
                    -- end)
                end
            end

            if not cc.UserDefault:getInstance():getBoolForKey("hall",false) then
                --首次进入游戏，显示游戏帮助
                -- self.gameHelp = GameHelpLayer:create("hall"):addTo(self)
                -- self.gameHelp:setOnExitCallBack(showPage)
            else
                showPage()
            end
        end

    end

    if device.platform == "android" then
        if GameManager:isPlatformControl() then
            --查询平台钻石
            if self.sdk == nil then
                self.sdk = jt.SDKControl:getInstance()
            end
            local handle1,tag1
            handle1,tag1 = SDKControlHandler:getInstance():addSelector(self.sdk,SDKControlHandler.RecipientsList.ccNd_Notify,function(event)
                SDKControlHandler:getInstance():removeEventListener(tag1)
                local map = event._userData
                if map.result == 1 then
                    local balance = tonumber(map.balance)
                    if balance ~= 0 then
                        GameManager:getUserSelf():setDiamond(balance)
                        self:updateGameView()
                    end
                end
            end)
            local map = {}
            map.mainType = CMD_Server_Logon.MDM_GP_USER_SERVICE
            map.subType = CMD_Server_Shop.SUB_MB_SALESHOP_REQ
            map.gameID = GameManager:getUserSelf():getGameID()
            map.domainURL = "http://" .. GameManager:getProject().LoginAddress ..GameManager:getProject().URLPort
            SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCNotify,map)
        end
    end

    --渠道
    if device.platform ~= "ios" then
        local isFirst_gameID = "isFirst_gameID_"..GameManager:getUserSelf():getGameID()
        local bool = cc.UserDefault:getInstance():getBoolForKey(isFirst_gameID,false)
        if not bool then
            local url = GameManager:getProject():getOrginal(GameManager:getUserSelf():getGameID(),jt.SDKControl:getInstance():getSDKPlatform())
            URLLoaderHandler:load(url,function(urlData)
                if urlData:getStatusCode() == URLLoaderHandler.STATUS_CODES.SUCCESS then
                    print("渠道：",urlData:getData())
                    cc.UserDefault:getInstance():setBoolForKey(isFirst_gameID,true)
                    cc.UserDefault:getInstance():flush()
                end
            end)
        end
    end
end

function HallScene:OnTCPWithDataRoom(notify)
    if notify:getMainType() == GCMD_Sever_Friends.MDM_GR_QUERY then --查询命令(主命令)
        local sub = notify:getSubType()
        if sub == CMD_Server_Mail.SUB_MB_S_EMAIL_MESSAGE_PUSH then --收到邮件（只是收到送礼的邮件信息）
            return true --self.hallView:getMail(notify)
        elseif sub == CMD_Server_Mail.SUB_GF_GAME_INFORM then--收到通知
            return true --self.hallView:getInfo(notify)
        elseif sub ==  GCMD_Sever_Friends.SUB_MB_FRIENT_USER_STATUS then --好友上下线
            return true --self.hallView:getFriendOnline(notify)
        elseif sub == CMD_Server_Mail.SUB_GF_SYS_GAME_INFORM then --红点通知
            return true --self.hallView:onEnterMsgInfo(notify)
        end
    end

    if notify:getMainType() == CMD_Server_Bank.MDM_GR_INSURE then             --银行命令
        local sub = notify:getSubType()
        if sub == CMD_Server_Bank.SUB_GR_S_USER_RELIVE_GOLD_RESPONSE then   --复活金响应
            return self.hallView:onReliveGoldResponse(notify)
        end
    end

    return false
end


---------
-- 重写更新视图
function HallScene:updateGameView()
    return self.hallView:updateGameView()
end

-------------
-- 公开方法
-- 登录房间
function HallScene:loginRoom(item,params)
    print("HallScene:loginRoom",item,params)
    if item ~= nil then
        --最低进入条件
        if GameManager:getUserSelf():getScore() < item:lMinEnterScore() then
            GameManager:showAlertSystem(self,"你的分数不足"..item:lMinEnterScore()..",是否立即购买？",handler(self,self.onOpenShop),1):setBtnVisible(true,true)
            return
        end
        local data,isStartEnable = SceneData:createWithRoom(item)
        if data == nil then
            GameManager:showAlertSystem(self,"尚未开放，敬请期待")
            return
        end

        --检测游戏资源包是否存在
        if not data:isExistRes() then
            GameManager:showAlertSystem(self,"尚未下载该游戏资源包（约"..data:getZipSize().."），是否立即下载？",function(result)
                if result == RT_SUCCESS then
                    self.roomItem = item
                    self:startDownLoad(data)
                end
            end):setBtnVisible(true,true)
            return
        end
        local guideName = ""
        if item:wKindID() == KIND_ID_BR or item:wKindID() ==KIND_ID_OXBR then
        	guideName = "hundred"
        elseif item:wKindID() == KIND_ID_KPQZ then
            guideName = "kanpai"
        elseif item:wKindID() == KIND_ID_Gongpo then
            guideName = "gongpo"
        elseif item:wKindID() == KIND_ID_YY then
            guideName = "yyl"
        elseif item:wKindID() == KIND_ID_Slot then
            guideName = "slotMachine"
        elseif item:wKindID() == KING_ID_FEIQIN then
            guideName = "feiqin"
        end
        if guideName ~= "" and not cc.UserDefault:getInstance():getBoolForKey(guideName,false) then
                --首次进入游戏，显示游戏帮助
            self.gameHelp = GameHelpLayer:create(guideName,self,item,params):addTo(self)
        else
            -- CC_DESIGN_RESOLUTION.setRequestedOrientation(data:getOrientation())
            self.tran = self:getApp():createView("scene/TransitionScene.lua")
            local function onLoginRoom()
                GameManager:getRoomServer():onLoginRoom(item,isStartEnable,params);
            end

            local fishLoader = import("app/views/game/fish/FishLoader.lua").new()
            self.tran.loadFunc = handler(fishLoader,fishLoader.load)
            self.tran:start(data,onLoginRoom)
            self.tran:showWithScene()
        end

    else
        GameManager:showAlertSystem(self,"尚未开放，敬请期待")
    end
end

-------------------------------------------
-- 热更新

function HallScene:startDownLoad(sceneData)

    if self.loadingDownload ~= nil then
        self.loadingDownload:hide()
        self.loadingDownload = nil
    end
    self.loadingDownload = LoadingDownload:create():addTo(self)
    self.loadingDownload:setTitle(self.roomItem:szServerName())
    self.loadingDownload:show()

    if self.uEngine ~= nil then
        self.uEngine:destrory()
        self.uEngine = nil
    end

    --创建更新引擎
    self.uEngine = update:getInstance()
    self.uEngine:setDelegate(self)
    self.uEngine:pushZIP(sceneData:getZipURL())
    self.uEngine:startUpdate()
end

function HallScene:playGame()
    print("进入游戏")

    self:onProgress(100)

    if self.loadingDownload ~= nil then
        self.loadingDownload:hide()
        self.loadingDownload = nil
    end

    self.uEngine:destrory()
    local des = self.roomItem:szServerName().."游戏下载完毕"
    self.roomItem = nil
    GameManager:showAlertSystem(self,des)
end

function HallScene:onProgress(percent)
    if self.loadingDownload ~= nil then
        self.loadingDownload:setProgress(percent)
    end
    print("正在下载文件:",percent)
end

function HallScene:onSuccess()
    print("onSuccess 自动更新完毕")
end

function HallScene:onDownload(notify)
    local downfile = string.format("正在下载文件:%s(0%%)", notify:getSubString())
    print(downfile)
end

function HallScene:onUncompress(notify)
    local uncompress = string.format("正在解压文件:%s", notify:getMainString())
    print(uncompress)
end

function HallScene:onError(errorCode)
    local function onClick()
        if self.loadingDownload ~= nil then
            self.loadingDownload:hide()
            self.loadingDownload = nil
        end
        self.uEngine:destrory()
        self.roomItem = nil
    end
    if errorCode == update.ErrorCode.NO_NEW_VERSION then
        print("已经是最新版本")
    elseif errorCode == URLLoaderHandler.STATUS_CODES.NOT_FOUND then
        GameManager:showAlertSystem(self,"获取下载文件失败，请联系客服",onClick)
    elseif errorCode == update.ErrorCode.NETWORK then
        GameManager:showAlertSystem(self,"获取下载文件失败，请稍候再试",onClick)
    elseif errorCode == update.ErrorCode.UNDOWNED or errorCode == update.ErrorCode.UNCOMPRESS  then
        GameManager:showAlertSystem(self,"下载文件失败，请稍候再试",onClick)
--    elseif errorCode == update.ErrorCode.UNCOMPRESS then
--        GameManager:showAlertSystem(self,"解压文件失败，请稍候再试",onClick)
    end
end

-----------------------//


-----------
--游戏消息处理
function HallScene:OnEventGameMessage(sub,obj)
    return true
end

function HallScene:onSubSystemMessage(szString,system,vipLevel)
    self.hallView:onSubSystemMessage(szString,system,vipLevel)
end

function HallScene:onKeyboard(keyCode,event)
    HallScene.super.onKeyboard(self,keyCode,event)

    if keyCode == cc.KeyCode.KEY_ESCAPE or keyCode == cc.KeyCode.KEY_BACKSPACE
        or keyCode == 6 then
        event:stopPropagation()
        SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCQueryExitGame)--离开游戏?
    end
end

function HallScene:onOpenShop(result,param)
    if result == RT_SUCCESS then
            --商店
        ShopLayer:create(GameManager:getUserSelf(),param):addTo(self)
    end
end

function HallScene:onCleanup()
    GameManager:setGameDelegate(nil)--移除代理设置
--    CFrameDataHandler:getInstance():removeEventListenerByList(self.events)
    SDKControlHandler:getInstance():removeSelectors(SDKControlHandler.RecipientsList.ccNd_Notify)
    CFrameDataHandler:getInstance():removeNotifyListener(self)

    if self.roomVs_schedule then
        cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.roomVs_schedule)        --关掉计时器
    end
    if self.roomVSStart_schedule then
        cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.roomVSStart_schedule)        --关掉计时器
    end
end

return HallScene
