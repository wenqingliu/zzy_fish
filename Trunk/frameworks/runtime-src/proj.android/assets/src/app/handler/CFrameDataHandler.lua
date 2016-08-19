local CMD_Server_Logon = import("app/cmd/loginSever/CMD_Server_Logon.lua")
local CMD_Sever_Friends = import("app/cmd/loginSever/CMD_Sever_Friends.lua")
local CMD_Server_Chat = import("app/cmd/loginSever/CMD_Server_Chat.lua")
local CMD_Server_Gift = import("app/cmd/loginSever/CMD_Server_Gift.lua")
local CMD_Server_Bank = import("app/cmd/loginSever/CMD_Server_Bank.lua")
local CMD_Server_Mail = import("app/cmd/loginSever/CMD_Server_Mail.lua")
local CMD_Server_Task = import("app/cmd/loginSever/CMD_Server_Task.lua")
local CMD_Server_share = import("app/cmd/loginSever/CMD_Server_share.lua")
local CMD_Server_VIP = import("src/app/cmd/loginSever/CMD_Server_VIP.lua")
local CMD_Server_Shop = import("src/app/cmd/loginSever/CMD_Server_Shop.lua")
local CMD_Server_NewYear = import("app/cmd/loginSever/CMD_Server_NewYear.lua")
local CMD_Server_Dragon = import("app/cmd/loginSever/CMD_Server_Dragon.lua")
local CMD_Room_User = import("app/cmd/room/CMD_Room_User.lua")
local CMD_Game_Server = import("app/cmd/room/CMD_Game_Server.lua")
local CMD_Server_Rank = import("app/cmd/loginSever/CMD_Server_Rank.lua")

local SDKControlHandler = import("app/handler/SDKControlHandler.lua")

--------------
-- 数据通讯事件类(C++/Lua)
CFrameDataHandler = CFrameDataHandler or class("CFrameDataHandler", cc.load("mvc").ViewBase)
local DataType = {
    Data_Default    = 0,       --默认
    Data_Load       = 1,       --登录命令
    Data_Room       = 2,       --房间命令
}

function CFrameDataHandler:onCreate()
    ScriptHandlerMgr:getInstance():registerScriptHandler(jt.CFrameData:getInstance():getSender(),
        handler(self,self.SocketDelegateWithRecvData),cc.Handler.CALLFUNC)
    cc.bind(self, "event")
    
    self.listenerList = {} --事件列表
    
    self:initConfig()
end

function CFrameDataHandler:initConfig()
    --设置工程数据
    local pro = GameManager:getProject()
    jt.CFrameData:getInstance():setLoginAddress(pro.LoginAddress)
    jt.CFrameData:getInstance():setLoginPort(pro.LoginPort)
    jt.CFrameData:getInstance():setValidateKey(pro.LogonValidateKey)
    jt.CFrameData:getInstance():setKindID(pro.AppId)
    jt.CFrameData:getInstance():setDeviceType(pro:getDeviceType())
    jt.CFrameData:getInstance():setPlazaVersion(pro:getVersionClient())
    
    --设置版本
    local nowVersion = cc.UserDefault:getInstance():getStringForKey("current-version-code","")
    if nowVersion ~= "" then
        local now1,now2,now3 = GameManager:getProject():getVersionList(nowVersion)
        local cur1,cur2,cur3 = GameManager:getProject():getVersionList(GameManager:getProject().Versions)
        local isUpdate = false
        if cur1 > now1 then
            isUpdate = true
        elseif cur1 == now1 and cur2 > now2 then
            isUpdate = true
        elseif cur1 == now1 and now2 == cur2 and cur3 > now3 then
            isUpdate = true
        end
        if isUpdate then
            --新装版本
            cc.UserDefault:getInstance():setStringForKey("current-version-code",GameManager:getProject().Versions)
            cc.UserDefault:getInstance():flush()
        else
            pro.Versions = nowVersion
        end
    end
    jt.CFrameData:getInstance():setHotVersion(pro.Versions)
    
