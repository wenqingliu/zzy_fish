--好友列表
local GCMD_Sever_Friends = {}

GCMD_Sever_Friends.MDM_GP_USER_SERVICE              =    3                          --用户服务(主命令)
GCMD_Sever_Friends.SUB_MB_FRIENT_QUERY_USER         =   601                         --查找用户
GCMD_Sever_Friends.SUB_MB_FRIENT_ADD_FRIENDLY       =   602                         --添加好友（废弃）
GCMD_Sever_Friends.SUB_MB_FRIENT_DELETE             =   603                         --删除好友
GCMD_Sever_Friends.SUB_MB_FRIENT_ADD_BLACKLIST      =   604                         --添加黑名单
GCMD_Sever_Friends.SUB_MB_FRIENT_REMOVE_BLACKLIST   =   605                         --移除黑名单
GCMD_Sever_Friends.SUB_MB_LOAD_FRIEND_LIST          =   606                         --好友列表
GCMD_Sever_Friends.SUB_MB_FRIENT_SYS_RECOMMEN       =   607                         --系统推荐好友
GCMD_Sever_Friends.SUB_MB_FRIENT_BLACKLIST          =   608                         --黑名单列表

GCMD_Sever_Friends.MDM_GR_INSURE                    =  5                              --银行消息主命令
GCMD_Sever_Friends.SUB_GR_FRIEND_REQ                = 48                              --申请好友
GCMD_Sever_Friends.SUB_GR_Query_Friend_Unverified   = 49                              --查询待验证的好友
GCMD_Sever_Friends.SUB_GR_FRIEND_Verified           = 50                              --验证好友

GCMD_Sever_Friends.SUB_GR_S_Query_Friend_Unverified             = 140                 --待验证好友响应
GCMD_Sever_Friends.SUB_GR_S_FRIEND_RESP                         = 141                                 --等待好友验证
GCMD_Sever_Friends.SUB_GR_S_FRINED_VERIFIED_RESP                = 142                                 --验证好友响应

GCMD_Sever_Friends.SUB_MB_USER_CHECK_SPREADERID_REQ     = 609                             --查询推广员ID
GCMD_Sever_Friends.SUB_MB_USER_CHECK_SPREADERID     = 633                             --查询推广员ID

GCMD_Sever_Friends.SUB_GR_USER_ADD_SPREADER_REQ      = 19                       --添加推广员ID请求
GCMD_Sever_Friends.SUB_GR_USER_ADD_SPREADER_RES      = 20                       --添加推广员回复
--好友上下线
GCMD_Sever_Friends.MDM_GR_QUERY                             =    8                       --查询命令(主命令)
GCMD_Sever_Friends.SUB_MB_FRIENT_TIMELY_STATUS            =   11                       --上下线
GCMD_Sever_Friends.SUB_MB_FRIENT_USER_STATUS            =   12                       --上下线

--推广
GCMD_Sever_Friends.SUB_GR_CHECK_SPREADER_REQ		=	29					--查询是不是推广用户
GCMD_Sever_Friends.SUB_GR_CHECK_SPREADER_RET		=	30					--查询信息返回
GCMD_Sever_Friends.SUB_GR_DRAW_SPREADER_REQ			=	31					--领取推广员分数
GCMD_Sever_Friends.SUB_GR_DRAW_SPREADER_RET        	=	32					--领取推广员分数返回

--用户操作数据发送
local CMDBase = import("app/cmd/CMDBase.lua")
GCMD_Sever_Friends.CMD_MB_FriendOption = class("CMD_MB_FriendOption",CMDBase)
function GCMD_Sever_Friends.CMD_MB_FriendOption:writeToByteArray(ba)
    ba:writeDWORD(                              self.dwGameID);                   -- 玩家ID
    ba:writeDWORD(                              self.dwFriendID);                 --好友FriendGameID
end     

