local BaseLayer           = import("app/views/layer/BaseLayer.lua")
local PersonInfoLayer     = class("PersonInfoLayer",BaseLayer)
local PersonInfoEditLayer = import("app/views/layer/PersonInfoEditLayer.lua")
local SDKControlHandler   = import("app/handler/SDKControlHandler.lua")
local GCMD_Sever_Friends  = import("app/cmd/loginSever/CMD_Sever_Friends.lua")
local StorageLayer        = import("app/views/layer/StorageLayer.lua")
local ShopLayer           = import("app/views/layer/ShopLayer.lua")
local PawnShopLayer       = import("app/views/layer/PawnShopLayer.lua")
local ShareLayer          = import("app/views/layer/ShareLayer.lua")
local json                = import("app/library/cjson")
local CMD_Server_Logon    = import("app/cmd/loginSever/CMD_Server_Logon.lua")
local CMD_Sever_Friends = import("app/cmd/loginSever/CMD_Sever_Friends.lua")

function PersonInfoLayer:ctor(user)
	self.super.ctor(self)

    display.addSpriteFrames("hall/person_info.plist","hall/person_info.png")
    display.addSpriteFrames("common.plist","common.png")

	self.user = user
    self.panel = display.newSprite("#bg_person.png"):addTo(self):setPosition(display.cx,display.cy)
    self:setRootBg(self.panel)
    local size = self.panel:getContentSize()
    self.closeBtn = ccui.Button:create("btn_close.png","btn_close.png","btn_close.png",1):addTo(self.panel,1):setPosition(size.width - 20,size.height - 20)
    self.closeBtn:addTouchEventListener(function(ref,type)
                                            if type == 0 then --begin
                                                 transition.scaleTo(ref, {time = 0.05, scale = 0.9})
                                            elseif type == 1 then --moved
                                            elseif type == 2 then --release
                                                transition.scaleTo(ref, {time = 0.05, scale = 1})
                                                self:hide()
                                            elseif type == 3 then --cancle
                                                transition.scaleTo(ref, {time = 0.05, scale = 1})
                                            end
                                        end)
    self.node = display.newNode():addTo(self.panel):setPosition(0,0)

    display.newSprite("#label_person_info.png"):addTo(self.panel):setPosition(462,534)


    if self.user:getGameID() == GameManager:getUserSelf():getGameID() then
        self.which = 0
        self.user = GameManager:getUserSelf()
    else
        self:setVisible(false)
        self.which = 1
    end

    self:setupView()
    --获取用户信息
    CFrameDataHandler:getInstance():getPersonInfo(self.user:getGameID())

    CFrameDataHandler:getInstance():addNotifyListener(self)
    self.sdk = jt.SDKControl:getInstance()
    SDKControlHandler:getInstance():addSelector(self.sdk,SDKControlHandler.RecipientsList.share,handler(self,self.shareResult))
end

function PersonInfoLayer:OnTCPWithDataRoom(notify)
    if notify:getMainType() == CMD_Sever_Friends.MDM_GR_QUERY then
        -- local sub = notify:getSubType()
        -- if sub == CMD_Sever_Friends.SUB_GR_CHECK_SPREADER_RET then  --查询信息返回
        --     return self:onCheckSpreader(notify)
        -- elseif sub == CMD_Sever_Friends.SUB_GR_DRAW_SPREADER_RET then --领取推广员分数返回
        --     return self:onDrawSpreader(notify)
        -- end
        return true
    end

    if notify:getMainType() == CMD_Sever_Friends.MDM_GR_INSURE then
        local sub = notify:getSubType()
        if sub == GCMD_Sever_Friends.SUB_GR_S_FRIEND_RESP then              --等待好友验证
            return self:onApplyFriendBack(notify)
        end
    end
    return false
end

function PersonInfoLayer:OnTCPWithDataLoad(notify)
    if notify:getMainType() == CMD_Server_Logon.MDM_GP_USER_SERVICE then --用户命令  3
        local sub = notify:getSubType()
        if sub == CMD_Server_Logon.SUB_MB_USER_INDIVIDUAL then --个人资料
            return self:onGetUserInfo(notify)
        elseif sub == CMD_Sever_Friends.SUB_MB_FRIENT_ADD_BLACKLIST then --添加黑名单
            return self:addToBlackListCallBack(notify)
        end
    end
    return false
end

