--礼物、典当
local CMD_Server_Gift = {}
---
--登录服务器
CMD_Server_Gift.MDM_GP_USER_SERVICE              = 3                                   --用户服务

CMD_Server_Gift.SUB_MB_USER_SEND_GIFT_REQ        = 508                                  --赠送礼物
CMD_Server_Gift.SUB_MB_USER_SEND_GIFT_RETURN     = 509                                  --返回礼物

CMD_Server_Gift.SUB_GP_USER_PAWNSHOP_REQ         = 510                                 -- 礼物操作
CMD_Server_Gift.SUB_GP_USER_PAWNSHOP_INFO_RET    = 511                                 -- 礼物数据接收
CMD_Server_Gift.SUB_GP_USER_PAWNSHOP_SALE_RET    = 512                                 -- 礼物典当


----
--消息服务器
CMD_Server_Gift.MDM_GR_INSURE                    =5                                  --银行消息
CMD_Server_Gift.SUB_GR_USER_PAWNSHOP_REQUEST        = 8                                 --典当功能
CMD_Server_Gift.SUB_GR_USER_SENT_REQUEST             =7                               --赠送礼物
CMD_Server_Gift.SUB_GR_USER_CHECK_GIFT_REQUEST       =23                            --查询礼物请求

CMD_Server_Gift.SUB_GR_USER_SENT_RESPONSE            =105                           --赠送礼物的响应
CMD_Server_Gift.SUB_GR_USER_PRODUCT_RESPONSE         =104                                 --商品查询响应
CMD_Server_Gift.SUB_GR_USER_PAWNSHOP_INFO            =108                                --查询典当的响应
CMD_Server_Gift.SUB_GR_S_USER_SEND_GIFT_RESPONSE    = 135                           --赠送记录响应


CMD_Server_Gift.LEN_GIFT_NUM                     = 10                                  -- 礼物数据数组长度
CMD_Server_Gift.LEN_GIFT_NAME                    = 32                                  -- 礼物名字长度
CMD_Server_Gift.MAX_COLUMN                          = 32                               -- 日期长度

CMD_Server_Gift.need = {2,6,7,8,9,10,11,12}                              --需要的礼物（有些礼物不需要）
--------------------------------------------------获取礼物信息
--用户操作数据发送
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Gift.CMD_MB_GiftOption = class("CMD_MB_GiftOption",CMDBase)
function CMD_Server_Gift.CMD_MB_GiftOption:writeToByteArray(ba)
    ba:writeDWORD(                              self.option);                     --0:查, 1:典当(消息服务器是1、查 2、典当)
    ba:writeDWORD(                              self.itemType);                   --类型
    ba:writeDWORD(                              self.itemCount);                  --数量
    ba:writeDWORD(                              self.dwUserID);                   --UserID
    ba:writeDWORD(                              self.dwGameID);                   --GameID
end

function CMD_Server_Gift.CMD_MB_GiftOption:readFormByteArray(ba)                    --典当操作结果
    self.info = {}
    self.info.dwUserID =        ba:readDWORD()          --玩家UserID
    self.info.stateCode =       ba:readDWORD()          --典当操作结果
    self.info.userScore =       ba:readLONGLONG()       --用户金钱数
    self.info.itemType =        ba:readDWORD()          --物品类型
    self.info.itemCount =       ba:readDWORD()          --剩余数量
    
end

function CMD_Server_Gift.CMD_MB_GiftOption:getSize()
    local size = 4+4+8+4+4
    return size
end
local CMDBase_ = import("app/cmd/CMDBase.lua")
CMD_Server_Gift.CMD_MB_GiftInfo = class("CMD_MB_GiftInfo",CMDBase_)

