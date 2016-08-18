local BaseLayer       = import("app/views/layer/BaseLayer.lua")
local StorageLayer    = class("StorageLayer",BaseLayer)
local CMD_Server_Gift = import("app/cmd/loginSever/CMD_Server_Gift.lua")
local CMD_Server_Bank = import("app/cmd/loginSever/CMD_Server_Bank.lua")
local LuaUtil         = import("app/library/LuaUtil")
StorageLayer.pic      = {2,1,3,5,4,6,7,8}

StorageLayer.events = {
--    ccNd_Bank_InsureInfo = "ccNd_Bank_InsureInfo", --银行资料
    ccND_Bank_Query         = "ccND_Bank_Query",
--    ccNd_Bank_Result = "ccNd_Bank_Result",--银行操作结果
    ccND_Bank_SUCCESS       = "ccND_Bank_SUCCESS",    --银行操作成功
    ccND_Bank_FAILURE       = "ccND_Bank_FAILURE",    --银行操作失败
    ccND_Storage_Info       = "ccND_Storage_Info",   --礼物数据接收
    ccND_Storage_GiftRecord = "ccND_Storage_GiftRecord"
}

function StorageLayer:ctor()
    self.super.ctor(self)

    display.addSpriteFrames("hall/storage.plist","hall/storage.png")
    display.addSpriteFrames("common.plist","common.png")

    self:setupView()
    self:show()

    CFrameDataHandler:getInstance():addNotifyListener(self)
end

function StorageLayer:OnTCPWithDataLoad(notify)
    if notify:getMainType() == CMD_Server_Gift.MDM_GP_USER_SERVICE then --用户命令  3
        local sub = notify:getSubType()
        if sub == CMD_Server_Gift.SUB_GP_USER_PAWNSHOP_INFO_RET then
            return true--self:giftInfo(notify)
        end
    end
    return false
end

function StorageLayer:OnTCPWithDataRoom(notify)
    if notify:getMainType() == CMD_Server_Bank.MDM_GR_INSURE then --银行命令 5
        local sub = notify:getSubType()
        if sub == CMD_Server_Bank.SUB_CP_QUERY_INSURE_INFO then --银行查询响应
            return self:onBankInsureInfo(notify)
        elseif sub == CMD_Server_Bank.SUB_GR_USER_INSURE_SUCCESS then  --银行操作成功
            return self:onBankOperationSuccess(notify)
        elseif sub == CMD_Server_Bank.SUB_GR_USER_INSURE_FAILURE then --银行操作失败
            return self:onBankOperationFailure(notify)
        elseif sub == CMD_Server_Gift.SUB_GR_S_USER_SEND_GIFT_RESPONSE then     --赠送记录响应
            return self:giftRecordCallBack(notify)
        end
    end
    return false
end


function StorageLayer:showCallBack()
    self:setupTab()
end

function StorageLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

function StorageLayer:setupView()
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

    self:showAcessPanel()
end


local tabPosX = {209,591,976}
local tabPosY = 601
function StorageLayer:setupTab()
    self.tabs = {}
    self.tabs[1] = ccui.Button:create("tab_acess_back.png","tab_acess_front.png","tab_acess_front.png",1):addTo(self.panel):setPosition(tabPosX[1],tabPosY)
    self.tabs[2] = ccui.Button:create("tab_giftware_back.png","tab_giftware_front.png","tab_giftware_front.png",1):addTo(self.panel):setPosition(tabPosX[2],tabPosY)
    self.tabs[3] = ccui.Button:create("tab_giftlog_back.png","tab_giftlog_front.png","tab_giftlog_front.png",1):addTo(self.panel):setPosition(tabPosX[3],tabPosY)

    for i = 1, 3 do
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

function StorageLayer:onTabClick(ref, type)
    if type == 2 then --release
        audio.playSound("music/click")
        for i = 1,#self.tabs do
            if ref == self.tabs[i] then
                self:setTab(i)
            end
        end
    end
end

function StorageLayer:setTab(tabIdx)
    for i = 1, #self.tabs do
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[tabIdx]:setTouchEnabled(false)
    self.tabs[tabIdx]:setBright(false)

    self.particle:setPosition(tabPosX[tabIdx],tabPosY - 15)

    self.tabIdx = tabIdx

    if tabIdx == 1 then
        self:showAcessPanel()
    elseif tabIdx == 2 then
        self:showGiftwarePanel()
    elseif tabIdx == 3 then
        self:showGiftlogPanel()
    end
end

