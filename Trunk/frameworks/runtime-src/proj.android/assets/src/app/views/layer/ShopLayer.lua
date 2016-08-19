--商店
local BaseLayer         = import("app/views/layer/BaseLayer.lua")
local ShopLayer         = class("ShopLayer",BaseLayer)
local URLLoaderHandler  = import("app/handler/URLLoaderHandler.lua")
local SDKControlHandler = import("app/handler/SDKControlHandler.lua")
local CMD_Server_Gift   = import("app/cmd/loginSever/CMD_Server_Gift.lua")
local SendGiftLayer     = import("app/views/layer/SendGiftLayer.lua")
local ShopData          = import("app/models/data/ShopData.lua")
local json              = import("app/library/cjson")
local Timer             = import("app/library/Timer.lua")

local CMD_Server_Shop  = import("app/cmd/loginSever/CMD_Server_Shop.lua")
local CMD_Server_Bank  = import("app/cmd/loginSever/CMD_Server_Bank.lua")
local CMD_Server_Logon = import("app/cmd/loginSever/CMD_Server_Logon.lua")

ShopLayer.PRODUCT_COUNT = 6
ShopLayer.GIFT_COUNT    = 8

local proList  = nil
local giftList = nil
local proData  = ""
local goldList = nil
local propData = nil
local instance = nil

local PaySelectLayer = class("PaySelectLayer",BaseLayer)

function ShopLayer:ctor(user,tabIndex)
    if device.platform == "android" then
        local online = tonumber(Resources:getString("online"))
        if GameManager.transferState == 0 and online == 1 then
            GameManager:showAlertSystem(self,"商城暂未开放,敬请期待")
            return
        end
    end

    instance = self
    self.super.ctor(self)
    self.user = user
    self.currentDiamond = tonumber(GameManager:getUserSelf():getDiamond())
    tabIndex = tabIndex or 1

    display.addSpriteFrames("hall/shop.plist","hall/shop.png")
    display.addSpriteFrames("common.plist","common.png")

    self.userSelf = GameManager:getUserSelf()

    self:setupView()
    self:show()
    self:setTab(tabIndex)
    self.choose = 0

    --注册SDK支付结果通知
    self.sdk = jt.SDKControl:getInstance()
    local handle1,tag1 = SDKControlHandler:getInstance():addSelector(self.sdk,SDKControlHandler.RecipientsList.ccNd_Shop_AppStore_Buy_Info_Result,handler(self,self.ccPayHandler))
    local handle2,tag2 = SDKControlHandler:getInstance():addSelector(self.sdk,SDKControlHandler.RecipientsList.ccNd_Notify,handler(self,self.ccNotifyHandler))
    self.listenersList = {tag1,tag2}

    CFrameDataHandler:getInstance():addNotifyListener(self)
end

function ShopLayer:OnTCPWithDataLoad(notify)
    if notify:getMainType() == CMD_Server_Logon.MDM_GP_USER_SERVICE then --用户命令  3
        local sub = notify:getSubType()
        if sub == CMD_Server_Shop.SUB_MB_QUERY_RETURN then     --商品查询返回 525
            return true --self:onQueryPropResult(notify)
        elseif sub == CMD_Server_Shop.SUB_MB_BUY_RETURN then   --购买返回 526
            return true --self:onBuyPropResult(notify)
        elseif sub == CMD_Server_Bank.SUB_GL_USER_INSURE_INFO then --银行资料  403
            return self:onBankInsureInfo(notify)
        elseif sub == CMD_Server_Logon.SUB_GL_OPERATE_SUCCESS then --操作成功  900
            return true
        elseif sub == CMD_Server_Logon.SUB_GL_OPERATE_FAILURE then --操作失败  901
            return true --self:onOpreate(notify)
        end
    end

    return false
end

function ShopLayer:OnTCPWithDataRoom(notify)
    if notify:getMainType() == CMD_Server_Bank.MDM_GR_INSURE then --银行命令 5
        local sub = notify:getSubType()
        if sub == CMD_Server_Shop.SUB_GR_S_USER_CHARGE_SCORE_RESPONSE then  -- 钻石换金币响应
            return self:onChargeResult(notify)
        elseif sub == CMD_Server_Shop.SUB_GR_S_USER_CHARGE_INFO_RESPONSE then   -- 钻石兑换查询响应
            return self:onQueryGoldResult(notify)
        end
    end
    return false
end