function CMD_Server_Gift.CMD_MB_GiftInfo:readFormByteArray(ba)
    self.info = {}
    self.info.dwUserID = ba:readDWORD()
    self.info.giftTpye = {}             --类型
    self.info.giftNum = {}              --数量
    self.info.giftBuyPrice = {}         --买入价格
    self.info.giftPawnPrice = {}        --典当价格
    self.info.GiftName = {}             --名字
    self.info.dwNotPawn = {}
    for i = 1, CMD_Server_Gift.LEN_GIFT_NUM do
        self.info.giftTpye[#self.info.giftTpye + 1] = ba:readDWORD()
    end

    for i = 1, CMD_Server_Gift.LEN_GIFT_NUM do
        self.info.giftNum[#self.info.giftNum + 1] = ba:readDWORD()
    end

    for i = 1, CMD_Server_Gift.LEN_GIFT_NUM do
        self.info.giftBuyPrice[#self.info.giftBuyPrice + 1] = ba:readDWORD()
    end

    for i = 1, CMD_Server_Gift.LEN_GIFT_NUM do
        self.info.giftPawnPrice[#self.info.giftPawnPrice + 1] = ba:readDWORD()
    end           

    for i = 1, CMD_Server_Gift.LEN_GIFT_NUM do
        self.info.GiftName[#self.info.GiftName + 1] = ba:readTchar(CMD_Server_Gift.LEN_GIFT_NAME)
    end 

    for i = 1, CMD_Server_Gift.LEN_GIFT_NUM do          --是否不可以典当(true是不可以， 为false是普通的)
        self.info.dwNotPawn[#self.info.dwNotPawn + 1] = ba:readBool()
    end
    print("aaa")  
end

function CMD_Server_Gift.CMD_MB_GiftInfo:getSize()
    local num = CMD_Server_Gift.LEN_GIFT_NUM
    local size = 4 + 4*num + 4*num + 4*num + 4*num + 2*12*32 + 1*num + 1*num + 1*num
    return size
end


--------------------------------------赠送礼物
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Gift.CMD_MB_Gift_send_Option = class("CMD_MB_Gift_send_Option",CMDBase)
function CMD_Server_Gift.CMD_MB_Gift_send_Option:writeToByteArray(ba)
    ba:writeInt(                              self.dwRecvUserID);                     --目标UserID
    ba:writeInt(                              self.dwItemType);                   --类型
    ba:writeInt(                              self.dwItemCount);                  --数量
    ba:writeInt(                              self.dwPrice);                   --价格
end

--赠送礼物(登录服务器)
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Gift.CMD_GR_C_User_Sent_Request = class("CMD_GR_C_User_Sent_Request",CMDBase)
function CMD_Server_Gift.CMD_GR_C_User_Sent_Request:writeToByteArray(ba)
    ba:writeDWORD(                            self.dwRecvGameID);              --目标
    ba:writeDWORD(                            self.dwSentGameID);              --送出GameID
    ba:writeDWORD(                            self.dwSentUserID);              --送出UserID
    ba:writeInt(                              self.ItemType);                   --类型
    ba:writeInt(                              self.ItemCount);                  --数量
end

local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Gift.CMD_MB_Gift_send_Option = class("CMD_MB_Gift_send_Option",CMDBase)
function CMD_Server_Gift.CMD_MB_Gift_send_Option:writeToByteArray(ba)
    ba:writeInt(                              self.dwRecvUserID);                     --目标UserID
    ba:writeInt(                              self.dwItemType);                   --类型
    ba:writeInt(                              self.dwItemCount);                  --数量
    ba:writeInt(                              self.dwPrice);                   --价格
end

local CMDBase_ = import("app/cmd/CMDBase.lua")
CMD_Server_Gift.CMD_MB_Gift_send_Info = class("CMD_MB_Gift_send_Info",CMDBase_)
function CMD_Server_Gift.CMD_MB_Gift_send_Info:readFormByteArray(ba)
    self.info = {}
    self.info.dwSendUserID =        ba:readDWORD()             --赠送玩家UserID
    self.info.dwRecvUserID =        ba:readDWORD()             --接收玩家UserID
    self.info.giftType =            ba:readInt()               --类型
    self.info.giftNum =             ba:readInt()               --数量
    self.info.ret =                 ba:readInt()               --1成功;0失败
    self.info.nInsureScores =       ba:readLONGLONG()          --剩余金币
    self.info.szdesc =              ba:readTchar(64)           --描述
end

function CMD_Server_Gift.CMD_MB_Gift_send_Info:getSize()
    local size = 4+4+4+4+4+8+128
    return size
end

local CMDBase_ = import("app/cmd/CMDBase.lua")
CMD_Server_Gift.CMD_SUB_S_GR_UserSentResponse = class("CMD_SUB_S_GR_UserSentResponse",CMDBase_)
function CMD_Server_Gift.CMD_SUB_S_GR_UserSentResponse:readFormByteArray(ba)
    self.lScore       =        ba:readLONGLONG()          --剩余金币   
    self.dwSendGameID =        ba:readDWORD()             --赠送玩家
    self.dwSentUserID =        ba:readDWORD()             --赠送玩家
    self.dwRecvGameID =        ba:readDWORD()             --接收玩家
    self.nItemType =           ba:readInt()               --类型
    self.nItemCount =          ba:readInt()               --数量
    self.nRet =                ba:readInt()               --0成功;1失败
    self.szdesc =              ba:readTchar(128)           --描述
end

-----
--赠送礼物请求
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Gift.CMD_MB_GiftRecord = class("CMD_MB_GiftRecord",CMDBase)
function CMD_Server_Gift.CMD_MB_GiftRecord:writeToByteArray(ba)
    ba:writeDWORD(                              self.dwSourceGameID);                   --当前用户ID
    ba:writeDWORD(                              self.dwDecGameID);                      --目标用户ID
    ba:writeDWORD(                              self.dwTargetID);                       --目标ID(为0时返回全部)
    ba:writeWORD(                              self.wNumber);                           --请求数量
end

function CMD_Server_Gift.CMD_MB_GiftRecord:readFormByteArray(ba)

    self.allInfo = {}
    local len_ = ba:getLength()
    for i = 1,ba:getLength()/self:getSize()do
        local info = {}
        info.dwSourceGameID =         ba:readDWORD()             --当前用户ID
        info.dwDecGameID =            ba:readDWORD()             --目标用户ID
        info.wGiftType =              ba:readWORD()               --类型
        info.wGiftCount =             ba:readWORD()               --数量
        info.szNickName =             ba:readTchar(32)          --用户昵称
        info.szDateTime =             ba:readTchar(32)          --送礼日期
        info.szDescMsg =              ba:readTchar(64)           --结果提示
        info.bInOut=                  ba:readInt()              --交易类型(赠送:1 收到0)
        if info.wGiftCount > 0 then
            table.insert(self.allInfo,info)
        end
    end
end

function CMD_Server_Gift.CMD_MB_GiftRecord:getSize()
    local size = 4+4+2+2+64+64+128+4
    return size
end

return CMD_Server_Gift