end

---------
--添加消息处理
function CFrameDataHandler:addNotifyListener(listener)
    if listener.OnTCPWithDataLoad ~= nil or listener.OnTCPWithDataRoom ~= nil then
        table.insert(self.listenerList,#self.listenerList+1,listener)
    else
        assert(false,"对象未实现事件接口方法")
    end
end

---------
--移除目标对象
function CFrameDataHandler:removeNotifyListener(listener)
    for i=#self.listenerList,1,-1 do
        if self.listenerList[i] == listener then
            return table.remove(self.listenerList,i)
        end
    end
end

---------
-- C++发送过来的数据处理
function CFrameDataHandler:SocketDelegateWithRecvData(notify)
    local typeData = notify:getTypeData()
    local isCheck = nil
    local listener = nil
    
    if typeData == DataType.Data_Default then
        --默认处理
        self:dispatchCustomEvent(notify)
        isCheck = true
    elseif typeData == DataType.Data_Load then --登录服务器消息命令
        for i=#self.listenerList,1,-1 do
            listener = self.listenerList[i]
            if listener.OnTCPWithDataLoad ~= nil then
                isCheck = listener:OnTCPWithDataLoad(notify)
                if isCheck ~= false then
                    printf("消息处理函数:%s:OnTCPWithDataLoad,mainType:%d,subType:%d",listener.__cname,notify:getMainType(),notify:getSubType())
                    break
                end
            end
        end
        if notify:getMainType() == 3 then --用户服务
            notify:getObject():setSocketClose()
        end
    elseif typeData == DataType.Data_Room then --房间消息
        for i=#self.listenerList,1,-1 do
            listener = self.listenerList[i]
            if listener.OnTCPWithDataRoom ~= nil then
                isCheck = listener:OnTCPWithDataRoom(notify)
                if isCheck then
                    printf("消息处理函数:%s:OnTCPWithDataRoom,mainType:%d,subType:%d",listener.__cname,notify:getMainType(),notify:getSubType())
                    break
                end
            end
        end
    end
    if not isCheck then
        if isCheck == nil then
            printf("消息处理-return有误：typeData:%d,mainType:%d,subType:%d",typeData,notify:getMainType(),notify:getSubType())
        else
            printf("消息处理-未处理的命令：typeData:%d,mainType:%d,subType:%d",typeData,notify:getMainType(),notify:getSubType())        
        end
    end
end

function CFrameDataHandler:removeEventListenerByList(events)
    for eventName in pairs(events) do
        self:removeEventListenersByEvent(eventName)
    end
end

---------------------------
-- @param self
-- @param #jt.CNotify notify
function CFrameDataHandler:dispatchCustomEvent(notify)
    self:dispatchEvent({name = notify:getEventName(),_userData=notify})
end

function CFrameDataHandler:doConnect()
    jt.CFrameData:getInstance():doConnect()--链接
    jt.CFrameData:getInstance():sendPacketWithCompilatio()--验证
end


----------------------
-- 发送数据(C++)
function CFrameDataHandler:sendData(wMainCmdID,wSubCmdID,ref)
    jt.CFrameData:getInstance():sendData(wMainCmdID,wSubCmdID,ref)
end


----------------------
-- 发送数据
function CFrameDataHandler:SendSocketData(wMainCmdID,wSubCmdID,cmd)
    local buffer,size = self:createTCPBuffer(wMainCmdID,wSubCmdID,cmd)
    --发送数据
    jt.CFrameData:getInstance():sendSocketData(buffer,size)
end

function CFrameDataHandler:createTCPBuffer(wMainCmdID,wSubCmdID,cmd)
    --创建tcp命令
    local buffer = jt.TCP_BufferRef:createWithNotify()

    --设置数据包头命令信息
    buffer:setMainCmdID(wMainCmdID)
    buffer:setSubCmdID(wSubCmdID)

    --写入数据
    local size = 0
    if cmd ~= nil then
        local byte = jt.ByteArray:createWithPacket(buffer)
        cmd:writeToByteArray(byte)
        size = byte:getPosition()
    end
    return buffer,size
end



-------------------------------我是分割线(发数据)------------------------------------------------------

--查询在线房间 
function CFrameDataHandler:sendPacketWithQueryPlayingRoom()
    local cmd = CMD_Server_Logon.CMD_MB_Query_In_GameRoom:create()
    cmd.dwUserID = GameManager:getUserSelfID()
    local pFrameData = GameManager.logonCFrame
    if pFrameData == nil or GameManager.logonCFrame.isSocketClosed == nil then --兼容旧版
        pFrameData = jt.CFrameData:createFrameData()
        pFrameData:doConnect()
        pFrameData:sendPacketWithCompilatio()
    end
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Server_Logon.SUB_MB_QUERY_PLAYING_ROOM,cmd))
end