function ShopLayer:setupView()
    self.panel = display.newNode():addTo(self):setPosition(display.cx,display.cy)
    self.bg = display.newSprite("bg_shop.jpg"):addTo(self.panel):setScale(nf.bgScale)
    -- self.panel = display.newSprite("#common_layer_bg.png"):addTo(self):setPosition(display.cx,display.cy - 10)
    self:setRootBg(self.panel)
    local size = self.bg:getContentSize()
    self.btnClose = ccui.Button:create("btn_close.png","btn_close.png","btn_close.png",1):addTo(self.panel,1):setPosition(display.width/2 - 53,display.height/2 - 55)
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
    --tab按钮
    self:setupTab()
    --下栏
    local bottomBar = display.newSprite("#shop_bottom_bar.png"):addTo(self.panel):setPosition(0,-display.cy + 123/2)
    local coinNode = display.newScale9Sprite("shop_value_bg.png",1,cc.size(332,57),cc.rect(141,57/2,1,1)):addTo(bottomBar):setPosition(700,123/2-5)
    display.newSprite("#icon_coin.png"):addTo(coinNode,1):setPosition(-5,57/2)
    self.labelCoin = cc.Label:create():addTo(coinNode):setPosition(161,57/2):setString(self.userSelf:getScore()):setSystemFontSize(38)
    local diamondNode = display.newScale9Sprite("shop_value_bg.png",1,cc.size(272,57),cc.rect(141,57/2,1,1)):addTo(bottomBar):setPosition(1110,123/2-5)
    display.newSprite("#icon_diamond.png"):addTo(diamondNode,1):setPosition(-5,57/2)
    self.labelDiamond = cc.Label:create():addTo(diamondNode):setPosition(136,57/2):setString(self.userSelf:getDiamond()):setSystemFontSize(38)
    --4个页面
    self.node = {}
    for i = 1, 4 do self.node[i] = display.newNode():addTo(self.panel):setVisible(false) end
    self:initCoinPanel()
    self:initDiamondPanel()
    self:initGiftPanel()
    self:initCannonPanel()
end

local tabPosX = {-405, -135, 135 , 405}
local tabPosY = display.cy - 55
function ShopLayer:setupTab()
    self.tabs = {{},{},{},{}}
    local tabFrontRes = {"tab_shop1_front.png","tab_shop2_front.png","tab_shop3_front.png","tab_shop4_front.png"}
    local tabBackRes = {"tab_shop1_back.png","tab_shop2_back.png","tab_shop3_back.png","tab_shop4_back.png"}

    for i = 1, #self.tabs do
        self.tabs[i] = ccui.Button:create(tabBackRes[i],tabFrontRes[i],tabFrontRes[i],1):addTo(self.panel):setPosition(tabPosX[i],tabPosY)
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[1]:setTouchEnabled(false)
    self.tabs[1]:setBright(false)
end

function ShopLayer:onTabClick(ref, type)
    if type == 2 then --release
        audio.playSound("music/click")
        for i = 1,#self.tabs do
            if ref == self.tabs[i] then
                self:setTab(i)
            end
        end
    end
end

function ShopLayer:setTab(tabIdx)
    for i = 1, #self.tabs do
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[tabIdx]:setTouchEnabled(false)
    self.tabs[tabIdx]:setBright(false)

    self.tabIdx = tabIdx

    for i = 1, 4 do
        self.node[i]:setVisible(tabIdx == i)
        if (tabIdx == i) and (tabIdx == 1 or tabIdx == 2) then
            local listView = self.node[i]:getChildByTag(1)
            listView:scrollToLeft(0.01, false)
            self.node[i]:setPositionX(display.width)
            self.node[i]:runAction(cc.MoveBy:create(0.3,cc.p(-display.width,0)))
        end
    end
end

function ShopLayer:initCoinPanel()
    local listView = ccui.ListView:create():addTo(self.node[1]):setTag(1)
    listView:setDirection(2)
    listView:setTouchEnabled(true)
    listView:setBounceEnabled(true)
    listView:setPosition(-display.cx,-230)
    listView:setContentSize(cc.size(display.width,460))

    for i = 1, ShopLayer.PRODUCT_COUNT do
        local item = display.newSprite("#shop_item_bg.png"):setPosition(263/2 + 20,225):setTag(1)
        display.newSprite("#shop_item_coin"..i..".png"):addTo(item):setPosition(263/2,256)
        local money = ShopData.MoneyNum[i]
        if money > 10000 then
            money = money/10000 .. "w"
        end
        local labelMoney = cc.Label:createWithBMFont("fonts/bmfont1.fnt",money):setPosition(263/2,405):addTo(item):setTag(200)
        local btn = ccui.Button:create("shop_item_btn.png","shop_item_btn.png","shop_item_btn.png",1):addTo(item):setPosition(263/2,100):setTag(i)
        btn:addTouchEventListener(handler(self,self.onBuyCoinClick))

        local diamond = ShopData.MoneyDiamond[i]
        display.newSprite("#icon_diamond.png"):addTo(btn):setPosition(40,39):setScale(0.8)
        local labelDiamond = cc.Label:createWithBMFont("fonts/bmfont2.fnt",diamond):setPosition(128,48):addTo(btn):setTag(100)

        zzy.ui.BlinkStar.new({starSrc = "#shine_coin.png", batchSrc = "hall/hall.png", num = 2,interval = 8, isRepeat = true, minX = -60, maxX = 60, minY = -60, maxY = 60})
             :show()
             :addTo(item,1)
             :setPosition(263/2,256)

        local layout = ccui.Layout:create()
        layout:setContentSize(cc.size(293,450))
        layout:addChild(item)
        listView:pushBackCustomItem(layout)
    end

    if goldList == nil then
        CFrameDataHandler:getInstance():getChargeScore(1,0)
    else
        self:onUpdateGold(goldList)
    end
