local GameSeverManager = class("GameSeverManager")

local UserData = import("app/models/data/UserData")
local LoginSceneData = import("app/models/data/login/LoginSceneData.lua")

local HornLayer = import("app/views/layer/HornLayer.lua")

local CMD_Server_Gift = import("app/cmd/loginSever/CMD_Server_Gift.lua")
local CMD_Server_Bank = import("app/cmd/loginSever/CMD_Server_Bank.lua")
local CMD_Server_VIP = import("src/app/cmd/loginSever/CMD_Server_VIP.lua")
local CMD_Server_Shop = import("src/app/cmd/loginSever/CMD_Server_Shop.lua")
local GCMD_Sever_Friends = import("app/cmd/loginSever/CMD_Sever_Friends.lua")
local CMD_Room_User = import("app/cmd/room/CMD_Room_User.lua")
local CMD_Game_Server = import("app/cmd/room/CMD_Game_Server.lua")

local scheduler = import("app/library/scheduler.lua")

GameSeverManager.events = {
    ccNd_Socket_CloseLink = "ccNd_Socket_CloseLink",                    --网络异常
}

local enterTime = 0
function GameSeverManager:ctor()
    self.isWaitClose = nil
    self.isNotClose = nil
    self.m_cbGameClient = 0x00
    self.m_cbGameStatus = 0
end

function GameSeverManager:setNotClose(isNotClose)
    self.isNotClose = isNotClose
end

function GameSeverManager:getGameClient()
    return self.m_cbGameClient
end

function GameSeverManager:setGameClient(m_cbGameClient)
    self.m_cbGameClient = m_cbGameClient
end

function GameSeverManager:start()
    if not self._isRunning then
        self._isRunning = true
        CFrameDataHandler:getInstance():addEventListener(self.events.ccNd_Socket_CloseLink,handler(self,self.OnSocketDelegateWithCloseNotify))
        CFrameDataHandler:getInstance():addNotifyListener(self)
        
        --APP前台/后台事件
        local eventDispatcher = cc.Director:getInstance():getEventDispatcher()
        local enter_bg = cc.EventListenerCustom:create("APP_ENTER_BACKGROUND_EVENT",
            function(parameters)
                print("applicationDidEnterBackground")
            end)
        eventDispatcher:addEventListenerWithFixedPriority(enter_bg, 1)
        local enter_fg = cc.EventListenerCustom:create("APP_ENTER_FOREGROUND_EVENT",
            function(parameters)
                print("applicationWillEnterForeground")
                enterTime = os.time()
                if GameManager:getKindID() ~= KIND_ID_MSG and jt.CFrameData:getInstance():getDataArraySize() >= 200 then
                    print("jt.CFrameData:getInstance():getDataArraySize():",jt.CFrameData:getInstance():getDataArraySize())
                    jt.CFrameData:getInstance():setSocketClose(true)
                    scheduler.performWithDelayGlobal(0.1,function()
                        GameManager:showAlertSystem(GameManager:getGameDelegate(),"您太久没有操作响应，正在为您返回游戏大厅",function()
                            GameManager:getRoomServer():onBackHall(GameManager:getGameDelegate():getApp())--返回大厅
                        end)
                    end)
                end
            end)
        eventDispatcher:addEventListenerWithFixedPriority(enter_fg,1)
        self.enter_bg = enter_bg
        self.enter_fg = enter_fg
    end

    return self
end

