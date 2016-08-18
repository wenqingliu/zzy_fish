local CMDBase = import("app/cmd/CMDBase.lua")
local CMD_Room_User = {}

--------------------邀请对战

CMD_Room_User.SUB_GR_USER_INVITE          =	5                           --用户邀请(收到))
CMD_Room_User.SUB_GR_USER_INVITE_REQ      =	6                           --邀请请求(发送)

CMD_Room_User.MDM_GR_USER            		=	3                  			--用户信息

--邀请用户(收到)
CMD_Room_User.CMD_GR_UserInvite = class("CMD_GR_UserInvite",CMDBase)
function CMD_Room_User.CMD_GR_UserInvite:readFormByteArray(ba)
	self.wTableID			=		ba:readWORD()									--桌子号码
	self.dwUserID			=		ba:readDWORD()									--用户 I D
end

--邀请用户请求(发送) 
CMD_Room_User.CMD_GR_UserInviteReq = class("CMD_GR_UserInviteReq",CMDBase)
function CMD_Room_User.CMD_GR_UserInviteReq:writeToByteArray(ba)
	ba:writeWORD(							self.wTableID)							--桌子号码
	ba:writeDWORD(							self.dwUserID)							--用户 I D
end

---------------------------

--全局邀请

CMD_Room_User.MDM_GR_QUERY						=		8					--查询命令
CMD_Room_User.SUB_GF_FRIEND_INVITE				=		13						--好友邀请

--好友邀请
CMD_Room_User.CMD_MB_FriendInvite = class("CMD_MB_FriendInvite",CMDBase)
function CMD_Room_User.CMD_MB_FriendInvite:readFormByteArray(ba)
    self.cbDataFrom                =            ba:readBYTE()       --0为玩家发起,1为管理员发起
	self.wKindID                   =			ba:readWORD()          --游戏ID
	self.wServerID					=			ba:readWORD()		--房间ID
	self.wTableID                  =			ba:readWORD()          --桌子号码
	self.wChairID                  =			ba:readWORD()          --椅子位置
	self.dwGameID					=			ba:readDWORD()		--玩家ID
	self.dwFriendID                =			ba:readDWORD()         --好友ID
	self.szNickName					=			ba:readTCHAR(32)		--用户名字
	self.szRoomName					=			ba:readTCHAR(32)			--房间名称
end

function CMD_Room_User.CMD_MB_FriendInvite:writeToByteArray(ba)
    ba:writeBYTE(self.cbDataFrom)
	ba:writeWORD(self.wKindID)   
	ba:writeWORD(self.wServerID)	
	ba:writeWORD(self.wTableID)   
	ba:writeWORD(self.wChairID)   
	ba:writeDWORD(self.dwGameID)	
	ba:writeDWORD(self.dwFriendID)  
	ba:writeTCHAR(self.szNickName,32)
	ba:writeTCHAR(self.szRoomName,32)
end

--用户信息
CMD_Room_User.tagMobileUserInfoHead = class("tagMobileUserInfoHead",CMDBase)
function CMD_Room_User.tagMobileUserInfoHead:readFormByteArray(ba)
	--用户属性
	self.dwGameID				=		ba:readDWORD()								--游戏 I D
	self.dwUserID				=		ba:readDWORD()								--用户 I D
    
	--头像信息
	self.wFaceID				=		ba:readWORD()								--头像索引
	self.dwCustomID				=		ba:readDWORD()								--自定标识
    
	--用户属性
	self.cbGender				=		ba:readBYTE()								--用户性别
	self.cbMemberOrder			=		ba:readBYTE()								--会员等级
    
	--用户状态
	self.wTableID				=		ba:readWORD()								--桌子索引
	self.wChairID				=		ba:readWORD()								--椅子索引
	self.cbUserStatus			=		ba:readBYTE()								--用户状态
    
	--积分信息
	self.lScore					=		ba:readLONGLONG()								--用户分数
    
	--游戏信息
	self.dwWinCount				=		ba:readDWORD()								--胜利盘数
	self.dwLostCount			=		ba:readDWORD()								--失败盘数
	self.dwDrawCount			=		ba:readDWORD()								--和局盘数
	self.dwFleeCount			=		ba:readDWORD()								--逃跑盘数
	self.dwExperience			=		ba:readDWORD()								--用户经验
    
	--新增
	self.szNickName				=		ba:readTCHAR(32)								--用户昵称
	self.szFaceIDDownURL		=		ba:readTCHAR(256) 								--自定义头像地址
end

return CMD_Room_User