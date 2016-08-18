local CMDBase = import("app/cmd/CMDBase.lua")
local CMD_Game_Server = {}

CMD_Game_Server.MDM_GR_LOGON 			=	1
CMD_Game_Server.SUB_GR_LOGON_MOBILE 	= 	2

--登录结果
CMD_Game_Server.SUB_GR_LOGON_SUCCESS    =    100                                 --登录成功
CMD_Game_Server.SUB_GR_LOGON_FAILURE    =    101                                 --登录失败
CMD_Game_Server.SUB_GR_LOGON_FINISH     =    102                                 --登录完成
CMD_Game_Server.SUB_GR_UPDATE_NOTIFY    =    200                                 --升级提示


CMD_Game_Server.MDM_GR_CONFIG				=	2								--配置信息
CMD_Game_Server.SUB_GR_CONFIG_COLUMN		=	100								--列表配置
CMD_Game_Server.SUB_GR_CONFIG_SERVER		=	101								--房间配置
CMD_Game_Server.SUB_GR_CONFIG_PROPERTY		=	102								--道具配置
CMD_Game_Server.SUB_GR_CONFIG_FINISH		=	103								--配置完成
CMD_Game_Server.SUB_GR_CONFIG_USER_RIGHT	=	104								--玩家权限


CMD_Game_Server.MDM_GR_USER					=	3								--用户信息
CMD_Game_Server.MDM_GR_INSURE				=	5								--银行消息

--用户动作
CMD_Game_Server.SUB_GR_USER_RULE			=	1									--用户规则
CMD_Game_Server.SUB_GR_USER_LOOKON			=	2									--旁观请求
CMD_Game_Server.SUB_GR_USER_SITDOWN			=	3									--坐下请求
CMD_Game_Server.SUB_GR_USER_STANDUP			=	4									--起立请求
CMD_Game_Server.SUB_GR_USER_INVITE			=	5									--用户邀请
CMD_Game_Server.SUB_GR_USER_INVITE_REQ		=	6									--邀请请求
CMD_Game_Server.SUB_GR_USER_REPULSE_SIT  	=	7									--拒绝玩家坐下
CMD_Game_Server.SUB_GR_USER_KICK_USER       =	8                                   --踢出用户
CMD_Game_Server.SUB_GR_USER_INFO_REQ        =	9                                   --请求用户信息
CMD_Game_Server.SUB_GR_USER_CHAIR_REQ       =	10                                  --请求更换位置
CMD_Game_Server.SUB_GR_USER_CHAIR_INFO_REQ  =	11                                  --请求椅子用户信息
CMD_Game_Server.SUB_GR_USER_WAIT_DISTRIBUTE =	12									--等待分配
CMD_Game_Server.SUB_GR_SHUT_DOWN_SOCKET     =	13
CMD_Game_Server.SUB_GR_USER_QUICK_JINE		=	18									--快速加入

--------------------------------------------//
CMD_Game_Server.MDM_GF_FRAME				=	100									--框架命令

CMD_Game_Server.SUB_GF_USER_CHAT			=	10									--用户聊天
CMD_Game_Server.SUB_GF_USER_EXPRESSION		=	11									--用户表情
--游戏信息
CMD_Game_Server.SUB_GF_GAME_STATUS			=	100									--游戏状态
CMD_Game_Server.SUB_GF_GAME_SCENE			=	101									--游戏场景
CMD_Game_Server.SUB_GF_LOOKON_STATUS		=	102									--旁观状态
CMD_Game_Server.SUB_GF_TASK_INFO			=	103									--任务信息
CMD_Game_Server.SUB_GF_TASK_STATUS			=	104									--任务状态

--系统消息
CMD_Game_Server.SUB_GF_SYSTEM_MESSAGE		=	200									--系统消息
CMD_Game_Server.SUB_GF_ACTION_MESSAGE		=	201									--动作消息
--------------------------------------------//