--游戏服务器
function GameSeverManager:OnTCPWithDataRoom(notify)
    local mainType = notify:getMainType()
    
    if mainType == CMD_Game_Server.MDM_GR_USER then --用户命令  3
        return self:OnTCPNetworkMainGRUser(notify)
    elseif mainType == CMD_Game_Server.MDM_GR_STATUS then --用户状态  4
        return true
    elseif mainType == CMD_Game_Server.MDM_GF_GAME then --游戏命令 200
        return self:onEventGameMessage(notify)
    elseif mainType == CMD_Game_Server.MDM_GF_FRAME then --框架命令100
        return self:OnTCPNetworkMainGFFrame(notify)
    elseif mainType == CMD_Game_Server.MDM_GR_INSURE then --银行命令 5
        return self:onEventBankMessage(notify)
    elseif mainType == CMD_Room_User.MDM_GR_QUERY then --查询命令8
        return self:OnTCPNetworkWithQuery(notify)
    elseif mainType == CMD_Game_Server.MDM_CM_SYSTEM then --系统命令 1000
        return self:OnTCPNetworkMainCMSystem(notify)
    end
    
    return false
end

----
--用户服务(游戏服务器)
function GameSeverManager:OnTCPNetworkMainGRUser(notify)
    local sub = notify:getSubType()
    if sub == CMD_Game_Server.SUB_GR_USER_ENTER then                 --用户进入 100
        return self:onSocketSubUserEnter(notify);
    elseif sub == CMD_Game_Server.SUB_GR_USER_SCORE then             --用户分数  101
        return self:OnSocketSubUserScore(notify)
    elseif sub == CMD_Game_Server.SUB_GR_USER_STATUS then            --用户状态  102
        return self:onUserStatus(notify);
    elseif sub == CMD_Game_Server.SUB_GR_REQUEST_FAILURE then        --请求失败  103
        return self:OnSocketSubRequestFailure(notify);
    elseif sub == CMD_Game_Server.SUB_GR_USER_WAIT_DISTRIBUTE then   --等待分配 12
        return true
    elseif sub == CMD_Game_Server.SUB_GR_USER_AWARD then            --用户奖励 104
        return true;
    elseif sub == CMD_Game_Server.SUB_GR_USER_GOLD then             --金币变化 105
        return true
    elseif sub == CMD_Game_Server.SUB_GR_PROPERTY_TRUMPET then      --喇叭消息 305
        return self:OnSocketPropertyTrympet(notify)
    elseif sub == CMD_Room_User.SUB_GR_USER_INVITE then             --好友邀请 5 
        return self:OnSocketSubUserInviteToGame(notify)
    end
    return false
end

--框架命令
function GameSeverManager:OnTCPNetworkMainGFFrame(notify)
    local sub = notify:getSubType()
    if sub == CMD_Game_Server.SUB_GF_USER_CHAT then                 --用户聊天 10
        return self:OnSocketChatWord(notify)
    elseif sub == CMD_Game_Server.SUB_GF_USER_EXPRESSION then       --用户表情
        return self:OnSocketChatExpression(notify)
    elseif sub == CMD_Game_Server.SUB_GF_GAME_STATUS then           --游戏状态 100
        return self:OnSocketSubGFGameStatus(notify)
    elseif sub == CMD_Game_Server.SUB_GF_GAME_SCENE then           --游戏场景 101
        return self:OnSocketSubGFGameScene(notify)
    elseif sub == CMD_Game_Server.SUB_GF_SYSTEM_MESSAGE then           --系统消息 200
        return self:OnSocketSubGFSystemMessage(notify)
    end
    
    return true
end

