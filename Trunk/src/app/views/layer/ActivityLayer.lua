----活动、公告、任务

local BaseLayer        = import("app/views/layer/BaseLayer.lua")
local ActivityLayer    = class("ActivityLayer",BaseLayer)
local URLLoaderHandler = import("app/handler/URLLoaderHandler.lua")
local cjson            = import("app/library/cjson.lua")
local CMD_Server_Bank  = import("app/cmd/loginSever/CMD_Server_Bank.lua")
local CMD_Server_Task  = import("app/cmd/loginSever/CMD_Server_Task.lua")

local logger = zzy.Logger.new("ActivityLayer")

ActivityLayer.events = {
    ccNd_Task_List = "ccNd_Task_List",
}

function ActivityLayer:ctor()
    self.super.ctor(self)

    self.activityList = {}

    display.addSpriteFrames("hall/activity.plist","hall/activity.png")
    display.addSpriteFrames("common.plist","common.png")

    self:setupView()
    self:show()

    self:showPanel1()
end

function ActivityLayer:showCallBack()
    self:setupTab()
end

function ActivityLayer:setupView()
    self.panel = display.newSprite("#bg_activity.png"):addTo(self):setPosition(display.cx,display.cy - 10)
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
    self.node = display.newNode():addTo(self.panel):setPosition(0,0)

    self.tips = cc.Label:create():addTo(self.node):setPosition(180,260):setSystemFontSize(38):setVisible(false):setString("没有公告")

    self.contentBg = display.newSprite("#bg_activity_content.png"):addTo(self.node):setPosition(608,240)

    self:initPanel1()
    self:initPanel2()
end

function ActivityLayer:initPanel1()
    self.panel1 = display.newNode():addTo(self.panel):setPosition(0,0):setVisible(true)
    self.listView1 = ccui.ListView:create():addTo(self.panel1)
    self.listView1:setDirection(1)
    self.listView1:setTouchEnabled(true)
    self.listView1:setBounceEnabled(true)
    self.listView1:setPosition(15,18)
    self.listView1:setContentSize(cc.size(322,442))
end

function ActivityLayer:initPanel2()
    self.panel2 = display.newNode():addTo(self.panel):setPosition(0,0):setVisible(false)
    self.listView2 = ccui.ListView:create():addTo(self.panel2)
    self.listView2:setDirection(1)
    self.listView2:setTouchEnabled(true)
    self.listView2:setBounceEnabled(true)
    self.listView2:setPosition(35,35)
    self.listView2:setContentSize(cc.size(322,442))
end


local tabPosX = {220,665}
local tabPosY = 513
function ActivityLayer:setupTab()
    self.tabs = {}
    self.tabs = {{},{}}
    local tabFrontRes = {"tab_activity1_front.png","tab_activity2_front.png"}
    local tabBackRes = {"tab_activity1_back.png","tab_activity2_back.png"}

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

function ActivityLayer:onTabClick(ref, type)
    if type == 2 then --release
        audio.playSound("music/click")
        for i = 1,#self.tabs do
            if ref == self.tabs[i] then
                self:setTab(i)
            end
        end
    end
end

function ActivityLayer:setTab(tabIdx)
    for i = 1, #self.tabs do
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[tabIdx]:setTouchEnabled(false)
    self.tabs[tabIdx]:setBright(false)

    self.particle:setPosition(tabPosX[tabIdx],tabPosY - 15)

    self.tabIdx = tabIdx

    self.contentBg:removeAllChildren()

    if tabIdx == 1 then
        self:showPanel1()
    elseif tabIdx == 2 then
        self:showPanel2()
    end
end

function ActivityLayer:showPanel1()
    logger:log("----------------------")
    self.panel1:setVisible(true)
    self.panel2:setVisible(false)
    self:getActivityList()
end

function ActivityLayer:showPanel2()
    self.panel1:setVisible(false)
    self.panel2:setVisible(true)
end

function ActivityLayer:getActivityList()
    logger:log("----------------------")
    if self.activityList ~= nil and #self.activityList > 0 then
        self:onPanel1TabSelect(1)
    else
        self.listView1:removeAllItems()
        URLLoaderHandler:load(GameManager:getProject():getActivityUrl(),handler(self,self.onLoadActivityComplete))
    end
end

function ActivityLayer:onLoadActivityComplete(urlData)
    logger:log("----------------------")
    print("RankLayer:onLoadComplete:",urlData:getData())

    if urlData:getStatusCode() == URLLoaderHandler.STATUS_CODES.SUCCESS then
        self.panel1Data = cjson.decode(urlData:getData()).ds
        self:updatePanel1(self.panel1Data)
    elseif self.root ~= nil then
        GameManager:showAlertSystem(self,"加载失败,请稍候再试",handler(self,self.hide))
    end
end

function ActivityLayer:addItemActivity(ds)
    self.panel:getChildByName("txt_content"):setString(ds.TrophyContent)
    local spr_btn = cc.Sprite:create()
    spr_btn:setName("spr_btn")
    local txt = cc.Label:createWithSystemFont(ds.TrophyTitle,"",36)
    txt:addTo(spr_btn):move(cc.p(166,52)):setName("txt")
    MotionUtil:cutLabel(txt,240)
    spr_btn:setSpriteFrame("layer_activity/anniu.png")
    local layout = ccui.Layout:create()
    layout:setContentSize(spr_btn:getContentSize())
    layout:addClickEventListener(handler(self,self.onClickAcitity))
    spr_btn:addTo(layout)
    layout:setTag(1)
    layout:setAnchorPoint(cc.p(0,0))
    spr_btn:setAnchorPoint(cc.p(0,0))
    layout:setTouchEnabled(true)
    self.listView:insertCustomItem(layout,0)