function PersonInfoLayer:onBtnsClick(ref,type)
    if type == 0 then --begin
    elseif type == 1 then --moved
    elseif type == 2 then --release
        if ref == self.btnShare then            --share
            local v = jt.SDKControl:getInstance():getValueFromPlatform(8,"")
            if device.platform == "ios" and v == 1 then
                GameManager:showAlertSystem(self,"暂未开放，敬请期待")
            else
                if device.platform == "ios" then
                    if GameManager.transferState == 0 then
                        ShareLayer:CCShare(2)
                    else
                        ShareLayer:create():addTo(self)
                    end
                else
                    local map = {}
                    if jt.SDKControl:getInstance():getVersionCode() >= 20160627 then --兼容性
                        map.title = jt.SDKControl:getInstance():getStringFromPlatform(0,"getAppName")
                    else
                        map.title = "皇家游戏"
                    end
                    map.content = map.title .. "是一款为玩家精心准备的棋牌休闲游戏，挑战智慧与运气的极限。"
                    map.link = "http://www.zzy1314.com/niuniu.html"
                    map.imageLink = "http://www.zzy1314.com/images/300.png"
                    self.sdk:initUmengShareSDK(map.content,map.imageLink,map.link,map.title)
                end
            end
        elseif ref == self.headBoard then       --edit self info
            PersonInfoEditLayer:create():addTo(self:getParent())
            self:hide()
        elseif ref == self.btnGift then         --send gift
            if GameManager.isCanSendGift > 0 then
                PawnShopLayer:create(self.user):addTo(self)
            else
                GameManager:showAlertSystem(self,"未开通赠送礼物功能")
            end
        elseif ref == self.btnAddBlack then     --add to black list
            self:addToBlackList()
        elseif ref == self.btnAddFriend then    --add friend
            if GameManager.isCanAddFriend > 0 then
                CFrameDataHandler:getInstance():sendPacketWithLoadAddFriend(self.user:getGameID())
            else
                GameManager:showAlertSystem(self,"未开通添加好友功能")
            end
        end
    elseif type == 3 then --cancle
    end
end

function PersonInfoLayer:setupView()
    local user = self.user
    --  self.btnPawn = ccui.Button:create("btn_share_normal.png","btn_share_pressed.png","btn_share_pressed.png",1)
    --  :addTo(self.panel)
    --  :setPosition(764,66)
    --  :addTouchEventListener(handler(self,self.onBtnsClick))

    local head = display.newNode():addTo(self.panel):setPosition(94,420)
    if head.faceURL ~= user:getFaceURL() and user:getFaceURL() ~= "" then
        head = MotionUtil:RepleaceWithURLPic(head,user,cc.size(110,110),nil,true)
        head.faceURL = user:getFaceURL()
    end

    self.headBoard = ccui.Button:create("head_board_big.png","head_board_big.png","head_board_big.png",1):addTo(self.panel,1):setPosition(94,420)
    -- self.headBoard:setTouchEnabled(true)

    if self.which == 0 then --self

        self.headBoard:addTouchEventListener(handler(self,self.onBtnsClick))
        local editBg = display.newSprite("#person_editbox_bg.png"):addTo(self.panel,1):setPosition(94,378):setScale(0.65)
        cc.Label:create():addTo(editBg,1):setPosition(85,18):setString("编辑"):setSystemFontSize(40):setTextColor(cc.c4b(255,255,255,255))

        self.btnShare = ccui.Button:create("btn_share_normal.png","btn_share_pressed.png","btn_share_pressed.png",1)
            :addTo(self.panel)
            :setPosition(458,69)
        self.btnShare:addTouchEventListener(handler(self,self.onBtnsClick))
    elseif self.which == 1 then -- friend
        self.btnGift = ccui.Button:create("btn_gift_normal.png","btn_gift_pressed.png","btn_gift_pressed.png",1)
            :addTo(self.panel)
            :setPosition(232,69)
        self.btnGift:addTouchEventListener(handler(self,self.onBtnsClick))
        self.btnAddBlack = ccui.Button:create("btn_addBlack_normal.png","btn_addBlack_pressed.png","btn_addBlack_pressed.png",1)
            :addTo(self.panel)
            :setPosition(684,69)
        self.btnAddBlack:addTouchEventListener(handler(self,self.onBtnsClick))
    elseif self.which == 2 then --other
        self.btnGift = ccui.Button:create("btn_gift_normal.png","btn_gift_pressed.png","btn_gift_pressed.png",1)
            :addTo(self.panel)
            :setPosition(232,69)
        self.btnGift:addTouchEventListener(handler(self,self.onBtnsClick))

        self.btnAddFriend = ccui.Button:create("btn_addfriend_normal.png","btn_addfriend_pressed.png","btn_addfriend_pressed.png",1)
            :addTo(self.panel)
            :setPosition(684,69)
        self.btnAddFriend:addTouchEventListener(handler(self,self.onBtnsClick))
    end

    local labelName = cc.Label:create():addTo(self.panel,1):setPosition(200,445):setAnchorPoint(0,0.5)
    :setString(user:getNickName()):setSystemFontSize(36):setTextColor(cc.c4b(255,255,255,255))

    self.moneyNode = display.newSprite("#coin_value_bg.png"):addTo(self.panel):setPosition(348,388)
    display.newSprite("#icon_coin.png"):addTo(self.moneyNode,1):setPosition(5,25)
    self.labelCoin = cc.Label:create():addTo(self.moneyNode,1):setPosition(140,25)
    :setString(user:getScore()):setSystemFontSize(30):setTextColor(cc.c4b(255,255,255,255))

    self.diamondNode = display.newSprite("#coin_value_bg.png"):addTo(self.panel):setPosition(693,388)
    display.newSprite("#icon_diamond.png"):addTo(self.diamondNode,1):setPosition(15,25)
    self.labelDiamond = cc.Label:create():addTo(self.diamondNode,1):setPosition(140,25)
    :setString(user:getDiamond() or 0):setSystemFontSize(30):setTextColor(cc.c4b(255,255,255,255))

    self.labelID = cc.Label:create():addTo(self.panel,1):setPosition(74,310):setAnchorPoint(0,0.5)
    :setString("用户ID："..user:getGameID()):setSystemFontSize(33):setTextColor(cc.c4b(255,255,255,255))

    self.labelTitle = cc.Label:create():addTo(self.panel,1):setPosition(74,238):setAnchorPoint(0,0.5)
    :setString("头  衔："..GameManager:getUserManager():getLevel(self.user:getScore())):setSystemFontSize(33):setTextColor(cc.c4b(255,255,255,255))

    self.labelGender = cc.Label:create():addTo(self.panel,1):setPosition(510,238):setAnchorPoint(0,0.5)
    :setString("性  别："..GameManager:getUserManager():getGender(self.user:getGender())):setSystemFontSize(33):setTextColor(cc.c4b(255,255,255,255))

    local sign = self.user:getsignature()
    sign = sign == "" and "这家伙很懒,什么都没留下" or sign
    self.labelSign = cc.Label:create():addTo(self.panel,1):setPosition(74,164):setAnchorPoint(0,0.5)
    :setString("个性签名："..sign):setSystemFontSize(33):setTextColor(cc.c4b(255,255,255,255))
