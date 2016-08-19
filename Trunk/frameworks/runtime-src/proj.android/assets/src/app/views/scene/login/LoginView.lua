local LoginView = class("LoginView",cc.load("mvc").ViewBase)

local permissionLayer = import("app/views/layer/PermissionLayer.lua")
local BulletinBoardLayer = import("app/views/layer/BulletinBoardLayer.lua")

local scheduler = import("app/library/scheduler.lua")
local Timer = import("app/library/Timer.lua")

function LoginView:ctor(scene)
    self:enableNodeEvents()

    self.gameScene = scene

    --背景图
    self.bg = ens.CrippleSprite.new(nil)
    self.bg:init("bg_login.jpg",8)
    self.bg:addTo(self)
    self.bg:setPosition(display.cx,display.cy)
    self.bg:setScale(nf.bgScale)
    self.bg:scheduleUpdate(handler(self.bg, self.bg.update))
    self:setupBgTouchEvent()

    -- display.addSpriteFrames("hall.plist","hall.png")
    -- self.RoomEntryView = import("app/views/scene/hall/RoomEntryView.lua").new():addTo(self):setPosition(0,0)

    local btnsPosX = display.cx + 350 * nf.widthScale
    local btnsPosY = {display.cy + 140,display.cy,display.cy - 140}

    self.btnLogin1 = ccui.Button:create("btn_login1.png","btn_login1.png","btn_login1.png",0):addTo(self):setPosition(btnsPosX,display.cy)
    self.btnLogin1:addTouchEventListener(handler(self,self.onLoginClick))

    self.btnLogin2 = ccui.Button:create("btn_login2.png","btn_login2.png","btn_login2.png",0):addTo(self):setPosition(btnsPosX,display.cy - 140)
    self.btnLogin2:addTouchEventListener(handler(self,self.onLoginClick))

    self.btnLogin6 = ccui.Button:create("btn_login6.png","btn_login6.png","btn_login6.png",0):addTo(self):setPosition(btnsPosX,display.cy - 280)
    self.btnLogin6:addTouchEventListener(handler(self,self.onLoginClick))

    --事件层
    -- self.touchLayer = display.newLayer()
    --     :onTouch(handler(self, self.onTouch))
    --     :onClick(handler(self, self.onClick))
    --     :addTo(self)
    -- self.touchLayer:setLocalZOrder(-1)
end

function LoginView:onEnter()
    -- self:initServer()
    self:initLogo()
    self:updateButton()
end

function LoginView:setupBgTouchEvent()
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

function LoginView:initLogo()

    --显示对应渠道LOGO
    -- local isShowEffect = false
    -- local spr_logo = self.root:getChildByName("spr_logo")
    -- if device.platform == "ios" then
    --     local platform = jt.SDKControl:getInstance():getValueFromPlatform(8,"")
    --     if platform == 1 then
    --         spr_logo:setTexture("scene/login/logo_douniu.png")
    --     elseif platform == 2 then
    --         spr_logo:setTexture("scene/login/logo_niuniu.png")
    --     else
    --         --            self:guangEffect()
    --         isShowEffect = true
    --     end
    --     if platform >= 1 then
    --         spr_logo:setPositionX(spr_logo:getPositionX()-25)
    --     end
    -- elseif device.platform == "android" then
    --     --应用宝
    --     if jt.SDKControl:getInstance():getSDKPlatform() == 1 and jt.SDKControl:getInstance():getVersionCode() >= 20160629 then
    --         local packageName = jt.SDKControl:getInstance():getStringFromPlatform(0,"getPackageName")
    --         if  packageName:find("com.tencent.tmgp.niuox.aiwan") ~= nil then
    --             spr_logo:setTexture("scene/login/logo_niuniu.png")
    --         else
    --             isShowEffect = true
    --         end
    --     else
    --         isShowEffect = true
    --     end
    -- else
    --     isShowEffect = true
    -- end
end

function LoginView:initServer()

    --服务器选择(隐藏功能)
    --release版，禁用服务器选择功能
    -- if not jt.SDKControl:getInstance():isAppDebug() then return end
    --
    -- local function setProjectInfo(str)
    --     if str == "" then return end
    --     local s,e = string.find(str,":")
    --     if e ~= nil then
    --         local port = string.sub(str,s)
    --         GameManager:getProject().URLPort = port
    --     end
    --
    --     local ip = str
    --     if s ~= nil then
    --         ip = string.sub(str,1,s-1)
    --     end
    --     if string.len(ip) > 8 then
    --         GameManager:getProject().LoginAddress = ip
    --         local txt_server = self.root:getChildByName("panel_server"):getChildByName("txt_server")
    --         txt_server:setString("当前服务器：\n"..ip)
    --     end
    --     CFrameDataHandler:getInstance():initConfig()
    -- end

    -- self.clickCount = 0
    -- local listView = self.root:getChildByName("listview")
    --
    -- local function onTouchItem(item,eventType)
    --     if eventType == 2 then
    --         local str = item:getString()
    --         setProjectInfo(str)
    --         listView:getChildByName("item_input"):setString(str)
    --     end
    --     return true
    -- end
    --
    -- local itemCount = 4
    -- for i=1,itemCount do
    --     local item = listView:getChildByName("item_"..i)
    --     item:setTag(i)
    --     item:setTouchEnabled(true)
    --     item:addTouchEventListener(onTouchItem)--注册按钮事件
    -- end
    -- self.root:getChildByName("panel_server"):getChildByName("txt_server"):setString("当前服务器：\n"..GameManager:getProject().LoginAddress)
    --
    -- local function onTouchItem2(eventType)
    --     local str = listView:getChildByName("item_input"):getString()
    --     setProjectInfo(str)
    -- end
    -- local btn = listView:getChildByName("btn_ok"):addClickEventListener(onTouchItem2)