function StorageLayer:showAcessPanel()
    CFrameDataHandler:getInstance():BankQuery()
    self.node:removeAllChildren()
    local bg = display.newSprite("#bg_acess.png"):addTo(self.node):setPosition(598,290)
    display.newSprite("#icon_coin_box.png"):addTo(bg):setPosition(190,255)

    local btnOnClick = function(ref,type)
                            if type == 0 then --begin
                            elseif type == 1 then --moved
                            elseif type == 2 then --release
                                audio.playSound("music/click")
                                if ref:getTag() == 201 then
                                    self:saveSorce()
                                elseif ref:getTag() == 202 then
                                    self:takeOutSorce()
                                end
                            elseif type == 3 then --cancle
                            end
                        end

    local btnStore = ccui.Button:create("btn_store_nornal.png","btn_store_pressed.png","btn_store_pressed.png",1):addTo(bg):setPosition(550,100):setTag(201)
    local btnTakeout = ccui.Button:create("btn_takeout_normal.png","btn_takeout_pressed.png","btn_takeout_pressed.png",1):addTo(bg):setPosition(950,100):setTag(202)
    btnStore:addTouchEventListener(btnOnClick)
    btnTakeout:addTouchEventListener(btnOnClick)

    local user = GameManager:getUserSelf()
    self.scoreLabel = cc.Label:create():addTo(bg):setPosition(452,438):setString("当前游戏币："..user:getScore()):setSystemFontSize(38):setAnchorPoint(0,0.5):setTextColor(cc.c4b(253,255,66,255))
    self.safeBoxLabel = cc.Label:create():addTo(bg):setPosition(452,348):setString("保险柜游戏币："..user:getInsureScore()):setSystemFontSize(38):setAnchorPoint(0,0.5):setTextColor(cc.c4b(253,255,66,255))

    self.textField = ccui.TextField:create():addTo(bg):setPosition(735,235):setAnchorPoint(0,0.5)
    self.textField:setPlaceHolder("输入金额")
    self.textField:setTouchSize(cc.size(365,60))
    self.textField:setFontSize(40)
end

function StorageLayer:updateAcessPanel()
    local user = GameManager:getUserSelf()
    self.scoreLabel:setString("当前游戏币："..user:getScore())
    self.safeBoxLabel:setString("保险柜游戏币："..user:getInsureScore())
    self.textField:setString("")
    --更新游戏大厅
    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():updateGameView()
    end
end

function StorageLayer:showGiftwarePanel()
    self.node:removeAllChildren()
    -- CFrameDataHandler:getInstance():sendSocketGift()
end

function StorageLayer:showGiftlogPanel()
    self.node:removeAllChildren()
    local bg = display.newSprite("#bg_gift_log.png"):addTo(self.node):setPosition(598,290)
    self.giftlogListView = ccui.ListView:create():addTo(bg)
    self.giftlogListView:setDirection(1)
    self.giftlogListView:setTouchEnabled(true)
    self.giftlogListView:setBounceEnabled(true)
    self.giftlogListView:setPosition(34,25)
    self.giftlogListView:setContentSize(cc.size(1090,404))
    CFrameDataHandler:getInstance():giveGiftRecord()
end

function StorageLayer:showGiftlogList(loglist)
    self.giftlogListView:removeAllItems()
    local user = GameManager:getUserSelf()
    for k,v in ipairs(loglist) do
        local item = display.newNode()
        local split = display.newSprite("#split.png"):addTo(item):setPosition(500,110)

        local labelName1 = cc.Label:create():addTo(item):setPosition(118,80):setSystemFontSize(40):setTextColor(cc.c4b(3,36,67,255))
        local labelName2 = cc.Label:create():addTo(item):setPosition(385,80):setSystemFontSize(40):setTextColor(cc.c4b(3,36,67,255))
        local labelID1 = cc.Label:create():addTo(item):setPosition(118,24):setSystemFontSize(35):setTextColor(cc.c4b(0,74,158,255))
        local labelID2 = cc.Label:create():addTo(item):setPosition(385,24):setSystemFontSize(35):setTextColor(cc.c4b(0,74,158,255))
        local strDate = string.sub(v.szDateTime,1,10)
        local labelDate = cc.Label:create():addTo(item):setPosition(930,64):setString(strDate):setSystemFontSize(40):setTextColor(cc.c4b(3,36,67,255))

        if v.bInOut == 1 then
            labelName1:setString(user:getNickName())
            labelName2:setString(v.szNickName)
            labelID1:setString("("..user:getGameID()..")")
            labelID2:setString("("..v.dwDecGameID..")")
        else
            labelName2:setString(user:getNickName())
            labelName1:setString(v.szNickName)
            labelID2:setString("("..user:getGameID()..")")
            labelID1:setString("("..v.dwDecGameID..")")
        end

        MotionUtil:cutLabel(labelName1,210)
        MotionUtil:cutLabel(labelName2,210)

        local layout = ccui.Layout:create()
        layout:setTag(k)
        layout:addChild(item)
        layout:setContentSize(cc.size(1080,114))
        self.giftlogListView:pushBackCustomItem(layout)
    end
end

-- 存入银行
function StorageLayer:saveSorce()

    local str = self.textField:getString()
    local suc,content = self:checkFromatSource(str)
    if suc then
--        GameManager:showLoading(self)
--        jt.CFrameData:getInstance():sendPacketWithGPSaveScore(tonumber(str))
        CFrameDataHandler:getInstance():BankSave(tonumber(str))
    else
        --数据有误
        GameManager:showAlertSystem(self,content)
    end
