---VIP
local CMD_Server_VIP = {}
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_VIP.MDM_GP_USER_SERVICE                  = 3                                   --用户服务

CMD_Server_VIP.SUB_MB_USER_VIP_REQ                  = 505                         --VIP查询
CMD_Server_VIP.SUB_MB_VIP_QUERY_RETURN              = 506                         --查询结果
CMD_Server_VIP.SUB_MB_VIP_DRAW_RETURN               = 507                         --领取结果

CMD_Server_VIP.VIP_LEVEL_COUNT                      = 2                           --VIP等级数目

--服务器需要进游戏的时候查询VIP等级
CMD_Server_VIP.MDM_GR_INSURE                        = 5                            --银行消息

CMD_Server_VIP.SUB_MB_USER_VIPSOUNA                 = 136                         --VIP喇叭
CMD_Server_VIP.SUB_MB_USER_VIPSOUNA_INFO            = 137                         --VIP喇叭信息

--查询、领取VIP奖励
CMD_Server_VIP.CMD_GR_C_USER_VIP_REQUEST = class("CMD_GR_C_USER_VIP_REQUEST",CMDBase)
function CMD_Server_VIP.CMD_GR_C_USER_VIP_REQUEST:writeToByteArray(ba)
    ba:writeInt(                             self.op)                         --0:查vip状态;1:领vip奖励
    ba:writeDWORD(                           self.dwUserID)                             --用户ID
    ba:writeDWORD(                           self.dwGameID)                             --游戏ID
end

--VIP奖励列表
CMD_Server_VIP.Vip_Reward_List = class("Vip_Reward_List",CMDBase)
function CMD_Server_VIP.Vip_Reward_List:readFormByteArray(ba)
    self.info = {}
    self.info.dwGiftType = ba:readDWORD();                          -- 礼物类型 4
    self.info.dwGiftCount = ba:readLONGLONG()                         -- 礼物数量 8
    self.info.lFreeHorn  = ba:readLONGLONG()                          -- 赠送免费喇叭 8
    self.info.lUserScore = ba:readLONGLONG()                          -- 用户分数[查询代表奖励数额，领取代表总分] 8
end

--Vip查询返回
CMD_Server_VIP.CMD_MB_S_UserVipInfo = class("CMD_MB_S_UserVipInfo",CMDBase)
function CMD_Server_VIP.CMD_MB_S_UserVipInfo:readFormByteArray(ba)
    self.info = {}
    self.info.dwUserID              = ba:readDWORD();                                   --用户ID
    self.info.bIsVip                = ba:readBool();                                    --vip状态
    self.info.wVipLevel             = ba:readWORD()                                     --vip级别
    self.info.wTodayDraw            = ba:readWORD()                                     --0-未领 1-已领    
    self.info.lVipExperience        = ba:readLONGLONG()                                 --Vip经验值
    self.info.lVipNextExp           = ba:readLONGLONG()                                 --下一次的VIP经验值
    self.info.stuVipRewardArray = {}
    for i=1, CMD_Server_VIP.VIP_LEVEL_COUNT do
        local cmd = CMD_Server_VIP.Vip_Reward_List:create()
        cmd:readFormByteArray(ba)
    	self.info.stuVipRewardArray[i] = cmd.info
    end
end

--Vip领取返回
CMD_Server_VIP.CMD_MB_VipUserReward = class("CMD_MB_VipUserReward",CMDBase)
function CMD_Server_VIP.CMD_MB_VipUserReward:readFormByteArray(ba)
    self.info = {}
    self.info.dwUserID = ba:readDWORD();                                --用户ID 4
    self.info.wStateCode = ba:readWORD()                               --领取结果 2   
    self.info.szDescReward = ba:readTchar(64)                           --领取奖励描述 128+28+6
    local cmd = CMD_Server_VIP.Vip_Reward_List:create()
    cmd:readFormByteArray(ba)
    self.info.stuVipGetReward = cmd.info;                               --VIP奖励
end

--VIP喇叭信息
CMD_Server_VIP.CMD_MB_C_VIPSOUNA = class("CMD_MB_C_VIPSOUNA",CMDBase)
function CMD_Server_VIP.CMD_MB_C_VIPSOUNA:writeToByteArray(ba)
    ba:writeDWORD(self.dwUserID)                                    --用户ID
    ba:writeDWORD(self.dwGameID)                                    --游戏ID
end

CMD_Server_VIP.CMD_MB_S_VIPSOUNA = class("CMD_MB_C_VIPSOUNA",CMDBase)
function CMD_Server_VIP.CMD_MB_S_VIPSOUNA:readFormByteArray(ba)
    self.info = {}
    self.info.nTrumpetCount         = ba:readInt();                 --喇叭数目
    self.info.nVipLevel             = ba:readInt()                  --VIP等级
    self.info.nTrumpetBuyCount      = ba:readInt();                 --购买喇叭数
    self.info.bOpenWareHouse        = ba:readInt()                  --开通仓库
    self.info.bSendGift             = ba:readInt()                  --赠送礼物
    self.info.bOpenYYle             = ba:readInt()                  --是否开通摇摇乐
    self.info.bOpenFM               = ba:readInt()                  --是否开通水果机
    self.info.nFriendCount          = ba:readInt()                  --好友数量
    self.info.lDiamond               = ba:readLONGLONG()            --钻石数量
end

return CMD_Server_VIP