end

function LoginView:onLoginClick(ref, type)
    if type == 0 then --begin
         transition.scaleTo(ref, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(ref, {time = 0.05, scale = 1})

        local loginType = -1
        local enum = GameManager:getProject().LogonType_Enum

        if ref == self.btnLogin1 then
            loginType = enum.LogonType_Tourist
        elseif ref == self.btnLogin2 then
            loginType = enum.LogonType_QQ
        elseif ref == self.btnLogin6 then
            if self.btnLogin6.loginType ~= nil then
                loginType = self.btnLogin6.loginType
            else
                loginType = enum.LogonType_WeChat
            end
        end

        if loginType ~= -1 then
            self.gameScene:onLogin(loginType)
            return
        end
    elseif type == 3 then --cancle
        transition.scaleTo(ref, {time = 0.05, scale = 1})
    end
end

function LoginView:onClick(event)

    --公告
    if MotionUtil:checkPointToNode(self.root:getChildByName("img_gg"),event) then
        BulletinBoardLayer:create():addTo(self)
    end

    --许可
    if MotionUtil:checkPointToNode(self.root:getChildByName("img_xk"),event) then
--        permissionLayer:create(1):addTo(self)
        HundredResultBankerLayer:create(1):addTo(self)
        return
    end

    --服务器选择
    if jt.SDKControl:getInstance():isAppDebug() and MotionUtil:checkPointToNode(self.root:getChildByName("panel_server"),event) then
        self.clickCount = self.clickCount + 1
        if self.clickCount >= 5 then
            self.root:getChildByName("panel_server"):setOpacity(255)
            self.root:getChildByName("listview"):setVisible(true)
        end
    end
end


function LoginView:updateButton()
    local project = GameManager:getProject()
    local enum = project.LogonType_Enum
    local list =  jt.SDKControl.LogonBtn_List
    --    list[enum.LogonType_QQ+1] = false
    --    list[enum.LogonType_WeChat+1] = true
    --设置按钮可见性
    self.btnLogin6:setVisible(list[enum.LogonType_WeChat+1])
    self.btnLogin2:setVisible(list[enum.LogonType_QQ+1])
    self.btnLogin1:setVisible(list[enum.LogonType_Tourist+1])

    if device.platform == "android" then
        --动态更改按钮图标
        if not list[enum.LogonType_WeChat+1] then
            for i=1,table.maxn(list) do
                if list[i]~=nil and i ~= enum.LogonType_WeChat and i ~= enum.LogonType_Tourist and i ~= enum.LogonType_QQ and list[i] == true then
                    self.btnLogin6:loadTextureNormal("btn_login"..i..".png",0)
                    self.btnLogin6:loadTexturePressed("btn_login"..i..".png",0)
                    self.btnLogin6:loadTextureDisabled("btn_login"..i..".png",0)
                    self.btnLogin6:setVisible(true)
                    self.btnLogin6.loginType = i-1
                end
            end
        end
    end

    if device.platform == "ios" then
        local v = jt.SDKControl:getInstance():getValueFromPlatform(8,"") --获取渠道类型
        if v == 1 then
            local i = 100 + v
            self.btnLogin6:loadTextureNormal("btn_login"..i..".png",0)
            self.btnLogin6:loadTexturePressed("btn_login"..i..".png",0)
            self.btnLogin6:loadTextureDisabled("btn_login"..i..".png",0)
            self.btnLogin6:setVisible(true)
            self.btnLogin6.loginType = i
            self.btnLogin2:setVisible(false)
        end
    end

    local loginList = {self.btnLogin6,self.btnLogin2,self.btnLogin1}
    local showList = {}
    for i=1,#loginList do
        if loginList[i]:isVisible() then
            showList[#showList+1] = loginList[i]
        end
    end

    local x = showList[1]:getPositionX()
    local yList = {self.btnLogin2:getPositionY(),self.btnLogin6:getPositionY(),self.btnLogin1:getPositionY()}
    if #showList == 1 then
        showList[1]:move(cc.p(x,yList[2]))
    elseif #showList == 2 then
        showList[1]:move(cc.p(x,yList[2]))
        showList[2]:move(cc.p(x,yList[3]))
    elseif #showList == 3 then
    --        showList[1]:move(cc.p(x,yList[1]))
    --        showList[2]:move(cc.p(x,yList[2]))
    --        showList[3]:move(cc.p(x,yList[3]))
    end
end


function LoginView:onCleanup()

end

return LoginView
