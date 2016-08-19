local CMD_Server_Logon = {}
local CMDBase = import("app/cmd/CMDBase.lua")

CMD_Server_Logon.MDM_MB_LOGON                =      100                                 --广场登录 


CMD_Server_Logon.MDM_GP_USER_SERVICE              = 3                                   --用户服务

CMD_Server_Logon.SUB_MB_LOGON_SUCCESS        =		100                                 --登录成功
CMD_Server_Logon.SUB_MB_LOGON_FAILURE        =		101                                 --登录失败
CMD_Server_Logon.SUB_GP_LOGIN_AWARD          =		104                                 --登录奖励
CMD_Server_Logon.SUB_MB_QUERY_PLAYING_ROOM   =		104									-- 查询在线房间
CMD_Server_Logon.SUB_MB_USER_PLAYING_ROOM	 =		105									-- 返回用户所在房间
CMD_Server_Logon.SUB_MB_UPDATE_NOTIFY        =      200                                 --版本升级 

--列表命令
CMD_Server_Logon.MDM_MB_SERVER_LIST			 =		101									--列表信息
CMD_Server_Logon.SUB_MB_LIST_KIND			 =		100									--种类列表
CMD_Server_Logon.SUB_MB_LIST_SERVER			 =		101									--房间列表
CMD_Server_Logon.SUB_MB_LIST_CONFIG			 =		102									--桌子配置
CMD_Server_Logon.SUB_MB_LIST_FINISH			 =		200									--列表完成

--操作结果
CMD_Server_Logon.SUB_GL_OPERATE_SUCCESS      =      900                                 --操作成功
CMD_Server_Logon.SUB_GL_OPERATE_FAILURE      =      901                                 --操作失败


--查询玩家所在的房间
CMD_Server_Logon.CMD_MB_Query_In_GameRoom = class("CMD_MB_Query_In_GameRoom",CMDBase)
function CMD_Server_Logon.CMD_MB_Query_In_GameRoom:writeToByteArray(ba)
    ba:writeDWORD(                           self.dwUserID)                               -- 用户ID
end

-- 玩家所在的房间返回
CMD_Server_Logon.CMD_MB_User_PlayingRoom = class("CMD_MB_User_PlayingRoom",CMDBase)
function CMD_Server_Logon.CMD_MB_User_PlayingRoom:readFormByteArray(ba)
    self.cbStatus = ba:readBYTE()                               -- 1:在房间 0：不在
	self.szGameRoom = ba:readTCHAR(32)                          -- 房间名字
end

CMD_Server_Logon.CMD_MB_LogonSuccess = class("CMD_MB_LogonSuccess",CMDBase)
function CMD_Server_Logon.CMD_MB_LogonSuccess:readFormByteArray(ba)
	self.cbGender                      =		ba:readBYTE()                              -- 用户性别
     self.dwUserID                     =		ba:readDWORD()                              -- 用户 I D
     self.dwGameID                     =		ba:readDWORD()                              -- 游戏 I D
    self.cbAccountType                 =		ba:readBYTE()                              -- 登录类型
     self.lUserScore                   =		ba:readLONGLONG()                              -- 用户金币
     self.lUserDaimond                 =		ba:readLONGLONG()                              -- 用户钻石
     self.szUUID			             =		ba:readTCHAR(33)                              -- 唯一标识
     self.szNickName     				=		ba:readTCHAR(32)                              -- 用户昵称
     self.szFaceURL          			=		ba:readTCHAR(256)                              -- 头像URL
end

