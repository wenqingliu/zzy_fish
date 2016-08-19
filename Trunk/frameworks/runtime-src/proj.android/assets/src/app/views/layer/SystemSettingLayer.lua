local BaseLayer = import("app/views/layer/BaseLayer.lua")
local SystemSettingLayer = class("SystemSettingLayer",BaseLayer)
local SDKControlHandler = import("app/handler/SDKControlHandler.lua")

function SystemSettingLayer:ctor()
    self.super.ctor(self)

    display.addSpriteFrames("hall/setting.plist","hall/setting.png")
    display.addSpriteFrames("common.plist","common.png")

    self:setupView()
    self:show()
end

function SystemSettingLayer:setupView()
    self.panel = display.newSprite("#setting_bg.png"):addTo(self):setPosition(display.cx,display.cy - 10)
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

    --name
    cc.Label:create():addTo(self.panel):setPosition(72,440):setString(GameManager:getUserSelf():getNickName()):setSystemFontSize(45):setAnchorPoint(0,0.5)

    self.logoutBtn = ccui.Button:create("btn_logout_normal.png","btn_logout_pressed.png","btn_logout_pressed.png",1):addTo(self.panel,1):setPosition(840,440)
    self.logoutBtn:addTouchEventListener(function(ref,type)
                                            if type == 0 then --begin
                                            elseif type == 1 then --moved
                                            elseif type == 2 then --release
                                                audio.playSound("music/click")
                                                local map = {}
                                                map.loginType = GameManager.accountType
                                                SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCGameLogout,map)
                                                jt.CFrameData:getInstance():setSocketClose(true)
                                                GameManager.isOnline = false
                                                GameManager:getUserManager():removeUserItemAll()
                                                GameManager:getRoomServer():stop()
                                                GameManager:getRoomServer():clearRoomList()
                                                GameManager:getGameDelegate():removeAllChildren()
                                                Resources:removeUnusedAllRes()
                                                GameManager:getGameDelegate():getApp():enterScene("scene/LoginScene")
                                            elseif type == 3 then --cancle
                                            end
                                        end)

    cc.Label:create():addTo(self.panel):setPosition(72,287):setString("音乐"):setSystemFontSize(45):setTextColor(cc.c4b(194,214,255,255)):setAnchorPoint(0,0.5)
    cc.Label:create():addTo(self.panel):setPosition(72,185):setString("音效"):setSystemFontSize(45):setTextColor(cc.c4b(194,214,255,255)):setAnchorPoint(0,0.5)
    cc.Label:create():addTo(self.panel):setPosition(72,86):setString("版本信息"):setSystemFontSize(45):setTextColor(cc.c4b(194,214,255,255)):setAnchorPoint(0,0.5)
    local version = jt.SDKControl:getInstance():getVersion()
    if version == "" then
        version = "1.0"
    end
    cc.Label:create():addTo(self.panel):setPosition(755,86):setString(version):setSystemFontSize(45):setTextColor(cc.c4b(194,214,255,255)):setAnchorPoint(0,0.5)

    local sliderMusic = ccui.Slider:create():addTo(self.panel,1)
    sliderMusic:loadBarTexture("setting_slider_track.png",1)
    sliderMusic:loadSlidBallTextures("setting_slide_thumbr.png", "setting_slide_thumbr.png", "setting_slide_thumbr.png",1)
    sliderMusic:loadProgressBarTexture("setting_slider_progress.png",1)
    sliderMusic:setPercent(audio.getMusicVolume() * 100)
    sliderMusic:setPosition(626,287)
    sliderMusic:addEventListener(handler(self,self.onSlideHandler))

    local sliderSound = ccui.Slider:create():addTo(self.panel)
    sliderSound:loadBarTexture("setting_slider_track.png",1)
    sliderSound:loadSlidBallTextures("setting_slide_thumbr.png", "setting_slide_thumbr.png", "setting_slide_thumbr.png",1)
    sliderSound:loadProgressBarTexture("setting_slider_progress.png",1)
    sliderSound:setPercent(audio.getSoundsVolume() * 100)
    sliderSound:setPosition(626,185)
    sliderSound:addEventListener(handler(self,self.onSlideHandler))
end

function SystemSettingLayer:setEnableLogout(bool)
    self.logoutBtn:setVisible(bool)
end

function SystemSettingLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

-------------------
-- @param self
-- @param #ccui.Slider node
function SystemSettingLayer:onSlideHandler(node)
    --WIN32下无法设置音量
    local percent = node:getPercent() / 100
    if node == self.slider_bgmusic then
        audio.setMusicVolume(percent)
    else
    if  node == self.slider_sound then
        audio.setSoundsVolume(percent)
    end
    end
end

function SystemSettingLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/setting.plist","hall/setting.png")
    cc.UserDefault:getInstance():setFloatForKey("MUSIC_VOLUME",audio.getMusicVolume())
    cc.UserDefault:getInstance():setFloatForKey("SOUND_VOLUME",audio.getSoundsVolume())
    cc.UserDefault:getInstance():flush()
end
return SystemSettingLayer
