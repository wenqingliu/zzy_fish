---银行信息

local CMD_Sever_Bank = {}

CMD_Sever_Bank.MDM_GR_INSURE                      =    5                                   --银行消息


--请求命令
CMD_Sever_Bank.SUB_GR_QUERY_INSURE_INFO             = 1                          --查询银行
CMD_Sever_Bank.SUB_GR_SAVE_SCORE_REQUEST            = 2                          --存款操作
CMD_Sever_Bank.SUB_GR_TAKE_SCORE_REQUEST            = 3                          --取款操作
CMD_Sever_Bank.SUB_GR_TRANSFER_SCORE_REQUEST        = 4                          --转账操作
CMD_Sever_Bank.SUB_GR_QUERY_USER_INFO_REQUEST       = 5                          --查询用户

CMD_Sever_Bank.SUB_CP_QUERY_INSURE_INFO             = 100                        --查询银行返回
CMD_Sever_Bank.SUB_GR_USER_INSURE_SUCCESS             = 101                        --查询成功
CMD_Sever_Bank.SUB_GR_USER_INSURE_FAILURE              = 102                        --查询失败


CMD_Sever_Bank.SUB_GR_USER_RELIVE_GOLD_REQUEST      = 21                          --复活金请求
CMD_Sever_Bank.SUB_GR_S_USER_RELIVE_GOLD_RESPONSE   = 133                         --复活金响应

--银行服务
CMD_Sever_Bank.SUB_GL_USER_SAVE_SCORE               =   400                       --存款操作
CMD_Sever_Bank.SUB_GL_USER_TAKE_SCORE               =   401                       --取款操作
CMD_Sever_Bank.SUB_GL_USER_TRANSFER_SCORE           =   402                       --转账操作
CMD_Sever_Bank.SUB_GL_USER_INSURE_INFO              =   403                       --银行资料
CMD_Sever_Bank.SUB_GL_QUERY_INSURE_INFO             =   404                       --查询银行
CMD_Sever_Bank.SUB_GL_USER_INSURE_SUCCESS           =   405                       --银行成功
CMD_Sever_Bank.SUB_GL_USER_INSURE_FAILURE           =   406                       --银行失败
CMD_Sever_Bank.SUB_GL_QUERY_USER_INFO_REQUEST       =   407                       --查询用户
CMD_Sever_Bank.SUB_GL_QUERY_USER_INFO_RESULT        =   408                       --用户信息

--查询
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Sever_Bank.CMD_MB_Query = class("CMD_MB_Query",CMDBase)
function CMD_Sever_Bank.CMD_MB_Query:writeToByteArray(ba)
    ba:writeBYTE(                              self.cbActivityGame)                     --游戏动作
    ba:writeTchar(                             self.szInsurePass,33)                    --银行密码
end

function CMD_Sever_Bank.CMD_MB_Query:readFormByteArray(ba)
    self.info = {}
    self.info.cbActivityGame =              ba:readBYTE()                                                 --游戏动作
    self.info.wRevenueTake =                ba:readWORD()                                                  --税收比例
    self.info.wRevenueTransfer =            ba:readWORD()                                               --税收比例
    self.info.wServerID =                   ba:readWORD()                                                     --房间标识
    self.info.lUserScore =                  ba:readLONGLONG()                                                    --用户金币
    self.info.lUserInsure =                 ba:readLONGLONG()                                                   --银行金币
    self.info.lTransferPrerequisite =       ba:readLONGLONG()                                         --转账条件
    print("aaa")
end

function CMD_Sever_Bank.CMD_MB_Query:getSize()
    local size = 1 + 2 + 2 + 2 + 8+8+8          --31
    return size
end

--存款
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Sever_Bank.CMD_MB_Save = class("CMD_MB_Save",CMDBase)
function CMD_Sever_Bank.CMD_MB_Save:writeToByteArray(ba)
    ba:writeBYTE(                              self.cbActivityGame)                     --游戏动作
    ba:writeLONGLONG(                          self.lSaveScore)                         --数目
    ba:writeWORD(                              self.wKindID)                    
end
--取款
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Sever_Bank.CMD_MB_Take = class("CMD_MB_Take",CMDBase)
function CMD_Sever_Bank.CMD_MB_Take:writeToByteArray(ba)
    ba:writeBYTE(                              self.cbActivityGame)                     --游戏动作
    ba:writeLONGLONG(                          self.lTakeScore)                         --数目
    ba:writeTchar(                             self.szInsurePass,33)                    --银行密码
    ba:writeWORD(                              self.wKindID)                    
end

--银行成功
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Sever_Bank.CMD_GR_S_UserInsureSuccess = class("CMD_GR_S_UserInsureSuccess",CMDBase)
function CMD_Sever_Bank.CMD_GR_S_UserInsureSuccess:readFormByteArray(ba)
    self.info = {}
    self.info.cbActivityGame =              ba:readBYTE()                                                 --游戏动作
    self.info.lUserScore =                  ba:readLONGLONG()                                                  --身上金币
    self.info.lUserInsure =                 ba:readLONGLONG()                                               --银行金币
    self.info.szDescribeString =            ba:readTchar(128)                                                     --描述消息
    print("aaa")
end

function CMD_Sever_Bank.CMD_GR_S_UserInsureSuccess:getSize()
    local size = 1 + 8+8+256          --273
    return size
end

--银行失败
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Sever_Bank.CMD_GR_S_UserInsureFailure = class("CMD_GR_S_UserInsureFailure",CMDBase)
function CMD_Sever_Bank.CMD_GR_S_UserInsureFailure:readFormByteArray(ba)
    self.info = {}
    self.info.cbActivityGame =              ba:readBYTE()                                                   --游戏动作
    self.info.lUserInsure =                 ba:readInt()                                                   --错误代码
    self.info.szDescribeString =            ba:readTchar(128)                                               --描述消息
    print("aaa")
end

function CMD_Sever_Bank.CMD_GR_S_UserInsureFailure:getSize()
    local size = 1+8+256          --265
    return size
end

--复活金请求
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Sever_Bank.CMD_GR_C_ReliveGoldRequest = class("CMD_GR_C_ReliveGoldRequest",CMDBase)
function CMD_Sever_Bank.CMD_GR_C_ReliveGoldRequest:writeToByteArray(ba)
    ba:writeDWORD(self.dwGameID)    --玩家ID
    ba:writeWORD(self.wTypeReq)    --请求类型(查询:0;领取:1)
end

--复活金响应
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Sever_Bank.CMD_GR_S_ReliveGoldInfo = class("CMD_GR_S_ReliveGoldInfo",CMDBase)
function CMD_Sever_Bank.CMD_GR_S_ReliveGoldInfo:readFormByteArray(ba)
    self.wTypeReq         =           ba:readWORD()              --请求类型
    self.dwGameID         =           ba:readDWORD()              --玩家ID
    self.lReliveScore     =           ba:readLONGLONG()              --复活分数
    self.wReliveTimes     =           ba:readWORD()               --剩余次数
    self.szDescMsg	      =			  ba:readTchar(64)              --结果提示(包含复活分数)
end

return CMD_Sever_Bank