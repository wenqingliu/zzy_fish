local RoomManager = class("RoomManager")
local SDKControlHandler = import("app/handler/SDKControlHandler.lua")

local HallSceneData = import("app/models/data/hall/HallSceneData.lua")
local LoginSceneData = import("app/models/data/login/LoginSceneData.lua")
local UserData = import("app/models/data/UserData")

local scheduler = import("app/library/scheduler.lua")

local CMD_Server_Logon = import("app/cmd/loginSever/CMD_Server_Logon.lua")
local CMD_Game_Server = import("app/cmd/room/CMD_Game_Server.lua")

RoomManager.events = {
    ccNd_Socket_ConnectResult = "ccNd_Socket_ConnectResult",        --网络连接结果
}

--行为标示
RoomManager.wBehaviorFlags = {
    VIEW_MODE_ALL = 0x0001,             --全部可视
    VIEW_MODE_PART = 0x0002,            --部分可视
    BEHAVIOR_LOGON_NORMAL = 0x0000,     --普通登录
    BEHAVIOR_LOGON_IMMEDIATELY = 0x1000 --立即登录
}

function RoomManager:ctor()
    self.roomList = {}
    self.messageServer = nil
    self.isStart = false
    self.playingRoom = nil
end

function RoomManager:start()
    --注册事件
    if not self.isStart then
        self.isStart = true
        CFrameDataHandler:getInstance():addEventListener(self.events.ccNd_Socket_ConnectResult,handler(self,self.onNetError))
        CFrameDataHandler:getInstance():addNotifyListener(self)
    end
    return self
end

function RoomManager:OnTCPWithDataLoad(notify)
    if notify:getMainType() == CMD_Server_Logon.MDM_MB_SERVER_LIST then
        local sub = notify:getSubType()
        if sub == CMD_Server_Logon.SUB_MB_LIST_SERVER then --房间列表
            return self:onRoomListServer(notify)
        elseif sub == CMD_Server_Logon.SUB_MB_USER_PLAYING_ROOM then
            
        end
        return true
    end
    
    if notify:getMainType() == CMD_Server_Logon.MDM_GP_USER_SERVICE then
        local sub = notify:getSubType()
        if sub == CMD_Server_Logon.SUB_MB_USER_PLAYING_ROOM then
            return self:onPlayingRoom(notify)
        elseif sub == 24 then
            --万普推广
            local map = {}
            map.domainURL = "http://" .. GameManager:getProject().LoginAddress ..GameManager:getProject().URLPort
            SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCSendWanpu,map)
            return true
        end
    end
    
    return false
end

function RoomManager:OnTCPWithDataRoom(notify)
    local sub = notify:getSubType()
    if notify:getMainType() == CMD_Game_Server.MDM_GR_LOGON then --登录命令 1
        if sub == CMD_Server_Logon.SUB_GR_LOGON_SUCCESS then --登录成功 100
            return true
        elseif sub == CMD_Game_Server.SUB_GR_LOGON_FAILURE then --登录失败 101
            return self:OnSocketSubGRLogonFailure(notify)
        elseif sub == CMD_Game_Server.SUB_GR_LOGON_FINISH then --登录完成  102
            return self:OnSocketSubGRLogonResult(notify)
        end
        return true
    end
    
    if notify:getMainType() == CMD_Game_Server.MDM_GR_CONFIG then --房间配置  2
        if sub == CMD_Game_Server.SUB_GR_CONFIG_SERVER then --房间配置  101
            self:onRoomConfig(notify)
        end
        return true
    end
    
    return false
end

----------
-- 房间列表
function RoomManager:onRoomListServer(notify)
--    local notify = event._userData
--    if notify:getResult() == RT_INGED then
        self:clearRoomList()
        local ser = jt.tagGameServerRef:createWithNotify()
        local structSize = ser:getSize()
        local count = notify:getSize() / structSize
        for i=1,count do
            local server = jt.tagGameServerRef:createWithDataArray(notify,i-1)
            server:retain()
            --同步登录服务器IP
            server:szServerAddr(GameManager:getProject().LoginAddress)
            printf("房间名称:%s wKindID:%d wServerPort:%d wSortID:%d",server:szServerName(),server:wKindID(),server:wServerPort(),server:wSortID())
            if "消息服务器" == server:szServerName() then
                print("连接消息服务器")
                self.messageServer = server