--用户进入
function GameSeverManager:onSocketSubUserEnter(notify)
--    local notify = event._userData
--    local pInfoHead = notify:getObject()
    local pInfoHead = CMD_Room_User.tagMobileUserInfoHead:createWithNotify(notify)
    local pUser = GameManager:getUserManager():getUserItem(pInfoHead.dwUserID)
    if pUser == nil then
        --创建用户
        pUser = UserData:create()
    end

    pUser:setNickName(pInfoHead.szNickName)
    pUser:setGameID(pInfoHead.dwGameID)  
    pUser:setUserID(pInfoHead.dwUserID)
    pUser:setFaceID(pInfoHead.wFaceID)
    pUser:setCustomID(pInfoHead.dwCustomID)
    pUser:setFaceURL(pInfoHead.szFaceIDDownURL)
    pUser:setGender(pInfoHead.cbGender)
    pUser:setUserStatus(pInfoHead.cbUserStatus)
    pUser:setTableID(pInfoHead.wTableID)
    pUser:setChairID(pInfoHead.wChairID)
    pUser:setScore(pInfoHead.lScore)
    pUser:setWinCount(pInfoHead.dwWinCount)
    pUser:setLostCount(pInfoHead.dwLostCount)
    pUser:setDrawCount(pInfoHead.dwDrawCount)
    pUser:setFleeCount(pInfoHead.dwFleeCount)

    pUser:setMemberOrder(pInfoHead.cbMemberOrder)

    local me = GameManager:getUserSelf()
    local userManager = GameManager:getUserManager()
    userManager:setUserItem(pUser)

    print("GameSeverManager:onSocketSubUserEnter",pInfoHead.szNickName,pUser:getUserStatus(),pUser:getGameID(),pInfoHead.cbUserStatus,pInfoHead.wTableID,pInfoHead.wChairID)
    
    local roomServer = GameManager:getRoomServer()
    if pInfoHead.dwUserID == me:getUserID() and roomServer.isEnterRoom == true then
        roomServer.isEnterRoom = false
        
        jt.CFrameData:getInstance():setTableID(pInfoHead.wTableID)
        jt.CFrameData:getInstance():setChairID(pInfoHead.wChairID)
        
        if pInfoHead.cbUserStatus == US_PLAYING then
            userManager:onSetTableInfo(me:getTableID(),me:getChairID())
            --            jt.CFrameData:getInstance():sendPacketWithGameOption()
        elseif not roomServer.isStartEnable then --发送快速加入游戏
            if roomServer.targetTableID == nil or roomServer.targetChairID == nil then
                jt.CFrameData:getInstance():sendPacketWithQuickJin()
--                jt.CFrameData:getInstance():sendPacketWithSitDown(8,0)
        else
            jt.CFrameData:getInstance():sendPacketWithSitDown(roomServer.targetTableID,roomServer.targetChairID)
            roomServer:clearTableChair()
        end
        else
            jt.CFrameData:getInstance():sendPacketWithRequestChairUserInfo(
                me:getTableID(),INVALID_CHAIR)
        end

    else

    end
    --//


    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():updateGameView()
    end
    return true
end

function GameSeverManager:OnSocketSubGFGameStatus(notify)
    local cmd = CMD_Game_Server.CMD_GF_GameStatus:createWithNotify(notify)
    self.m_cbGameStatus = cmd.cbGameStatus
    self.m_cbGameClient = 0x02
    return true
end

function GameSeverManager:OnSocketVIPAndHorn(notify)

    if notify:getSize() ~= 0 then
        local cmd = CMD_Server_VIP.CMD_MB_S_VIPSOUNA:createWithNotify(notify)
        GameManager:getUserSelf():setMemberOrder(cmd.info.nVipLevel)
        GameManager:getUserSelf():setHornNum(cmd.info.nTrumpetCount)
        GameManager:getUserSelf():setVIPHornNum(cmd.info.nTrumpetBuyCount)
        GameManager.isOpenStorage   = cmd.info.bOpenWareHouse       --是否开通仓库
        GameManager.isCanSendGift   = cmd.info.bSendGift            --是否可以赠送礼物
        GameManager.isCanAddFriend  = cmd.info.nFriendCount         --最大好友数量（0表示不可以添加好友）
        GameManager.isOpenYYL       = cmd.info.bOpenYYle            --是否开通摇摇乐
        GameManager.isOpenSlot      = cmd.info.bOpenFM              --是否开通水果机
        if not GameManager:isPlatformControl() then
            GameManager:getUserSelf():setDiamond(cmd.info.lDiamond)
        end
        if GameManager:getGameDelegate() ~= nil then
            GameManager:getGameDelegate():updateGameView()
        end
    end
    return true
