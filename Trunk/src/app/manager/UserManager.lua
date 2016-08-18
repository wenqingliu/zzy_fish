local UserManager = class("UserManager")
local UserData = import("app/models/data/UserData")
local GCMD_Sever_Friends = import("app/cmd/loginSever/CMD_Sever_Friends.lua")

function UserManager:ctor()
    self.m_userList = {}
    self.nTableID = INVALID_TABLE--默认值,与服务器对应
    self.nChairID = INVALID_CHAIR
    self.nChairCount = 0
    self.nViewID = {}
end

function UserManager:start()
    if not self._isRunning then
        self._isRunning = true
        CFrameDataHandler:getInstance():addNotifyListener(self)
    end
end

function UserManager:OnTCPWithDataLoad(notify)
    if notify:getMainType() == GCMD_Sever_Friends.MDM_GP_USER_SERVICE then
        local sub = notify:getSubType()
        if sub == GCMD_Sever_Friends.SUB_MB_LOAD_FRIEND_LIST then
            return self:OnSocketSubFriendsList(notify)
        elseif sub == GCMD_Sever_Friends.SUB_MB_FRIENT_BLACKLIST then
            return self:OnSocketSubFriendBlackList(notify)
        end
    end
    
    return false
end

--获取好友列表
function UserManager:OnSocketSubFriendsList(notify)
--    local notify = event._userData
--    GameManager:getUserSelf().friendsList = {}
    
    if notify:getSize() == 0 then
        --        GameManager:showAlert(self,"好友提示","好友列表为空")
        printf("好友列表为空")
    else
        local friends = {}
        local cmd = GCMD_Sever_Friends.DBR_MB_UserFriendInfo:createWithNotify(notify)
        for k,friend_user in ipairs(cmd.allUser) do
            local pUser = UserData:create()
            pUser:setScore(0)
            pUser:setNickName(friend_user.szNickName)
            pUser:setGameID(friend_user.dwPlayID)
            pUser:setFaceURL(friend_user.szPlayHeadUrl)
            pUser:setGender(friend_user.cbGender)
            pUser:setsignature(friend_user.szUnderWrite)
            pUser:setUserID(friend_user.dwUserID)
            pUser:setMemberOrder(friend_user.wVipLevel)
            pUser:setIsOnline(friend_user.cbUserStatus)
            table.insert(GameManager:getUserSelf().friendsList,pUser)
            table.insert(friends,pUser)
        end
        CFrameDataHandler:getInstance():dispatchEvent({name = "reFreshFriendList",_userData=GameManager:getUserSelf().friendsList})
    end
    return true
--    GameManager:getFriendsBlackList()
end

--获取黑名单
function UserManager:OnSocketSubFriendBlackList(notify)
--    local notify = event._userData
    
--    GameManager:getUserSelf().blackList = {}
    if notify:getSize() == 0 then
        --        GameManager:showAlert(self,"好友提示","好友列表为空")
        print("黑名单列表为空")
    else
        local friends = {}
        local cmd = GCMD_Sever_Friends.DBR_MB_UserFriendInfo:createWithNotify(notify)
        for k,friend_user in ipairs(cmd.allUser) do
            local pUser = UserData:create()
            pUser:setScore(0)
            pUser:setNickName(friend_user.szNickName)
            pUser:setGameID(friend_user.dwPlayID)
            pUser:setFaceURL(friend_user.szPlayHeadUrl)
            pUser:setGender(friend_user.cbGender)
            pUser:setsignature(friend_user.szUnderWrite)
            pUser:setUserID(friend_user.dwUserID)
            pUser:setMemberOrder(friend_user.wVipLevel)
            pUser:setIsOnline(friend_user.cbUserStatus)
            table.insert(GameManager:getUserSelf().blackList,pUser)
            table.insert(friends,pUser)
        end
        CFrameDataHandler:getInstance():dispatchEvent({name = "reFreshBlackList",_userData=friends})
    end
    return true