end

function PersonInfoLayer:updateView()
    self.labelTitle:setString("头  衔："..GameManager:getUserManager():getLevel(self.user:getScore()))
    self.labelGender:setString("性  别："..GameManager:getUserManager():getGender(self.user:getGender()))
    local sign = self.user:getsignature()
    sign = sign == "" and "这家伙很懒,什么都没留下" or sign
    self.labelSign:setString("个性签名："..sign)
end

function PersonInfoLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

function PersonInfoLayer:onApplyFriendBack(notify)
    if notify:getSize() ~= 0 then
        local cmd = GCMD_Sever_Friends.CMD_GR_S_RIEND_RESP:createWithNotify(notify)
        local function click()
            self:hide()
        end

        if cmd.dwStatus == 0 then
            GameManager:showAlertSystem(self,"申请好友成功，请等待好友响应！",click)
        else
            GameManager:showAlertSystem(self,cmd.szDesc,click)
        end
    end
    return true
end
--废弃
function PersonInfoLayer:addFriendCallBack(event)
    local notify = event._userData
    if notify:getSize() == 0 then
        GameManager:showAlert(self,"好友提示","添加失败")
    else
        local cmd = GCMD_Sever_Friends.CMD_MB_S_FriendRet:createWithNotify(notify)
        if cmd.nRet == 1 then
            local function click()
                self:hide()
            end

            GameManager:showAlert(self,"好友提示","添加成功",click)
            table.insert(GameManager:getUserSelf().friendsList,self.user)
            local friends = {}
            table.insert(friends,self.user)
            CFrameDataHandler:getInstance():dispatchEvent({name = "reFreshFriendList",_userData=friends})
        else
            GameManager:showAlert(self,"好友提示",cmd.szDescribe)
        end
    end
end