end

--------
-- 用户分数
function GameSeverManager:OnSocketSubUserScore(notify)
--    local notify = event._userData
    local cmd = jt.CMD_GR_MobileUserScoreRef:createWithNotify(notify)
    cmd:initRef()
    GameManager:getUserManager():onEventUserScore(cmd:dwUserID(),nil,cmd:getUserScore())
    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():onUpdateScore()
    end
    return true
end

--------
-- 用户状态
function GameSeverManager:onUserStatus(notify)
--    local notify = event._userData
    local cmd = jt.CMD_GR_UserStatusRef:createWithNotify(notify)
    cmd:initRef()
    local userStatus = cmd:getUserStatus()
    local userManager = GameManager:getUserManager()

    local olditem = userManager:searchUserByUserID(cmd:dwUserID())
    local oldstatus = jt.tagUserStatusRef:createWithNotify()

    local bCheckUserInfo = false;

    if olditem ~= nil then
        oldstatus:wTableID(olditem:getTableID())
        oldstatus:wChairID(olditem:getChairID())
        oldstatus:cbUserStatus(olditem:getUserStatus())
    else 
        --创建临时用户数据
        olditem = UserData:create()
        olditem:setNickName("加载中...");
        olditem:setUserID(cmd:dwUserID())
        olditem:setTableID(userStatus:wTableID());
        olditem:setChairID(userStatus:wChairID());
        olditem:setUserStatus(userStatus:cbUserStatus())
        userManager:setUserItem(olditem)

        bCheckUserInfo = true
        oldstatus:wTableID(INVALID_TABLE)
        oldstatus:wChairID(INVALID_CHAIR)
        oldstatus:cbUserStatus(US_FREE)

    end

    --更新用户状态
    userManager:onEventUserStatus(cmd:dwUserID(),oldstatus,userStatus)

    local me = GameManager:getUserSelf()
    if cmd:dwUserID() == me:getUserID() then
    
        jt.CFrameData:getInstance():setTableID(userStatus:wTableID())
        jt.CFrameData:getInstance():setChairID(userStatus:wChairID())
        
        if self.m_cbGameClient == 0 and userStatus:wTableID() ~= INVALID_TABLE then
            self.m_cbGameClient = 0x02
        elseif self.m_cbGameClient ~= 0 and userStatus:wTableID() == INVALID_TABLE and userStatus:cbUserStatus() ~= US_SIT then
            self.m_cbGameClient = 0x00
        end
        
        --判断用户是否还在游戏状态
        if self.m_cbGameClient == 0x00 and GameManager:getGameDelegate() ~= nil then
            if self.isWaitClose and not self.isNotClose then
                GameManager:hideLoading()
                jt.CFrameData:getInstance():setSocketClose(true)
                GameManager:getRoomServer():onBackHall(GameManager:getGameDelegate():getApp())--返回大厅
                self.isWaitClose = nil
            else

            end
            self.isNotClose = nil
        end

        if me:getUserStatus() == US_SIT and oldstatus:cbUserStatus() ~= US_PLAYING then
            if GameManager:getGameDelegate() ~= nil then
                --重置游戏
                if GameManager:getGameDelegate():isShow() then
                    GameManager:getGameDelegate():onReSetGame()
                elseif GameManager:getTransitionScene() ~= nil then
                    GameManager:getTransitionScene():showNextScene()
                end
            end
            --设置桌子显示顺序
            userManager:onSetTableInfo(me:getTableID(),me:getChairID())
            --获取椅子信息
            jt.CFrameData:getInstance():sendPacketWithGameOption()
            jt.CFrameData:getInstance():sendPacketWithRequestChairUserInfo(
                userStatus:wTableID(),INVALID_CHAIR)

        else

            if GameManager:getGameDelegate() ~= nil 
                and userStatus:cbUserStatus() == US_PLAYING and me:getUserStatus() == US_PLAYING
                and oldstatus:cbUserStatus() == US_FREE then
                --设置桌子显示顺序
                userManager:onSetTableInfo(me:getTableID(),me:getChairID())

                if not GameManager:getGameDelegate():isShow() then
                    --进入游戏
                    GameManager:getTransitionScene():showNextScene()
                end

                --获取椅子信息
                jt.CFrameData:getInstance():sendPacketWithGameOption()
                jt.CFrameData:getInstance():sendPacketWithRequestChairUserInfo(
                    userStatus:wTableID(),INVALID_CHAIR)

            end

        end    

    end
    --//

    if (oldstatus:wTableID() ~= INVALID_TABLE and oldstatus:wTableID() == me:getTableID())
        or (userStatus:wTableID() ~= INVALID_TABLE and userStatus:wTableID() == me:getTableID()) then

        if GameManager:getGameDelegate() ~= nil then
            GameManager:getGameDelegate():updateGameView()
        end

        if bCheckUserInfo
            and userStatus:wTableID() ~= INVALID_TABLE and userStatus:wTableID() == me:getTableID() then
            --获取椅子信息
            jt.CFrameData:getInstance():sendPacketWithRequestChairUserInfo(
                userStatus:wTableID(),userStatus:wChairID())
        end

    end

    return true