--返回 client
local CMDBase = import("app/cmd/CMDBase.lua")
GCMD_Sever_Friends.DBR_MB_UserFriendInfo = class("DBR_MB_UserFriendInfo",CMDBase)
function GCMD_Sever_Friends.DBR_MB_UserFriendInfo:readFormByteArray(ba)
    self.allUser = {}
    local len_ = ba:getLength()
    for i = 1,ba:getLength()/self:getSize()do
        local userinfo = {}
        userinfo.cbGender = ba:readBYTE();                   -- 性别
        userinfo.wVipLevel = ba:readWORD();                  -- ip等级
        userinfo.wRankLevel = ba:readWORD();                 -- 保留
        userinfo.dwPlayID = ba:readDWORD();                   -- 玩家GameID
        userinfo.dwUserID = 0;                              -- 玩家UserID
        userinfo.szNickName = ba:readTchar(32);             -- 好友昵称 32
        userinfo.szPlayHeadUrl = ba:readTchar(256);         -- 玩家头像Url 256 
        userinfo.szUnderWrite = ba:readTchar(32);           -- 个性签名 32
        userinfo.cbUserStatus = ba:readBYTE()               -- 用户的状态
        table.insert(self.allUser,userinfo)
    end
end

function GCMD_Sever_Friends.DBR_MB_UserFriendInfo:getSize()
    return 1+2+2+4+64+512+64+1
end

GCMD_Sever_Friends.CMD_MB_S_FriendRet = class("CMD_MB_S_FriendRet",CMDBase)              --好友响应
function GCMD_Sever_Friends.CMD_MB_S_FriendRet:readFormByteArray(ba)
    self.nRet = ba:readWORD()                                   --1成功 2失败
    self.szDescribe = ba:readTchar(128)                         --描述
end

--好友上下线
GCMD_Sever_Friends.CMD_MB_UserStatus = class("CMD_MB_UserStatus",CMDBase)
function GCMD_Sever_Friends.CMD_MB_UserStatus:readFormByteArray(ba)
    self.allUser = {}
    local len_ = ba:getLength()
    for i = 1,ba:getLength()/self:getSize()do
        local userinfo = {}
        userinfo.cbStatus = ba:readBYTE()                    -- 1-在线  0-不在线
        userinfo.dwFriendUserID = ba:readDWORD()             -- 好友ID
        userinfo.dwFriendGameID = ba:readDWORD()             -- 玩家ID
        userinfo.dwUserID = ba:readDWORD()                   -- 
        userinfo.dwGameID = ba:readDWORD()                   -- 
        userinfo.dwVipLevel  = ba:readDWORD()               -- 好友Vip
        userinfo.szNickName  = ba:readTchar(32)               -- 好友昵称
        table.insert(self.allUser,userinfo)
    end

end

function GCMD_Sever_Friends.CMD_MB_UserStatus:getSize()
    return 1+4+4+4+4+4+64
end

GCMD_Sever_Friends.CMD_MB_FriendStatus = class("CMD_MB_FriendStatus",CMDBase)              --好友响应
function GCMD_Sever_Friends.CMD_MB_FriendStatus:writeToByteArray(ba)
    ba:writeBYTE(                                    self.cbStatus)                          -- 1-在线  0-不在线
    ba:writeDWORD(                                   self.dwUserID)                          -- UserID
    ba:writeDWORD(                                   self.dwGameID)                          -- 玩家ID
    ba:writeDWORD(                                   self.dwVipLevel)                        -- 好友Vip
    ba:writeTchar(                                   self.szNickName,32)                        -- 好友Vip
end


--查询待验证好友信息
GCMD_Sever_Friends.CMD_GR_C_Query_Friend_Unverified = class("CMD_GR_C_Query_Friend_Unverified",CMDBase)
function GCMD_Sever_Friends.CMD_GR_C_Query_Friend_Unverified:writeToByteArray(ba)
    ba:writeDWORD(                              self.dwGameID);                   -- 玩家ID
end 