--                self:onLoginMsgServer(server)
            elseif string.find(server:szServerName(),"李逵劈鱼") then --只有捕鱼的房间才放进房间列表
                self.roomList[#self.roomList+1] = server
            end
        end
        --查询在线房间
        CFrameDataHandler:getInstance():sendPacketWithQueryPlayingRoom()
        --消息服务器房间未开启
        --[[if self.messageServer == nil then
            GameManager:hideLoading()
            jt.CFrameData:getInstance():setSocketClose(true)
            if GameManager:getGameDelegate() ~= nil then
                GameManager:showAlert(GameManager:getTransitionScene(),"连接提示","消息服务器未开启，游戏大厅登录失败",handler(self,self.onBackLogin))
            end
            return
        end]]--
    
        --排序
        local function sornID(server1,server2)
            return server1:wSortID() < server2:wSortID()
        end
    
        table.sort(self.roomList,sornID)
--    elseif notify:getResult() == RT_ENDED then
--        self:onLoginMsgServer(self.messageServer)
--    end
    return true
end

-------------
-- 查询在线房间响应
function RoomManager:onPlayingRoom(notify)
--    local notify = event._userData
    local cmd = CMD_Server_Logon.CMD_MB_User_PlayingRoom:createWithNotify(notify)
    
    if GameManager.logonCFrame ~= nil then
        GameManager.logonCFrame:setSocketClose()
        GameManager.logonCFrame = nil
    end
    local isOpenGameRoom = false
    if cmd.cbStatus == 1 then
        local roomList = self:getRoomList()
        for i = 1,#roomList do
            local item = roomList[i]
            if item:szServerName():find(cmd.szGameRoom) ~= nil then
                isOpenGameRoom = true
            end
        end
     end
     
    if cmd.cbStatus ~= 1 or not isOpenGameRoom then
        if self.messageServer ~= nil then
            self:onLoginMsgServer(self.messageServer)
        else
            --消息服务器房间未开启
            GameManager:hideLoading()
            jt.CFrameData:getInstance():setSocketClose(true)
            if GameManager:getGameDelegate() ~= nil then
                GameManager:showAlert(GameManager:getTransitionScene(),"连接提示","消息服务器未开启，游戏大厅登录失败",handler(self,self.onBackLogin))
            end
        end
    else
        --在游戏中未正常退出,显示大厅界面,点击重连游戏房间
        self.playingRoom = cmd.szGameRoom
        if isOpenGameRoom and GameManager:getTransitionScene() ~= nil and GameManager:getKindID() == KIND_ID_MSG then
            GameManager:getTransitionScene():showNextScene()--进入场景 
        end
    end
    
    return true
end

function RoomManager:onRoomConfig(notify)
--	local notify = event._userData
--	if notify:getResult() ~= RT_INGED then return end;
    local cmd = jt.CMD_GR_ConfigServerRef:createWithNotify(notify)
    local mm = GameManager:getUserManager()
    mm:onInitGameInfo(cmd:wChairCount())
    return true
end

------------
-- 房间登录结果
function RoomManager:OnSocketSubGRLogonResult(notify)
--    local notify = event._userData
    
    --启动游戏
    if GameManager:getUserSelf():getChairID() ~= INVALID_CHAIR then
        jt.CFrameData:getInstance():sendPacketWithGameOption()--发送游戏规则
    end
    
    GameManager:getGameServer():setGameClient(0x02)
    
--    if notify:getResult() == RT_ENDED then
        
        --连接消息服务器
        if GameManager:getKindID() == KIND_ID_MSG then
            if GameManager:getTransitionScene() ~= nil then
                GameManager:getTransitionScene():showNextScene()--进入场景 
            end

            --获取VIP
            CFrameDataHandler:getInstance():getVIPAndHornNum()
            
            --发送上线
            if not GameManager.isOnline then
                GameManager.isOnline = true
                CFrameDataHandler:getInstance():UserOnline(1)
            end
            return true
        end
        
        --游戏房间
        if GameManager:getTransitionScene() ~= nil then
            GameManager:getTransitionScene():showNextScene()--进入场景
        end
        
--    elseif notify:getResult() == RT_FAILURE then
--        local function onError(parameters)
--            GameManager:hideAlert()
--        	if GameManager:getTransitionScene() ~= nil then
--                GameManager:getTransitionScene():showPrevScene()--返回
--            end
--        end
--        jt.CFrameData:getInstance():setSocketClose(true)
--        GameManager:setGameDelegate(nil)
--        if GameManager:getTransitionScene() ~= nil then
--            GameManager:showAlertSystem(GameManager:getTransitionScene(),notify:getMainString(),onError)
--        end
--    end
    return true
end

--房间登录失败
function RoomManager:OnSocketSubGRLogonFailure(notify)
    local function onError(parameters)
        GameManager:hideAlert()
        if GameManager:getTransitionScene() ~= nil then
            GameManager:getTransitionScene():showPrevScene()--返回
        end
    end
    jt.CFrameData:getInstance():setSocketClose(true)
    GameManager:setGameDelegate(nil)
    local cmd = CMD_Game_Server.CMD_GR_LogonFailure:createWithNotify(notify)
    if GameManager:getTransitionScene() ~= nil then
        GameManager:showAlertSystem(GameManager:getTransitionScene(),cmd.szDescribeString,onError)
    end
    return true
end

function RoomManager:getRoomList()
    return self.roomList
end

function RoomManager:getMessageServer()
    return self.messageServer
end

function RoomManager:getRoomByName(roomName)
    for i = 1,#self.roomList do
        local item = self.roomList[i]
        if item:szServerName():find(roomName) ~= nil then
            return item
        end
    end
    return nil
end

function RoomManager:getRoomByKindID(kindid)
    for i = 1,#self.roomList do
        local item = self.roomList[i]
        if item:wKindID() == kindid then
            return item
        end
    end
    return nil
end

--设置进入房间目标桌椅
function RoomManager:setTargetTableChair(tableID,chairID)
    self.targetTableID = tableID
    self.targetChairID = chairID
end

function RoomManager:clearTableChair()
    self.targetTableID = nil
    self.targetChairID = nil
end

-------
--登录游戏房间
function RoomManager:onLoginRoom(item,isStartEnable,roomParams)
    --关闭当前连接
    jt.CFrameData:getInstance():setSocketClose(true)
    GameManager:getUserManager():removeRoomUserItem()
    --关闭socker有一定延迟,未关闭前调用会导致报错 ,故需延迟调用
    scheduler.performWithDelayGlobal(0.02,function()
        self.isStartEnable = isStartEnable
        self.roomParams = roomParams
        local wBehaviorFlags = 0
        if isStartEnable then
            wBehaviorFlags = bit.bor(RoomManager.wBehaviorFlags.BEHAVIOR_LOGON_IMMEDIATELY,RoomManager.wBehaviorFlags.VIEW_MODE_PART);
        else
            wBehaviorFlags = RoomManager.wBehaviorFlags.VIEW_MODE_PART
        end
        GameManager:getRoomServer().isEnterRoom = true
        GameManager:getRoomServer().currentRoom = item
        jt.CFrameData:getInstance():sendPacketWithEnterRoomPageCount(wBehaviorFlags,item)
    end)
end

-------
--登录消息服务器
function RoomManager:onLoginMsgServer(item)
    GameManager:getRoomServer().currentRoom = item
	jt.CFrameData:getInstance():sendPacketWithEnterRoomPageCount(RoomManager.wBehaviorFlags.VIEW_MODE_PART,item)
end

-------
--登录游戏大厅
function RoomManager:onLoginHall(app)
    self.tran = app:createView("scene/TransitionScene.lua")
    local sceneData = HallSceneData:create(LoginSceneData.targetScene)
    self.tran:start(sceneData,function()
        
        end)
    self.tran:showWithScene()
end

-------
--返回游戏大厅
function RoomManager:onBackHall(app)
    local function onLogin()
        self.tran = app:createView("scene/TransitionScene.lua")
        local sceneData = HallSceneData:create(LoginSceneData.targetScene)
        self.tran:start(sceneData,function()
                --连接消息服务器
                GameManager:getRoomServer():onLoginMsgServer(GameManager:getRoomServer().messageServer) 
            end)
        self.tran:showWithScene()
    end
    scheduler.performWithDelayGlobal(0.03,onLogin)
end

---------
-- 返回登录界面
function RoomManager:onBackLogin()
    self:clearRoomList()
    if GameManager:getTransitionScene() ~= nil then
        --游戏返回
        GameManager:getTransitionScene():showPrevScene()
    elseif GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():getApp():enterScene(LoginSceneData.targetScene)
    end
end

function RoomManager:onNetError(event)
    local notify = event._userData
    local result = notify:getResult()
    if result == RT_FAILURE then
        GameManager:hideLoading()
        jt.CFrameData:getInstance():setSocketClose()
        GameManager:showAlertSystem(cc.Director:getInstance():getRunningScene(),"网络中断，请检测网络后再次打开，更多疑问请联系客服QQ:33836594",handler(self,self.onBackLogin))
    end
end

function RoomManager:clearRoomList()
    for i=1,#self.roomList do
        local server = self.roomList[i]
        server:release()
    end
    self.messageServer = nil
    GameManager:getRoomServer().currentRoom = nil
    self.roomList = {}
end


function RoomManager:stop()
    self.isStart = false
    CFrameDataHandler:getInstance():removeEventListenerByList(self.events)
    CFrameDataHandler:getInstance():removeNotifyListener(self)
end

function RoomManager:destroy()
    self:stop()
    self:clearRoomList()
end

return RoomManager