end

----------
-- 游戏消息
function GameSeverManager:onEventGameMessage(notify)
    local sub = notify:getSubType()
    if GameManager:getGameDelegate() ~= nil then
        --房间消息处理
        GameManager:getGameDelegate():OnEventGameMessage(sub,notify)
    end
    return true
end

----------
-- 银行消息
function GameSeverManager:onEventBankMessage(notify)
    local sub = notify:getSubType()
    if sub == CMD_Server_VIP.SUB_MB_USER_VIPSOUNA_INFO then             --VIP喇叭信息 
        return self:OnSocketVIPAndHorn(notify)
    end
    
    return false
end

function GameSeverManager:OnTCPNetworkMainCMSystem(notify)
    local sub = notify:getSubType()
    if sub == CMD_Game_Server.SUB_CM_SYSTEM_MESSAGE then --系统消息
        return self:OnSocketSubGFSystemMessage(notify)
    elseif sub == CMD_Game_Server.SUB_CM_DOWN_LOAD_MODULE then --下载消息
        return true
    end 
    return true
end

--查询命令
function GameSeverManager:OnTCPNetworkWithQuery(notify)
    local sub = notify:getSubType()
    if sub == CMD_Room_User.SUB_GF_FRIEND_INVITE then --好友邀请 13
        return self:OnSocketSubUserInviteToGame(notify)
    elseif sub == 2 then --未知命令
        return true
    end 
    return false
end

----------
-- 游戏场景消息
function GameSeverManager:OnSocketSubGFGameScene(notify)
--    local notify = event._userData
    notify:setSubType(self.m_cbGameStatus)
    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():OnEventSceneMessage(notify:getSubType(),notify)
    end
    return true
end

