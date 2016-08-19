--聊天记录
ChatRecordPool = class("ChatRecordPool")
local CMD_Server_Chat = import("app/cmd/loginSever/CMD_Server_Chat.lua")
--ChatRecordPool.chatRecord = {["100103"] = {["user"] = "aaaaaaa",["friend"] = "aaaaaaa",["isHaveRead"] = false},["100104"] = {["user"] = "aaaaaaa",["friend"] = "aaaaaaa",["isHaveRead"] = false}}
ChatRecordPool.events = {
}
function ChatRecordPool:ctor()
    self.chatRecord = {
--       ["1001029"] = {{"user", 2},{"friend", 1},["isHaveRead"] = true},
--       ["100104"] = {{"user", "aaaaaa"},{"friend", "bbbbbbb"},["isHaveRead"] = false}
    }
    self.IsInChatUserGameID = nil
end

function ChatRecordPool:start()
    if not self._isRunning then
        self._isRunning = true
        CFrameDataHandler:getInstance():addNotifyListener(self)
    end
end


function ChatRecordPool:OnTCPWithDataRoom(notify)
    if notify:getMainType() == CMD_Server_Chat.MDM_GR_QUERY then
        local sub = notify:getSubType()
        if sub == CMD_Server_Chat.SUB_GF_FRIENT_TIMELY_CHAT then    --实时聊天
            return self:OnSocketSubChat(notify)
        end
    end
    return false
end


--根据好友ID查询聊天记录
function ChatRecordPool:getRecordByFriendID(id)
    local aaa = self.chatRecord
    for k,v in pairs(self.chatRecord) do
        if tonumber(k) == id then
			return v
		end
	end
	return {}
end

function ChatRecordPool:OnSocketSubChat(notify)
	printLog("aaaa","abcdefg")
--    local notify = event._userData
    if notify:getSize() == 0 then
        print("no chat")
    else
        local cmd = CMD_Server_Chat.CMD_MB_ChatOption:createWithNotify(notify)
        local which = false
        if cmd.info.dwSendGameID == GameManager:getUserSelf():getGameID() then
            which = true
        end
        local chat_word
        if cmd.info.szMsg == "" then
            chat_word = cmd.info.wExpression            --表情
        else
            chat_word = cmd.info.szMsg                  --文字
        end
        self:insertRecordToFriend(cmd.info.dwSendGameID,cmd.info.dwRecvGameID,which,chat_word)
        
        local chat_ = {cmd.info.dwSendGameID,chat_word}                
        CFrameDataHandler:getInstance():dispatchEvent({name = "getChatMessage_friendsLayer",_userData=chat_}) 
        CFrameDataHandler:getInstance():dispatchEvent({name = "getChatMessage_hallScene",_userData=chat_}) 
        CFrameDataHandler:getInstance():dispatchEvent({name = "getChatMessage_talkLayer",_userData=chat_}) 
    end
end

--是否有未读的聊天
function ChatRecordPool:isHaveUnRead(id)        
	local rec = self:getRecordByFriendID(id)
    return rec["isHaveRead"]
end

--设置已读
function ChatRecordPool:setHasRead(id)        
    local rec = self:getRecordByFriendID(id)
    rec["isHaveRead"] = false
end

--添加聊天记录 which = true 自己       which = false 好友
function ChatRecordPool:insertRecordToFriend(send_id,recv_id,which,content)
    local re = {}
    local id = nil

    if which then
        re = {"user",content}
        id = recv_id
    else
        re = {"friend",content}
        id = send_id
    end
    
    for k,v in pairs(self.chatRecord) do
        if tonumber(k) == id then
            table.insert(v,re)
            if self.IsInChatUserGameID ~= send_id and GameManager:getUserSelf():getGameID() ~= send_id then
                v["isHaveRead"] = true
            end
            return
        end
    end
    self.chatRecord[tostring(id)] = {}      --记录
    if self.IsInChatUserGameID ~= send_id and GameManager:getUserSelf():getGameID() ~= send_id then
       self.chatRecord[tostring(id)]["isHaveRead"] = true
    end
    table.insert(self.chatRecord[tostring(id)],re)
    local ttt = self.chatRecord
    return self.chatRecord 
end

function ChatRecordPool:getInstance()
    if self._instance == nil then
        self._instance = ChatRecordPool:create()
    end
    return self._instance
end

function ChatRecordPool:stop()
    if self._isRunning then
        CFrameDataHandler:getInstance():removeNotifyListener(self)
        self._isRunning = false
    end
end

function ChatRecordPool:destroyInstance()
    if self._instance == nil then
        self._instance:stop()
        self._instance = nil
    end
    return self._instance
end 

return ChatRecordPool