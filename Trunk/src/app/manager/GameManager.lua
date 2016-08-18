
GameManager = {}

local Project = import("app/models/project/Project.lua")
local RoomManager = import("app/manager/RoomManager.lua")
local UserManager = import("app/manager/UserManager")
local GameSeverManager = import("app/manager/GameSeverManager")

local LoadingNiu = import("app/views/animate/LoadingNiu")
local PopupLayer = import("app/views/layer/PopupLayer.lua")
local Timer = import("app/library/Timer.lua")
local CMD_Room_User = import("app/cmd/room/CMD_Room_User.lua")

GameManager.events = {
}

GameManager.transferState = -1  --控制状态
GameManager.gameCount = 0       --游戏次数

GameManager.chatRecord = {}         --聊天记录
GameManager.BankerWinOrLose = {-1,-1,-1,-1}    --一场比赛庄家胜负

GameManager.accountType = 0

GameManager.isFriendsListLayer = false        --是否在好友列表界面
GameManager.isOnline = false                  --是否在线
GameManager.cbAdviceUpdate = nil              --建议更新

-------
--权限
GameManager.isOpenStorage = 0           --是否开通仓库
GameManager.isCanSendGift = 0           --是否可以赠送礼物
GameManager.isCanAddFriend = 0          --是否可以添加好友
GameManager.isOpenYYL = 0               --是否开通摇摇乐
GameManager.isOpenSlot = 0              --是否开通水果机
---------//

---------------------------
--@param 
--@return
function GameManager:setGameDelegate(delegate)
	self._gameDelegate = delegate
end

---------------------------
--@param self
--@return GameDelegate#GameDelegate ret (return value: GameDelegate)
function GameManager:getGameDelegate()
    return self._gameDelegate
end

---------
-- 获取当前房间ID
function GameManager:getKindID()
    return self._kindID
end

---------
-- 设置当前房间ID
function GameManager:setKindID(kindID)
    self._kindID = kindID
end

---------
-- 获取工程配置
-- @return #Project Project
function GameManager:getProject()
	if self._project == nil then
--	    local Project = import("app/models/project/Project.lua")
        self._project = Project:create()
	end
    return self._project
end

function GameManager:getRoomServer()
    if self._roomManager == nil then
        self._roomManager = RoomManager:create()
--        self._roomManager:start()
    end
    return self._roomManager
end

---------------------------
-- 获取用户实例
-- @param self
-- @return UserData#UserData ret (return value: UserData)
function GameManager:getUserSelf()
--    if self._selfInstance == nil then
----        self._selfInstance = UserData:create()
--        GameManager:getUserManager():setUserItem(self._selfInstance)
    return GameManager:getUserManager():getUserItem(self._selfUserID)
--    end
    
--    return self._selfInstance
end

function GameManager:getUserSelfID()
    return self._selfUserID
end

function GameManager:setUserSelfID(id)
    self._selfUserID = id
end

function GameManager:setGameStatus(status)
    self._gameStatus = status
end

function GameManager:getGameStatus()
    return self._gameStatus
end

function GameManager:getUserManager()
    if self._userManager == nil then
        self._userManager = UserManager:create()
        self._userManager:start()
    end
    return self._userManager
end

function GameManager:getGameServer()
    if self._gameSever == nil then
        self._gameSever = GameSeverManager:create()
--        self._gameSever:start()
    end
    return self._gameSever
end

function GameManager:destroyGameSever()
    if self._gameSever ~= nil then
        self._gameSever:destroy()
        self._gameSever =  nil
    end
end

function GameManager:showLoading(parentNode,callback)

    self:hideLoading()
    
    --   wifi下不显示loading
--    if jt.SDKControl:getInstance():getWifiState() == 3 then
--        return
--    else
        if self._loadingNiu == nil then
            self._loadingNiu = LoadingNiu:create()
--          self._loadingNiu:retain()
        end
        
        if self._loadingNiu:getParent() == nil then
            self._loadingNiu:addTo(parentNode)
            self._loadingNiu:show()
        end
        
--    end
    
    
    if self._loadingTimer == nil then
        
        callback = callback or handler(self,self.timerOut)
        self._loadingTimer = Timer:create(parentNode,callback,25)--服务器连接超时关闭
        self._loadingTimer:start()