--房间列表
function CFrameDataHandler:sendPacketWithLoadRoomServer()
    local pFrameData = GameManager.logonCFrame
    if pFrameData == nil or GameManager.logonCFrame.isSocketClosed == nil then --兼容旧版
        pFrameData = jt.CFrameData:createFrameData()
        pFrameData:doConnect()
        pFrameData:sendPacketWithCompilatio()
    end
    pFrameData:sendSocketData(self:createTCPBuffer(101,101,nil))
end

--好友列表
function CFrameDataHandler:sendPacketWithLoadFriendList()
    local option = CMD_Sever_Friends.CMD_MB_FriendOption:create()
    local userSelf = GameManager:getUserSelf()
--    option.dwUserID = userSelf:getUserID()
    option.dwGameID = userSelf:getGameID()
--    option.dwFriendUserID = 0
    option.dwFriendID = 0
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_MB_LOAD_FRIEND_LIST,option))
end

--黑名单
function CFrameDataHandler:sendPacketWithLoadBlackList()
    local option = CMD_Sever_Friends.CMD_MB_FriendOption:create()
    local userSelf = GameManager:getUserSelf()
--    option.dwUserID = userSelf:getUserID()
    option.dwGameID = userSelf:getGameID()
--    option.dwFriendUserID = 0
    option.dwFriendID = 0
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_MB_FRIENT_BLACKLIST,option))
end
--推荐好友列表
function CFrameDataHandler:sendPacketWithLoadRecommendFriendList()
    local option = CMD_Sever_Friends.CMD_MB_FriendOption:create()
    local userSelf = GameManager:getUserSelf()
--    option.dwUserID = userSelf:getUserID()
    option.dwGameID = userSelf:getGameID()
--    option.dwFriendUserID = 0
    option.dwFriendID = 0
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_MB_FRIENT_SYS_RECOMMEN,option))
end

--添加好友(申请好友)
function CFrameDataHandler:sendPacketWithLoadAddFriend(userGameID)
--    local option = CMD_Sever_Friends.CMD_MB_FriendOption:create()
--    local userSelf = GameManager:getUserSelf()
----    option.dwUserID = userSelf:getUserID()
--    option.dwGameID = userSelf:getGameID()
----    option.dwFriendUserID = 0
--    option.dwFriendID = userGameID
--    local pFrameData = jt.CFrameData:createFrameData()
--    pFrameData:doConnect()
--    pFrameData:sendPacketWithCompilatio()
--    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_MB_FRIENT_ADD_FRIENDLY,option))
    local option = CMD_Sever_Friends.CMD_MB_FriendOption:create()
    local user = GameManager:getUserSelf()
    option.dwGameID = user:getGameID()
    option.dwFriendID = userGameID
    self:SendSocketData(CMD_Sever_Friends.MDM_GR_INSURE,CMD_Sever_Friends.SUB_GR_FRIEND_REQ,option)
end