end

function ShopLayer:initDiamondPanel()
    local listView = ccui.ListView:create():addTo(self.node[2]):setTag(1)
    listView:setDirection(2)
    listView:setTouchEnabled(true)
    listView:setBounceEnabled(true)
    listView:setPosition(-display.cx,-230)
    listView:setContentSize(cc.size(display.width,460))

    for i = 1, ShopLayer.PRODUCT_COUNT do
        local item = display.newSprite("#shop_item_bg.png"):setPosition(263/2 + 20,225):setTag(1)
        display.newSprite("#shop_item_diamond"..i..".png"):addTo(item):setPosition(263/2,256)
        local diamond = ShopData.diamondNum[i]
        if diamond > 10000 then
            diamond = diamond/10000 .. "w"
        end
        local labelDiamond = cc.Label:createWithBMFont("fonts/bmfont1.fnt",diamond):setPosition(263/2,405):addTo(item):setTag(200)
        local btn = ccui.Button:create("shop_item_btn.png","shop_item_btn.png","shop_item_btn.png",1):addTo(item):setPosition(263/2,100):setTag(i)
        btn:addTouchEventListener(handler(self,self.onBuyDiamondClick))

        local diamond = ShopData.diamondMoney[i]
        local labelMoney = cc.Label:createWithBMFont("fonts/bmfont2.fnt","y"..diamond):setPosition(104,48):addTo(btn):setTag(100)

        zzy.ui.BlinkStar.new({starSrc = "#shine_diamond.png", batchSrc = "hall/hall.png", num = 2,interval = 8, isRepeat = true, minX = -60, maxX = 60, minY = -60, maxY = 60})
             :show()
             :addTo(item,1)
             :setPosition(263/2,256)

        local layout = ccui.Layout:create()
        layout:setContentSize(cc.size(293,450))
        layout:addChild(item)
        listView:pushBackCustomItem(layout)
    end

    if proList == nil then
        local platform = jt.SDKControl:getInstance():getSDKPlatform()
       local storetype = nil
       if platform == 1 then --应用宝
           storetype = 4
       end
       URLLoaderHandler:load(GameManager:getProject():getProductURL(storetype),handler(self,self.onLoadComolete))
    else
        self:loadData(proList)
    end
end

function ShopLayer:initGiftPanel()
    cc.Label:create():addTo(self.node[3]):setString("即将开放，敬请期待！"):setSystemFontSize(46)
end

function ShopLayer:initCannonPanel()
    cc.Label:create():addTo(self.node[4]):setString("即将开放，敬请期待！"):setSystemFontSize(46)
end