end

function ActivityLayer:updatePanel1(obj)
    logger:log("----------------------")

    if obj == nil then
        self.panel1:setVisible(false)
        self.tips:setVisible(true)
        self.tips:setString("暂无公告")
        return
    end
    self.activityList = obj

    for i=1,#self.activityList do
        local item = display.newNode():setTag(1)
        local btn = ccui.Button:create("item_normal.png","item_selected.png","item_selected.png",1):addTo(item):setPosition(5,55):setTag(1):setAnchorPoint(0,0.5)
        btn:addTouchEventListener(function(ref,type)
                                    if type == 0 then --begin
                                        audio.playSound("music/click")
                                        self:onPanel1TabSelect(i)
                                    end
                                end)
        btn:setSwallowTouches(false)
        local labelTrophyTitle = cc.Label:create():addTo(item):setPosition(46,55):setString(self.activityList[i].TrophyTitle):setSystemFontSize(36):setAnchorPoint(0,0.5)
        MotionUtil:cutLabel(labelTrophyTitle,220)
        local layout = ccui.Layout:create()
        layout:setContentSize(320,110)
        layout:addChild(item)
        self.listView1:pushBackCustomItem(layout)
    end

    self:onPanel1TabSelect(1)
end

function ActivityLayer:onPanel1TabSelect(idx)
    for i = 1,#self.activityList do
        local item = self.listView1:getItem(i-1)
        local btn = item:getChildByTag(1):getChildByTag(1)
        if i == idx then
            btn:setTouchEnabled(false)
            btn:setBright(false)
            btn:setPosition(20,55)
        else
            btn:setTouchEnabled(true)
            btn:setBright(true)
            btn:setPosition(5,55)
        end
        self:setPanel1Content(idx)
    end
end

function ActivityLayer:setPanel1Content(idx)
    self.contentBg:removeAllChildren()
    cc.Label:create():addTo(self.contentBg):setPosition(270,400):setString("公告"):setSystemFontSize(42)
    local labelTrophyTitle = cc.Label:create():addTo(self.contentBg):setPosition(270,190)
    :setString(self.activityList[idx].TrophyContent):setSystemFontSize(36):setDimensions(440,270)
end

--标签2
function ActivityLayer:updateActivity1()
    self.panel:getChildByName("txt_title"):setVisible(false)
    self.panel:getChildByName("txt_content"):setVisible(false)
    self.panel:getChildByName("spr_content"):setVisible(true)
    for i=1,#self.listView:getItems() do
        self.listView:getChildByName("panel_item_"..i):setTag(i)
        self.listView:getChildByName("panel_item_"..i):addClickEventListener(handler(self,self.onClickAcitity))
    end
    self:switchActivity(1)
end

function ActivityLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

function ActivityLayer:onClickAcitity(sender,eventType)
    if sender:getTag() ~= self.currentIndex then
        if self.choose_index == 1 then
            self:switchActivity(sender:getTag())
        else
            self:switchBulletin(sender:getTag())
        end
    end
end

--公告栏切换
function ActivityLayer:switchBulletin(i)
    if self.currentIndex == i then
        return
    end
    self.panel:getChildByName("txt_content"):setString(self.activityList[i].TrophyContent)
    self.listView:getChildByTag(i):getChildByName("spr_btn"):setSpriteFrame("layer_activity/anniu.png")
    self.listView:getChildByTag(i):getChildByName("spr_btn"):getChildByName("txt"):setTextColor(cc.c4b(255,255,255,255))
    self.listView:getChildByTag(self.currentIndex):getChildByName("spr_btn"):setSpriteFrame("layer_activity/anniu1.png")
    self.listView:getChildByTag(self.currentIndex):getChildByName("spr_btn"):getChildByName("txt"):setTextColor(cc.c4b(143,129,182,255))
    self.currentIndex = i
end

--活动切换
function ActivityLayer:switchActivity(i)
    if self.currentIndex == i then
        return
    end
    self.listView:getChildByTag(i):getChildByName("spr_btn"):setSpriteFrame("layer_activity/anniu.png")
    self.listView:getChildByTag(self.currentIndex):getChildByName("spr_btn"):setSpriteFrame("layer_activity/anniu1.png")
    if i == 1 then
        self.panel:getChildByName("spr_content"):setSpriteFrame("layer_activity/layer_activity_content_1.png")
    elseif i==2 then
        self.panel:getChildByName("spr_content"):setSpriteFrame("layer_activity/longzhu.png")
    elseif i==3 then
        self.panel:getChildByName("spr_content"):setSpriteFrame("layer_activity/layer_activity_content_3.png")
    end
    self.panel:getChildByName("spr_content"):setVisible(true)

    self.currentIndex = i
end


function ActivityLayer:setOnExitCallBack(callBack)
    self.onExitCallBack = callBack
end

function ActivityLayer:onExit()
    if self.onExitCallBack ~= nil then
        self.onExitCallBack()
    end
end


function ActivityLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/activity.plist","hall/activity.png")
    URLLoaderHandler:destroyInstance()
    self:removeAllChildren()
    cc.SpriteFrameCache:getInstance():removeUnusedSpriteFrames()
    CFrameDataHandler:getInstance():removeEventListenerByList(self.events)
end

return ActivityLayer