---------
-- 系统消息
function GameSeverManager:OnSocketSubGFSystemMessage(notify)
--    local notify = event._userData
    local cmd = jt.CMD_CM_SystemMessageRef:createWithNotify(notify)
    if GameManager:getGameDelegate() ~= nil then
        local szString = cmd:szString()

        if cmd:wType() == 8 then --房间
            GameManager:showAlert(GameManager:getGameDelegate(),"游戏提示",cmd:szString())
            return true
        else

        end

        if bit.band(cmd:wType(),0x200) ~= 0 then
            if GameManager:getKindID() ~= KIND_ID_MSG then
                GameManager:showAlert(GameManager:getGameDelegate(),"游戏提示",cmd:szString(),handler(self,self.onGameBack))
                return true
            end
        end

        local SMT_CHAT             =       0x0001                              --聊天消息
        local SMT_EJECT            =       0x0002                              --弹出消息
        local SMT_GLOBAL           =       0x0004                              --全局消息
        local SMT_PROMPT           =       0x0008                              --提示消息
        local SMT_CLOSE_ROOM       =       0x0100                              --关闭房间

        if bit.bor(bit.bor(bit.bor(bit.bor(cmd:wType(),SMT_CHAT),SMT_EJECT),SMT_GLOBAL),SMT_CLOSE_ROOM) == cmd:wType() then --wType == 263
            --请注意，您的帐号在另一地方进入了此游戏房间，您被迫离开！
            local function gameback()
                if GameManager:getTransitionScene() ~= nil then
                    GameManager:getTransitionScene():showPrevScene()--返回
                else
                    GameManager:getGameDelegate():getApp():enterScene(LoginSceneData.targetScene)
                end
            end
            jt.CFrameData:getInstance():setSocketClose(true)
            GameManager:showAlertSystem(cc.Director:getInstance():getRunningScene(),cmd:szString(),gameback)
            return true
        elseif (bit.bor(bit.bor(cmd:wType(),SMT_CHAT),SMT_EJECT) == cmd:wType())--cmd:wType() == 3
            or (bit.bor(bit.bor(cmd:wType(),SMT_EJECT),SMT_PROMPT) == cmd:wType())
          then
            GameManager:hideLoading()
            GameManager:showAlertSystem(cc.Director:getInstance():getRunningScene(),cmd:szString())
            return true
        end

        HornLayer:addHornInfo(HornLayer.MsgRecordItem.TYPE_SYS,szString,-1)
        GameManager:getGameDelegate():onSubSystemMessage(szString,true)
    end
    return true
end


--邀请对战响应
function GameSeverManager:OnSocketSubUserInviteToGame(notify)
--    local notify = event._userData
    local cmd = CMD_Room_User.CMD_MB_FriendInvite:createWithNotify(notify)
    if GameManager:getGameDelegate() ~= nil then
        if cmd.wKindID == GameManager:getKindID() and cmd.wTableID == GameManager:getUserSelf():getTableID() then
            print("收到游戏邀请，已在同一张游戏桌中")
            return true
        end
        local nickName = cmd.szNickName
        GameManager:showAlert(GameManager:getGameDelegate(),"游戏邀请","你的好友“"..nickName.."”邀请你进行“"..cmd.szRoomName.."”游戏，是否立即前往？",function(result)
            if result == RT_SUCCESS then
                local item = GameManager:getRoomServer():getRoomByName(cmd.szRoomName)
                GameManager:getRoomServer():setTargetTableChair(cmd.wTableID,cmd.wChairID)
                if GameManager:getKindID() ~= KIND_ID_VS then
                    if GameManager:getKindID() ~= KIND_ID_MSG then
                        --返回大厅再登录游戏房间
                        GameManager:getRoomServer().playingRoom = item:szServerName()
                        self:onGameBack()
                    else
                        GameManager:getGameDelegate():loginRoom(item)
                    end
                else
                    --重新进入当前游戏房间
                    --                    GameManager:getGameServer():setNotClose(true)
                    --                    jt.CFrameData:getInstance():sendPacketWithStandUpLeave(1)
                    local SceneData = import("app/models/data/SceneData.lua")
                    local data,isStartEnable = SceneData:createWithRoom(item)
                    GameManager:getRoomServer():onLoginRoom(item,isStartEnable);
                end
            else

            end
        end):setBtnVisible(true,true)
    else
        print("当前玩家不在游戏场景")
    end
    return true
end

