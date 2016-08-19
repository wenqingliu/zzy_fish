--聊天
local GCMD_Sever_Chat = {}

GCMD_Sever_Chat.MDM_GR_QUERY                      =    8                                   --查询命令
GCMD_Sever_Chat.SUB_GF_FRIENT_TIMELY_CHAT         =   7                         --好友聊天

--用户操作数据发送
local CMDBase = import("app/cmd/CMDBase.lua")
GCMD_Sever_Chat.CMD_MB_ChatOption = class("CMD_MB_FriendOption",CMDBase)
function GCMD_Sever_Chat.CMD_MB_ChatOption:writeToByteArray(ba)
    ba:writeWORD(                              self.wExpression);                     --表情
--    ba:writeDWORD(                              self.dwSendUserID);                   --发送UserID
    ba:writeDWORD(                              self.dwSendGameID);                   --发送GameID
--    ba:writeDWORD(                              self.dwRecvUserID);                   --接收UserID
    ba:writeDWORD(                              self.dwRecvGameID);                   --接收GameID
    ba:writeTchar(                              self.szMsg,256)                      --消息内容
end
GCMD_Sever_Chat.CMD_MB_ChatOption.info = {}
function GCMD_Sever_Chat.CMD_MB_ChatOption:readFormByteArray(ba)
    self.info.wExpression = ba:readWORD()
    self.info.dwSendUserID = 0                                                  --ba:readDWORD()               
    self.info.dwSendGameID = ba:readDWORD()               
    self.info.dwRecvUserID = 0                                                   --ba:readDWORD()                  
    self.info.dwRecvGameID = ba:readDWORD()            
    self.info.szMsg = ba:readTchar(256)      
end

function GCMD_Sever_Chat.CMD_MB_ChatOption:getSize()
    return 2+4+4+4+4+512
end

return GCMD_Sever_Chat