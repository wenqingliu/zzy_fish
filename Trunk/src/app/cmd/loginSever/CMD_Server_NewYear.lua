---VIP
local CMD_Server_NewYear = {}
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_NewYear.MDM_GR_QUERY                     = 8                                   --主命令

CMD_Server_NewYear.SUB_MB_USER_LOTTERY              = 25                             --抽奖开始
CMD_Server_NewYear.SUB_GR_LOTTERY_RESULT            = 28                             --返回中奖奖品

CMD_Server_NewYear.SUB_GF_LOTTERY_REQUEST           = 26                              --大转盘获取信息
CMD_Server_NewYear.SUB_GR_LOTTERY_REQUEST           = 27                              --返回消息大转盘

CMD_Server_NewYear.CMD_GR_S_LottreyRequest = class("CMD_GR_S_LottreyRequest",CMDBase)
function CMD_Server_NewYear.CMD_GR_S_LottreyRequest:readFormByteArray(ba)
    self.info = {}
    self.info.nGameCount        = ba:readInt()                      --游戏局数
    self.info.nValue1           = ba:readInt()                      --配置文件中满足nValue1局后能抽奖的次数
    self.info.nValue2           = ba:readInt()
    self.info.nValue3           = ba:readInt()
    self.info.nLotteryCount     = ba:readInt()                      --可抽奖次数
    self.info.nDrawCount        = ba:readInt()                      --已抽奖次数
end

CMD_Server_NewYear.CMD_MB_C_UserLottery = class("CMD_MB_C_UserLottery",CMDBase)             --大转盘 用户发送过来
function CMD_Server_NewYear.CMD_MB_C_UserLottery:writeToByteArray(ba)                     
    ba:writeDWORD(                           self.dwUserID)                             --用户ID
    ba:writeDWORD(                           self.dwPlayerID)                             --游戏ID
end

CMD_Server_NewYear.CMD_MB_S_UserLottery = class("CMD_MB_S_UserLottery",CMDBase)             --大转盘 用户接收
function CMD_Server_NewYear.CMD_MB_S_UserLottery:readFormByteArray(ba)  
    self.info = {}
    self.info.ItemType      = ba:readInt()               --奖品种类
    self.info.nGiftCount    = ba:readInt()               --奖品数量
end

return CMD_Server_NewYear