function ShopLayer:onBuyCoinClick(ref,type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        self.buyIdx = ref:getTag()
        local function chargeScore()
            local cmd = goldList[self.buyIdx]
            local diamond = cmd.nDiamondCount
            if GameManager:getUserSelf():getDiamond() < diamond then
                GameManager:showAlertSystem(self,"操作失败，您的钻石不够！")
                return
            end
            local function onClick(result)
                if result == RT_SUCCESS then
                    if GameManager:isPlatformControl() then
                        local niu,timer = GameManager:showLoading(self)
                        timer:stop()
                        local map = {}
                        map.mainType = CMD_Server_Bank.MDM_GR_INSURE
                        map.subType = CMD_Server_Shop.SUB_GR_USER_CHARGE_SCORE
                        map.amt = diamond
                        map.userid = GameManager:getUserSelf():getUserID()
                        map.gameID = GameManager:getUserSelf():getGameID()
                        map.domainURL = "http://" .. GameManager:getProject().LoginAddress ..GameManager:getProject().URLPort
                        SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCNotify,map)
                    else
                        CFrameDataHandler:getInstance():getChargeScore(2,self.buyIdx)
                    end
                end
            end
            local gold = cmd.nDiamondCount * cmd.nCharageRate
            if gold > 10000 then
                gold = gold * 0.0001 .. "万"
            end
            --                local diamond = self.panel_coin:getChildByName("txt_xia_"..i):getString()
            --                local gold = self.panel_coin:getChildByName("txt_shang_"..i):getString()
            GameManager:showAlertSystem(self,"确认使用"..diamond.."钻石兑换"..gold.."金币吗？",onClick):setBtnVisible(true,true)
        end

        local function checkData()
            if goldList == nil then
                GameManager:showAlertSystem(self,"正在为你获取商品数据，点击再次尝试购买",function(result)
                    if result == RT_SUCCESS then
                        checkData()--递归检查
                    end
                end):setBtnVisible(true,true)
            elseif #goldList == 0 then
                GameManager:showAlertSystem(self,"兑换失败，钻石兑换列表数据为空")
            else
                chargeScore()
            end
        end
        checkData()
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function ShopLayer:onBuyDiamondClick(ref,type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        self.buyIdx = ref:getTag()
        local function startBuy()
            if device.platform == "ios" then
                local v = jt.SDKControl:getInstance():getValueFromPlatform(8,"") --获取渠道类型
                if GameManager.transferState == 0 and device.platform == "ios" then
                    self:onBuyDiamond(0)--使用appstore
                elseif v == 1 then
                    self:onBuyDiamond(1)
                else
                    PaySelectLayer:create(self,self.buyIdx):addTo(self)
                end
            else
                self:onBuyDiamond(1)
            end
        end

        local function checkData()
            if   proList == nil or proList.ds == nil then
                GameManager:showAlertSystem(self,"正在为你获取商品数据，点击再次尝试购买",function(result)
                    if result == RT_SUCCESS then
                        checkData()--递归检查
                    end
                end):setBtnVisible(true,true)
            else
                startBuy()
            end
        end
        checkData()
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function ShopLayer:onTouch(event)
    return true
end

function ShopLayer:onLoadComolete(urlData)
    print("ShopLayer:onLoadComolete(urlData)",urlData:getStatusCode(),urlData:getData())

    GameManager:hideLoading()
    if urlData:getStatusCode() == URLLoaderHandler.STATUS_CODES.SUCCESS then
        proData = urlData:getData()
        --        proData = '{"ok":true,"ds":[{"ProductID":"30000549400901","APPID":"27","DeviceType":"0","StoreType":"0","ProductName":"初级宝箱","Description":"获得6万金币奖励","Price":"6.00","ImageUrl":"http://61.147.113.53:8931/Upload/1.png","Remark":"60000","CollectDate":"2015-5-13 15:30:44","ProductState":"0"},{"ProductID":"30000549400902","APPID":"27","DeviceType":"0","StoreType":"0","ProductName":"高级宝箱","Description":"获得80万金币奖励","Price":"60.00","ImageUrl":"http://61.147.113.53:8931/Upload/3.png","Remark":"800000","CollectDate":"2015-5-13 15:34:21","ProductState":"0"},{"ProductID":"30000549400904","APPID":"27","DeviceType":"0","StoreType":"0","ProductName":"中级宝箱","Description":"获得39万金币奖励","Price":"30.00","ImageUrl":"http://61.147.113.53:8931/Upload/2.png","Remark":"390000","CollectDate":"2015-5-13 15:33:27","ProductState":"0"},{"ProductID":"30000549400906","APPID":"27","DeviceType":"0","StoreType":"0","ProductName":"超级宝箱","Description":"获得150万金币奖励","Price":"108.00","ImageUrl":"http://61.147.113.53:8931/Upload/4.png","Remark":"1500000","CollectDate":"2015-5-13 15:36:38","ProductState":"0"},{"ProductID":"30000549400907","APPID":"27","DeviceType":"0","StoreType":"0","ProductName":"豪华宝箱","Description":"获得300万金币奖励","Price":"208.00","ImageUrl":"http://61.147.113.53:8931/Upload/5.png","Remark":"3000000","CollectDate":"2015-5-13 15:37:38","ProductState":"0"},{"ProductID":"30000549400908","APPID":"27","DeviceType":"0","StoreType":"0","ProductName":"白金宝箱","Description":"获得968万金币奖励","Price":"618.00","ImageUrl":"http://61.147.113.53:8931/Upload/6.png","Remark":"9680000","CollectDate":"2015-5-13 15:38:26","ProductState":"0"}]}'
        proList = json.decode(proData)
        self:loadData(proList)
    else
    --        GameManager:showAlertSystem(self,"加载失败,请稍候再试",handler(self,self.hide))
    end
end

function ShopLayer:loadData(proList)
    if proList.ds == nil then
        return
    end

    for i = 1, ShopLayer.PRODUCT_COUNT do
        local list =  self.node[2]:getChildByTag(1)
        local layout = list:getItem(i-1)
        local item = layout:getChildByTag(1)
        local label1 = item:getChildByTag(200)
        local btn = item:getChildByTag(i)
        local label2 = btn:getChildByTag(100)

        local cmd = goldList[i]
        local gold = cmd.nDiamondCount * cmd.nCharageRate
        if gold > 10000 then
            gold = gold * 0.0001 .. "w"
        end

        label1:setString(proList.ds[i].Remark)
        label2:setString("y"..tonumber(proList.ds[i].Price))
    end
end

--------
-- 金币查询操作
function ShopLayer:onBankInsureInfo(notify)
    local cmd = jt.CMD_GP_UserInsureInfoRef:createWithNotify(notify)
    GameManager:getUserSelf():setScore(cmd:lUserScore())
    --更新游戏大厅
    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():updateGameView()
    end
    return true
end

function ShopLayer:onGiftInfo(event)
    GameManager:hideLoading()
    self.root:setVisible(true)
--    self:show()
    local notify = event._userData
    if notify:getSize() == 0 then
        print("没有数据")
    else
        local cmd = CMD_Server_Gift.CMD_MB_GiftInfo:createWithNotify(notify)
        giftList = cmd.info
        self:ShowGiftInfo(giftList)
    end
end

function ShopLayer:ShowGiftInfo(gift)
    local index = 1
    for i=1, CMD_Server_Gift.LEN_GIFT_NUM do
        if not gift.dwNotPawn[i] then
            local button_ = self.contentNode:getChildByName("shop_scroll"):getChildByTag(index)
            button_.price = gift.giftBuyPrice[i]

            local price = gift.giftBuyPrice[index]
            if price >= 10000 then
                price = (price/10000).."w"
            end
            self.contentNode:getChildByName("shop_scroll"):getChildByName("price_"..index):setString(price)
            index = index + 1
        end

    end
end

-- 钻石换金币响应
function ShopLayer:onChargeResult(notify)
    local cmd = CMD_Server_Shop.CMD_GR_S_ChargeScore:createWithNotify(notify)
    if cmd.bShareSuccess == 0 then
        GameManager:getUserSelf():setScore(cmd.lCurUserScore)
        GameManager:getUserSelf():setDiamond(cmd.lCurDiamondCount)
        if GameManager:getGameDelegate() ~= nil then
            GameManager:getGameDelegate():updateGameView()
        end
        GameManager:showAlertSystem(self,"兑换成功")
    else
        GameManager:showAlertSystem(self,cmd.szDesc)
    end
    return true
end

-- 钻石兑换查询响应
function ShopLayer:onQueryGoldResult(notify)
    local len = notify:getSize() / CMD_Server_Shop.CMD_GR_S_ChargeQueryResponse:getSize()
    goldList = {}
    local ba = jt.ByteArray:createWithNotify(notify)
    for i = 1,len do
        local cmd = CMD_Server_Shop.CMD_GR_S_ChargeQueryResponse:create()
        cmd:readFormByteArray(ba)
        goldList[i] = cmd
    end
    self:onUpdateGold(goldList)
    return true
end

function ShopLayer:onUpdateGold(goldList)
    for i = 1, #goldList do
        local list =  self.node[1]:getChildByTag(1)
        local layout = list:getItem(i-1)
        local item = layout:getChildByTag(1)
        local label1 = item:getChildByTag(200)
        local btn = item:getChildByTag(i)
        local label2 = btn:getChildByTag(100)

        local cmd = goldList[i]
        local gold = cmd.nDiamondCount * cmd.nCharageRate
        if gold > 10000 then
            gold = gold * 0.0001 .. "w"
        end

        label1:setString(gold)
        label2:setString(cmd.nDiamondCount)
    end
end

--道具查询响应
function ShopLayer:onQueryPropResult(event)
    local notify = event._userData
    local cmd = CMD_Server_Shop.CMD_GR_S_USER_SALESHOP:createWithNotify(notify)
    propData = cmd
    self:updateProp(propData)
end

function ShopLayer:updateProp(propData)
    if self.choose_index ~= 3 then
        return
    end
    self.panel_prop:setVisible(true)
    local list = {GameManager.isOpenStorage,GameManager.isOpenYYL,GameManager.isOpenSlot,0,0}
    local count = ShopLayer.PRODUCT_COUNT-1
    for i=1, ShopLayer.PRODUCT_COUNT-1 do
        local shop_scroll = self.panel_prop:getChildByName("shop_scroll")
        local panel_item = shop_scroll:getChildByName("panel_item_"..i)
        local btn = panel_item:getChildByName("img_btn_"..i)
        local label = panel_item:getChildByName("fnt_gold_"..i)
        local index = i == 5 and 6 or i
        local price = propData.dwSalePrice[index]
        if price > 10000 then
            price = price * 0.0001
        end
        label:setString("$"..price.."w")

        local v = list[i] > 0
        panel_item:getChildByName("spr_isopen_"..i):setVisible(v)
        panel_item:getChildByName("img_btn_"..i):setVisible(not v)
        panel_item:getChildByName("fnt_gold_"..i):setVisible(not v)
    end
end

function ShopLayer:onBuyPropResult(event)
    local notify = event._userData
    local cmd = CMD_Server_Shop.CMD_GR_S_ITEM_SALE:createWithNotify(notify)
    if cmd.dwSuccess == 0 then

        --更新分数
        GameManager:getUserSelf():setScore(cmd.lRestScore)
        if GameManager:getGameDelegate() ~= nil then
            GameManager:getGameDelegate():updateGameView()
        end

        --购买类型
        if cmd.dwItemType == propData.dwItemType[1] then
            GameManager.isOpenStorage = 1
        elseif cmd.dwItemType == propData.dwItemType[2] then
            GameManager.isOpenYYL = 1
        elseif cmd.dwItemType == propData.dwItemType[3] then
            GameManager.isOpenSlot = 1
        elseif cmd.dwItemType == propData.dwItemType[4] then
            GameManager:getUserSelf():setHornNum(GameManager:getUserSelf():getHornNum() + cmd.dwItemCount)
        elseif cmd.dwItemType == propData.dwItemType[6] then
            GameManager.isCanAddFriend = GameManager.isCanAddFriend + cmd.dwItemCount * 10
            --            GameManager:showAlert(self,"操作提示","购买成功，当前好友数量增加为"..(cmd.dwItemCount * 10).."个共"..GameManager.isCanAddFriend.."个")
        end
        GameManager:showAlertSystem(self,"购买成功")
    else
        GameManager:showAlertSystem(self,"操作失败")
    end
    self:updateProp(propData)
end

function ShopLayer:onOpreate(event)
    local notify = event._userData
    if notify:getResult() == RT_FAILURE then
        GameManager:showAlertSystem(self,notify:getMainString())
    end
end

function ShopLayer:onTouchButtonGift(btn,eventType)
    BtnGroup:onTouchButton(btn,eventType)

    if eventType == 2 then
        SendGiftLayer:create(self.user,btn:getTag(),btn.price):addTo(self)
    end
    return true
end

--赠送礼物返回
function ShopLayer:onSendGiftCallBack(event)
    local notify = event._userData
    if notify:getSize() == 0 then
        GameManager:showAlertSystem(self,"赠送礼物失败")
    else
        local cmd = CMD_Server_Gift.CMD_SUB_S_GR_UserSentResponse:createWithNotify(notify)
        if cmd.nRet == 0 then
            GameManager:showAlertSystem(self,"赠送礼物成功")
            GameManager:getUserSelf():setScore(cmd.lScore)
            --更新游戏大厅
            if GameManager:getGameDelegate() ~= nil then
                GameManager:getGameDelegate():updateGameView()
            end
        else
            GameManager:showAlert(self,"赠送失败",cmd.szdesc)
        end

    end
end

function ShopLayer:onBuyDiamond(payType)
    print("----------------------------   ShopLayer:onBuyDiamond",payType)
    local type = payType
    local index = self.buyIdx

    if type == 0 and device.platform ~= "windows" then
        --关闭自动移除
        local niu,timer = GameManager:showLoading(self)
        timer:stop()
    end

    local item = proList.ds[index]
    local map = {}
    map.type = type
    map.gameID = GameManager:getUserSelf():getGameID()
    map.userID = GameManager:getUserSelf():getUserID()
    map.ProductName = item.ProductName
    map.Description = item.Description
    map.Price = item.Price
    map.appid = GameManager:getProject().AppId

    if device.platform == "ios" then --IOS下appstore需把商品ID数据全部传入
        map.data = proData
    else

    end
    local orderURL = GameManager:getProject():getOrderNo(GameManager:getUserSelf():getGameID(),item.ProductID)
    map.OrderURL = orderURL
    map.domainURL = "http://" .. GameManager:getProject().LoginAddress ..GameManager:getProject().URLPort

    -- if CC_SHOW_FPS then
    --     map.Price = "0.01"
    -- end
    map.ProductID = item.ProductID
    map.NotifyURL = GameManager:getProject():getNotifyURL(type)
    map.Remark = item.Remark

    SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCPay,map)