end
-------------------------------------------------------------------
--
function UserManager:onInitGameInfo(chaircount)
    if self.nChairCount ~= chaircount then
        self.nChairCount = chaircount
        self.nViewID = {}
        for i = 1, chaircount do
            self.nViewID[i] = INVALID_CHAIR
        end
    end
end

--设置桌子信息
function UserManager:onSetTableInfo(tableid,chairid)
    self.nTableID = tableid
    self.nChairID = chairid
    if self.nTableID ~= INVALID_TABLE and self.nChairID ~= INVALID_CHAIR then
        for i = 1,self.nChairCount do
            local viewId = self:switchViewChairID(i-1)
            self.nViewID[viewId+1] = i-1
        end
    end
end

-------
--将服务器椅子号转换成本地显示椅子号
function UserManager:switchViewChairID(chair)
    if self.nTableID == INVALID_TABLE or self.nChairID == INVALID_CHAIR or chair >= self.nChairCount then
        return INVALID_CHAIR
    else
        return ((chair +  math.floor(self.nChairCount * 3 / 2)) - self.nChairID) % self.nChairCount
    end
end

--获取当前桌子人数
function UserManager:getTableUserCount()
    local count = 0
    for i = 1,#self.m_userList do
        local item = self.m_userList[i]
        if item:getTableID() == self.nTableID and item:getChairID() ~= INVALID_CHAIR then
            count = count + 1
        end
    end
    return count
end

-------------------------------------------------------------------//


-------------------------------------------------------------------
-- 用户数据操作

--获得自己
function UserManager:getUserItemSelf()
    return self:getUserItem(GameManager:getUserSelf():getUserID())
end

--获取用户
function UserManager:getUserItem(userID)
    for i=1,#self.m_userList do
        local pUser = self.m_userList[i]
        if pUser ~= nil and pUser:getUserID() == userID then
            return pUser 
        end
    end
    return nil
end

--获取用户
function UserManager:getClientUserItem(index)
    local chairID = self.nViewID[index]
    if self.nTableID == INVALID_TABLE or chairID == INVALID_CHAIR then
        return nil
    end
    
    for i = 1,#self.m_userList do
        local item = self.m_userList[i]
        if item:getTableID() == self.nTableID and item:getChairID() == chairID then
            return item;
        end
    end
    return nil
end

--获取用户
function UserManager:getUserItemWithChairID(chairID)
    for i=1,#self.m_userList do
        local pUser = self.m_userList[i]
        if pUser ~= nil and pUser:getChairID() == chairID then
            return pUser 
        end
    end
    return nil
end

--查找用户
function UserManager:searchUserByUserID(userid)
    if (userid == 0 or userid == INVALID_CHAIR) then 
        return nil
    end
    for i = 1,#self.m_userList do
        local item = self.m_userList[i]
        if item:getUserID() == userid then
            return item
        end
    end
    return nil
end

--查找用户
function UserManager:searchUserByGameID(gameID)
    if (gameID == 0 or gameID == INVALID_CHAIR) then 
        return nil
    end
    for i = 1,#self.m_userList do
        local item = self.m_userList[i]
        if item:getGameID() == gameID then
            return item
        end
    end
    return nil
end

--查找用户
function UserManager:searchUserByTableInfo(table,chair)
    if table == INVALID_TABLE or chair == INVALID_CHAIR then 
        return nil 
    end
    for i = 1,#self.m_userList do
        local item = self.m_userList[i]
        if item:getTableID() == table and item:getChairID() == chair then
            return item
        end
    end
    return nil
end