--    else
--        self._loadingTimer:reset()
    end
    
    return self._loadingNiu,self._loadingTimer
end

function GameManager:timerOut()
    self:showAlertSystem(self._loadingNiu:getParent(),"连接超时")
    self:hideLoading()
end

function GameManager:getFriendsList()
    GameManager:getUserSelf().friendsList = {}
    CFrameDataHandler:getInstance():sendPacketWithLoadFriendList()      --获取好友列表
end

function GameManager:getFriendsBlackList()
    GameManager:getUserSelf().blackList = {}
    CFrameDataHandler:getInstance():sendPacketWithLoadBlackList()      --获取好友列表
end

function GameManager:ReceiveResurrection(wTypeReq)
    CFrameDataHandler:getInstance():ReceiveResurrection(GameManager:getUserSelf():getGameID(),wTypeReq)    --复活金操作
end

function GameManager:hideLoading()
    if self._loadingNiu ~= nil then
        self._loadingNiu:removeFromParent()
        self._loadingNiu = nil
    end
    
    if self._loadingTimer ~= nil then
        self._loadingTimer:stop()
        self._loadingTimer = nil
    end
    
end

function GameManager:showAlert(parentNode,title,content,callback,param)
--    self:hideAlert()
    if self._alert == nil then
        self._alert = PopupLayer:create():addTo(parentNode)
        self._alert:show(title,content,callback,param)
    end
    return self._alert
end

function GameManager:showAlertSystem(parentNode,content,callback,param)
--    self:hideAlert()
    if self._alert == nil then
        self._alert = PopupLayer:create():addTo(parentNode)
        self._alert:show("系统提示",content,callback,param)
    end
    return self._alert
end

function GameManager:hideAlert()
	if self._alert ~= nil then
	    self._alert:destroy()
        self._alert = nil
	end
end

function GameManager:setTransitionScene(scene)
    self.TransitionScene = scene
end

function GameManager:getTransitionScene()
    return self.TransitionScene
end

function GameManager:showHornMsg(parent)
--    if self._hornLayer == nil then
--       self._hornLayer:create()
--       self._hornLayer:retain()
--    end
--    self._hornLayer:addTo(self)
end


function GameManager:onInviteGame(roomName,user,chairID)
    if GameManager:getUserManager():getTableUserCount() >= GameManager:getUserManager().nChairCount then
        GameManager:showAlert(GameManager:getGameDelegate(),"好友邀请","本桌游戏人数已满，不可进行邀请")
    else
        local gameID = user:getGameID()
        local user = GameManager:getUserManager():searchUserByGameID(gameID)
        if user == nil then

        elseif user:getTableID() ~= INVALID_TABLE and user:getTableID() == GameManager:getUserSelf():getTableID() then
            GameManager:showAlert(GameManager:getGameDelegate(),"好友邀请","对方已经在本桌游戏中，不可重复邀请")
            return
        end
        local item = GameManager:getRoomServer():getRoomByName(roomName)
        local cmd = CMD_Room_User.CMD_MB_FriendInvite:create()
        cmd.cbDataFrom = 0
        cmd.wKindID = item:wKindID()
        cmd.wServerID = item:wServerID()
        cmd.wTableID = GameManager:getUserSelf():getTableID()
        cmd.wChairID = chairID
        cmd.dwGameID = GameManager:getUserSelf():getGameID()
        cmd.dwFriendID = gameID
        cmd.szNickName = GameManager:getUserSelf():getNickName()
        cmd.szRoomName = item:szServerName()
        CFrameDataHandler:getInstance():SendSocketData(CMD_Room_User.MDM_GR_QUERY,CMD_Room_User.SUB_GF_FRIEND_INVITE,cmd)
    end
end

function GameManager:isPlatformControl(logonType)
    if device.platform ~= "android" then
        return false
    end
    local p = jt.SDKControl:getInstance():getSDKPlatform()
    if p == 1 then
        return true
    else

    end
    return false
end


function GameManager:destroy()
    if GameManager._gameSever ~= nil then
        GameManager._gameSever:destroy()
    end
    if GameManager._roomManager ~= nil then
        GameManager._roomManager:destroy()
    end
    if self._userManager ~= nil then
        self._userManager:destroy()
    end
    CFrameDataHandler:destroy()
end

function GameManager:exitGame()
    cc.Director:getInstance():endToLua()
end

return GameManager
