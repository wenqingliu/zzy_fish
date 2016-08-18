local HallView = class("HallView",cc.load("mvc").ViewBase)

local Timer              = import("app/library/Timer.lua")
local LuaUtil            = import("app/library/LuaUtil")
local scheduler          = import("app/library/scheduler.lua")
local VIPLayer           = import("app/views/layer/VIPLayer.lua")
local RoomSelectLayer    = import("app/views/layer/RoomSelectLayer.lua")
local PersonInfoLayer    = import("app/views/layer/PersonInfoLayer.lua")
local SystemSettingLayer = import("app/views/layer/SystemSettingLayer.lua")
local ShopLayer          = import("app/views/layer/ShopLayer.lua")
local BankLayer          = import("app/views/layer/BankLayer.lua")
local RankLayer          = import("app/views/layer/RankLayer.lua")
local HornLayer          = import("app/views/layer/HornLayer.lua")
local PawnShopLayer      = import("app/views/layer/PawnShopLayer.lua")
local GameHelpLayer      = import("app/views/layer/GameHelpLayer.lua")
local FriendsLayer       = import("app/views/layer/FriendsLayer.lua")
local ActivityLayer      = import("app/views/layer/ActivityLayer.lua")
local MailLayer          = import("app/views/layer/MailLayer.lua")
local TaskLayer          = import("app/views/layer/TaskLayer.lua")
local StorageLayer       = import("app/views/layer/StorageLayer.lua")
local CMD_Server_Bank    = import("app/cmd/loginSever/CMD_Server_Bank.lua")
local GCMD_Sever_Friends = import("app/cmd/loginSever/CMD_Sever_Friends.lua")
local CMD_Server_Shop    = import("app/cmd/loginSever/CMD_Server_Shop.lua")
local HallTopBar         = import("app/views/scene/hall/HallTopBar.lua")
local RoomEntryView      = import("app/views/scene/hall/RoomEntryView.lua")

HallView.events = {
    getTishiFinish = "getTishiFinish",                                       --收到提示完成（好友，任务，邮件红点）
    ccNd_Hall_Info = "ccNd_Hall_Info"                                           --刚进入大厅的提示红点信息
}

function HallView:ctor(scene)
    self.gameScene = scene
    self:enableNodeEvents()
    self.roomManager = GameManager:getRoomServer()
    self.btnList = {}
    self.msgList = {}                   --喇叭列表
    self.IsHaveRunMsg = false           --是否有喇叭在跑
end

function HallView:onSpriteFrameLoad()
    self:initView()
    self:initServer()
    self:updateGameView()
    self:runQuickBtnAnimate()
end