end

function ShopLayer:ccPayHandler(event)
    local valueMapRef = event._userData

    local type = valueMapRef.type
    local result = valueMapRef.result

    --Appstore
    if type == 0 then
        GameManager:hideLoading()
        local state = valueMapRef.state
        local diamond = valueMapRef.diamond
        if result == 1 and diamond > 0 and state == 0 then
            GameManager:getUserSelf():setDiamond(diamond)
            GameManager:showAlert(self,"充值提示","充值成功",function()
                --获取VIP
                CFrameDataHandler:getInstance():getVIPAndHornNum()
            end)
            --更新游戏大厅
            if GameManager:getGameDelegate() ~= nil then
                GameManager:getGameDelegate():updateGameView()
            end
            --获取VIP
            CFrameDataHandler:getInstance():getVIPAndHornNum()
        else
            GameManager:showAlertSystem(self,"购买失败")
        end
        return
    end

    --其它支付结果
    if result == RT_SUCCESS then
        GameManager:showAlertSystem(self,"购买成功",function()
            CFrameDataHandler:getInstance():getVIPAndHornNum()
        end)
        if GameManager:isPlatformControl() then
            --平台控制
        elseif type == 12 or type == 13 then          --魅族、uumon有延迟
            self.oldDiamond = GameManager:getUserSelf():getDiamond()
            local function refreshDiamond()
                if GameManager:getUserSelf():getDiamond() == self.oldDiamond then
                    CFrameDataHandler:getInstance():getVIPAndHornNum()
                else
                    cc.Director:getInstance():getScheduler():unscheduleScriptEntry(meizuSchedule)
                    meizuSchedule = nil
                end
            end
            CFrameDataHandler:getInstance():getVIPAndHornNum()
            meizuSchedule = cc.Director:getInstance():getScheduler():scheduleScriptFunc(refreshDiamond,3,false)
        else
            CFrameDataHandler:getInstance():getVIPAndHornNum()
        end
    else
        GameManager:hideLoading(self)
        GameManager:showAlertSystem(self,"购买失败")
    end
