--喇叭层
local BaseLayer     = import("app/views/layer/BaseLayer.lua")
local HornLayer     = class("HornLayer",BaseLayer)
local ShopLayer     = import("app/views/layer/ShopLayer.lua")
local MsgRecordItem = class("MsgRecordItem")

MsgRecordItem.TYPE_SYS  = 1
MsgRecordItem.TYPE_HORN = 2

HornLayer.msgList = {}
HornLayer.msgList_ = {{},{}}

function MsgRecordItem:ctor()
    self.nType = 0
    self.szMsg = ""
end

HornLayer.MsgRecordItem = MsgRecordItem

function HornLayer:ctor()
    self.super.ctor(self)

    display.addSpriteFrames("hall/speaker.plist","hall/speaker.png")
    display.addSpriteFrames("common.plist","common.png")

    self:setupView()
    self:show()
end

function HornLayer:showCallBack()
    self:setupTab()
end

function HornLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

function HornLayer:setupView()
    self.panel = display.newSprite("#bg_speaker_layer.png"):addTo(self):setPosition(display.cx,display.cy - 10)
    self:setRootBg(self.panel)
    local size = self.panel:getContentSize()
    self.closeBtn = ccui.Button:create("btn_close.png","btn_close.png","btn_close.png",1):addTo(self.panel,1):setPosition(size.width - 20,size.height - 20)
    self.closeBtn:addTouchEventListener(function(ref,type)
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

    display.newSprite("#icon_speaker_big.png"):addTo(self.node):setPosition(65,444)

    self.hornNumLabel = cc.Label:createWithBMFont("fonts/bmfont3.fnt","x"..GameManager:getUserSelf():getAllHornNum()):addTo(self.node,1):setPosition(105,422)
    -- self.hornNumLabel = cc.Label:create():addTo(self.node,1):setPosition(109,422):setString("X"..GameManager:getUserSelf():getAllHornNum()):setSystemFontSize(38):setTextColor(cc.c4b(249,127,42,255))
    display.newSprite("#editbox_speaker.png"):addTo(self.node):setPosition(405,442)
    local btnSend = ccui.Button:create("btn_send.png","btn_send.png","btn_send.png",1):addTo(self.node):setPosition(777,435)
    btnSend:addTouchEventListener(handler(self,self.sendUserHorn))

    self.textField = ccui.TextField:create():addTo(self.node):setPosition(170,445):setAnchorPoint(0,0.5)
    self.textField:setPlaceHolder("请输入聊天内容")
    self.textField:setTouchSize(cc.size(522,67))
    self.textField:setFontSize(40)
    self.textField:setTextColor(cc.c3b(0,0,0))

    self.listView = ccui.ListView:create():addTo(self.node,1)
    self.listView:setDirection(1)
    self.listView:setTouchEnabled(true)
    self.listView:setBounceEnabled(true)
    self.listView:setPosition(40,40)
    self.listView:setContentSize(cc.size(860,350))

    self:showSystemChatPanel()
end

local tabPosX = {236,678}
local tabPosY = 525
function HornLayer:setupTab()
    self.tabs = {}
    self.tabs[1] = ccui.Button:create("tab_systemchat_back.png","tab_systemchat_front.png","tab_systemchat_front.png",1):addTo(self.panel):setPosition(tabPosX[1],tabPosY)
    self.tabs[2] = ccui.Button:create("tab_worldchat_back.png","tab_worldchat_front.png","tab_worldchat_front.png",1):addTo(self.panel):setPosition(tabPosX[2],tabPosY)

    for i = 1, #self.tabs do
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

function HornLayer:onTabClick(ref, type)
    if type == 2 then --release
        audio.playSound("music/click")
        for i = 1,#self.tabs do
            if ref == self.tabs[i] then
                self:setTab(i)
            end
        end
    end
end

function HornLayer:setTab(tabIdx)
    for i = 1, #self.tabs do
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[tabIdx]:setTouchEnabled(false)
    self.tabs[tabIdx]:setBright(false)

    self.particle:setPosition(tabPosX[tabIdx],tabPosY - 15)

    self.tabIdx = tabIdx

    self.listView:removeAllChildren()
    if tabIdx == 1 then
        self:showSystemChatPanel()
    elseif tabIdx == 2 then
        self:showWorldChatPanel()
    end
end

function HornLayer:showSystemChatPanel()
    for i = #HornLayer.msgList_[1],1,-1 do
        self:insertMsg(HornLayer.msgList_[1][i])
    end
end

function HornLayer:showWorldChatPanel()
    for i = #HornLayer.msgList_[2],1,-1 do
        self:insertMsg(HornLayer.msgList_[2][i])
    end
end

function HornLayer:sendUserHorn(sender,eventType)
    if eventType == 2 then
        audio.playSound("music/click")
        if self.textField:getString() ~= "" then
            if GameManager:getUserSelf():getAllHornNum() > 0 then
                CFrameDataHandler:getInstance():sendUserHorn(self.textField:getString())
                self.textField:setString("")
                GameManager:getUserSelf():setAllHornNumDownOne()
                self.hornNumLabel:setString("/"..GameManager:getUserSelf():getAllHornNum())
             else
                 local function openShop(result)
                    if result == RT_SUCCESS then
                 	  ShopLayer:create(GameManager:getUserSelf(),3):addTo(self:getParent())
                 	  self:hide()
                 	end
                 end
                GameManager:showAlertSystem(self,"您的喇叭数不足，购买钻石成为VIP玩家即可每日领取喇叭"):setBtnVisible(true,true)
             end
        end
    end
end

function HornLayer:insertMsg(msg)
    local item = display.newNode()
    display.newSprite("#item_speaker.png"):addTo(item):setPosition(420,40)
    local labelMsg = cc.Label:create():addTo(item):setPosition(20,40):setString(msg.szMsg):setSystemFontSize(38):setAnchorPoint(0,0.5)
    if msg.vipLevel == -1 then
        labelMsg:setColor(cc.c3b(207,60,41))
    elseif msg.vipLevel >= 0 and msg.vipLevel < 4 then
        labelMsg:setColor(cc.c3b(189,188,217))
    elseif msg.vipLevel== 4 or msg.vipLevel== 5 or msg.vipLevel== 6 then
        labelMsg:setColor(cc.c4b(170,183,178))--
    elseif msg.vipLevel== 7 or msg.vipLevel== 8 then
        labelMsg:setColor(cc.c4b(253,211,81))--
    elseif msg.vipLevel== 9 then
        labelMsg:setColor(cc.c4b(221,121,225))--
    end

    local layout = ccui.Layout:create()
    layout:addChild(item)
    layout:setContentSize(cc.size(848,88))

    if msg.nType == MsgRecordItem.TYPE_SYS and self.tabIdx == 1 then
        self.listView:insertCustomItem(layout,0)
    elseif msg.nType == MsgRecordItem.TYPE_HORN and self.tabIdx == 2 then
        self.listView:insertCustomItem(layout,0)
	end

    if #self.listView:getItems() >30 then
        self.listView:removeLastItem()
	end
end

-- 静态方法
function HornLayer:addHornInfo(nType,szinfo,vipLevel)
    local item = MsgRecordItem:create()
    item.nType = nType
    item.szMsg = szinfo
    item.vipLevel = vipLevel

    if item.nType == MsgRecordItem.TYPE_SYS then
        table.insert(HornLayer.msgList,1,item)
        table.insert(HornLayer.msgList_[1],1,item)
        if #HornLayer.msgList >= 30 then
            table.remove(HornLayer.msgList,#HornLayer.msgList)
        end
        if #HornLayer.msgList_[1] >= 30 then
            table.remove(HornLayer.msgList_[1],#HornLayer.msgList_[1])
        end
    elseif item.nType == MsgRecordItem.TYPE_HORN then
        table.insert(HornLayer.msgList,1,item)
        table.insert(HornLayer.msgList_[2],1,item)
        if #HornLayer.msgList >= 30 then
            table.remove(HornLayer.msgList,#HornLayer.msgList)
        end
        if #HornLayer.msgList_[2] >= 30 then
            table.remove(HornLayer.msgList_[2],#HornLayer.msgList_[2])
        end
    end
end

function HornLayer:onClear()
    HornLayer.msgList = {}
    HornLayer.msgList_ = {}
end

function HornLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/speaker.plist","hall/speaker.png")
end

return HornLayer