function HallView:initView()
    --背景图
    self.bg = ens.CrippleSprite.new(nil)
    print(tolua.type(self.bg))
    self.bg:init("bg_hall.jpg",8)
    self.bg:addTo(self)
    self.bg:setPosition(display.cx,display.cy)
    self.bg:setScale(nf.bgScale)
    self.bg:scheduleUpdate(handler(self.bg, self.bg.update))
    self:setupBgTouchEvent()

    -- self.bg = display.newSprite("hall_bg.jpg"):addTo(self):setPosition(display.cx,display.cy):setScale(nf.bgScale)

    self.hallTopBar = HallTopBar.new():addTo(self):setPosition(140,display.top - 50)

    self.RoomEntryView = RoomEntryView.new():addTo(self):setPosition(0,0)

    -- 下排菜单按钮 活动，排行榜，好友，邮件，背包
    self.btnMenu = {}
    local btnMenuSrc = {"btn_activity.png","btn_rank.png","btn_task.png","btn_friend.png","btn_mail.png","btn_package.png"}
    for i = 1, 6 do
        local posX = 70 + 122*(i-1)
        self.btnMenu[i] = ccui.Button:create(btnMenuSrc[i],btnMenuSrc[i],btnMenuSrc[i],1)
        self.btnMenu[i]:addTo(self)
        self.btnMenu[i]:setPosition(posX,display.bottom + 68)
        self.btnMenu[i]:addTouchEventListener(handler(self,self.onBtnMenuClick))
    end

    -- 其他四个按钮 vip，商店，设置，喇叭
    self.btns = {}
    local btnsSrc = {"btn_vip.png","btn_shop.png","btn_setting.png","btn_speaker.png"}
    local btnsPosX = {68,68,display.right - 60, display.right - 60}
    local btnsPosY = {display.top - 140,display.top - 250,display.top - 64,display.top - 182}
    for i = 1 , 4 do
        self.btns[i] = ccui.Button:create(btnsSrc[i],btnsSrc[i],btnsSrc[i],1)
        self.btns[i]:addTo(self)
        self.btns[i]:setPosition(btnsPosX[i],btnsPosY[i])
        self.btns[i]:addTouchEventListener(handler(self,self.onBtnsClick))
    end

    --快速游戏
    self.btnQuickGame = ccui.Button:create("btn_quick_game_normal.png","btn_quick_game_pressed.png","btn_quick_game_pressed.png",1)
    self.btnQuickGame:addTo(self)
    self.btnQuickGame:setPosition(display.right - 128,display.bottom + 115)
    self.btnQuickGame:addTouchEventListener(handler(self,self.onBtnQuickGameClick))

    self.speakerBg = display.newSprite("#speaker_content_bg.png"):addTo(self):setPosition(display.cx,display.top - 118)

    local width,height = 690,45
    local stencil = display.newPolygon({
        {-width/2, -height/2},
        {-width/2,  height/2},
        {width/2,  height/2},
        {width/2, -height/2}
    })

    self.speakerNode = cc.ClippingNode:create()
    self.speakerNode:setPosition(390, 20)
    self.speakerNode:addTo(self.speakerBg)
    self.speakerNode:setInverted(false)      --设置底板可见
    self.speakerNode:setAlphaThreshold(1)   --设置绘制底板的Alpha值为0
    self.speakerNode:setStencil(stencil)

    display.newSprite("#icon_speaker.png"):addTo(self.speakerBg):setPosition(22,22)
end

function HallView:setupBgTouchEvent()
    local lis = cc.EventListenerTouchOneByOne:create()
    lis:registerScriptHandler(function (touch, event)
        local selectorPoint = touch:getLocation()
        self.bg:doTouch(selectorPoint, 512, 12)
        return true
        end,cc.Handler.EVENT_TOUCH_BEGAN )

    lis:registerScriptHandler(function (touch, event)
        local selectorPoint = touch:getLocation()
        self.bg:doTouch(selectorPoint, 512, 12)
        end, cc.Handler.EVENT_TOUCH_MOVED)

    lis:registerScriptHandler(function (touch, event)
        end, cc.Handler.EVENT_TOUCH_ENDED)

    local eventDispatcher = self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(lis, self.bg)
end