end

-- 银行取出
function StorageLayer:takeOutSorce()
    local str = self.textField:getString()
    local suc,content = self:checkFromatSource(str)
    if suc then
--        GameManager:showLoading(self)
--        jt.CFrameData:getInstance():sendPacketWithGPTakeScore(tonumber(str),"888888")
        CFrameDataHandler:getInstance():BankTake(tonumber(str))
    else
        --数据有误
        GameManager:showAlertSystem(self,content)
    end
end

-----------
--银行转账
function StorageLayer:transferScore()
    local userid = self.panel2:getChildByName("tf_user_id"):getString()
    local tf_score_num = self.panel2:getChildByName("tf_score_num"):getString()
    local suc,content = self:checkFromatSource(userid)
    if suc then
--        GameManager:showLoading(self)
        jt.CFrameData:getInstance():sendPacketWithGPTransferScore(
            tonumber(tf_score_num),"888888",0,userid)
    else
        --数据有误
        GameManager:showAlertSystem(self,content)
    end
end

function StorageLayer:onBankInsureInfo(notify)
    local user = GameManager:getUserSelf()
    GameManager:hideLoading()
    if notify:getSize() == 0 then
        print("没有数据")
    else
        local cmd = CMD_Server_Bank.CMD_MB_Query:createWithNotify(notify)

        user:setScore(cmd.info.lUserScore)
        user:setInsureScore(cmd.info.lUserInsure)
    end
    if self.tabIdx == 1 then
        self:updateAcessPanel()
    end
    return true
end

-----
--存取款操作成功
function StorageLayer:onBankOperationSuccess(notify)
--    self.contentNode:getChildByName("gold_input"):setString("")
    local user = GameManager:getUserSelf()
    GameManager:hideLoading()

    if notify:getSize() == 0 then
        print("没有数据")
    else
        local cmd = CMD_Server_Bank.CMD_GR_S_UserInsureSuccess:createWithNotify(notify)
        user:setScore(cmd.info.lUserScore)
        user:setInsureScore(cmd.info.lUserInsure)
        GameManager:showAlertSystem(self,cmd.info.szDescribeString)
        if self.tabIdx == 1 then
            self:updateAcessPanel()
        end
    end
    return true
end

function StorageLayer:onBankOperationFailure(notify)
    GameManager:hideLoading()
--    self.contentNode:getChildByName("gold_input"):setString("")
    if notify:getSize() == 0 then
        print("没有数据")
    else
        local cmd = CMD_Server_Bank.CMD_GR_S_UserInsureFailure:createWithNotify(notify)
        GameManager:showAlertSystem(self,cmd.info.szDescribeString)
    end
    return true
end

function StorageLayer:giftInfo(event)
    if self.tabIdx ~= 2 then
        return
    end
    local notify = event._userData
    if notify:getSize() == 0 then
        print("没有数据")
    else
        local cmd = CMD_Server_Gift.CMD_MB_GiftInfo:createWithNotify(notify)
        local t = cmd.info.giftTpye
        local n = cmd.info.giftNum
        local name = cmd.info.GiftName
        for i=1,CMD_Server_Gift.LEN_GIFT_NUM do
            self.contentNode:getChildByName("scrollView"):getChildByTag(i):setString("x"..cmd.info.giftNum[i])
        end
    end
end

function StorageLayer:giftRecordCallBack(notify)
    if self.tabIdx ~= 3 then
    	return
    end
    if notify:getSize() == 0 then
        print("没有数据")
    else
        local cmd = CMD_Server_Gift.CMD_MB_GiftRecord:createWithNotify(notify)
        local user = GameManager:getUserSelf()
        self:showGiftlogList(cmd.allInfo)
    end
    return true
end

-- 转账记录
function StorageLayer:onBankTransGoldRecord(event)
    local notify = event._userData
    local ref = jt.CMD_GR_S_TransGoldRecordInfoRef:createWithNotify()
    local size = ref:getSize()
    for i=1,notify:getSize()/size do
        local cmd = jt.CMD_GR_S_TransGoldRecordInfoRef:createWithDataArray(notify,i-1)
        --        print(cmd:szDateTime(),cmd:)
    end
end

-- 检测输入框金额格式
-- @return #bool #string
function StorageLayer:checkFromatSource(str)
    if string.len(str) == 0 then
        return false,"金额不能为空"
    end

    local num = tonumber(str)
    if num == nil then
        return false,"输入金额有误"
    end

    if num <= 0 then
        return false,"输入金额不能为0"
    end
    return true,""
end

function StorageLayer:getIndexByType(gift_type)
    for i = 1,#CMD_Server_Gift.need do
        if gift_type == CMD_Server_Gift.need[i] - 1 then
    		return i
    	end
    end
	return 1
end

function StorageLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/storage.plist","hall/storage.png")
    CFrameDataHandler:getInstance():removeNotifyListener(self)  
end

return StorageLayer
