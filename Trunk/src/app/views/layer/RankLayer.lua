local BaseLayer       = import("app/views/layer/BaseLayer.lua")
local RankLayer       = class("RankLayer",BaseLayer)
-- local URLLoaderHandler = import("app/handler/URLLoaderHandler.lua")
local UserData        = import("app/models/data/UserData")
local PersonInfoLayer = import("app/views/layer/PersonInfoLayer.lua")
local CMD_Server_Rank = import("app/cmd/loginSever/CMD_Server_Rank.lua")

RankLayer.PRODUCT_COUNT = 20

function RankLayer:ctor()
    self.super.ctor(self)
    self.DATA_LENGTH = 20
    display.addSpriteFrames("hall/rank.plist","hall/rank.png")
    display.addSpriteFrames("common.plist","common.png")

    self:setupView()
    self:show()
end

function RankLayer:showCallBack()
    self:setupTab()
    self:setTab(2)
end

function RankLayer:setupView()
    self.panel = display.newSprite("#common_layer_bg.png"):addTo(self):setPosition(display.cx,display.cy - 10)
    self:setRootBg(self.panel)
    local size = self.panel:getContentSize()
    self.btnClose = ccui.Button:create("btn_close.png","btn_close.png","btn_close.png",1):addTo(self.panel,1):setPosition(size.width - 20,size.height - 20)
    self.btnClose:addTouchEventListener(function(ref,type)
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
                                        end)
    self.node = {}
    self.node[1] = display.newNode():addTo(self.panel):setPosition(0,0):setVisible(false)
    self.node[2] = display.newNode():addTo(self.panel):setPosition(0,0):setVisible(false)

    self.listView = ccui.ListView:create():addTo(self.node[2])
    self.listView:setDirection(1)
    self.listView:setTouchEnabled(true)
    self.listView:setBounceEnabled(true)
    self.listView:setPosition(35,35)
    self.listView:setContentSize(cc.size(1150,502))

    cc.Label:create():addTo(self.node[1]):setString("即将开放，敬请期待！"):setSystemFontSize(46):setPosition(580,310)
    -- URLLoaderHandler:load(GameManager:getProject():getRankUrl(1),handler(self,self.onLoadComplete))

    CFrameDataHandler:getInstance():getRankData()
    -- CFrameDataHandler:getInstance():addEventListener(self.events.ccNd_Rank_List,handler(self,self.onGetRankList))
    CFrameDataHandler:getInstance():addNotifyListener(self)
end

function RankLayer:OnTCPWithDataLoad(notify)
    if notify:getMainType() ~= CMD_Server_Rank.MDM_GR_USER then --用户命令  3
        return false
    end

    if notify:getSubType() == CMD_Server_Rank.SUB_MB_SCORE_LIST_RESULT then --排行榜数据
        return self:onGetRankList(notify)
    end
    return false
end


local tabPosX = {308,880}
local tabPosY = 600
function RankLayer:setupTab()
    self.tabs = {{},{}}
    local tabFrontRes = {"tab_rank1_front.png","tab_rank2_front.png"}
    local tabBackRes = {"tab_rank1_back.png","tab_rank2_back.png"}

    for i = 1, #self.tabs do
        self.tabs[i] = ccui.Button:create(tabBackRes[i],tabFrontRes[i],tabFrontRes[i],1):addTo(self.panel):setPosition(tabPosX[i],tabPosY)
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[1]:setTouchEnabled(false)
    self.tabs[1]:setBright(false)

    self.particle = cc.ParticleSystemQuad:create("particle/diandian.plist")
    self.particle:setPosition(tabPosX[1],tabPosY-15)
    self.particle:setScale(0.6)
    self.particle:addTo(self.panel)

    self.tabIdx = 1
end

function RankLayer:onTabClick(ref, type)
    if type == 2 then --release
        audio.playSound("music/click")
        for i = 1,#self.tabs do
            if ref == self.tabs[i] then
                self:setTab(i)
            end
        end
    end
end

function RankLayer:setTab(tabIdx)
    for i = 1, #self.tabs do
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[tabIdx]:setTouchEnabled(false)
    self.tabs[tabIdx]:setBright(false)

    self.particle:setPosition(tabPosX[tabIdx],tabPosY - 15)

    self.tabIdx = tabIdx

    for i = 1, 2 do
        self.node[i]:setVisible(tabIdx == i)
    end
end

