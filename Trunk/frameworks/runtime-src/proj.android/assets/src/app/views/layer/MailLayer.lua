----邮箱
local BaseLayer       = import("app/views/layer/BaseLayer.lua")
local MailLayer       = class("MailLayer",BaseLayer)
local CMD_Server_Mail = import("app/cmd/loginSever/CMD_Server_Mail.lua")
local UserData        = import("app/models/data/UserData")

MailLayer.isInMailLayer = false     --是否在打开邮箱状态

function MailLayer:ctor()
    self.super.ctor(self)

    display.addSpriteFrames("hall/mail.plist","hall/mail.png")
    display.addSpriteFrames("common.plist","common.png")

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
    self.node = display.newNode():addTo(self.panel):setPosition(0,0)

    self:setupView()
    self:show()

    self.mailList = {}
    MailLayer.isInMailLayer = true
    CFrameDataHandler:getInstance():getMailList()
    CFrameDataHandler:getInstance():addNotifyListener(self)
end

function MailLayer:OnTCPWithDataRoom(notify)
    if notify:getMainType() == CMD_Server_Mail.MDM_GR_QUERY then --查询命令(主命令)
        local sub = notify:getSubType()
        if sub == CMD_Server_Mail.SUB_GR_S_EMAIL_MESSAGE then--邮件列表
            return self:getMailList(notify)
        elseif sub == CMD_Server_Mail.SUB_MB_S_EMAIL_MESSAGE_BACK then
            return self:getMailReward(notify)
        end
    end

    return false
end

function MailLayer:setupView()
    display.newSprite("#mail_title.png"):addTo(self.panel):setPosition(595,609)
    local bottomBar = display.newSprite("#common_bottm_bar.png"):addTo(self.panel):setPosition(593,83)

    self.btnGetAll = ccui.Button:create("btn_getall_normal.png","btn_getall_pressed.png","btn_getall_pressed.png",1):addTo(bottomBar):setPosition(326,58)
    self.btnGetAll:addTouchEventListener(handler(self,self.onBtnsClick))

    self.btnDelAll = ccui.Button:create("btn_delall_normal.png","btn_delall_pressed.png","btn_delall_pressed.png",1):addTo(bottomBar):setPosition(875,58)
    self.btnDelAll:addTouchEventListener(handler(self,self.onBtnsClick))

    self.listView = ccui.ListView:create():addTo(self.panel)
    self.listView:setDirection(1)
    self.listView:setTouchEnabled(true)
    self.listView:setBounceEnabled(true)
    self.listView:setPosition(20,153)
    self.listView:setContentSize(cc.size(1152,404))
end

function MailLayer:onMailClick(ref,type)
    if type == 0 then --begin
        transition.scaleTo(ref, {time = 0.05, scale = 0.99})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        GameManager:showLoading(self)
        CFrameDataHandler:getInstance():getMailReward(ref.mailID)
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function MailLayer:onBtnsClick(ref,type)
    if type == 0 then --begin
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        if ref == self.btnGetAll then
            self:optionAllMail(CMD_Server_Mail.SUB_MB_C_EMAIL_MSG_ALL_RECV)
        elseif ref == self.btnDelAll then
            self:optionAllMail(CMD_Server_Mail.SUB_MB_C_EMAIL_MSG_ALLDELETE)
        end
    elseif type == 3 then --cancle
    end
end

function MailLayer:addSysMail()
    self.listView:removeAllItems()
    for i = 1,#self.mailList do
        local item = display.newNode():setPosition(575,50)
        local btn = ccui.Button:create("mail_item_normal.png","mail_item_pressed.png","mail_item_pressed.png",1):addTo(item):setPosition(0,0)
        btn:addTouchEventListener(handler(self,self.onMailClick))
        btn:setSwallowTouches(false)
        btn.mailID = self.mailList[i].wMessageID

        cc.Label:create():addTo(btn):setAnchorPoint(0,0.5):setPosition(32,47):setString(self.mailList[i].szDateTime):setSystemFontSize(45)

        local labelContent =  cc.Label:create():addTo(btn):setAnchorPoint(0,0.5):setPosition(265,47)
        :setString(self.mailList[i].szMessageContent):setSystemFontSize(45)
        MotionUtil:cutLabel(labelContent,750)

        local layout = ccui.Layout:create()
        layout:addChild(item)
        layout:setContentSize(cc.size(1152,101))
        self.listView:pushBackCustomItem(layout)
    end
end

function MailLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

-----邮件全部请求
function MailLayer:optionAllMail(optionType)
    local bool = self.mailList == nil or #self.mailList == 0
    if bool then
        return
    end
    local option = CMD_Server_Mail.CMD_GR_C_UserEmailAllRecv:create()
    option.lMessageIDList = {}
    for i=1,#self.mailList do
        option.lMessageIDList[#option.lMessageIDList+1] = self.mailList[i].wMessageID
    end
    local b = true
    if b then
        CFrameDataHandler:getInstance():SendSocketData(CMD_Server_Mail.MDM_GR_QUERY,optionType,option)
    end
end

function MailLayer:getMailList(notify)
    if notify:getSize() == 0 then
        self.listView:removeAllItems()
        self.listView:setVisible(false)
        self.mailList = {}
        return
    else
        self.mailList = {}
        local cmd = CMD_Server_Mail.CMD_MB_MailInfo:createWithNotify(notify)
        for k,mail in ipairs(cmd.allMail) do
            if mail.wMessageType ~= 1 then
                table.insert(self.mailList,mail)
            else
                table.insert(self.mailList,mail)
            end
        end
    end
	self:addSysMail()
    return true
end

function MailLayer:getMailReward(notify)
    GameManager:hideLoading()
    if notify:getSize() == 0 then
        GameManager:showAlertSystem(self,"操作失败")
    else
        local cmd = CMD_Server_Mail.CMD_MB_REQ_MailReward:createWithNotify(notify)
        GameManager:showAlertSystem(self,cmd.info.szRemark,function()
        end)
        self:runAction(MotionUtil:delayCallFunc(0.2,function()
            CFrameDataHandler:getInstance():getMailList()
        end))

        GameManager:getUserSelf():setScore(cmd.info.IScore)
        if GameManager:getGameDelegate() ~= nil then
            GameManager:getGameDelegate():updateGameView()
        end
    end
    return true
end

function MailLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/mail.plist","hall/mail.png")
    CFrameDataHandler:getInstance():removeNotifyListener(self)
    self.mailList = {}
    MailLayer.isInMailLayer = false
end

return MailLayer