--用户状态
CMD_Game_Server.SUB_GR_USER_ENTER			=	100									--用户进入
CMD_Game_Server.SUB_GR_USER_SCORE			=	101									--用户分数
CMD_Game_Server.SUB_GR_USER_STATUS			=	102									--用户状态
CMD_Game_Server.SUB_GR_REQUEST_FAILURE		=	103									--请求失败
CMD_Game_Server.SUB_GR_USER_AWARD			=	104									--用户奖励
CMD_Game_Server.SUB_GR_USER_GOLD			=	105									--金币变化


--游戏命令
CMD_Game_Server.MDM_GF_GAME					=	200										--游戏命令

--聊天命令
CMD_Game_Server.SUB_GR_USER_CHAT				=	201									--聊天消息
CMD_Game_Server.SUB_GR_USER_EXPRESSION		=	202									--表情消息
CMD_Game_Server.SUB_GR_WISPER_CHAT			=	203									--私聊消息
CMD_Game_Server.SUB_GR_WISPER_EXPRESSION		=	204									--私聊表情
CMD_Game_Server.SUB_GR_COLLOQUY_CHAT			=	205									--会话消息
CMD_Game_Server.SUB_GR_COLLOQUY_EXPRESSION	=	206									--会话表情

--道具命令
CMD_Game_Server.SUB_GR_PROPERTY_BUY			=	300									--购买道具
CMD_Game_Server.SUB_GR_PROPERTY_SUCCESS		=	301									--道具成功
CMD_Game_Server.SUB_GR_PROPERTY_FAILURE		=	302									--道具失败
CMD_Game_Server.SUB_GR_PROPERTY_MESSAGE     	=	303                                 --道具消息
CMD_Game_Server.SUB_GR_PROPERTY_EFFECT      	=	304                                 --道具效应
CMD_Game_Server.SUB_GR_PROPERTY_TRUMPET		=	305                                 --喇叭消息
CMD_Game_Server.CMD_GR_PROPERTY_PROPSOUNA   	=	310									-- 喇叭

--系统命令
CMD_Game_Server.MDM_CM_SYSTEM				=	1000							--系统命令
CMD_Game_Server.SUB_CM_SYSTEM_MESSAGE		=	1								--系统命令
CMD_Game_Server.SUB_CM_ACTION_MESSAGE		=	2								--动作消息
CMD_Game_Server.SUB_CM_DOWN_LOAD_MODULE		=	3								--下载消息

--喇叭消息
CMD_Game_Server.CMD_GR_C_SendTrumpet = class("CMD_GR_C_SendTrumpet",CMDBase)
function CMD_Game_Server.CMD_GR_C_SendTrumpet:writeToByteArray(ba)
	ba:writeBYTE(self.cbRequestArea)                              --请求范围 
	ba:writeWORD(self.wPropertyIndex)                             --道具索引 
    ba:writeDWORD(self.dwSendUserID)                               --用户ID
	ba:writeDWORD(self.TrumpetColor)                              --喇叭颜色
	ba:writeTCHAR(self.szTrumpetContent,128)                      --喇叭内容
end


--请求失败
CMD_Game_Server.CMD_GR_RequestFailure = class("CMD_GR_RequestFailure",CMDBase)
function CMD_Game_Server.CMD_GR_RequestFailure:readFormByteArray(ba)
	self.lErrorCode			=		ba:readInt()									--错误代码
	self.szDescribeString	=		ba:readTCHAR(256)									--描述信息
end

--游戏环境
CMD_Game_Server.CMD_GF_GameStatus = class("CMD_GF_GameStatus",CMDBase)
function CMD_Game_Server.CMD_GF_GameStatus:readFormByteArray(ba)
	self.cbGameStatus			=		ba:readBYTE()									--游戏状态
	self.cbAllowLookon			=		ba:readBYTE()									--旁观标志
end

--登录失败
CMD_Game_Server.CMD_GR_LogonFailure = class("CMD_GR_LogonFailure",CMDBase)
function CMD_Game_Server.CMD_GR_LogonFailure:readFormByteArray(ba)
    self.lErrorCode         =       ba:readInt()                                    --错误代码
    self.szDescribeString   =       ba:readTCHAR(128)                               --描述信息
    self.szRoomName         =       ba:readTCHAR(32)                                --描述信息
end


return CMD_Game_Server