local BaseLayer          = import("app/views/layer/BaseLayer.lua")
local FriendsLayer       = class("FriendsLayer",BaseLayer)
local FriendTalkLayer    = import("app/views/layer/FriendTalkLayer.lua")
local CMD_Sever_Friends = import("app/cmd/loginSever/CMD_Sever_Friends.lua")
local PersonInfoLayer    = import("app/views/layer/PersonInfoLayer.lua")
local UserData           = import("app/models/data/UserData")
local URLLoaderHandler   = import("app/handler/URLLoaderHandler.lua")
local PawnShopLayer      = import("app/views/layer/PawnShopLayer.lua")
local logger             = zzy.Logger.new("FriendsLayer")

FriendsLayer.events = {
    addToBlackListSuccesful     = "addToBlackListSuccesful",            --添加黑名单成功
    getChatMessage_friendsLayer = "getChatMessage_friendsLayer",        --收到聊天消息
    reFreshFriendList           = "reFreshFriendList",
    reFreshBlackList            = "reFreshBlackList",
    friendOnlineFromHall        = "friendOnlineFromHall",               --从大厅传过来好友上下线
}

function FriendsLayer:ctor()
    self.super.ctor(self)

    display.addSpriteFrames("hall/friend.plist","hall/friend.png")
    display.addSpriteFrames("common.plist","common.png")

    self.unverifiedList = {}
    self.recommendFriendsList = {}
    self.isShowAddFriend = false
    self.isShowRecommend = false
    self.isShowBlack = false

    self.panel = display.newSprite("#common_layer_bg.png"):addTo(self):setPosition(display.cx,display.cy-10)
    self:setRootBg(self.panel)
    local size = self.panel:getContentSize()
    self.btnClose = ccui.Button:create("btn_close.png","btn_close.png","btn_close.png",1):addTo(self.panel,1):setPosition(size.width - 20,size.height - 20)
    self.btnClose:addTouchEventListener(handler(self,self.onBtnCloseClick))
    self.node = display.newNode():addTo(self.panel):setPosition(0,0)
    self:show()
    GameManager.isFriendsListLayer = true

    CFrameDataHandler:getInstance():addEventListener(self.events.addToBlackListSuccesful,handler(self,self.addToBlackListCallback))
    -- CFrameDataHandler:getInstance():addEventListener(self.events.getChatMessage_friendsLayer,handler(self,self.getMessage))
    CFrameDataHandler:getInstance():addEventListener(self.events.reFreshFriendList,handler(self,self.refreshFriendList))
    CFrameDataHandler:getInstance():addEventListener(self.events.reFreshBlackList,handler(self,self.addBlackList))
    -- CFrameDataHandler:getInstance():addEventListener(self.events.friendOnlineFromHall,handler(self,self.onFriendOnlineFromHall))

    GameManager:getFriendsList()
    self:showMyFriendsPanel()
    --TODO CFrameDataHandler:getInstance():sendPacketWithLoadSpreadried()  --查询推广员
end

function FriendsLayer:OnTCPWithDataLoad(notify)
    if notify:getMainType() == CMD_Sever_Friends.MDM_GP_USER_SERVICE then --用户服务(主命令)
        local sub = notify:getSubType()
        if sub == CMD_Sever_Friends.SUB_MB_FRIENT_QUERY_USER then   --查找用户
            return self:showSearchFriend(notify)
        elseif sub == CMD_Sever_Friends.SUB_MB_FRIENT_SYS_RECOMMEN then   --推荐好友
            return self:RecommendFriends(notify)
        elseif sub == CMD_Sever_Friends.SUB_MB_FRIENT_REMOVE_BLACKLIST then --移除黑名单
            return self:deleteBlackFriendCallBack(notify)
        elseif sub == CMD_Sever_Friends.SUB_MB_USER_CHECK_SPREADERID then   --查询推广员ID
            return true--self:onFriendspreadried(notify)
        end
    end
    return false
end