end

function ShopLayer:ccNotifyHandler(event)
    local map = event._userData
    local mainType = map.mainType
    local subType = map.subType
    GameManager:hideLoading()
    self:updateGameView()

    --查询余额
    if mainType == CMD_Server_Logon.MDM_GP_USER_SERVICE
        and subType == CMD_Server_Shop.SUB_MB_SALESHOP_REQ then
        if map.result == 1 then
            local balance = tonumber(map.balance)
            --金币刷新有延迟，须重复查询
            if self.currentDiamond == balance then
                GameManager:getUserSelf():setDiamond(balance)
                self:runAction(MotionUtil:delayCallFunc(3,function()
                    local map = {}
                    map.mainType = CMD_Server_Logon.MDM_GP_USER_SERVICE
                    map.subType = CMD_Server_Shop.SUB_MB_SALESHOP_REQ
                    SDKControlHandler:getInstance():sendMessge(SDKControlHandler.SendMsgList.CCNotify,map)
                end))
            else
                self.currentDiamond = balance
                GameManager:getUserSelf():setDiamond(balance)
                self:updateGameView()
                --更新游戏大厅
                if GameManager:getGameDelegate() ~= nil then
                    GameManager:getGameDelegate():updateGameView()
                end
            end
        end
        return
    end

    if mainType == CMD_Server_Bank.MDM_GR_INSURE
        and subType == CMD_Server_Shop.SUB_GR_USER_CHARGE_SCORE then
        if tonumber(map.result) == 1 then
            --            jt.CFrameData:getInstance():sendPacketWithGPInsureInfo("0")
            GameManager:getUserSelf():setScore(tonumber(map.newscore))
            GameManager:getUserSelf():setDiamond(tonumber(map.balance))
            GameManager:showAlert(self,"操作提示","金币兑换成功")
        else
            GameManager:showAlert(self,"操作提示","兑换失败："..map.msg)
        end
        return
    end
