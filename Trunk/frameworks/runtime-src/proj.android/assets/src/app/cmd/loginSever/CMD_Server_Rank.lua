--排行榜
local CMD_Server_Rank = {}


--请求领取邮件奖励
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Rank.MDM_GR_USER                    =     3
CMD_Server_Rank.SUB_MB_SCORE_LIST_REQUEST      =     430                         --查询排行
CMD_Server_Rank.SUB_MB_SCORE_LIST_RESULT       =     431                         --排行结果

--玩家排行榜子项
CMD_Server_Rank.tagScoreListItem = class("tagScoreListItem",CMDBase)
function CMD_Server_Rank.tagScoreListItem:readFormByteArray(ba)
	self.cbGender				=	ba:readBYTE()										--玩家性别
	self.cbVipLevel				=	ba:readBYTE()										--VIP等级
	self.dwUserID				=	ba:readDWORD()										--玩家UserID
	self.dwGameID				=	ba:readDWORD()										--玩家GameID
	self.lUserScore				=	ba:readLONGLONG()										--玩家分数                    
	self.szNickName				=	ba:readTCHAR(32)							--玩家昵称
	self.szFaceUrl				=	ba:readTCHAR(256)							--头像URL
end

--获取排行
CMD_Server_Rank.CMD_MB_GetScoreList = class("CMD_MB_GetScoreList",CMDBase)
function CMD_Server_Rank.CMD_MB_GetScoreList:writeToByteArray(ba)
	ba:writeDWORD(self.dwUserID)												--玩家ID
end

--排行榜结果
CMD_Server_Rank.CMD_MB_ScoreListResult = class("CMD_MB_ScoreListResult",CMDBase)
function CMD_Server_Rank.CMD_MB_ScoreListResult:readFormByteArray(ba)
	self.wUserCount					=	ba:readWORD()								--获取数量
	self.ScoreListItem				=	{}											--玩家信息
	for i=1,self.wUserCount do
		local tag = CMD_Server_Rank.tagScoreListItem:create()
		tag:readFormByteArray(ba)
		self.ScoreListItem[i] = tag
	end				
end

return CMD_Server_Rank