function FriendsLayer:OnTCPWithDataRoom(notify)
    if notify:getMainType() == CMD_Sever_Friends.MDM_GR_INSURE then        --银行命令 5
        local sub = notify:getSubType()
        if sub == CMD_Sever_Friends.SUB_GR_S_Query_Friend_Unverified then  --待验证好友响应
            return self:onUnverifiedList(notify)
        elseif sub == CMD_Sever_Friends.SUB_GR_S_FRINED_VERIFIED_RESP then --同意或拒绝响应
            return self:onVerifiedBack(notify)
        end
    end
    if notify:getMainType() == CMD_Room_User.MDM_GR_USER then             --用户信息3
        local sub = notify:getSubType()
        if sub == CMD_Sever_Friends.SUB_GR_USER_ADD_SPREADER_RES then   --添加推广员回复
            return true--self:onFriendAddSpreadried(notify)
        end
    end
    return false
end

function FriendsLayer:showCallBack()
    self:setupTab()
end

function FriendsLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

local tabPosX = {160,453,742,1032}
local tabPosY = 600
function FriendsLayer:setupTab()
    self.tabs = {}
    self.tabs[1] = ccui.Button:create("tab_myfriend_back.png","tab_myfriend_front.png","tab_myfriend_front.png",1):addTo(self.panel):setPosition(tabPosX[1],tabPosY)
    self.tabs[2] = ccui.Button:create("tab_addfriend_back.png","tab_addfriend_front.png","tab_addfriend_front.png",1):addTo(self.panel):setPosition(tabPosX[2],tabPosY)
    self.tabs[3] = ccui.Button:create("tab_recommend_back.png","tab_recommend_front.png","tab_recommend_front.png",1):addTo(self.panel):setPosition(tabPosX[3],tabPosY)
    self.tabs[4] = ccui.Button:create("tab_blacklist_back.png","tab_blacklist_front.png","tab_blacklist_front.png",1):addTo(self.panel):setPosition(tabPosX[4],tabPosY)

    for i = 1, 4 do
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[1]:setTouchEnabled(false)
    self.tabs[1]:setBright(false)

    self.particle = cc.ParticleSystemQuad:create("particle/diandian.plist")
    self.particle:setPosition(tabPosX[1],tabPosY-15)
    self.particle:setScale(0.5)
    self.particle:addTo(self.panel)

    self.tabIdx = 1
    GameManager.isFriendsListLayer = true
end

function FriendsLayer:onTabClick(ref, type)
    if type == 2 then --release
        audio.playSound("music/click")
        for i = 1,4 do
            if ref == self.tabs[i] then
                self:setTab(i)
            end
        end
    end
end

function FriendsLayer:setTab(tabIdx)
    for i = 1, 4 do
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[tabIdx]:setTouchEnabled(false)
    self.tabs[tabIdx]:setBright(false)

    self.particle:setPosition(tabPosX[tabIdx],tabPosY - 15)


    GameManager.isFriendsListLayer = false
    self.tabIdx = tabIdx

    if tabIdx == 1 then
        self:showMyFriendsPanel()
        GameManager.isFriendsListLayer = true
    elseif tabIdx == 2 then
        if GameManager.transferState ~= 0 or device.platform ~= "ios" then
            self:showUnverifiedPanel()
        end
    elseif tabIdx == 3 then
        self:showRecommendPanel()
    elseif tabIdx == 4 then
        self:showBlackListPanel()
    end
end