end

function ShopLayer:updateGameView()
    local user = GameManager:getUserSelf()
    self.labelCoin:setString(user:getScore())
    self.labelDiamond:setString(user:getDiamond())
end

--获取当前显示对象
function ShopLayer:getInstance()
    return instance
end

----------
--添加消费记录(已废弃)
--
function ShopLayer:loadAddExpenseURL(ProductID)
    --验证
    local url = GameManager:getProject():getAddExpenseURL(GameManager:getUserSelfID(),ProductID)
    URLLoaderHandler:load(url,handler(self,self.onAddExpense))
end

function ShopLayer:onAddExpense(urlData)
    print("ShopLayer:onLoadComolete(urlData)",urlData:getStatusCode(),urlData:getData())

    GameManager:hideLoading()
    if urlData:getStatusCode() == URLLoaderHandler.STATUS_CODES.SUCCESS then
        local data = json.decode(urlData:getData())
        if data.state == nil or data.state == 0 then
            GameManager:getUserSelf():setScore(data.score)
            --更新游戏大厅
            if GameManager:getGameDelegate() ~= nil then
                GameManager:getGameDelegate():updateGameView()
            end
            GameManager:showAlert(self,"充值提示","充值成功")
            --获取VIP
            CFrameDataHandler:getInstance():getVIPAndHornNum()
        else
            GameManager:showAlert(self,"充值提示","充值失败")
        end
    else
        local function retry(result)
            --            if result == 1 then
            self:loadAddExpenseURL(proList.ds[self.tabIdx].ProductID)
            --            end
        end
        local alert = GameManager:showAlert(self,"充值提示","网络异常，请检查网络后点击重试，否则该订单将失效",retry)
        alert:setBtnVisible(true,true)
        --        cc.UserDefault:setBoolForKey("unfinished",true)
        --        cc.UserDefault:getInstance():flush()
    end
end

------------------------------------
--支付类型选择层
function PaySelectLayer:ctor(ShopLayer)
    PaySelectLayer.super.ctor(self)
    self.shop = ShopLayer
    -- self.root = Resources:createNodeAndDoLayout("layer/system_shop/layer_pay_select.csb"):addTo(self)
    -- self.panel = self.root:getChildByName("panel")
    -- self:setRootBg(self.panel:getChildByName("alert_bg"))
    --
    -- self.btnList = {self.panel:getChildByName("alert_ok"),self.panel:getChildByName("alert_cancal")}
    --
    self.choose = 1
    self:setupView()
end

