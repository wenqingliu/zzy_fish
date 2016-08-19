--分享
local CMD_Server_share = {}

CMD_Server_share.MDM_GR_QUERY                            =   8                            --查询命令

CMD_Server_share.SUB_GF_FRIENT_TIMELY_CHAT                  =   20                           --游戏分享

--请求领取邮件奖励
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_share.CMD_Server_Success = class("CMD_Server_Success",CMDBase)

function CMD_Server_share.CMD_Server_Success:writeToByteArray(ba)
    ba:writeWORD(                              self.wKindID);                   -- 游戏ID
    ba:writeWORD(                              self.wPlatformID);               -- 平台ID
    ba:writeDWORD(                             self.dwUserID);                  -- 用户ID
end   


return CMD_Server_share