function FriendsLayer:onBtnCloseClick(ref, type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        self:hide()
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function FriendsLayer:showMyFriendsPanel()
    self.node:removeAllChildren()

    local bg = display.newSprite("#bg_friend_content.png"):addTo(self.node):setPosition(598,290)

    local seachEditBox = ccui.EditBox:create(cc.size(426,58),"friend_search_box.png",1):addTo(bg):setPosition(310,458)
    seachEditBox:setFontSize(36)
    seachEditBox:setFontColor(cc.c3b(10,10,10))
    seachEditBox:setPlaceHolder("搜索用户")
    seachEditBox:setPlaceholderFontSize(36)
    seachEditBox:setPlaceholderFontColor(cc.c3b(110,110,110))
    local btnSearch = ccui.Button:create("btn_friend_search.png","btn_friend_search.png","btn_friend_search.png",1):setPosition(500,458):addTo(bg)
    btnSearch:addTouchEventListener(function(ref,eventType)
        if eventType == 0 then --begin
             transition.scaleTo(ref, {time = 0.05, scale = 0.9})
        elseif eventType == 1 then --moved
        elseif eventType == 2 then --release
            audio.playSound("music/click")
            transition.scaleTo(ref, {time = 0.05, scale = 1})
            local str = seachEditBox:getText()
            if  str ~= "" then
                CFrameDataHandler:getInstance():sendPacketWithLoadSearchFriend(str)
            end
        elseif eventType == 3 then --cancle
            transition.scaleTo(ref, {time = 0.05, scale = 1})
        end
    end)

    self.friendListView = ccui.ListView:create():addTo(bg)
    self.friendListView:setDirection(1)
    self.friendListView:setTouchEnabled(true)
    self.friendListView:setBounceEnabled(true)
    self.friendListView:setPosition(34,15)
    self.friendListView:setContentSize(cc.size(1090,404))
    -- self.friendListView:setClippingType(1)

    self:showFriendsList(GameManager:getUserSelf().friendsList)
end

function FriendsLayer:showFriendsList(friendsList)
    --TODO friend num & freind search

    self.friendListView:removeAllItems()
    GameManager:getUserSelf().friendsList = self:sortFriends(GameManager:getUserSelf().friendsList)
    local friendList = GameManager:getUserSelf().friendsList
    for k,v in ipairs(friendList) do
        local friendItem = display.newNode()
        friendItem:setTag(1)
        local split = display.newSprite("#split.png"):addTo(friendItem):setPosition(500,0)
        local btnChat = ccui.Button:create("btn_friend_chat.png","btn_friend_chat.png","btn_friend_chat.png",1):setPosition(950,68):addTo(friendItem)
        btnChat:addTouchEventListener(handler(self,self.talk))
        btnChat.user = v
        local head = display.newNode():addTo(friendItem):setPosition(99,68)
        head = MotionUtil:RepleaceWithURLPic(head,v,cc.size(105,105))
        if v:getIsOnline() == 0 then
            head:setColor(cc.c3b(96,96,96))
        end

        local headBoard = ccui.Button:create("head_board.png","head_board.png","head_board.png",1):addTo(friendItem,1):setPosition(100,68):setScale(1.52)
        headBoard:setTouchEnabled(true)
        headBoard:addTouchEventListener(handler(self,self.ClickUser))
        headBoard.user = v

        local labelName = cc.Label:create():addTo(friendItem,1):setPosition(180,84):setAnchorPoint(0,0.5)
        :setString(v:getNickName()):setSystemFontSize(38):setTextColor(cc.c4b(3,36,67,255))
        MotionUtil:cutLabel(labelName,250)

        local labelID = cc.Label:create():addTo(friendItem,1):setPosition(450,84):setAnchorPoint(0,0.5)
        :setString("(ID:"..v:getGameID()..")"):setSystemFontSize(38):setTextColor(cc.c4b(202,48,0,255))

        local sign = v:getsignature()
        local strSign = sign == "" and "这家伙很懒,什么都没留下" or sign
        local labelSign = cc.Label:create():addTo(friendItem,1):setPosition(180,32):setAnchorPoint(0,0.5)
        :setString("个性签名："..strSign):setSystemFontSize(32):setTextColor(cc.c4b(58,61,80,255))
        MotionUtil:cutLabel(labelSign,500)

        local layout = ccui.Layout:create()
        layout:setTag(k)
        layout.user = v
        layout.head = head
        layout:addChild(friendItem)
        layout:setContentSize(cc.size(1080,136))
        self.friendListView:pushBackCustomItem(layout)
    end
end

function FriendsLayer:showUnverifiedPanel()
    self.node:removeAllChildren()
    if not self.isShowAddFriend then
        if GameManager.transferState ~= 0 then
            CFrameDataHandler:getInstance():sendPacketWithLoadUnverifiedList()          --获取待验证好友列表
        end
        self.isShowAddFriend = true
    end

    self.unverifiedListView = ccui.ScrollView:create():addTo(self.node)
    self.unverifiedListView:setTouchEnabled(true)
    self.unverifiedListView:setBounceEnabled(true)
    self.unverifiedListView:setPosition(34,45)
    self.unverifiedListView:setContentSize(cc.size(1100,510))
    self.unverifiedListView:setClippingType(1)

    self:showUnverifiedList()
end

function FriendsLayer:showUnverifiedList()
    self.unverifiedListView:removeAllChildren()
    local list = self.unverifiedList

    local innerHeight = math.ceil(#list/3)*260
    self.unverifiedListView:setInnerContainerSize(cc.size(1100,innerHeight))
    for i = 1,#list do
        local item = display.newSprite("#bg_addfriend_item.png")
        local v = list[i]

        local xt = i%3
        xt = xt == 0 and 3 or xt
        local yt = math.ceil(i/3)
        item:setPosition(-200 + xt*378,innerHeight + 125 - yt * 260)

        local btnAgree = ccui.Button:create("btn_agree.png","btn_agree.png","btn_agree.png",1):setPosition(85,50):addTo(item)
        btnAgree:addTouchEventListener(handler(self,self.agreeOrRefuse))
        btnAgree.user = v
        btnAgree.which = 0

        local btnReject = ccui.Button:create("btn_reject.png","btn_reject.png","btn_reject.png",1):setPosition(245,50):addTo(item)
        btnReject:addTouchEventListener(handler(self,self.agreeOrRefuse))
        btnReject.user = v
        btnReject.which = 1

        local gender = v:getGender()
        if gender == 0 then
           display.newSprite("#icon_friend_female.png"):addTo(item):setPosition(264,212)
        else
           display.newSprite("#icon_friend_male.png"):addTo(item):setPosition(264,212)
        end

        local head = display.newNode():addTo(item):setPosition(75,155)
        head = MotionUtil:RepleaceWithURLPic(head,v,cc.size(110,110))

        local headBoard = ccui.Button:create("head_board_big.png","head_board_big.png","head_board_big.png",1):addTo(item,1):setPosition(75,155)
        headBoard:setTouchEnabled(true)
        headBoard:addTouchEventListener(handler(self,self.ClickUser))
        headBoard.user = v

        local labelName = cc.Label:create():addTo(item,1):setPosition(145,150):setAnchorPoint(0,0.5)
        :setString(v:getNickName()):setSystemFontSize(30):setTextColor(cc.c4b(255,255,255,255))
        MotionUtil:cutLabel(labelName,150)

        local labelID = cc.Label:create():addTo(item,1):setPosition(145,105):setAnchorPoint(0,0.5)
        :setString("ID:"..v:getGameID()):setSystemFontSize(26):setTextColor(cc.c4b(252,194,8,255))

        self.unverifiedListView:addChild(item)
    end
end

--0 同意  1：拒绝
function FriendsLayer:agreeOrRefuse(sender,eventType)
    BtnGroup:onTouchButton(sender,eventType)
    if eventType == 2 then
        audio.playSound("music/click")
        self.nowVerfiedUser = sender.user
        CFrameDataHandler:getInstance():sendPacketWithLoadVerifrid(sender.user:getGameID(),sender.which)
    end
end

function FriendsLayer:onVerifiedBack(notify)
    if notify:getSize() ~= 0 then
        local cmd = CMD_Sever_Friends.CMD_GR_S_Verifiend_RESP:createWithNotify(notify)
        if cmd.dwStatus == 0 then               --同意成功
            GameManager:showAlertSystem(self,cmd.szDesc)
            local index_ = self:findUserIndex(self.nowVerfiedUser,self.unverifiedList)
            if index_ ~= 0 then
                table.remove(self.unverifiedList,index_)
                if self.tabIdx == 2 then
                    self:showUnverifiedPanel()
                end
                self.nowVerfiedUser:setIsOnline(cmd.cbUserStatus)
                GameManager:getUserSelf().friendsList = self:insertToFriendsList(GameManager:getUserSelf().friendsList,self.nowVerfiedUser)

                CFrameDataHandler:getInstance():dispatchEvent({name = "reFreshFriendList",_userData=GameManager:getUserSelf().friendsList})       --刷新好友列表
                self.nowVerfiedUser = nil
            end
        elseif cmd.dwStatus == 100 then         --拒绝成功
            GameManager:showAlertSystem(self,"您已拒绝该用户的好友申请")
            local index_ = self:findUserIndex(self.nowVerfiedUser,self.unverifiedList)
            if index_ ~= 0 then
                table.remove(self.unverifiedList,index_)
                self.nowVerfiedUser = nil
                if self.tabIdx == 2 then
                    self:showUnverifiedPanel()
                end
            end

        else                                    --同意失败
            GameManager:showAlertSystem(self,cmd.szDesc)
        end
    end
    return true
end

function FriendsLayer:showRecommendPanel()
    self.node:removeAllChildren()
    if not self.isShowRecommend then
        if GameManager.transferState ~= 0 then
            CFrameDataHandler:getInstance():sendPacketWithLoadRecommendFriendList()
        end
        self.isShowRecommend = true
    end

    self.recommendListView = ccui.ScrollView:create():addTo(self.node)
    self.recommendListView:setTouchEnabled(true)
    self.recommendListView:setBounceEnabled(true)
    self.recommendListView:setPosition(34,45)
    self.recommendListView:setContentSize(cc.size(1100,510))
    self.recommendListView:setClippingType(1)

    self:showRecommendList()
end

function FriendsLayer:showRecommendList()
    self.recommendListView:removeAllChildren()
    local list = self.recommendFriendsList
    local innerHeight = math.ceil((#list + 1)/3)*260
    self.recommendListView:setInnerContainerSize(cc.size(1100,innerHeight))


    local item = display.newSprite("#bg_recommend_item.png"):setPosition(-200 + 378,innerHeight + 125 - 260)
    local seachEditBox = ccui.EditBox:create(cc.size(293,67),"friend_recommend_edit.png",1):addTo(item):setPosition(160,160)
    seachEditBox:setFontSize(30)
    seachEditBox:setFontColor(cc.c3b(10,10,10))
    seachEditBox:setPlaceHolder("搜索用户")
    seachEditBox:setPlaceholderFontSize(30)
    seachEditBox:setPlaceholderFontColor(cc.c3b(110,110,110))
    local btnSearch = ccui.Button:create("btn_confirm_search.png","btn_confirm_search.png","btn_confirm_search.png",1):setPosition(160,72):addTo(item)
    btnSearch:addTouchEventListener(function(ref,eventType)
        if eventType == 0 then --begin
             transition.scaleTo(ref, {time = 0.05, scale = 0.9})
        elseif eventType == 1 then --moved
        elseif eventType == 2 then --release
            audio.playSound("music/click")
            transition.scaleTo(ref, {time = 0.05, scale = 1})
            local str = seachEditBox:getText()
            if  str ~= "" then
                CFrameDataHandler:getInstance():sendPacketWithLoadSearchFriend(str)
            end
        elseif eventType == 3 then --cancle
            transition.scaleTo(ref, {time = 0.05, scale = 1})
        end
    end)
    self.recommendListView:addChild(item)


    for i = 1,#list do
        local item = display.newSprite("#bg_recommend_item.png")
        local v = list[i]

        local j = i + 1 --because idx 1 is search board
        local xt = j%3
        xt = xt == 0 and 3 or xt
        local yt = math.ceil(j/3)
        item:setPosition(-200 + xt*378,innerHeight + 125 - yt * 260)

        local sign = v:getsignature()
        local strSign = sign == "" and "这家伙很懒,什么都没留下" or sign
        local labelSign = cc.Label:create():addTo(item,1):setPosition(180,50):setAnchorPoint(0.5,0.5)
        :setString("个性签名："..strSign):setSystemFontSize(25):setTextColor(cc.c4b(2,77,177,255))
        labelSign:setDimensions(290,60)
        MotionUtil:cutLabel(labelSign,500)

        local gender = v:getGender()
        if gender == 0 then
           display.newSprite("#icon_friend_female.png"):addTo(item):setPosition(264,212)
        else
           display.newSprite("#icon_friend_male.png"):addTo(item):setPosition(264,212)
        end

        local head = display.newNode():addTo(item):setPosition(75,155)
        head = MotionUtil:RepleaceWithURLPic(head,v,cc.size(110,110))

        local headBoard = ccui.Button:create("head_board_big.png","head_board_big.png","head_board_big.png",1):addTo(item,1):setPosition(75,155)
        headBoard:setTouchEnabled(true)
        headBoard:addTouchEventListener(handler(self,self.ClickUser))
        headBoard.user = v

        local labelName = cc.Label:create():addTo(item,1):setPosition(145,150):setAnchorPoint(0,0.5)
        :setString(v:getNickName()):setSystemFontSize(30):setTextColor(cc.c4b(255,255,255,255))
        MotionUtil:cutLabel(labelName,150)

        local labelID = cc.Label:create():addTo(item,1):setPosition(145,105):setAnchorPoint(0,0.5)
        :setString("ID:"..v:getGameID()):setSystemFontSize(26):setTextColor(cc.c4b(249,200,2,255))

        self.recommendListView:addChild(item)
    end
end

function FriendsLayer:RecommendFriends(notify)
    self.recommendFriendsList = {}
    if notify:getSize() == 0 then
    --        GameManager:showAlert(self,"好友提示","")
    else
        local cmd = CMD_Sever_Friends.DBR_MB_UserFriendInfo:createWithNotify(notify)
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

            table.insert(self.recommendFriendsList,pUser)
        end
        if self.tabIdx == 3 then
            self:showRecommendList()
        end
    end
    return true
end

function FriendsLayer:showBlackListPanel()
    self.node:removeAllChildren()
    if not self.isShowBlack then
        GameManager:getFriendsBlackList()
        self.isShowBlack = true
    end
    local bg = display.newSprite("#bg_friend_content.png"):addTo(self.node):setPosition(598,290)
    self.blackListView = ccui.ListView:create():addTo(bg)
    self.blackListView:setDirection(1)
    self.blackListView:setTouchEnabled(true)
    self.blackListView:setBounceEnabled(true)
    self.blackListView:setPosition(34,25)
    self.blackListView:setContentSize(cc.size(1090,480))
    self:showBlackList()
end

function FriendsLayer:showBlackList()
    local list = GameManager:getUserSelf().blackList
    for k,v in ipairs(list)  do

        local friendItem = display.newNode()
        friendItem:setTag(k)
        local split = display.newSprite("#split.png"):addTo(friendItem):setPosition(500,0)

        local btnDelFriend = ccui.Button:create("btn_delfriend.png","btn_delfriend.png","btn_delfriend.png",1):setPosition(945,68):addTo(friendItem)
        btnDelFriend:addTouchEventListener(handler(self,self.deleteBlackFriend))
        btnDelFriend.idx = k
        btnDelFriend.user = v

        local head = display.newNode():addTo(friendItem):setPosition(99,68)
        head = MotionUtil:RepleaceWithURLPic(head,v,cc.size(105,105))
        if v:getIsOnline() == 0 then
            head:setColor(cc.c3b(96,96,96))
        end

        local headBoard = ccui.Button:create("head_board.png","head_board.png","head_board.png",1):addTo(friendItem,1):setPosition(100,68):setScale(1.52)
        headBoard:setTouchEnabled(true)
        headBoard:addTouchEventListener(handler(self,self.ClickUser))
        headBoard.user = v

        local labelName = cc.Label:create():addTo(friendItem,1):setPosition(180,84):setAnchorPoint(0,0.5)
        :setString(v:getNickName()):setSystemFontSize(38):setTextColor(cc.c4b(3,36,67,255))
        MotionUtil:cutLabel(labelName,250)

        local labelID = cc.Label:create():addTo(friendItem,1):setPosition(420,84):setAnchorPoint(0,0.5)
        :setString("(ID:"..v:getGameID()..")"):setSystemFontSize(38):setTextColor(cc.c4b(202,48,0,255))

        local sign = v:getsignature()
        local strSign = sign == "" and "这家伙很懒,什么都没留下" or sign
        local labelSign = cc.Label:create():addTo(friendItem,1):setPosition(180,32):setAnchorPoint(0,0.5)
        :setString("个性签名："..strSign):setSystemFontSize(32):setTextColor(cc.c4b(58,61,80,255))
        MotionUtil:cutLabel(labelSign,500)

        local layout = ccui.Layout:create()
        layout:setTag(k)
        layout.user = v
        layout.head = head
        layout:addChild(friendItem)
        layout:setContentSize(cc.size(1080,136))
        self.blackListView:pushBackCustomItem(layout)
    end
end

function FriendsLayer:addBlackList(event)
	GameManager:getUserSelf().blackList = event._userData
    if self.tabIdx == 4 then
        self:showBlackList()
    end
end

function FriendsLayer:showSearchFriend(notify)
    if notify:getSize() == 0 then
        GameManager:showAlert(self,"好友提示","未找到该用户")
    else
        local cmd = CMD_Sever_Friends.DBR_MB_UserFriendInfo:createWithNotify(notify)
        local userinfo = cmd.allUser[1]
        local pUser = UserData:create()
        pUser:setScore(0)
        pUser:setNickName(userinfo.szNickName)
        pUser:setGameID(userinfo.dwPlayID)
        pUser:setFaceURL(userinfo.szPlayHeadUrl)
        pUser:setGender(userinfo.cbGender)
        pUser:setUserID(userinfo.dwUserID)
        pUser:setMemberOrder(userinfo.wVipLevel)
        self:showUserInfo(pUser)
    end
    return true
end

function FriendsLayer:refreshFriendList(event)
    local friends = event._userData
    if self.tabIdx == 1 then
        self:showFriendsList(friends)
    end
end

function FriendsLayer:onUnverifiedList(notify)
    if notify:getSize() ~= 0 then
        local cmd = CMD_Sever_Friends.DBR_MB_UserFriendInfo:createWithNotify(notify)
        if #cmd.allUser == 0 and #self.unverifiedList ~= 0 then
            self.RecommendOrUnverfid = 0
        elseif #cmd.allUser == 1 and cmd.allUser[1].dwPlayID == 0 and #self.unverifiedList == 0 then
            self.RecommendOrUnverfid = 0
        else
            self.RecommendOrUnverfid = 1
            for k,friend_user in ipairs(cmd.allUser) do
                local pUser = UserData:create()
                pUser:setNickName(friend_user.szNickName)
                pUser:setGameID(friend_user.dwPlayID)
                pUser:setFaceURL(friend_user.szPlayHeadUrl)
                pUser:setGender(friend_user.cbGender)
                pUser:setsignature(friend_user.szUnderWrite)
                pUser:setUserID(friend_user.dwUserID)
                pUser:setMemberOrder(friend_user.wVipLevel)
                table.insert(self.unverifiedList,pUser)
                if self.tabIdx == 2 then
                    self:showUnverifiedList()
                end
            end

        end
    end
    return true
end

function FriendsLayer:deleteBlackFriendCallBack(notify)
    if notify:getSize() == 0 then
        GameManager:showAlert(self,"好友提示","黑名单删除失败")
    else
        local cmd = CMD_Sever_Friends.CMD_MB_S_FriendRet:createWithNotify(notify)
        if cmd.nRet == 1 then
            GameManager:showAlert(self,"好友提示","黑名单删除成功")
            local index_ = self:findUserIndex(self.nowDeleteUser,GameManager:getUserSelf().blackList)
            if index_ ~= 0 then
                table.remove(GameManager:getUserSelf().blackList,index_)
                self.nowDeleteUser = nil
            end
            if self.tabIdx == 4 then
                self:showBlackList()
            end
        else
            GameManager:showAlert(self,"好友提示",cmd.szDescribe)
        end
    end
    return true
end

function FriendsLayer:talk(sender,eventType)
    if eventType == 0 then --begin
         transition.scaleTo(sender, {time = 0.05, scale = 0.9})
    elseif eventType == 1 then --moved
    elseif eventType == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(sender, {time = 0.05, scale = 1})
        ChatRecordPool:getInstance():setHasRead(sender.user:getGameID())
        FriendTalkLayer:create(sender.user):addTo(self,2)
    elseif eventType == 3 then --cancle
        transition.scaleTo(sender, {time = 0.05, scale = 1})
    end
end

function FriendsLayer:deleteBlackFriend(sender,eventType)
    if eventType == 0 then --begin
         transition.scaleTo(sender, {time = 0.05, scale = 0.9})
    elseif eventType == 1 then --moved
    elseif eventType == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(sender, {time = 0.05, scale = 1})
        self.deleteIndex = sender.idx
        local function confirmDelete(result)
            if result == RT_SUCCESS then
                printLog("delete")
                CFrameDataHandler:getInstance():sendPacketWithLoadDeleteFromBlackList(sender.user:getGameID())
                self.nowDeleteUser = sender.user
            end
        end
        GameManager:showAlertSystem(self,"确认删除？",confirmDelete):setBtnVisible(true,true)
    elseif eventType == 3 then --cancle
        transition.scaleTo(sender, {time = 0.05, scale = 1})
    end
end

function FriendsLayer:addToBlackListCallback(notify)
    local index_ = self:findUserIndex(notify._userData,GameManager:getUserSelf().friendsList)
    if index_ ~= 0 then
        table.remove(GameManager:getUserSelf().friendsList,index_)
        if self.tabIdx == 1 then
            self:showMyFriendsPanel()
        end
    end
end

function FriendsLayer:ClickUser(sender,eventType)        --点击
    if eventType == 2 then
        audio.playSound("music/click")
        self:showUserInfo(sender.user)
    end
end

function FriendsLayer:showUserInfo(user)
    local preson = PersonInfoLayer:create(user):addTo(self)
end

function FriendsLayer:jugle(user)        --判断是那个用户  0： 是自己   1：  好友    2： 是其他玩家
    if user:getGameID() == GameManager:getUserSelf():getGameID() then
        return 0
    end
    for k,v in ipairs(GameManager:getUserSelf().friendsList) do
        if v:getGameID() == user:getGameID() then
            return 1
        end
    end
    return 2
end

--根据用户是否在线和VIP等级插入到好友表中
function FriendsLayer:insertToFriendsList(friendsList,user)
    if #friendsList == 0 then
        table.insert(friendsList,user)
        return friendsList
    end

    local table_online = {}         --在线用户
    local table_NotOnline = {}      --不在线用户

    for k,friend in ipairs(friendsList) do
        if friend:getIsOnline() == 1 then
            table.insert(table_online,friend)
        else
            table.insert(table_NotOnline,friend)
        end
    end

    --合并
    local function mergerTable()
        friendsList = table_online
        for k,friend in ipairs(table_NotOnline) do
            table.insert(friendsList,friend)
        end
    end
    if user:getIsOnline() == 1 then
        if #table_online == 0 then
            table.insert(table_online,user)
        else
            for i=1, #table_online do
                if user:getMemberOrder() >= table_online[i]:getMemberOrder() then
                    table.insert(table_online,i,user)
                    mergerTable()
                    return friendsList
                end
                if i == #table_online then
                    table.insert(table_online,user)
                end
            end
        end
    else
        if #table_NotOnline == 0 then
            table.insert(table_NotOnline,user)
        else
            for i=1, #table_NotOnline do
                if user:getMemberOrder() >= table_NotOnline[i]:getMemberOrder() then
                    table.insert(table_NotOnline,i,user)
                    mergerTable()
                    return friendsList
                end
                if i == #table_online then
                    table.insert(table_NotOnline,user)
                end
            end
        end
	end
    mergerTable()
    return friendsList
end

--好友排序
function FriendsLayer:sortFriends(friendsList)
    local table_online = {}         --在线用户
    local table_NotOnline = {}      --不在线用户
	for k,friend in ipairs(friendsList) do
		if friend:getIsOnline() == 1 then
			table.insert(table_online,friend)
		else
		    table.insert(table_NotOnline,friend)
		end
	end
	local function func(friend1,friend2)
		return friend1:getMemberOrder() > friend2:getMemberOrder()
	end
    table.sort(table_online,func)       --排序在线玩家
    table.sort(table_NotOnline,func)    --排序不在线玩家
    friendsList = table_online
    --合并在线和不在线玩家
    for k,friend in ipairs(table_NotOnline) do
    	table.insert(friendsList,friend)
    end
    return friendsList
end

--查找用户在表中的位置
function FriendsLayer:findUserIndex(user,userTable)
	for k,user_t in ipairs(userTable) do
	   if user_t:getGameID() == user:getGameID() then
	       return k
	   end
	end
	return 0
end

function FriendsLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/friend.plist","hall/friend.png")

    URLLoaderHandler:destroyInstance()
    CFrameDataHandler:getInstance():removeEventListenerByList(self.events)
    CFrameDataHandler:getInstance():removeNotifyListener(self)

    if self.refreshSchedule then
        cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.refreshSchedule)
        self.refreshSchedule = nil
    end
    GameManager.isFriendsListLayer = false
end

return FriendsLayer
