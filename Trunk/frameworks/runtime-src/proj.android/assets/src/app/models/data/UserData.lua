local UserData = class("UserData")
local LuaUtil = import("app/library/LuaUtil")
function UserData:ctor()
    
    --基本信息
    self.nickName         = ""               --昵称
    self.score            = 0                --用户分数
    
    --头像信息
    self.faceID           = 0                --头像索引
    self.customID        = 0                --自定标识
    self.faceURL  = ""                --自定义头像下载地址

    --用户属性
    self.gender          = 0                --用户性别
    self.memberOrder     = 0                --VIP会员等级
    
    self.insureScore    = 0                 --银行金币

    --用户状态
    self.tableID         = INVALID_TABLE    --桌子索引
    self.chairID         = INVALID_CHAIR    --椅子索引
    self.userStatus      = 0                --用户状态

    --游戏信息
    self.winCount        = 0                --胜利盘数
    self.lostCount       = 0                --失败盘数
    self.drawCount       = 0                --和局盘数
    self.fleeCount       = 0                --逃跑盘数
    self.exp             = 0                --用户经验
    
    self.friendsList = {}                   --好友列表
    self.blackList = {}                     --黑名单
    self.signature = ""                     --个性签名
    self.VIPHornNum     = 0                 --VIP喇叭数量
    self.hornNum        = 0                 --喇叭数量
    self.diamond        = 0                 --钻石数量
    self.isOnline       = 0                 --是否在线
end

--昵称
function UserData:getNickName()
    return self.nickName
end

function UserData:setNickName(nickName)
    if device.platform == "ios" then
        self.nickName = LuaUtil:filterChar(nickName)
    else
        self.nickName = nickName
    end
end
--//

--玩家ID
function UserData:getGameID()
    return self.gameID
end

function UserData:setGameID(gameID)
    self.gameID = gameID
end
--//

--用户ID
function UserData:getUserID()
    return self.userID
end

function UserData:setUserID(userID)
    self.userID = userID
end
--//

--头像
function UserData:getFaceID()
    return self.faceID
end

function UserData:setFaceID(faceID)
    self.faceID = faceID
end
--//

--自定义标识
function UserData:getCustomID()
    return self.customID
end

function UserData:setCustomID(customID)
    self.customID = customID
end
--//

--自定义头像下载地址
function UserData:getFaceURL()
    return self.faceURL
end

function UserData:setFaceURL(url)
    self.faceURL = url
end
--//

--性别
function UserData:getGender()
    return self.gender
end

function UserData:setGender(gender)
    self.gender = gender
end
--//

--会员等级
function UserData:getMemberOrder()
    return self.memberOrder
end

function UserData:setMemberOrder(memberOrder)
    self.memberOrder = memberOrder
end
--//

--分数
function UserData:getScore()
    return self.score
end

function UserData:setScore(score)
    self.score = score
end
--//

--桌子
function UserData:getTableID()
    return self.tableID
end

function UserData:setTableID(tableID)
    self.tableID = tableID
end
--//

--椅子
function UserData:getChairID()
    return self.chairID
end

function UserData:setChairID(chairID)
    self.chairID = chairID
end
--//

--用户状态
function UserData:getUserStatus()
    return self.userStatus
end

function UserData:setUserStatus(userStatus)
    self.userStatus = userStatus
end
--//

--胜利盘数
function UserData:getWinCount()
    return self.winCount
end

function UserData:setWinCount(winCount)
    self.winCount = winCount
end
--//

--失败盘数
function UserData:getLostCount()
    return self.lostCount
end

function UserData:setLostCount(lostCount)
    self.lostCount = lostCount
end
--//

--和局盘数
function UserData:getDrawCount()
    return self.drawCount
end

function UserData:setDrawCount(drawCount)
    self.drawCount = drawCount
end
--//

--逃跑盘数
function UserData:getFleeCount()
    return self.fleeCount
end

function UserData:setFleeCount(fleeCount)
    self.fleeCount = fleeCount
end
--//

--经验
function UserData:getExp()
    return self.exp
end

function UserData:setExp(exp)
    self.exp = exp
end
--//

--银行金币
function UserData:getInsureScore()
    return self.insureScore
end

function UserData:setInsureScore(insureScore)
    self.insureScore = insureScore
end
--//
--个性签名
function UserData:getsignature()
    return self.signature
end

function UserData:setsignature(signature_)
    self.signature = signature_
end

--喇叭
function UserData:getHornNum()
    return self.hornNum
end

function UserData:setHornNum(num)
    self.hornNum = num
end

--VIP喇叭
function UserData:getVIPHornNum()
    return self.VIPHornNum
end

function UserData:setVIPHornNum(num)
    self.VIPHornNum = num
end

--总喇叭
function UserData:getAllHornNum()
    return self.VIPHornNum + self.hornNum
end

function UserData:setAllHornNumDownOne()
    if self.VIPHornNum > 0 then
        self.VIPHornNum = self.VIPHornNum - 1
    else
        self.hornNum = self.hornNum - 1
    end
end

--钻石数量
function UserData:getDiamond()
    return self.diamond
end

function UserData:setDiamond(num)
    self.diamond = num
end

--是否在线
function UserData:getIsOnline()
    return self.isOnline
end

function UserData:setIsOnline(online)
    self.isOnline = online
end
return UserData