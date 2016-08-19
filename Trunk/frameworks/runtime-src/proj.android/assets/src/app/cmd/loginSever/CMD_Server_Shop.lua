local CMD_Server_Shop = {}
local CMDBase = import("app/cmd/CMDBase.lua")

CMD_Server_Shop.SUB_MB_SALESHOP_REQ        =         524                         --查询购买商品
CMD_Server_Shop.SUB_MB_QUERY_RETURN        =         525                         --商品查询返回
CMD_Server_Shop.SUB_MB_BUY_RETURN          =         526                         --购买返回

CMD_Server_Shop.SUB_GR_USER_CHARGE_SCORE   =		 47							 --钻石换金币

CMD_Server_Shop.SUB_GR_S_USER_CHARGE_SCORE_RESPONSE		=	 138				 -- 钻石换金币响应
CMD_Server_Shop.SUB_GR_S_USER_CHARGE_INFO_RESPONSE      =    139				 -- 钻石兑换查询响应

local ITEM_BUT_NUM = 6

--商品
CMD_Server_Shop.CMD_GR_C_USER_SALESHOP_REQUEST = class("CMD_GR_C_USER_SALESHOP_REQUEST",CMDBase)
function CMD_Server_Shop.CMD_GR_C_USER_SALESHOP_REQUEST:writeToByteArray(ba)
    ba:writeDWORD(             self.dwOperate)                            --1:查,2:购买
    ba:writeDWORD(             self.dwItemType)                           --类型
    ba:writeDWORD(             self.dwItemCount)                          --数量
    ba:writeDWORD(             self.dwUserID)                             --用户ID
    ba:writeDWORD(             self.dwGameID)                             --游戏ID          
end

--商品查询返回
CMD_Server_Shop.CMD_GR_S_USER_SALESHOP = class("CMD_GR_S_USER_SALESHOP",CMDBase)
function CMD_Server_Shop.CMD_GR_S_USER_SALESHOP:readFormByteArray(ba)
    self.dwUserID         =                    	ba:readDWORD()	-- 用户ID
    
	self.dwItemType = {} -- 类型
    for i=1,ITEM_BUT_NUM do
		self.dwItemType[i] = ba:readDWORD()
	end
	
	self.dwItemCount = {}  -- 数量
    for i=1,ITEM_BUT_NUM do
		self.dwItemCount[i] = ba:readDWORD()
	end
	
	self.dwSalePrice = {} -- 卖价
	for i=1,ITEM_BUT_NUM do
		self.dwSalePrice[i] = ba:readDWORD()
	end
	
	self.szItemName = {} -- 名称
	for i=1,ITEM_BUT_NUM do
		self.szItemName[i] = ba:readTCHAR(32)  
	end
end

--购买商品结果
CMD_Server_Shop.CMD_GR_S_ITEM_SALE = class("CMD_GR_S_ITEM_SALE",CMDBase)
function CMD_Server_Shop.CMD_GR_S_ITEM_SALE:readFormByteArray(ba)
    self.dwUserID        =          ba:readDWORD()          -- 用户ID
    self.dwSuccess       =          ba:readDWORD()          -- 当操作结果
    self.lRestScore      =          ba:readLONGLONG()       -- 用户金钱数
    self.dwItemType      =          ba:readDWORD()          -- 物品类型
    self.dwItemCount     =          ba:readDWORD()          -- 物品数量
end 


--钻石换金币
CMD_Server_Shop.CMD_GR_C_ChargeScore = class("CMD_GR_C_ChargeScore",CMDBase)
function CMD_Server_Shop.CMD_GR_C_ChargeScore:writeToByteArray(ba)
	ba:writeInt(								  self.op)                          -- 1查 2兑   
	ba:writeDWORD(                                self.dwUserID)					--用户ID
	ba:writeDWORD(								  self.dwGameID)					--游戏ID
	ba:writeInt(								  self.nItemType)					--兑换类型

end

--钻石兑换查询响应
CMD_Server_Shop.CMD_GR_S_ChargeQueryResponse = class("CMD_GR_S_ChargeQueryResponse",CMDBase)
function CMD_Server_Shop.CMD_GR_S_ChargeQueryResponse:readFormByteArray(ba)
	self.nDiamondType				=			ba:readInt()						--钻石类型
	self.nDiamondCount				=			ba:readInt()						--钻石数量
	self.nCharageRate				=			ba:readInt()						--兑换比率
end

function CMD_Server_Shop.CMD_GR_S_ChargeQueryResponse:getSize()
	return 4+4+4
end

--钻石换金币
CMD_Server_Shop.CMD_GR_S_ChargeScore = class("CMD_GR_S_ChargeScore",CMDBase)
function CMD_Server_Shop.CMD_GR_S_ChargeScore:readFormByteArray(ba)
	self.dwUserID				=			ba:readDWORD()                                 		--用户ID
	self.dwGameID				=			ba:readDWORD()								  		--游戏ID
	self.nItemType				=			ba:readInt()									  	--兑换类型
	self.bShareSuccess         	=			ba:readInt()								        --分享成功
    self.lCurUserScore         	=			ba:readLONGLONG()								    --获得分数
	self.lCurDiamondCount		=			ba:readLONGLONG()									--当前钻石数
	self.szDesc				   	=			ba:readTCHAR(64)								    --操作结果

end


return CMD_Server_Shop