function PaySelectLayer:setupView()
    self.panel = display.newSprite("#alert_bg.png"):addTo(self):setPosition(display.cx,display.cy - 10)
    self:setRootBg(self.panel)
    local size = self.panel:getContentSize()
    self.node = display.newNode():addTo(self.panel):setPosition(0,0)

    display.newSprite("label_pay_type.png"):addTo(self.panel):setPosition(705/2,406)

    self.labelContent = cc.Label:create():addTo(self.panel):setPosition(705/2,200):setSystemFontSize(40):setDimensions(540,230)

    self.btnConfirm = ccui.Button:create("btn_confirm_normal.png","btn_confirm_pressed.png","btn_confirm_pressed.png",1)
        :addTo(self.panel)
        :setPosition(586,63)
        :setScale(0.7)
    self.btnConfirm:addTouchEventListener(handler(self,self.onBtnClick))

    self.btnCancel = ccui.Button:create("btn_cancel_normal.png","btn_cancel_pressed.png","btn_cancel_pressed.png",1)
        :addTo(self.panel)
        :setPosition(120,63)
        :setScale(0.7)
        :setVisible(true)
    self.btnCancel:addTouchEventListener(handler(self,self.onBtnClick))

    cc.Label:create():addTo(self.panel):setPosition(250,300):setAnchorPoint(0,0.5):setSystemFontSize(30):setTextColor(cc.c4b(255,255,255,255)):setString("支付宝")
    cc.Label:create():addTo(self.panel):setPosition(280,265):setAnchorPoint(0,0.5):setSystemFontSize(22):setTextColor(cc.c4b(255,255,255,255)):setString("(使用支付宝支付有额外钻石赠送)")
    cc.Label:create():addTo(self.panel):setPosition(250,220):setAnchorPoint(0,0.5):setSystemFontSize(30):setTextColor(cc.c4b(255,255,255,255)):setString("微信")
    cc.Label:create():addTo(self.panel):setPosition(280,185):setAnchorPoint(0,0.5):setSystemFontSize(22):setTextColor(cc.c4b(255,255,255,255)):setString("(使用微信支付有额外钻石赠送)")
    cc.Label:create():addTo(self.panel):setPosition(250,140):setAnchorPoint(0,0.5):setSystemFontSize(30):setTextColor(cc.c4b(255,255,255,255)):setString("App Store")

    self.checkSp   = display.newSprite("#shop_radio_check.png"):addTo(self.panel,1):setPosition(220,300)
    self.checkBtn1 = ccui.Button:create("shop_radio_bg.png","shop_radio_bg.png","shop_radio_bg.png",1):addTo(self.panel):setPosition(220,300)
    self.checkBtn2 = ccui.Button:create("shop_radio_bg.png","shop_radio_bg.png","shop_radio_bg.png",1):addTo(self.panel):setPosition(220,220)
    self.checkBtn3 = ccui.Button:create("shop_radio_bg.png","shop_radio_bg.png","shop_radio_bg.png",1):addTo(self.panel):setPosition(220,140)
    self.checkBtn1:addTouchEventListener(handler(self,self.onBtnClick))
    self.checkBtn2:addTouchEventListener(handler(self,self.onBtnClick))
    self.checkBtn3:addTouchEventListener(handler(self,self.onBtnClick))
end

function PaySelectLayer:onBtnClick(target,eventType)
    if eventType == 2 then
        audio.playSound("music/click")
        if target == self.btnConfirm then
            local type = 0 and 0 or self.choose
            if self.choose == 1 then
                type = 1 --支付宝
            elseif self.choose == 3 then
                local wechat = GameManager:getProject().LogonType_Enum.LogonType_WeChat --微信5
                if not jt.SDKControl.LogonBtn_List[wechat+1] then
                    GameManager:showAlertSystem(self,"检测到尚未安装微信，请安装微信后再进行微信支付")
                    return
                end
                type = wechat
            elseif self.choose == 2 then
                type = 0 --appstore
            end
            self:hide()
            self.shop:onBuyDiamond(type)
        elseif target == self.btnCancel then
            self:hide()
        elseif target == self.checkBtn1 then
            self.choose = 1
            self.checkSp:setPositionY(300)
        elseif target == self.checkBtn2 then
            self.choose = 2
            self.checkSp:setPositionY(220)
        elseif target == self.checkBtn3 then
            self.choose = 3
            self.checkSp:setPositionY(140)
        end
    end
end

-- function PaySelectLayer:onTouch(event)
--     BtnGroup:onTouchLayer(event,self.btnList)
--     self.super.onTouch(self,event)
--     if event.name ~= "ended" then return true end
--     local payTypeLen = 3
--     for i=1,payTypeLen do
--         local item = self.panel:getChildByName("panel_item_"..i)
--         if MotionUtil:checkPointToNode(item,event) then
--             item:getChildByName("spr_select"):setSpriteFrame("layer_shop/pay_selected.png")
--             if self.choose ~= i then
--                 local spr_select = self.panel:getChildByName("panel_item_"..self.choose):getChildByName("spr_select")
--                 spr_select:setSpriteFrame("layer_shop/pay_select.png")
--                 self.choose = i
--             end
--         end
--     end
-- end

function ShopLayer:onCleanup()
    instance = nil

    display.removeSpriteFramesWithFile("hall/shop.plist","hall/shop.png")

    SDKControlHandler:getInstance():removeSelectorsBySDK(self.sdk,SDKControlHandler.RecipientsList.ccNd_Shop_AppStore_Buy_Info_Result)
    SDKControlHandler:getInstance():removeSelectorsBySDK(self.sdk,SDKControlHandler.RecipientsList.ccNd_Notify)

    CFrameDataHandler:getInstance():removeNotifyListener(self)
    URLLoaderHandler:destroyInstance()
    if self.meizuSchedule then
--    	cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.meizuSchedule)
    end
end

return ShopLayer