function RankLayer:onGetRankList(notify)
    rankData = CMD_Server_Rank.CMD_MB_ScoreListResult:createWithNotify(notify)
    local userManager = GameManager:getUserManager()
    local len = rankData.wUserCount <= self.DATA_LENGTH and rankData.wUserCount or self.DATA_LENGTH
    for i = 1,len do
        local item = display.newNode()
        local bg = display.newSprite("#item_rank.png"):addTo(item):setPosition(561,54)

        if i == 1 then
            display.newSprite("#icon_rank_1.png"):addTo(bg):setPosition(55,52)
        elseif i == 2 then
            display.newSprite("#icon_rank_2.png"):addTo(bg):setPosition(55,52)
        elseif i == 3 then
            display.newSprite("#icon_rank_3.png"):addTo(bg):setPosition(55,52)
        else
            local labelIdx = cc.Label:create():addTo(bg):setPosition(55,52):setString(i):setSystemFontSize(42):setTextColor(cc.c4b(19,72,112,255))
            labelIdx:enableOutline(cc.c4b(255,255,255,255),3)
        end

        local data = rankData.ScoreListItem[i]
        local user = UserData:create()
        user:setFaceURL(data.szFaceUrl)
        user:setGameID(data.dwGameID)
        user:setNickName(data.szNickName)
        user:setMemberOrder(data.cbVipLevel)
        user:setScore(data.lUserScore)

        local head = display.newNode():addTo(bg):setPosition(150,52)
        head = MotionUtil:RepleaceWithURLPic(head,user,cc.size(72,72))

        local headBoard = ccui.Button:create("head_board.png","head_board.png","head_board.png",1):addTo(bg,1):setPosition(150,52)
        headBoard:setTouchEnabled(true)
        headBoard:addTouchEventListener(handler(self,self.ClickUser))
        headBoard.user = user

        display.newScale9Sprite("common_conten_bg.png",1,cc.size(315,50),cc.rect(183/2,47/2,2,2)):addTo(bg):setPosition(360,52)
        local labelName = cc.Label:create():addTo(bg):setPosition(225,52):setString(data.szNickName):setSystemFontSize(38):setTextColor(cc.c4b(255,255,255,255)):setAnchorPoint(0,0.5)
        labelName:enableOutline(cc.c4b(11,62,102,255),3)
        MotionUtil:cutLabel(labelName,275)

        display.newScale9Sprite("common_conten_bg.png",1,cc.size(476,50),cc.rect(183/2,47/2,2,2)):addTo(bg):setPosition(850,52)
        display.newSprite("#icon_coin.png"):addTo(bg):setPosition(615,52)
        local labelCoin = cc.Label:create():addTo(bg):setPosition(645,52):setString("金币:"..data.lUserScore):setSystemFontSize(38):setTextColor(cc.c4b(255,255,65,255)):setAnchorPoint(0,0.5)
        labelCoin:enableOutline(cc.c4b(11,62,102,255),3)

        local layout = ccui.Layout:create()
        layout:setContentSize(cc.size(1116,108))
        layout:addChild(item)
        self.listView:pushBackCustomItem(layout)
    end
    return true
end

function RankLayer:onLoadComplete(urlData)
    print("RankLayer:onLoadComplete:",urlData:getData())

    if urlData:getStatusCode() == URLLoaderHandler.STATUS_CODES.SUCCESS then
        self:updateData(urlData:getData())
    else
        GameManager:showAlertSystem(self,"加载失败,请稍候再试")
    end
end

function RankLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

function RankLayer:updateData(str)
    local json = require "cocos.cocos2d.json"
    local obj = json.decode(str)
    if obj.ok == nil then
        GameManager:showAlertSystem(self,"没有数据")
        return
    end
    local userManager = GameManager:getUserManager()
    for i = 1,#obj.ds do
        local item = display.newNode()
        local bg = display.newSprite("#item_rank.png"):addTo(item):setPosition(561,54)

        if i == 1 then
            display.newSprite("#icon_rank_1.png"):addTo(bg):setPosition(55,52)
        elseif i == 2 then
            display.newSprite("#icon_rank_2.png"):addTo(bg):setPosition(55,52)
        elseif i == 3 then
            display.newSprite("#icon_rank_3.png"):addTo(bg):setPosition(55,52)
        else
            local labelIdx = cc.Label:create():addTo(bg):setPosition(55,52):setString(i):setSystemFontSize(42):setTextColor(cc.c4b(19,72,112,255))
            labelIdx:enableOutline(cc.c4b(255,255,255,255),3)
        end

        local data = obj.ds[i]
        local user = UserData:create()
        user:setFaceURL(data.faceurl)
        user:setGameID(data.GameID)
        user:setNickName(data.NickName)

        local head = display.newNode():addTo(bg):setPosition(150,52)
        head = MotionUtil:RepleaceWithURLPic(head,user,cc.size(72,72))

        local headBoard = ccui.Button:create("head_board.png","head_board.png","head_board.png",1):addTo(bg,1):setPosition(150,52)
        headBoard:setTouchEnabled(true)
        headBoard:addTouchEventListener(handler(self,self.ClickUser))
        headBoard.user = user

        display.newScale9Sprite("common_conten_bg.png",1,cc.size(315,50),cc.rect(183/2,47/2,2,2)):addTo(bg):setPosition(360,52)
        local labelName = cc.Label:create():addTo(bg):setPosition(225,52):setString(data.NickName):setSystemFontSize(38):setTextColor(cc.c4b(255,255,255,255)):setAnchorPoint(0,0.5)
        labelName:enableOutline(cc.c4b(11,62,102,255),3)
        MotionUtil:cutLabel(labelName,275)

        display.newScale9Sprite("common_conten_bg.png",1,cc.size(476,50),cc.rect(183/2,47/2,2,2)):addTo(bg):setPosition(850,52)
        display.newSprite("#icon_coin.png"):addTo(bg):setPosition(615,52)
        local labelCoin = cc.Label:create():addTo(bg):setPosition(645,52):setString("金币:"..data.Score):setSystemFontSize(38):setTextColor(cc.c4b(255,255,65,255)):setAnchorPoint(0,0.5)
        labelCoin:enableOutline(cc.c4b(11,62,102,255),3)

        local layout = ccui.Layout:create()
        layout:setContentSize(cc.size(1116,108))
        layout:addChild(item)
        self.listView:pushBackCustomItem(layout)
    end
end

function RankLayer:ClickUser(sender,eventType)        --点击
    if eventType == 2 then
        audio.playSound("music/click")
        PersonInfoLayer:create(sender.user):addTo(self)
        audio.playSound("music/click")
    end
end

function RankLayer:onCleanup()
    CFrameDataHandler:getInstance():removeNotifyListener(self)
    display.removeSpriteFramesWithFile("hall/rank.plist","hall/rank.png")
    GameManager:hideLoading()
    -- URLLoaderHandler:destroyInstance()
end

return RankLayer