function PersonInfoLayer:onGetUserInfo(notify)
    local cmd = CMD_Server_Logon.CMD_MB_UserIndividual:createWithNotify(notify)
    self.user:setGender(cmd.cbGender)
    self.user:setMemberOrder(cmd.cbVipLevel)
    self.user:setUserID(cmd.dwUserID)
    self.user:setGameID(cmd.dwGameID)
    self.user:setWinCount(cmd.dwWinCount)
    self.user:setDrawCount(cmd.dwLostCount)
    self.user:setFleeCount(cmd.dwFleeCount)
    self.user:setScore(cmd.lUserScore)
    self.user:setNickName(cmd.szNickName)
    self.user:setsignature(cmd.szUnderWrite)
    self.user:setFaceURL(cmd.szFaceUrl)

    if self.user:getGameID() ~= GameManager:getUserSelf():getGameID() then
        self:setVisible(true)
        if cmd.cbRelation == 2 then
            self.which = 1
        else
            self.which = 2
        end
        self:show()
    end

    self:updateView()
    return true
end


function PersonInfoLayer:loadData(data)
    self.user:setScore(tonumber(data.Score))
    self.user:setWinCount(tonumber(data.WinCount))
    self.user:setLostCount(tonumber(data.LostCount))
    self.user:setFaceURL(data.faceurl)
    self.user:setMemberOrder(tonumber(data.VipLevel))
end

function PersonInfoLayer:shareResult(event)
    local map = event._userData
    local msg = map.errorMsg
    jt.SDKControl:getInstance():printInfo("shareResult:",msg)
    if map.stCode == 200 then
        self.isShareSuccessful = true
        local shareSuccessPlatform = map.platform
        --服务器定义 1：QQ，2：微信，3：新浪
        local serverPlatfrom = -1

        if shareSuccessPlatform == 4 then           -- 4:QQ空间,2:微信朋友圈，0：新浪微博
            serverPlatfrom = 1
        elseif shareSuccessPlatform == 2 then
            serverPlatfrom = 2
        elseif shareSuccessPlatform == 0 then
            serverPlatfrom = 3
        else
            GameManager:showAlertSystem(self,"分享到QQ空间、微信朋友圈、微博才可以获得奖励哦")
            return
        end
        GameManager:showAlertSystem(self,"分享成功！")
        self.isShareSuccessful = false
        CFrameDataHandler:getInstance():shareSuccess(serverPlatfrom)
    elseif msg ~= "" then
        GameManager:showAlertSystem(self,msg)
    end
end

--添加到黑名单
function PersonInfoLayer:addToBlackList()

    local function comfirm(result)
        if result == RT_SUCCESS then
            CFrameDataHandler:getInstance():sendPacketWithLoadAddToBlackList(self.user:getGameID())
        end
    end
    GameManager:showAlertSystem(self,"确定添加到黑名单？",comfirm):setBtnVisible(true,true)
end

function PersonInfoLayer:addToBlackListCallBack(notify)
    if notify:getSize() == 0 then
        GameManager:showAlertSystem(self,"黑名单添加失败")
    else
        local cmd = GCMD_Sever_Friends.CMD_MB_S_FriendRet:createWithNotify(notify)
        if cmd.nRet == 1 then
            local function click()
                self:hide()
            end
            GameManager:showAlertSystem(self,"黑名单添加成功",click)

--            GameManager:getFriendsBlackList()
            --GameManager:getFriendsList()
            table.insert(GameManager:getUserSelf().blackList,self.user)
            CFrameDataHandler:getInstance():dispatchEvent({name = "addToBlackListSuccesful",_userData=self.user})

        else
            GameManager:showAlertSystem(self,"黑名单添加失败")
        end
    end
    return true
end

function PersonInfoLayer:jugle(user)        --判断是那个用户  0： 是自己   1：  好友    2： 是其他玩家

    if user:getGameID() == GameManager:getUserSelf():getGameID() then
    	return 0
    end
    for k,friend_user in ipairs(GameManager:getUserSelf().friendsList) do
    	if friend_user:getGameID() == user:getGameID() then
    		return 1
    	end
    end
	return 2
end


function PersonInfoLayer:onCheckSpreader(event)
    local notify = event._userData
    local cmd = GCMD_Sever_Friends.CMD_S_CHECK_SPREADER_REQ:createWithNotify(notify)
    GameManager:showAlertSystem(self,"推广获得总游戏币为："..cmd.lPushScore)
end

function PersonInfoLayer:onDrawSpreader(event)
    local notify = event._userData
    local cmd = GCMD_Sever_Friends.CMD_S_DRAW_SPREADER_REQ:createWithNotify(notify)
end

function PersonInfoLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/person_info.plist","hall/person_info.png")
    CFrameDataHandler:getInstance():removeNotifyListener(self)
    SDKControlHandler:getInstance():removeSelectors(SDKControlHandler.RecipientsList.share)
end


return PersonInfoLayer
