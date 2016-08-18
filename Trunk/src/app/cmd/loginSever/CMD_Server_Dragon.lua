local CMD_Server_Dragon = {}
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Dragon.MDM_GR_QUERY                     = 8                                   --主命令

CMD_Server_Dragon.SUB_GF_DRAGON_BALL_REQ                = 37                         --龙珠抽奖信息请求
CMD_Server_Dragon.SUB_GF_DRAGON_BALL_RET1               = 38                         --龙珠抽奖信息返回
CMD_Server_Dragon.SUB_GF_DRAGON_BALL_RET2               = 39                         --龙珠抽奖信息返回

CMD_Server_Dragon.SUB_GF_START_DRAGON                   = 40                  --开始点击获取龙珠
CMD_Server_Dragon.SUB_GF_START_DRAGON_RET               = 41                  --返回龙珠信息

CMD_Server_Dragon.SUB_GF_DRAGON_EXCHANGE                = 42                  --点击兑换龙珠
CMD_Server_Dragon.SUB_GF_DRAGON_EXCHANGE_RET            = 43                  --返回是否兑换龙珠

CMD_Server_Dragon.SUB_GF_SURE_EXCHANGE                  = 44                  --确认兑换龙珠
CMD_Server_Dragon.SUB_GF_SURE_EXCHANGE_RET              = 45                  --返回确认兑换龙珠

CMD_Server_Dragon.CMD_GR_C_DragonBallRequest = class("CMD_GR_C_DragonBallRequest",CMDBase)
function CMD_Server_Dragon.CMD_GR_C_DragonBallRequest:readFormByteArray(ba)
    self.allinfo = {}
    for var=1, ba:getLength()/self:getSize() do
        local info = {}
        info.wKindID = ba:readWORD();                          -- 游戏类型
        info.cbPlayTimes = ba:readBYTE()                       -- 游戏多少局才能抽一次奖
        info.cbDragonStatus  = ba:readBYTE()                   -- 抽奖状态--0，没资格抽奖--1，有资格抽奖---2，已经抽过奖了
        info.nDayPlayCounts = ba:readInt()                     -- 单个游戏的局数
        table.insert(self.allinfo,info)
    end
end
function CMD_Server_Dragon.CMD_GR_C_DragonBallRequest:getSize()
    local size = 2 + 1 + 1 + 4
    return size
end

--开始返回
CMD_Server_Dragon.CMD_GR_C_IsHaveDragonBall = class("CMD_GR_C_IsHaveDragonBall",CMDBase)
function CMD_Server_Dragon.CMD_GR_C_IsHaveDragonBall:readFormByteArray(ba)
    self.info = {}
    self.info.cbDragon = {}                             --是否有龙珠   1有龙珠   0没有龙珠
    for i=1, 7 do
        self.info.cbDragon[i] = ba:readBYTE()
    end
    self.info.cbCurrentDragon = ba:readBYTE()           --当前摇中的龙珠
    self.info.wKindID = ba:readWORD()                          -- 游戏类型
end

CMD_Server_Dragon.CMD_GR_C_ExchangeDragon = class("CMD_GR_C_ExchangeDragon",CMDBase)
function CMD_Server_Dragon.CMD_GR_C_ExchangeDragon:readFormByteArray(ba)
    self.bExchangeSix       = ba:readBool()                         --是否兑换6颗龙珠
    self.bExchangeSeven     = ba:readBool()                         --是否兑换7颗龙珠
end

CMD_Server_Dragon.CMD_GR_C_ExchangeScore = class("CMD_GR_C_ExchangeScore",CMDBase)
function CMD_Server_Dragon.CMD_GR_C_ExchangeScore:readFormByteArray(ba)
    self.nExchangeScore = ba:readInt()                     --兑换金币
end
return CMD_Server_Dragon