function UserManager:searchAllUserByTable(table)
    if table == INVALID_TABLE then 
        return nil 
    end
    local allList = {}
    for i = 1,#self.m_userList do
        local item = self.m_userList[i]
        if item:getTableID() == table then
            allList[#allList+1] = item
        end
    end
    return allList
end

--设置用户
function UserManager:setUserItem(item)
    --查找是否已有用户
    for i=1,#self.m_userList do
        local pUser = self.m_userList[i]
        if pUser:getUserID() == item:getUserID() then
            self.m_userList[i] = item
            return
        end
    end
    --添加新用户
    self.m_userList[#self.m_userList+1] = item
end

--获取用户等级
function UserManager:getLevel(s)
    if s >= 0 and s <= 2000 then
        return "务农";
    elseif s > 2000 and s <= 4000 then
        return "佃户";
    elseif s > 4000 and s <= 8000 then
        return "雇工";
    elseif s > 8000 and s <= 20000 then
        return "作坊主";
    elseif s > 20000 and s <= 40000 then
        return "农场主";
    elseif s > 40000 and s <= 150000 then
        return "地主";
    elseif s > 80000 and s <= 300000 then
        return "大地主";
    elseif s > 150000 and s <= 500000 then
        return "财主";
    elseif s > 300000 and s <= 1000000 then
        return "富翁";
    elseif s > 500000 and s <= 2000000 then
        return "大富翁";
    elseif s > 1000000 and s <= 5000000 then
        return "小财神";
    elseif s > 2000000 and s <= 10000000 then
        return "大财神";
    elseif s > 5000000 and s <= 50000000 then
        return "赌棍";
    elseif s > 10000000 and s <= 100000000 then
        return "赌侠";
    elseif s > 50000000 and s <= 500000000 then
        return "赌王";
    elseif s > 100000000 and s <= 500000000 then
        return "赌圣";
    elseif s > 500000000 and s <= 1000000000 then
        return "赌神";
    elseif s > 1000000000 then
        return "职业赌神";
    end
    return "";
end

function UserManager:getGender(gender)
    if gender == GENDER_FEMALE then
        return "女"
    elseif gender == GENDER_MANKIND then
        return "男"
    end
    return "保密"
end

--获取用户胜率
function UserManager:getShenglv(WinCount,LostCount) 
    local per = 0;
    local allcount = WinCount + LostCount
    if allcount ~= 0 then
        per = WinCount / allcount;
        -- 精度到小数后1位
        per = math.floor(per * 100, 1);
    end
    return per;
end

function UserManager:getDefaultFace(gender)
    --设置头像
    if gender == 0 then
        return "image/head/head_br_nv.jpg"
    else
        return "image/head/head_br_nan.jpg"
    end
end

----------------
-- @param self
-- @param 
--
function UserManager:onEventUserStatus(userid,oldstatus,newstatus)
    for i = 1,#self.m_userList do
        local item = self.m_userList[i]
        if item:getUserID() == userid then
            item:setTableID(newstatus:wTableID())
            item:setChairID(newstatus:wChairID())
            item:setUserStatus(newstatus:cbUserStatus())
            return item
        end
    end
    return nil
end

function UserManager:onEventUserScore(lUserid,oldscore,newscore)
    for i = 1,#self.m_userList do
        local item = self.m_userList[i]
        if item:getUserID() == lUserid then
            item:setScore(newscore:lScore())
--            item:setInsureScore(newscore:lInsure())
--            lInsure = score.lInsure;
            item:setWinCount(newscore:dwWinCount());
            item:setLostCount(newscore:dwLostCount());
            item:setDrawCount(newscore:dwDrawCount());
            item:setFleeCount(newscore:dwFleeCount());
            item:setExp(newscore:dwExperience());
            return item;
        end
    end

   return nil;
end

-------------------------------------------------------------------//

--清空数据
function UserManager:removeUserItemAll()
    self.m_userList = {}
end

--清空数据
function UserManager:removeRoomUserItem()
    local userSelf = GameManager:getUserSelf()
    self.m_userList = {userSelf}
end

function UserManager:destroy()
    self._isRunning = false
    CFrameDataHandler:getInstance():removeNotifyListener(self)
    
    self:removeUserItemAll()
end

return UserManager