--修改资料
CMD_Server_Logon.CMD_GP_ModifyIndividual = class("CMD_GP_ModifyIndividual",CMDBase)
function CMD_Server_Logon.CMD_GP_ModifyIndividual:writeToByteArray(ba)
    ba:writeBYTE(                            self.cbGender)                           --用户性别
    ba:writeDWORD(                           self.dwUserID)                           --用户 I D
    ba:writeTCHAR(                           self.szPassword,33)                      --用户密码
    
    --昵称
    if self.nickString ~= nil then
        local DTP_GP_UI_NICKNAME = 1
        local tag = CMD_Server_Logon.tagDataDescribe:create()
        tag.wDataSize = 32 * 2
        tag.wDataDescribe = DTP_GP_UI_NICKNAME
        tag:writeToByteArray(ba)
        ba:writeTCHAR(self.nickString,32)
    end
    
    --签名
    if self.szUnderWrite ~= nil then
        local DTP_GP_UI_UNDER_WRITE = 3
        local tag = CMD_Server_Logon.tagDataDescribe:create()
        tag.wDataSize = 32 * 2
        tag.wDataDescribe = DTP_GP_UI_UNDER_WRITE
        tag:writeToByteArray(ba)
        ba:writeTCHAR(self.szUnderWrite,32)
    end
end

CMD_Server_Logon.tagDataDescribe = class("tagDataDescribe",CMDBase)
function CMD_Server_Logon.tagDataDescribe:writeToByteArray(ba)
    ba:writeWORD(                            self.wDataSize)                           --用户性别
    ba:writeWORD(                            self.wDataDescribe)      
end

CMD_Server_Logon.SUB_MB_USER_INDIVIDUAL			=				306						--个人资料
CMD_Server_Logon.SUB_MB_QUERY_INDIVIDUAL		=				307						--查询信息


--个人资料
CMD_Server_Logon.CMD_MB_UserIndividual = class("CMD_MB_UserIndividual",CMDBase)
function CMD_Server_Logon.CMD_MB_UserIndividual:readFormByteArray(ba)
	self.cbGender				=		ba:readBYTE()										--玩家性别
	self.cbVipLevel				=		ba:readBYTE()										--VIP等级
	self.cbRelation				=		ba:readBYTE()										--好友关系
	self.dwUserID				=		ba:readDWORD()										--玩家UserID
	self.dwGameID				=		ba:readDWORD()										--玩家GameID

	self.dwWinCount				=		ba:readDWORD()										--胜利盘数
	self.dwLostCount			=		ba:readDWORD()										--失败盘数
	self.dwDrawCount			=		ba:readDWORD()										--和局盘数
	self.dwFleeCount			=		ba:readDWORD()										--逃跑盘数
                                
	self.lUserScore				=		ba:readLONGLONG()										--玩家分数
	self.szNickName				=		ba:readTCHAR(32)							--玩家昵称
	self.szUnderWrite			=		ba:readTCHAR(32)							--个性签名
	self.szFaceUrl				=		ba:readTCHAR(256)							--头像URL
end

--查询信息
CMD_Server_Logon.CMD_MB_QueryIndividual = class("CMD_MB_QueryIndividual",CMDBase)
function CMD_Server_Logon.CMD_MB_QueryIndividual:writeToByteArray(ba)
	ba:writeDWORD(self.dwSrcGameID)							--自己ID
	ba:writeDWORD(self.dwDstGameID)							--别人ID
end

--操作失败
CMD_Server_Logon.CMD_GP_OperateFailure = class("CMD_GP_OperateFailure",CMDBase)
function CMD_Server_Logon.CMD_GP_OperateFailure:readFormByteArray(ba)
    self.lResultCode = ba:readInt()                               -- 错误代码
    self.szDescribeString = ba:readTCHAR(128)                     -- 描述消息
end

--操作成功
CMD_Server_Logon.CMD_GP_OperateSuccess = class("CMD_GP_OperateSuccess",CMDBase)
function CMD_Server_Logon.CMD_GP_OperateSuccess:readFormByteArray(ba)
    self.lResultCode = ba:readInt()                               -- 错误代码
    self.szDescribeString = ba:readTCHAR(128)                     -- 描述消息
end


return CMD_Server_Logon