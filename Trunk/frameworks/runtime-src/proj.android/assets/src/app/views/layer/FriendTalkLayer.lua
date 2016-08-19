local BaseLayer       = import("app/views/layer/BaseLayer.lua")
local FriendTalkLayer = class("FriendTalkLayer",BaseLayer)
local LuaUtil         = import("app/library/LuaUtil.lua")

FriendTalkLayer.events = {
    getChatMessage_talkLayer = "getChatMessage_talkLayer"
}

function FriendTalkLayer:ctor(user)
    self.super.ctor(self)
    self.user = user

    display.addSpriteFrames("hall/expression.plist","hall/expression.png")
    display.addSpriteFrames("common.plist","common.png")

    self.expressionIsShow = false

    self:setupView()
    self:show()

    self.charRecord = ChatRecordPool:getInstance():getRecordByFriendID(user:getGameID())
    ChatRecordPool:getInstance().IsInChatUserGameID = user:getGameID()

    CFrameDataHandler:getInstance():addEventListener(self.events.getChatMessage_talkLayer,handler(self,self.getMessage))
    self:initRecord()
end

function FriendTalkLayer:setupView()
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

    local topBar = display.newSprite("#common_top_bar.png"):addTo(self.panel):setPosition(593,611)
    local bottomBar = display.newSprite("#common_bottm_bar.png"):addTo(self.panel):setPosition(593,78)

    cc.Label:create():addTo(topBar):setPosition(35,54):setString("与"):setSystemFontSize(50):setAnchorPoint(0,0.5)
    local labelName = cc.Label:create():addTo(topBar):setPosition(275,54):setString(self.user:getNickName()):setSystemFontSize(50)
    MotionUtil:cutLabel(labelName,320)
    cc.Label:create():addTo(topBar):setPosition(465,54):setString("的聊天"):setSystemFontSize(50):setAnchorPoint(0,0.5)

    self.btnChatFace = ccui.Button:create("btn_chatface.png","btn_chatface.png","btn_chatface.png",1):addTo(bottomBar):setPosition(70,60):setSwallowTouches(true)
    self.btnChatFace:addTouchEventListener(handler(self,self.onBtnsClick))
    self.btnSend = ccui.Button:create("btn_send.png","btn_send.png","btn_send.png",1):addTo(bottomBar):setPosition(1030,60)
    self.btnSend:addTouchEventListener(handler(self,self.onBtnsClick))

    display.newScale9Sprite("friend_search_box.png",1,cc.size(772,80),cc.rect(233,32,1,1)):addTo(bottomBar):setPosition(512,60)

    self.chatTextField = ccui.TextField:create():addTo(bottomBar):setPosition(155,60):setAnchorPoint(0,0.5)
    self.chatTextField:setMaxLengthEnabled(true)
    self.chatTextField:setMaxLength(100)
    self.chatTextField:setTouchEnabled(true)
    self.chatTextField:setFontSize(40)
    self.chatTextField:setTouchSize(cc.size(772,80))
    self.chatTextField:setPlaceHolder("请输入聊天内容")
    self.chatTextField:setTextColor(cc.c4b(6,36,60,255))

    --表情面板
    self:initExpressionNode()

    self.chatContentListView = ccui.ListView:create():addTo(self.node)
    self.chatContentListView:setDirection(1)
    self.chatContentListView:setTouchEnabled(true)
    self.chatContentListView:setBounceEnabled(true)
    self.chatContentListView:setPosition(34,153)
    self.chatContentListView:setContentSize(cc.size(1138,404))
end

function FriendTalkLayer:initExpressionNode()
    self.expressionNode = display.newLayer():addTo(self,2):setVisible(false)
    self.expressionNode:onTouch(function(event)
        if event.name ~= "began" then return end
        if self.expressionIsShow then
            self.expressionIsShow = false
            self.expressionNode:setVisible(false)
            self.btnChatFace:setTouchEnabled(true)
        end
    end)

    local facePanle = display.newSprite("#bg_face_panel.png"):addTo(self.expressionNode):setPosition(590,300)

    local faceScrollView = ccui.ScrollView:create():addTo(facePanle)
    faceScrollView:setTouchEnabled(true)
    faceScrollView:setBounceEnabled(true)
    faceScrollView:setPosition(0,28)
    faceScrollView:setContentSize(cc.size(998,276))
    faceScrollView:setClippingType(1)

    local innerHeight = math.ceil(27/9)*95
    faceScrollView:setInnerContainerSize(cc.size(998,innerHeight))
    for i = 1, 27 do
        -- local item = display.newSprite("#expression_"..i..".png"):setScale(0.90)
        local item =  ccui.Button:create("expression_"..i..".png","expression_"..i..".png","expression_"..i..".png",1):setSwallowTouches(true):setScale(0.90)
        item:setTag(i)
        local xt = i%9
        xt = xt == 0 and 9 or xt
        local yt = math.ceil(i/9)
        item:setPosition(-40 + xt*110,innerHeight + 54 - yt * 95)

        -- item:setTag(i)
        -- item:setTouchEnabled(true)
        item:addTouchEventListener(handler(self,self.talkExpressionEvent))
        faceScrollView:addChild(item)
    end
end

