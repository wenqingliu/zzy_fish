--邮件
local CMD_Server_Mail = {}
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Mail.MDM_GR_QUERY                            =   8                            --查询命令

CMD_Server_Mail.SUB_GR_C_EMAIL_MESSAGE                  =   5                           --邮件消息请求
CMD_Server_Mail.SUB_GR_S_EMAIL_MESSAGE                  =   6                           --消息返回
CMD_Server_Mail.SUB_MB_S_EMAIL_MESSAGE_RECV             =   8                           --用户领取
CMD_Server_Mail.SUB_MB_S_EMAIL_MESSAGE_BACK             =   9                           --用户领取结果
CMD_Server_Mail.SUB_MB_S_EMAIL_MESSAGE_PUSH             =   10                          --邮件推送
CMD_Server_Mail.SUB_MB_C_EMAIL_MSG_ALL_RECV     =           15                   --用户领取全部邮件
CMD_Server_Mail.SUB_MB_C_EMAIL_MSG_ALLDELETE        =           16                   --用户删除全部邮件

CMD_Server_Mail.SUB_GF_GAME_INFORM                      =   21                          --通知
CMD_Server_Mail.SUB_GF_SYS_GAME_INFORM                  =   46                          --红点通知



--请求邮件列表

CMD_Server_Mail.CMD_MB_MailOption = class("CMD_MB_MailOption",CMDBase)
function CMD_Server_Mail.CMD_MB_MailOption:writeToByteArray(ba)
    ba:writeDWORD(                              self.dwUserID);                   -- 玩家UserID
    ba:writeDWORD(                              self.dwGameID);                   -- 玩家GameID
end     

--返回 邮件列表
CMD_Server_Mail.CMD_MB_MailInfo = class("DBR_MB_MailInfo",CMDBase)
function CMD_Server_Mail.CMD_MB_MailInfo:readFormByteArray(ba)
    self.allMail = {}
    local len_ = ba:getLength()
    for i = 1,ba:getLength()/self:getSize() do
        local mailinfo = {}
        mailinfo.wMessageType =     ba:readWORD();                  -- 消息类型
        mailinfo.dwSendGameID =     ba:readDWORD();                  -- 发件人GameID
        mailinfo.wItemType =        ba:readWORD();                  -- 赠送物品类型
        mailinfo.dwItemCount =     ba:readDWORD();                  -- 赠送物品数量
        mailinfo.wMessageID =       ba:readLONGLONG();              -- 消息ID
        
        mailinfo.szTitle =          ba:readTchar(32);               --标题                      --LEN_NICKNAME
        mailinfo.szMessageContent = ba:readTchar(256);              -- 内容                   --LEN_DESC
        mailinfo.szDateTime =       ba:readTchar(20);               -- 日期                   --LEN_DATETIME
        mailinfo.szRemark =         ba:readTchar(256);              -- 备注                   --LEN_DESC
        mailinfo.szSendNickName =   ba:readTchar(32);               -- 发送人昵称
        mailinfo.szSendFaceUrl =    ba:readTchar(256);              -- 发送人头像
        table.insert(self.allMail,mailinfo)
    end
end

function CMD_Server_Mail.CMD_MB_MailInfo:getSize()
    local size = 2+4+2+4+8+64+512+40+512+64+512             --1724
    return size
end

--请求领取邮件奖励
CMD_Server_Mail.CMD_MB_REQ_MailReward = class("CMD_MB_REQ_MailReward",CMDBase)
function CMD_Server_Mail.CMD_MB_REQ_MailReward:writeToByteArray(ba)
    ba:writeDWORD(                              self.dwUserID);                   -- 玩家UserID
    ba:writeDWORD(                              self.dwGameID);                   -- 玩家GameID
    ba:writeLONGLONG(                              self.wMessageID);                   -- 消息ID
end   

function CMD_Server_Mail.CMD_MB_REQ_MailReward:readFormByteArray(ba)
    self.info = {}
    self.info.uerID =           ba:readDWORD()
    self.info.GameID =          ba:readDWORD()
    self.info.wMessageID =      ba:readLONGLONG()                   --消息ID
    self.info.IScore =          ba:readLONGLONG()                   --用户分数
    self.info.szRemark =        ba:readTchar(256)                   --备注
end 
function CMD_Server_Mail.CMD_MB_REQ_MailReward:getSize()
	local size = 4+4+8+8+512
	return size
end

--通知
CMD_Server_Mail.CMD_GR_S_SysInform = class("CMD_GR_S_SysInform",CMDBase)

function CMD_Server_Mail.CMD_GR_S_SysInform:readFormByteArray(ba)
    self.info = {}
    self.info.uerID =           ba:readDWORD()
    self.info.gameID =          ba:readDWORD()
    self.info.wMsgType =        ba:readWORD()           --通知类型 1：邮件通知
    self.info.szRemark =        ba:readTchar(256)
end

--红点通知
CMD_Server_Mail.CMD_GR_S_SysGameInform = class("CMD_GR_S_SysGameInform",CMDBase)
function CMD_Server_Mail.CMD_GR_S_SysGameInform:readFormByteArray(ba)
    self.wMsgType = {}
    for i=1, ba:getLength()/2 do
        table.insert(self.wMsgType,ba:readWORD())       --1.分享   2.添加好友  3.邮件  4.任务 5.龙珠是否可以抽奖 
    end
end

--用户领取/删除全部邮件
CMD_Server_Mail.CMD_GR_C_UserEmailAllRecv = class("CMD_GR_C_UserEmailAllRecv",CMDBase)
function CMD_Server_Mail.CMD_GR_C_UserEmailAllRecv:writeToByteArray(ba)
	for i=1,#self.lMessageIDList do
        ba:writeLONGLONG(self.lMessageIDList[i]);                                --消息ID
	end
end

return CMD_Server_Mail