--验证好友
GCMD_Sever_Friends.CMD_GR_C_Verifiend = class("CMD_GR_C_Verifiend",CMDBase)
function GCMD_Sever_Friends.CMD_GR_C_Verifiend:writeToByteArray(ba)
    ba:writeDWORD(                              self.dwGameID);                   -- 玩家ID
    ba:writeDWORD(                              self.dwFriendID);                 --好友FriendGameID
    ba:writeDWORD(                              self.dwStatus);                 --0同意,1`拒绝
end

--好友验证响应
GCMD_Sever_Friends.CMD_GR_S_Verifiend_RESP = class("CMD_GR_S_Verifiend_RESP",CMDBase)
function GCMD_Sever_Friends.CMD_GR_S_Verifiend_RESP:readFormByteArray(ba)
    self.dwGameID = ba:readDWORD() 
    self.dwFriendID = ba:readDWORD()
    self.szDesc = ba:readTchar(64)          --操作结果
    self.dwStatus = ba:readDWORD()          --0成功，其它都失败
    self.cbUserStatus = ba:readBYTE()       -- 用户的状态
end

--等待好友验证
GCMD_Sever_Friends.CMD_GR_S_RIEND_RESP = class("CMD_GR_S_RIEND_RESP",CMDBase)
function GCMD_Sever_Friends.CMD_GR_S_RIEND_RESP:readFormByteArray(ba)
    self.dwGameID = ba:readDWORD() 
    self.dwFriendID = ba:readDWORD()
    self.szDesc = ba:readTchar(64)          --操作结果
    self.dwStatus = ba:readDWORD()          --0成功，其它都失败
end

--查询推广员ID
GCMD_Sever_Friends.CMD_MB_S_Check_SpreaderID = class("CMD_MB_S_Check_SpreaderID",CMDBase)
function GCMD_Sever_Friends.CMD_MB_S_Check_SpreaderID:readFormByteArray(ba)
    self.dwSpreadID = ba:readDWORD()                    --推广员ID
end

GCMD_Sever_Friends.CMD_MB_C_Check_SpreaderID_REQ = class("CMD_MB_S_Check_SpreaderID_REQ",CMDBase)
function GCMD_Sever_Friends.CMD_MB_C_Check_SpreaderID_REQ:writeToByteArray(ba)
    ba:writeDWORD(                                   self.dwGameID)                          -- 玩家ID
end

--请求添加推广号
GCMD_Sever_Friends.CMD_CR_C_AddSpreaderReq = class("CMD_CR_C_AddSpreaderReq",CMDBase)
function GCMD_Sever_Friends.CMD_CR_C_AddSpreaderReq:writeToByteArray(ba)
    ba:writeDWORD(                                   self.dwGameID)                             -- 游戏ID
    ba:writeDWORD(                                   self.dwSpreadID)                          -- 推广员ID
end

--请求添加推广号返回
GCMD_Sever_Friends.CMD_CR_S_AddSpreaderRes = class("CMD_CR_S_AddSpreaderRes",CMDBase)
function GCMD_Sever_Friends.CMD_CR_S_AddSpreaderRes:readFormByteArray(ba)
    self.bSuccess = ba:readInt()               --添加推广员是否成功  1:成功 , 2:失败
    self.dwSpreadID = ba:readDWORD()                    --推广员ID
    self.szDes    = ba:readTchar(64)            --添加推广员的结果
end

--查询是不是推广用户
GCMD_Sever_Friends.CMD_C_CHECK_SPREADER_REQ = class("CMD_C_CHECK_SPREADER_REQ",CMDBase)
function GCMD_Sever_Friends.CMD_C_CHECK_SPREADER_REQ:writeToByteArray(ba)
	ba:writeDWORD(                      self.dwUserID);
	ba:writeDWORD(					    self.dwGameID);
end

--查询信息返回
GCMD_Sever_Friends.CMD_S_CHECK_SPREADER_REQ = class("CMD_S_CHECK_SPREADER_REQ",CMDBase)
function GCMD_Sever_Friends.CMD_S_CHECK_SPREADER_REQ:readFormByteArray(ba)
	self.bSpreaderID	=	ba:readInt();              --1：是推广员，2：不是推广员
	self.lPushScore		=	ba:readLONGLONG();
end

--领取推广员分数
GCMD_Sever_Friends.CMD_C_DRAW_SPREADER_REQ = class("CMD_C_DRAW_SPREADER_REQ",CMDBase)
function GCMD_Sever_Friends.CMD_C_DRAW_SPREADER_REQ:writeToByteArray(ba)
	ba:writeDWORD(                      self.dwUserID);
	ba:writeDWORD(					    self.dwGameID);
end

--领取推广员分数返回
GCMD_Sever_Friends.CMD_S_DRAW_SPREADER_REQ = class("CMD_S_DRAW_SPREADER_REQ",CMDBase)
function GCMD_Sever_Friends.CMD_S_DRAW_SPREADER_REQ:readFormByteArray(ba)
	self.bSuccess	=	ba:readInt();              --1：领取成功，2：领取不成功
	self.lPushScore	=	ba:readLONGLONG();
end

return GCMD_Sever_Friends