function HallView:onBtnMenuClick(ref, type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        for i = 1, 6 do
            if ref == self.btnMenu[i] then
                if i == 1 then  --活动
                    self.activity = ActivityLayer:create():addTo(self,1)
                elseif i == 2 then  --排行榜
                    RankLayer:create():addTo(self,1)
                elseif i == 3 then  --任务
                    TaskLayer:create():addTo(self,1)
                elseif i == 4 then  --好友
                    FriendsLayer:create():addTo(self,1)
                elseif i == 5 then  --邮件
                    MailLayer:create():addTo(self,1)
                elseif i == 6 then  --背包
                    StorageLayer:create():addTo(self,1)
                end
                break
            end
        end
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function HallView:onBtnsClick(ref, type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(ref, {time = 0.05, scale = 1})
        for i = 1, 6 do
            if ref == self.btns[i] then
                if i == 1 then --VIP
                    GameManager:showAlertSystem(self,"领取成功")
                    -- GameManager:showAlert(self,"1","22222222222222222")
                    -- local lighting = ens.ClightningBoltNode.new(nil)
                    -- print(tolua.type(lighting))
                    -- lighting:init("lightingSeg.png",cc.p(100,display.cy-100), cc.p(display.cx+100,display.cy+100))
                    -- lighting:addTo(self)
                    -- lighting:runFlashActionOnce()
                elseif i == 2 then --商店
                    ShopLayer:create(GameManager:getUserSelf()):addTo(self,1)
                elseif i == 3 then --设置
                    SystemSettingLayer:create():addTo(self,1)
                elseif i == 4 then --喇叭
                    HornLayer:create():addTo(self,1)
                end
                break
            end
        end
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function HallView:onBtnQuickGameClick(ref, type)
    if type == 0 then --begin
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        local roomList = GameManager:getRoomServer():getRoomList()
        local item =  GameManager:getRoomServer():getRoomByName(roomList[1]:szServerName())
        GameManager:getGameDelegate():loginRoom(item)
    elseif type == 3 then --cancle
    end
end

function HallView:initServer()
    --事件
    CFrameDataHandler:getInstance():addEventListener(self.events.getTishiFinish,handler(self,self.getTishiFinish))
    CFrameDataHandler:getInstance():addEventListener(self.events.ccNd_Hall_Info,handler(self,self.onEnterMsgInfo))
end


function HallView:onEnter()

end

function HallView:runQuickBtnAnimate()
    local circle = display.newCircle(80,{borderColor = cc.c4b(1,1,1,0)}):addTo(self.btnQuickGame):setPosition(197/2,206/2+10)
    local spEff1 = display.newSprite("#quick_game_eff1.png"):addTo(self.btnQuickGame,1):setPosition(197/2,206/2-5):setOpacity(0)
    local spEff2 = display.newSprite("#quick_game_eff2.png"):addTo(self.btnQuickGame,1):setPosition(197/2,206/2-5):setOpacity(0)
    local particleQbtn = cc.ParticleSystemQuad:create("particle/qbtn.plist")
    particleQbtn:setPosition(0,80)
    particleQbtn:addTo(circle)

    local actionRotate = cc.RotateBy:create(3,360)
    local actionRepeat = cc.RepeatForever:create(cc.Sequence:create(actionRotate,cc.DelayTime:create(0)))
    circle:runAction(actionRepeat)

    local callfunc1 = cc.CallFunc:create(function() spEff1:setScale(1) end)
    local callfunc2 = cc.CallFunc:create(function() spEff2:setScale(1) end)

    local actionSequence1 = cc.Sequence:create(cc.FadeIn:create(0.1),cc.FadeOut:create(3),callfunc1)
    local actionSequence2 = cc.Sequence:create(cc.FadeIn:create(0.1),cc.FadeOut:create(3),callfunc2)
    local actionSpawn1 = cc.Spawn:create(actionSequence1,cc.ScaleTo:create(3,1.6))
    local actionSpawn2 = cc.Spawn:create(actionSequence2,cc.ScaleTo:create(3,1.6))

    local actionRepeat1 = cc.RepeatForever:create(cc.Sequence:create(actionSpawn1,cc.DelayTime:create(1.2)))
    local actionRepeat2 = cc.RepeatForever:create(cc.Sequence:create(cc.DelayTime:create(1.2),actionSpawn2))

    spEff1:runAction(actionRepeat1)
    spEff2:runAction(actionRepeat2)
end



function HallView:createShakeAction(time_)
    local move_1 = cc.MoveBy:create(0.03,cc.p(8,0))
    local move_2 = move_1:reverse()
    local actions = {}
    for i = 1,time_ do
        table.insert(actions,move_1:clone())
        table.insert(actions,move_2:clone())
    end
    return cc.Sequence:create(actions)
end


function HallView:onTouch(event)
    BtnGroup:onTouchLayer(event,self.btnList)
--    self.rankLayer:onTouch(event)
    return true
end


---------
-- 重写更新视图
function HallView:updateGameView()
    local user = GameManager:getUserSelf()
    if user == nil then return end
    if self.hallTopBar == nil then return end
    self.hallTopBar:setUserName(user:getNickName())
    self.hallTopBar:setUserCoin(user:getScore())
    self.hallTopBar:setUserDiamond(user:getDiamond())

    if user:getFaceURL() ~= "" then
        self.hallTopBar:setUserHead(user,user:getFaceURL())
    end

    -- TODO
    -- --更新VIP等级显示
    -- if user:getMemberOrder() > 0 and user:getMemberOrder() <= 9 then
    --     self.spr_vip_num:setTexture("image/VIP_flag/vip_num_" .. user:getMemberOrder() ..".png")
    -- end
    --
    -- --商城
    -- if ShopLayer:getInstance() ~= nil then
    --     ShopLayer:getInstance():updateGameView()
    -- end

    return true
end

function HallView:onSubSystemMessage(szString,system,vipLevel)
    print("系统消息:",szString,system)
    local msg = {}
    msg.str = szString
    msg.isSys = system
    msg.vip = vipLevel
    table.insert(self.msgList,msg)
    if not self.IsHaveRunMsg and #self.msgList > 0 then
        self:msgRun(self.msgList[1])
    end
end

function HallView:msgRun(msg)
    self.IsHaveRunMsg = true
    table.remove(self.msgList,1)
    local systemWord_ = cc.Label:create():addTo(self.speakerNode)
    local labelWidth = systemWord_:getContentSize().width
    systemWord_:setString(msg.str)
    systemWord_:setSystemFontSize(30)
    -- systemWord_:setAnchorPoint(0,0)
    systemWord_:setPosition(labelWidth + 800,0)
    local move = cc.MoveTo:create((systemWord_:getPositionX() + labelWidth + 800)/200,cc.p(-labelWidth - 800,0))
    local function moveCall()
        systemWord_:removeFromParent()
        self.IsHaveRunMsg = false
        if #self.msgList > 0 then
            return self:msgRun(self.msgList[1])
        end
        print("remove")
    end
    systemWord_:runAction(cc.Sequence:create(move,cc.CallFunc:create(moveCall)))

    if msg.isSys then
        --系统消息:红色
        systemWord_:setTextColor(cc.c4b(207,60,41,255))
    else
        --喇叭消息:
        if msg.vip < 4 then
            systemWord_:setTextColor(cc.c4b(255,255,255,255))--白色
        elseif msg.vip== 4 or msg.vip== 5 or msg.vip== 6 then
            systemWord_:setTextColor(cc.c4b(170,183,178,255))--
        elseif msg.vip== 7 or msg.vip== 8 then
            systemWord_:setTextColor(cc.c4b(253,211,81,255))--
        elseif msg.vip== 9 then
            systemWord_:setTextColor(cc.c4b(221,121,225,255))--
        end
    end
end





-------------
-- 复活金响应
function HallView:onReliveGoldResponse(notify)
--    local notify = event._userData
    local cmd = CMD_Server_Bank.CMD_GR_S_ReliveGoldInfo:createWithNotify(notify)
    local visible = cmd.wReliveTimes > 0
    if cmd.wTypeReq == 1 then
        self.isRequestReliveGold = nil
        GameManager:showAlertSystem(self,"领取成功")
        GameManager:getUserSelf():setScore(cmd.lReliveScore)
        if GameManager:getGameDelegate() ~= nil then
            GameManager:getGameDelegate():updateGameView()
        end
    else
        if self.isRequestReliveGold then
            self.isRequestReliveGold = nil
            GameManager:showAlert(self,"复活金领取失败","保险柜尚有存款，请前往支取")
        else
            if cmd.wReliveTimes > 0 then
                local ds = {}
                ds.TrophyTitle = "复活金领取"
                ds.TrophyContent = "复活条件：总财富小于" .. cmd.lReliveScore .. "分，今天剩余" .. cmd.wReliveTimes .. "次复活机会"
                GameManager:showAlert(self,ds.TrophyTitle,ds.TrophyContent,function(result)
                    if result == RT_SUCCESS then
                        self.isRequestReliveGold = true
                        GameManager:ReceiveResurrection(1)      --领取复活金
                    end
                end):setBtnVisible(true,true)
            end
        end
    end
    return true
end

--好友发聊天
function HallView:getMessage(notify)
    local id = notify._userData[1]
    if ChatRecordPool:getInstance().IsInChatUserGameID ~= id and GameManager:getUserSelf():getGameID() ~= id then --正在聊天的不是发消息来的
        self.root:getChildByName("hall_bottom"):getChildByName("tishi_img"):setVisible(true)
    end
end

--好友发邮件
function HallView:getMail(notify)
    self.root:getChildByName("hall_bottom"):getChildByName("tishi_mail_img"):setVisible(true)
    return true
end

--好友上下线
function HallView:getFriendOnline(notify)
--    local notify = event._userData
    if notify:getSize() == 0 then
        printf("好友上下线数据错误")
    else
        local cmd = GCMD_Sever_Friends.CMD_MB_UserStatus:createWithNotify(notify)
        if GameManager.isFriendsListLayer then      --如果好友列表界面打开就在好友中出现上下线
            local data_ = {cmd.allUser[1].cbStatus,cmd.allUser[1].dwFriendGameID}
            CFrameDataHandler:getInstance():dispatchEvent({name = "friendOnlineFromHall",_userData=data_})
        end
        --大厅中提示上下线
        self:FriendOnlineshow(cmd.allUser[1].szNickName,cmd.allUser[1].dwVipLevel,cmd.allUser[1].cbStatus)
    end
    return true
end

function HallView:getInfo(notify)
--    local notify = event._userData
    if notify:getSize() ~= 0 then
        local cmd = CMD_Server_Mail.CMD_GR_S_SysInform:createWithNotify(notify)
        if cmd.info.wMsgType == 2 then     --添加好友
            --self.root:getChildByName("hall_bottom"):getChildByName("tishi_img"):setVisible(true)
        elseif cmd.info.wMsgType == 3 then     --邮件
            --self.root:getChildByName("hall_bottom"):getChildByName("tishi_img"):setVisible(true)
        end
    end
    return true
end

function HallView:onEnterMsgInfo(notify)
--    local notify = event._userData
    -- if notify:getSize() ~= 0 then
    --     local cmd = CMD_Server_Mail.CMD_GR_S_SysGameInform:createWithNotify(notify)
    --     for var=1, #cmd.wMsgType do
    --         if cmd.wMsgType[var] == 1 then
    --         elseif cmd.wMsgType[var] == 2 then
    --             self.root:getChildByName("hall_bottom"):getChildByName("tishi_img"):setVisible(true)
    --         elseif cmd.wMsgType[var] == 3 then
    --             self.root:getChildByName("hall_bottom"):getChildByName("tishi_mail_img"):setVisible(true)
    --         elseif cmd.wMsgType[var] == 4 then
    --             self.root:getChildByName("hall_bottom"):getChildByName("tishi_task"):setVisible(true)
    --         elseif cmd.wMsgType[var] == 5 then
    --             if GameManager.transferState ~= 0 then
    --                 self.root:getChildByName("hall_top"):getChildByName("tishi_more_activity"):setVisible(true)
    --                 self.root:getChildByName("hall_top"):getChildByName("spr_more_content"):getChildByName("tishi_spr_1"):setVisible(true)
    --             end
    --         end
    --     end
    -- end
    return true
end

--提示完成   红点消失
function HallView:getTishiFinish(event)
    -- local index = event._userData       ---index 1:好友    2：邮件   3：任务  4：龙珠
    -- if index == 1 then
    -- 	self.root:getChildByName("hall_bottom"):getChildByName("tishi_img"):setVisible(false)
    -- elseif index == 2 then
    --     self.root:getChildByName("hall_bottom"):getChildByName("tishi_mail_img"):setVisible(false)
    -- elseif index == 3 then
    --     self.root:getChildByName("hall_bottom"):getChildByName("tishi_task"):setVisible(false)
    -- elseif index == 4 then
    --     self.root:getChildByName("hall_top"):getChildByName("tishi_more_activity"):setVisible(false)
    --     self.root:getChildByName("hall_top"):getChildByName("spr_more_content"):getChildByName("tishi_spr_1"):setVisible(false)
    -- end
    return true
end


-------------
-- 显示活动
function HallView:onShowActivity()
    self.activity = ActivityLayer:create():addTo(self)
end

function HallView:onEnter()
    display.addSpriteFrames("common.plist","common.png")
    display.addSpriteFrames("hall/hall.plist","hall/hall.png")
    self:onSpriteFrameLoad()
end

function HallView:onCleanup()
    CFrameDataHandler:getInstance():removeEventListenerByList(self.events)
    if self.shopLightSchedule ~= nil then
        cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.shopLightSchedule)
        self.shopLightSchedule = nil
    end
    cc.AnimationCache:getInstance():removeAnimation("Hall_Feiqin_Ani")

    display.removeSpriteFramesWithFile("hall/hall.plist","hall/hall.png")
end

return HallView