function FriendTalkLayer:onBtnsClick(ref,type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        if ref == self.btnChatFace then
            if not self.expressionIsShow then
                self.expressionIsShow = true
                self.expressionNode:setVisible(true)
                self.btnChatFace:setTouchEnabled(false)
                -- self.input:setEnabled(true)
                -- self.talkListView:setEnabled(true)
            end
        elseif ref == self.btnSend then
            if self.chatTextField:getString() ~= "" then
                CFrameDataHandler:getInstance():SendChat(self.user,0,self.chatTextField:getString())      --发送聊天
                self.chatTextField:setString("")
            end
        end
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function FriendTalkLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

function FriendTalkLayer:addExpressionList()
    local expressionListView = self.expressionNode:getChildByName("talk_list")
    local onelineSize = 9
    expressionListView:setInnerContainerSize(cc.size(570,100 * math.ceil(26/onelineSize)))
    for i = 1, 27 do
        local expression_sp = ccui.ImageView:create("expression_"..i..".png",1)
        expression_sp:setScale(0.8)
        expression_sp:setPosition(50 + 90*math.mod(i - 1,onelineSize),250 - 100*math.floor((i - 1)/onelineSize))
        expression_sp:addTo(expressionListView)
        expression_sp:setTag(i)
        expression_sp:setTouchEnabled(true)
        expression_sp:addTouchEventListener(handler(self,self.talkExpressionEvent))--注册事件
    end
end

function FriendTalkLayer:talkExpressionEvent(sender,eventType)
    if eventType == 2 then
        audio.playSound("music/click")
        CFrameDataHandler:getInstance():SendChat(self.user,sender:getTag(),"")      --发送聊天
        if self.expressionIsShow then
            self.expressionIsShow = false
            self.expressionNode:setVisible(false)
            self.btnChatFace:setTouchEnabled(true)
        end
    end
end

function FriendTalkLayer:initRecord()
    local list = self.charRecord
    -- list = {{"user","拉开三季度分厘卡集散地立刻飞机阿隆索款到即发绿拉开三季度分厘卡集散地立刻飞机阿隆索款到即发绿卡时间的奋力抗击阿斯利分级阿斯利康分卡时间的奋力抗击阿斯利分级阿斯利康分"},{"user","123456"},{"user",1},{"user","122222222222223456"},{"user","123456"}
    --         ,{"1","123456"},{"1",2},{"1","122222222222223456"},{"1","拉开三季度分厘卡集散地立刻飞机阿隆索款到即发绿卡时间的奋力抗击阿斯利分级阿斯利康分"},{"1","123456"}}
    for k,v in ipairs(list) do
		if v[1] == "user" then
			self:addWord(0,v[2])
		else
            self:addWord(1,v[2])
		end
	end
end
function FriendTalkLayer:addWord(which,word)        --word如果是数字就表示表情
    local chatContent = nil
    local contentBg = nil
    local item = display.newNode()

    if type(word) == "number" then
        if word >= 1 and word <= 27 then
            chatContent = display.newSprite("#expression_"..word..".png")
        else
            print("没有找到表情图片")
            chatContent = display.newSprite("#expression_1.png")
        end
    else
        chatContent = cc.Label:create():setString(word):setSystemFontSize(35):setTextColor(cc.c4b(1,36,65,255))
        if chatContent:getContentSize().width >= 830 then
            chatContent:setDimensions(830,0)
        end
    end

    local padding = 12
    local size = chatContent:getContentSize()
    local bgWidth,bgHeight = size.width + padding*2, size.height + padding*2
    contentBg = display.newScale9Sprite("bg_chat_content.png",1,cc.size(bgWidth,bgHeight),cc.rect(105/2,33,1,1)):addTo(item)
    chatContent:addTo(contentBg):setPosition(bgWidth/2,bgHeight/2)
    local arrow = display.newSprite("#arrow_chat_content.png"):addTo(contentBg)

    local headBoard = display.newSprite("#head_board.png"):addTo(item)

    local head = display.newNode():addTo(headBoard,-1):setPosition(39,39)


    local headPosY = bgHeight/2 + (bgHeight/2 - 39)
    local contentPosY = bgHeight/2--bgHeight  + 40 - bgHeight/2
    if which == 0 then          --自己
        arrow:setPosition(bgWidth+5,bgHeight - 15):setFlippedX(true)
        contentBg:setPosition(1070 - bgWidth/2 - 62, contentPosY)
        headBoard:setPosition(1070,headPosY)
        head = MotionUtil:RepleaceWithURLPic(head,GameManager:getUserSelf(),cc.size(74,74))
	else
        arrow:setPosition(-5,bgHeight - 15)
        contentBg:setPosition(bgWidth/2 + 122,contentPosY)
        headBoard:setPosition(52,headPosY)
        head = MotionUtil:RepleaceWithURLPic(head,self.user,cc.size(74,74))
	end

    item:setPosition(0,38)
    local layout = ccui.Layout:create()
    layout:addChild(item)
    layout:setContentSize(cc.size(1138,bgHeight + 40))

    self.chatContentListView:pushBackCustomItem(layout)
             --使scrollToBottom可以移到最底部
    self.chatContentListView:setInnerContainerSize(cc.size(self.chatContentListView:getInnerContainerSize().width,self.chatContentListView:getInnerContainerSize().height  + bgHeight + 40))

    if self.chatContentListView:getInnerContainerSize().height > 404 then
        self.chatContentListView:scrollToBottom(0.02,false)
    end
end

function FriendTalkLayer:getMessage(notify)
    local id = notify._userData[1]
    if ChatRecordPool:getInstance().IsInChatUserGameID == id then                   --正在聊天的是发消息来的
        self:addWord(1,notify._userData[2])
    elseif GameManager:getUserSelf():getGameID() == id then
        self:addWord(0,notify._userData[2])
    end
end

function FriendTalkLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/expression.plist","hall/expression.png")
	ChatRecordPool:getInstance().IsInChatUserGameID  = nil
    CFrameDataHandler:getInstance():removeEventListenerByList(self.events)
end

return FriendTalkLayer