---------
-- 返回游戏
function GameSeverManager:onGameBack()
    local function backHall()
        self.isWaitClose = nil
        jt.CFrameData:getInstance():setSocketClose(true)
        if GameManager:getGameDelegate() ~= nil then
            GameManager:getRoomServer():onBackHall(GameManager:getGameDelegate():getApp())
        end
    end
    if GameManager:getUserSelf():getTableID() == INVALID_TABLE or GameManager:getUserSelf():getChairID() == INVALID_CHAIR then
        backHall()
    else
        self.isWaitClose = true
        GameManager:showLoading(GameManager:getGameDelegate(),function()
            GameManager:hideLoading()
            backHall()
        end)
        jt.CFrameData:getInstance():sendPacketWithStandUpLeave(1)--发送起立(离开游戏)
    end
end

---------
-- 网络异常
function GameSeverManager:OnSocketDelegateWithCloseNotify(event)
    local notify = event._userData
    if GameManager:getGameDelegate() ~= nil and notify:getObject() == jt.CFrameData:getInstance() then
        local curTime = os.time()
        print("OnSocketDelegateWithCloseNotify",enterTime,curTime)
        if math.abs(enterTime - curTime) <= 8 then --后台转入前台，做断线重连处理
            scheduler.performWithDelayGlobal(0.5,function()
                print("applicationWillEnterForeground-OnSocketDelegateWithCloseNotify")
                local roomServer = GameManager:getRoomServer()
                if GameManager:getKindID() == KIND_ID_MSG then
                    roomServer:onLoginMsgServer(GameManager:getRoomServer():getMessageServer())
                else
                    roomServer:onLoginRoom(roomServer.currentRoom,roomServer.isStartEnable,roomServer.roomParams)
                end
            end)
        else
            GameManager:showAlertSystem(GameManager:getGameDelegate(),"网络中断,请重新登录游戏",function()
                self.isWaitClose = nil
                GameManager:getGameDelegate():getApp():enterScene(LoginSceneData.targetScene)
            end)
        end
    end
    return true
end

----------
-- 请求失败
function GameSeverManager:OnSocketSubRequestFailure(notify)
--    local notify = event._userData
    local notify = CMD_Game_Server.CMD_GR_RequestFailure:createWithNotify(notify)
    GameManager:showAlertSystem(cc.Director:getInstance():getRunningScene(),notify.szDescribeString,handler(self,self.onGameBack))
    return true
end

---------
-- 喇叭消息
function GameSeverManager:OnSocketPropertyTrympet(notify)
    --控制模式下不接收玩家喇叭(屏蔽广告刷屏)
    if GameManager.transferState == 0 then 
       return true
    end
    
--    local notify = event._userData
    local cmd = jt.CMD_GR_S_SendTrumpetRef:createWithNotify(notify)
    if GameManager:getGameDelegate() ~= nil then
        local str = "[" .. cmd:szSendNickName() .. "]  " .. cmd:szTrumpetContent()
        local VipLevel = cmd:TrumpetColor()                         --VIp等级
        HornLayer:addHornInfo(HornLayer.MsgRecordItem.TYPE_HORN,str,VipLevel)
        GameManager:getGameDelegate():onSubSystemMessage(str,false,VipLevel);
    end
    return true
end

--------
-- 聊天文字
function GameSeverManager:OnSocketChatWord(notify)
    print("GameSeverManager:OnSocketChatWord")
--    local notify = event._userData
    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():onUserChat(notify);
    end
    return true
end

--------
-- 聊天表情
function GameSeverManager:OnSocketChatExpression(notify)
--    local notify = event._userData
    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():onUserImage(notify);
    end
    return true
end

function GameSeverManager:destroy()
    if self._isRunning then
        CFrameDataHandler:getInstance():removeEventListenerByList(self.events)
        CFrameDataHandler:getInstance():removeNotifyListener(self)
        
        self._isRunning = false
    end
    if self.enter_bg ~= nil then
        local eventDispatcher = cc.Director:getInstance():getEventDispatcher()
        eventDispatcher:removeEventListener(self.enter_bg)
        eventDispatcher:removeEventListener(self.enter_fg)
        self.enter_bg = nil
        self.enter_fg = nil
    end
end

return GameSeverManager