--待验证好友列表
function CFrameDataHandler:sendPacketWithLoadUnverifiedList()
    local option = CMD_Sever_Friends.CMD_GR_C_Query_Friend_Unverified:create()
    local userSelf = GameManager:getUserSelf()
    option.dwGameID = userSelf:getGameID()
    self:SendSocketData(CMD_Sever_Friends.MDM_GR_INSURE,CMD_Sever_Friends.SUB_GR_Query_Friend_Unverified,option)
end

--验证好友(choose ：同意还是拒绝)
function CFrameDataHandler:sendPacketWithLoadVerifrid(friendID,choose)
    local option = CMD_Sever_Friends.CMD_GR_C_Verifiend:create()
    local userSelf = GameManager:getUserSelf()
    option.dwGameID = userSelf:getGameID()
    option.dwFriendID = friendID
    option.dwStatus = choose                      --0同意,1`拒绝
    self:SendSocketData(CMD_Sever_Friends.MDM_GR_INSURE,CMD_Sever_Friends.SUB_GR_FRIEND_Verified,option)
end

--搜索好友
function CFrameDataHandler:sendPacketWithLoadSearchFriend(userGameID)
    local option = CMD_Sever_Friends.CMD_MB_FriendOption:create()
    local userSelf = GameManager:getUserSelf()
--    option.dwUserID = userSelf:getUserID()
    option.dwGameID = userSelf:getGameID()
--    option.dwFriendUserID = 0
    option.dwFriendID = userGameID
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_MB_FRIENT_QUERY_USER,option))
end
--添加黑名单
function CFrameDataHandler:sendPacketWithLoadAddToBlackList(userGameID)
    local option = CMD_Sever_Friends.CMD_MB_FriendOption:create()
    local userSelf = GameManager:getUserSelf()
--    option.dwUserID = userSelf:getUserID()
    option.dwGameID = userSelf:getGameID()
--    option.dwFriendUserID = 0
    option.dwFriendID = userGameID
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_MB_FRIENT_ADD_BLACKLIST,option))
end

--删除黑名单
function CFrameDataHandler:sendPacketWithLoadDeleteFromBlackList(userGameID)
    local option = CMD_Sever_Friends.CMD_MB_FriendOption:create()
    local userSelf = GameManager:getUserSelf()
--    option.dwUserID = userSelf:getUserID()
    option.dwGameID = userSelf:getGameID()
--    option.dwFriendUserID = 0
    option.dwFriendID = userGameID
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_MB_FRIENT_REMOVE_BLACKLIST,option))
end

--查询推广号
function CFrameDataHandler:sendPacketWithLoadSpreadried()
    local option = CMD_Sever_Friends.CMD_MB_C_Check_SpreaderID_REQ:create()
    local userSelf = GameManager:getUserSelf()
    option.dwGameID = userSelf:getGameID()
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_MB_USER_CHECK_SPREADERID_REQ,option))
end

--添加推广号
function CFrameDataHandler:sendPacketWithLoadAddSpreadried(SpreadriedID)
    local option = CMD_Sever_Friends.CMD_CR_C_AddSpreaderReq:create()
    local userSelf = GameManager:getUserSelf()
    option.dwGameID = userSelf:getGameID()
    option.dwSpreadID = SpreadriedID
    self:SendSocketData(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_GR_USER_ADD_SPREADER_REQ,option)
end

--查询是否推广人
function CFrameDataHandler:sendPacketWithLoadIsSpreadried()
    local option = CMD_Sever_Friends.CMD_C_CHECK_SPREADER_REQ:create()
    local userSelf = GameManager:getUserSelf()
    option.dwUserID = userSelf:getUserID()
    option.dwGameID = userSelf:getGameID()
--    local pFrameData = jt.CFrameData:createFrameData()
--    pFrameData:doConnect()
--    pFrameData:sendPacketWithCompilatio()
--    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Sever_Friends.MDM_GP_USER_SERVICE,CMD_Sever_Friends.SUB_MB_USER_CHECK_SPREADERID_REQ,option))
    self:SendSocketData(CMD_Sever_Friends.MDM_GR_QUERY,CMD_Sever_Friends.SUB_GR_CHECK_SPREADER_REQ,option)
end

--领取推广员分数
function CFrameDataHandler:sendPacketWithLoadDrawSpreadried()
    local option = CMD_Sever_Friends.CMD_C_DRAW_SPREADER_REQ:create()
    local userSelf = GameManager:getUserSelf()
    option.dwUserID = userSelf:getUserID()
    option.dwGameID = userSelf:getGameID()
    self:SendSocketData(CMD_Sever_Friends.MDM_GR_QUERY,CMD_Sever_Friends.SUB_GR_DRAW_SPREADER_REQ,option)
end

-------------------
--与好友聊天
function CFrameDataHandler:SendChat(recvUser,expression,msg)
    local option = CMD_Server_Chat.CMD_MB_ChatOption:create()
    local userSelf = GameManager:getUserSelf()
    option.wExpression = expression
--    option.dwSendUserID = userSelf:getUserID()
    option.dwSendGameID = userSelf:getGameID()
--    option.dwRecvUserID = recvUser:getUserID()
    option.dwRecvGameID = recvUser:getGameID()
    option.szMsg = msg
    self:SendSocketData(CMD_Server_Chat.MDM_GR_QUERY,CMD_Server_Chat.SUB_GF_FRIENT_TIMELY_CHAT,option)
end

----
--获取礼品
function CFrameDataHandler:sendSocketGift()
    local option = CMD_Server_Gift.CMD_MB_GiftOption:create()
    local user = GameManager:getUserSelf()
    option.option = 0
    option.itemType = 0
    option.itemCount = 0
    option.dwUserID = user:getUserID()
    option.dwGameID = user:getGameID()
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Server_Gift.MDM_GP_USER_SERVICE,CMD_Server_Gift.SUB_GP_USER_PAWNSHOP_REQ,option))
end

----
--典当
function CFrameDataHandler:sendSocketPawn(gift_type,num)
    local option = CMD_Server_Gift.CMD_MB_GiftOption:create()
    local user = GameManager:getUserSelf()
    option.option = 2
    option.itemType = gift_type
    option.itemCount = num
    option.dwUserID = user:getUserID()
    option.dwGameID = user:getGameID()
    self:SendSocketData(CMD_Server_Gift.MDM_GR_INSURE,CMD_Server_Gift.SUB_GR_USER_PAWNSHOP_REQUEST,option)
end
----
--赠送礼物
function CFrameDataHandler:giveGift(user,itemType,itemCount,itemPrice)
    --    local option = CMD_Server_Gift.CMD_MB_Gift_send_Option
--    option.dwRecvUserID = user:getGameID()
--    option.dwItemType = itemType - 1
--    option.dwItemCount = itemCount
--    option.dwPrice = itemPrice
--    self:SendSocketData(CMD_Server_Gift.MDM_GR_INSURE,CMD_Server_Gift.SUB_GR_USER_SENT_REQUEST,option)
    
    local option = CMD_Server_Gift.CMD_GR_C_User_Sent_Request:create()
    option.dwRecvGameID = user:getGameID()
    option.dwSentGameID = GameManager:getUserSelf():getGameID()
    option.dwSentUserID = GameManager:getUserSelf():getUserID()
    option.ItemType = itemType-- - 1
    option.ItemCount = itemCount
    
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Server_Gift.MDM_GP_USER_SERVICE,CMD_Server_Gift.SUB_MB_USER_SEND_GIFT_REQ,option))
    end

----
--赠送礼物记录
function CFrameDataHandler:giveGiftRecord()
    local user = GameManager:getUserSelf()
    local option = CMD_Server_Gift.CMD_MB_GiftRecord:create()
    option.dwSourceGameID = user:getGameID()
    option.dwDecGameID = 0
    option.dwTargetID = 0
    option.wNumber = 0
    self:SendSocketData(CMD_Server_Gift.MDM_GR_INSURE,CMD_Server_Gift.SUB_GR_USER_CHECK_GIFT_REQUEST,option)
end

----
--获取任务列表
function CFrameDataHandler:getDailyTaskList()
    local user = GameManager:getUserSelf()
    local option = CMD_Server_Task.CMD_GR_C_GameDayTaskList:create()
    -- option.dwGameID = user:getGameID()
    self:SendSocketData(CMD_Server_Task.MDM_GR_QUERY,CMD_Server_Task.SUB_GF_GAME_CHECK_DAYTASK_REQ,option)
end

function CFrameDataHandler:getWeekTaskList()
    local option = CMD_Server_Task.CM_GR_C_Query_WeekTask:create()
    option.dwUserID = GameManager:getUserSelf():getUserID()
    self:SendSocketData(CMD_Server_Task.MDM_GR_QUERY,CMD_Server_Task.SUB_GF_QUERY_WEEKTASK_REQ,option)
end

---
--获取任务奖励
function CFrameDataHandler:getTaskReward(taskID)
    local user = GameManager:getUserSelf()
    local option = CMD_Server_Task.CMD_GR_C_GameDayTaskReq:create()
    option.dwTaskID = taskID
    option.dwGameID = user:getGameID()
    self:SendSocketData(CMD_Server_Task.MDM_GR_QUERY,CMD_Server_Task.SUB_GF_GAME_DRAW_DAYTASK_REQ,option)
end

---
--获取周任务奖励
function CFrameDataHandler:giveWeekTaskReward(taskID)
    local user = GameManager:getUserSelf()
    local option = CMD_Server_Task.CM_GR_C_Draw_WeekTask:create()
    option.dwUserID = user:getUserID()
    option.cbTaskType = taskID
    self:SendSocketData(CMD_Server_Task.MDM_GR_QUERY,CMD_Server_Task.SUB_GF_DRAW_WEEKTASK_REQ,option)
end

----
--银行查询
function CFrameDataHandler:BankQuery()
    local option = CMD_Server_Bank.CMD_MB_Query:create()
    option.cbActivityGame = 1
    self:SendSocketData(CMD_Server_Bank.MDM_GR_INSURE,CMD_Server_Bank.SUB_GR_QUERY_INSURE_INFO,option)
end

----
--银行存款
function CFrameDataHandler:BankSave(count)
    local option = CMD_Server_Bank.CMD_MB_Save:create()
    option.cbActivityGame = 1
    option.lSaveScore = count
    option.wKindID = 1
    self:SendSocketData(CMD_Server_Bank.MDM_GR_INSURE,CMD_Server_Bank.SUB_GR_SAVE_SCORE_REQUEST,option)
end

----
--银行取款
function CFrameDataHandler:BankTake(count)
    local option = CMD_Server_Bank.CMD_MB_Take:create()
    option.cbActivityGame = 1
    option.lTakeScore = count
    option.szInsurePass = ""
    option.wKindID = 1
    self:SendSocketData(CMD_Server_Bank.MDM_GR_INSURE,CMD_Server_Bank.SUB_GR_TAKE_SCORE_REQUEST,option)
end

----
--复活金请求
function CFrameDataHandler:ReceiveResurrection(dwGameID,wTypeReq)
    local option = CMD_Server_Bank.CMD_GR_C_ReliveGoldRequest:create()
    option.dwGameID = dwGameID
    option.wTypeReq = wTypeReq
    self:SendSocketData(CMD_Server_Bank.MDM_GR_INSURE,CMD_Server_Bank.SUB_GR_USER_RELIVE_GOLD_REQUEST,option)
end

---
-----邮件请求
function CFrameDataHandler:getMailList()
    local option = CMD_Server_Mail.CMD_MB_MailOption:create()
    local user = GameManager:getUserSelf()
    option.dwGameID = user:getGameID()
    option.dwUserID = user:getUserID()
    self:SendSocketData(CMD_Server_Mail.MDM_GR_QUERY,CMD_Server_Mail.SUB_GR_C_EMAIL_MESSAGE,option)
end

-----邮件奖励请求
function CFrameDataHandler:getMailReward(mailID)
    local option = CMD_Server_Mail.CMD_MB_REQ_MailReward:create()
    local user = GameManager:getUserSelf()
    option.dwUserID = user:getUserID()
    option.dwGameID = user:getGameID()
    option.wMessageID = mailID
    self:SendSocketData(CMD_Server_Mail.MDM_GR_QUERY,CMD_Server_Mail.SUB_MB_S_EMAIL_MESSAGE_RECV,option)
end

----
--分享成功
function CFrameDataHandler:shareSuccess(Platform)
    local option = CMD_Server_share.CMD_Server_Success:create()
    local user = GameManager:getUserSelf()
    option.wKindID = GameManager:getProject().AppId
    option.wPlatformID = Platform
    option.dwUserID = user:getUserID()
    self:SendSocketData(CMD_Server_share.MDM_GR_QUERY,CMD_Server_share.SUB_GF_FRIENT_TIMELY_CHAT,option)
end

--VIP  0:查询、1:领取
function CFrameDataHandler:VIPInfo(which)
    local option = CMD_Server_VIP.CMD_GR_C_USER_VIP_REQUEST:create()
    local user = GameManager:getUserSelf()
    option.op = which
    option.dwUserID = user:getUserID()
    option.dwGameID = user:getGameID()
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Server_VIP.MDM_GP_USER_SERVICE,CMD_Server_VIP.SUB_MB_USER_VIP_REQ,option))
end

--获取VIP等级和喇叭数量
function CFrameDataHandler:getVIPAndHornNum()
    local option = CMD_Server_VIP.CMD_MB_C_VIPSOUNA:create()
    local user = GameManager:getUserSelf()
    option.dwUserID = user:getUserID()
    option.dwGameID = user:getGameID()
    self:SendSocketData(CMD_Server_VIP.MDM_GR_INSURE,CMD_Server_VIP.SUB_MB_USER_VIPSOUNA,option)
end

--发送喇叭
function CFrameDataHandler:sendUserHorn(szchat)
    local option = CMD_Game_Server.CMD_GR_C_SendTrumpet:create()
    option.cbRequestArea = 4
    option.TrumpetColor = 0xff000000
    option.dwSendUserID = GameManager:getUserSelfID()
    option.wPropertyIndex = 19
    option.szTrumpetContent = szchat
    self:SendSocketData(3,305,option)
--    jt.CFrameData:getInstance():sendUserHorn(szchat)
end

---
--龙珠摇奖请求
function CFrameDataHandler:getDragonBallInfo()
    self:SendSocketData(CMD_Server_Dragon.MDM_GR_QUERY,CMD_Server_Dragon.SUB_GF_DRAGON_BALL_REQ,nil)
end
---
--龙珠摇奖开始
function CFrameDataHandler:getDragonBallStart()
    self:SendSocketData(CMD_Server_Dragon.MDM_GR_QUERY,CMD_Server_Dragon.SUB_GF_START_DRAGON,nil)
end

---
--龙珠摇奖兑换
function CFrameDataHandler:getDragonBallDuihuan()
    self:SendSocketData(CMD_Server_Dragon.MDM_GR_QUERY,CMD_Server_Dragon.SUB_GF_DRAGON_EXCHANGE,nil)
end
----------------------

-------
--获取或购买道具(商店)
function CFrameDataHandler:getPropList(which,dwItemType,dwItemCount)
    local option = CMD_Server_Shop.CMD_GR_C_USER_SALESHOP_REQUEST:create()
    option.dwOperate = which--查询
    option.dwItemType = dwItemType
    option.dwItemCount = dwItemCount
    option.dwUserID = GameManager:getUserSelf():getUserID()
    option.dwGameID = GameManager:getUserSelf():getGameID()
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Server_Logon.MDM_GP_USER_SERVICE,CMD_Server_Shop.SUB_MB_SALESHOP_REQ,option))
end

-----
--钻石换金币
function CFrameDataHandler:getChargeScore(which,nItemType)
    local option = CMD_Server_Shop.CMD_GR_C_ChargeScore:create()
    option.op = which
    option.dwUserID = GameManager:getUserSelf():getUserID()
    option.dwGameID = GameManager:getUserSelf():getGameID()
    option.nItemType = nItemType
    self:SendSocketData(CMD_Server_Bank.MDM_GR_INSURE,CMD_Server_Shop.SUB_GR_USER_CHARGE_SCORE,option)
end

--玩家上下线 1-在线  0-不在线
function CFrameDataHandler:UserOnline(which)
    local option = CMD_Sever_Friends.CMD_MB_FriendStatus:create()
    option.cbStatus = which
    option.dwUserID = GameManager:getUserSelf():getUserID()
    option.dwGameID = GameManager:getUserSelf():getGameID()
    option.dwVipLevel = GameManager:getUserSelf():getMemberOrder()
    option.szNickName = GameManager:getUserSelf():getNickName()
    self:SendSocketData(CMD_Sever_Friends.MDM_GR_QUERY,CMD_Sever_Friends.SUB_MB_FRIENT_TIMELY_STATUS,option)
end

---获取大厅红点信息
function CFrameDataHandler:getHallInfo()
    self:SendSocketData(CMD_Server_Mail.MDM_GR_QUERY,CMD_Server_Mail.SUB_GF_SYS_GAME_INFORM,nil)
end

---------
-- 排行榜
function CFrameDataHandler:getRankData()
    local option = CMD_Server_Rank.CMD_MB_GetScoreList:create()
    option.dwUserID = GameManager:getUserSelfID()
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Server_Logon.MDM_GP_USER_SERVICE,CMD_Server_Rank.SUB_MB_SCORE_LIST_REQUEST,option))
end

-------
--查询个人信息
function CFrameDataHandler:getPersonInfo(dwDstGameID)
    local option = CMD_Server_Logon.CMD_MB_QueryIndividual:create()
    option.dwSrcGameID = GameManager:getUserSelf():getGameID()
    option.dwDstGameID = dwDstGameID
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(self:createTCPBuffer(CMD_Server_Logon.MDM_GP_USER_SERVICE,CMD_Server_Logon.SUB_MB_QUERY_INDIVIDUAL,option))
end

------
--起立(离开游戏)
function CFrameDataHandler:sendPacketWithStandUpLeave()
    GameManager:getGameServer():onGameBack()
   --[[ if GameManager:getUserSelf():getChairID() ~= INVALID_CHAIR then
        jt.CFrameData:getInstance():sendPacketWithStandUpLeave(1)--发送起立(离开游戏)
    else
        if GameManager:getGameDelegate() ~= nil then
            print("起立失败，用户未坐下，直接返回大厅")
            jt.CFrameData:getInstance():setSocketClose(true)
            GameManager:getRoomServer():onBackHall(GameManager:getGameDelegate():getApp())
        end
    end]]--
end

----------------------
--
-- @return CFrameDataHandler#CFrameDataHandler ret (return value: CFrameDataHandler)
function CFrameDataHandler:getInstance()
    if self._instance == nil then
        self._instance = CFrameDataHandler:create()
        self._instance:retain()
    end
    return self._instance
end

function CFrameDataHandler:destroy()
    if self._instance ~= nil then
        ScriptHandlerMgr:getInstance():unregisterScriptHandler(jt.CFrameData:getInstance():getSender(),cc.Handler.CALLFUNC)
        self._instance:release()
        self._instance = nil
    end
end

return CFrameDataHandler
