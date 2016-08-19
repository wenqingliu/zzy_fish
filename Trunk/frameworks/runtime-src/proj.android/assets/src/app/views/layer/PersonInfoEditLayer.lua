local BaseLayer           = import("app/views/layer/BaseLayer.lua")
local PersonInfoEditLayer = class("PersonInfoEditLayer",BaseLayer)
local CMD_Server_Logon    = import("app/cmd/loginSever/CMD_Server_Logon.lua")
local URLLoaderHandler    = import("app/handler/URLLoaderHandler.lua")
local SDKControlHandler   = import("app/handler/SDKControlHandler.lua")
local json                = import("app/library/cjson")

function PersonInfoEditLayer:ctor()
    self.super.ctor(self)

    display.addSpriteFrames("hall/person_info.plist","hall/person_info.png")
    display.addSpriteFrames("common.plist","common.png")

	self.user = user
    self.panel = display.newSprite("#bg_person.png"):addTo(self):setPosition(display.cx,display.cy)
    self:setRootBg(self.panel)
    local size = self.panel:getContentSize()
    self.btnClose = ccui.Button:create("btn_close.png","btn_close.png","btn_close.png",1):addTo(self.panel,1):setPosition(size.width - 20,size.height - 20)
    self.btnClose:addTouchEventListener(function(ref,type)
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
    display.newSprite("#label_data_modify.png"):addTo(self.panel):setPosition(462,534)

    self:setupView()

    self.targetGender = GENDER_FEMALE
-- --    self:show()
    CFrameDataHandler:getInstance():addNotifyListener(self)
end

function PersonInfoEditLayer:OnTCPWithDataLoad(notify)
    if notify:getMainType() == CMD_Server_Logon.MDM_GP_USER_SERVICE then --用户命令  3
        local sub = notify:getSubType()
        if sub == CMD_Server_Logon.SUB_GL_OPERATE_SUCCESS then
            return self:onOperateSuccess(notify)
        elseif sub == CMD_Server_Logon.SUB_GL_OPERATE_FAILURE then
            return self:onOperateFailure(notify)
        end
    end
    return false
end

function PersonInfoEditLayer:setupView()
    local user = GameManager:getUserSelf()

    self.head = display.newNode():addTo(self.panel):setPosition(144,390)
    if self.head.faceURL ~= user:getFaceURL() and user:getFaceURL() ~= "" then
        self.head = MotionUtil:RepleaceWithURLPic(self.head,user,cc.size(188,188),nil,true)
        self.head.faceURL = user:getFaceURL()
    end

    -- local editBg = display.newSprite("#person_editbox_bg.png"):addTo(self.panel,1):setPosition(144,378)
    self.editBg = ccui.Button:create("person_editbox_bg.png","person_editbox_bg.png","person_editbox_bg.png",1)
        :addTo(self.panel)
        :setPosition(144,378)
        :setTag(200)
        :addTouchEventListener(handler(self,self.onBtnsClick))
    cc.Label:create():addTo(self.panel,1):setPosition(144,378):setString("编辑"):setSystemFontSize(40):setTextColor(cc.c4b(255,255,255,255))

    self.btnConfirm = ccui.Button:create("btn_confirm_normal.png","btn_confirm_pressed.png","btn_confirm_pressed.png",1)
        :addTo(self.panel)
        :setPosition(684,69)
        :setTag(201)
        :addTouchEventListener(handler(self,self.onBtnsClick))

    self.btnCancel = ccui.Button:create("btn_cancel_normal.png","btn_cancel_pressed.png","btn_cancel_pressed.png",1)
        :addTo(self.panel)
        :setPosition(232,69)
        :setTag(202)
        :addTouchEventListener(handler(self,self.onBtnsClick))

    display.newScale9Sprite("bg_person_editbox.png",1,cc.size(404,63),cc.rect(31,31,2,2)):addTo(self.panel):setPosition(600,417)
    self.nameTextField = ccui.TextField:create():addTo(self.panel):setPosition(600,417)
    self.nameTextField:setTouchEnabled(true)
    self.nameTextField:setString(user:getNickName())
    self.nameTextField:setFontSize(40)

    cc.Label:create():addTo(self.panel):setPosition(283,420):setAnchorPoint(0,0.5):setString("昵称："):setSystemFontSize(45):setTextColor(cc.c4b(255,255,255,255))
    cc.Label:create():addTo(self.panel):setPosition(283,330):setAnchorPoint(0,0.5):setString("性别："):setSystemFontSize(45):setTextColor(cc.c4b(255,255,255,255))

    self.btnSelectMale = ccui.Button:create("bg_person_editbox.png","bg_person_editbox.png","bg_person_editbox.png",1)
        :addTo(self.panel)
        :setPosition(480,330)
        :setTag(203)
        :addTouchEventListener(handler(self,self.onBtnsClick))

    self.btnSelectFemale = ccui.Button:create("bg_person_editbox.png","bg_person_editbox.png","bg_person_editbox.png",1)
        :addTo(self.panel)
        :setPosition(690,330)
        :setTag(204)
        :addTouchEventListener(handler(self,self.onBtnsClick))

    cc.Label:create():addTo(self.panel):setPosition(530,330):setAnchorPoint(0,0.5):setString("男"):setSystemFontSize(45):setTextColor(cc.c4b(255,255,255,255))
    cc.Label:create():addTo(self.panel):setPosition(745,330):setAnchorPoint(0,0.5):setString("女"):setSystemFontSize(45):setTextColor(cc.c4b(255,255,255,255))

    self.genderCheckSP = display.newSprite("#checked_icon.png"):addTo(self.panel):setPosition(690,330)
    self.selectGender = 0
    if user:getGender() == 1 then
        self.selectGender = 1
        self.genderCheckSP:setPosition(480,330)
    end

    cc.Label:create():addTo(self.panel):setPosition(60,235):setAnchorPoint(0,0.5):setString("个人签名："):setSystemFontSize(45):setTextColor(cc.c4b(255,255,255,255))

    display.newScale9Sprite("bg_person_editbox.png",1,cc.size(588,142),cc.rect(31,31,2,2)):addTo(self.panel):setPosition(575,206)
    local sign = user:getsignature()
    local strSign = sign == "" and "这家伙很懒,什么都没留下" or sign
    self.signTextField = ccui.TextField:create():addTo(self.panel):setPosition(575,206)
    -- self.signTextField:setTouchEnabled(true)
    self.signTextField:setString(strSign)
    self.signTextField:setTouchSize(cc.size(560,130))
    self.signTextField:setFontSize(50)
    self.signTextField:setTextColor(cc.c4b(6,36,60,255))
    self.signTextField:addEventListener(handler(self,self.onTextFieldEvent))

    self.signLabel = cc.Label:create():addTo(self.panel):setPosition(575,176):setAnchorPoint(0.5,0.5):setString(strSign)
    :setSystemFontSize(45):setTextColor(cc.c4b(255,255,255,255)):setDimensions(560,150)

end

function PersonInfoEditLayer:onBtnsClick(ref,type)
    if type == 0 then --begin
    elseif type == 1 then --moved
    elseif type == 2 then --release
        if ref:getTag() == 201 then
            self:onCommit()
        elseif  ref:getTag() == 202 then
            self:hide()
        elseif  ref:getTag() == 203 then
            self.selectGender = 1
            self.genderCheckSP:setPosition(480,330)
        elseif  ref:getTag() == 204 then
            self.selectGender = 0
            self.genderCheckSP:setPosition(690,330)
        elseif  ref:getTag() == 200 then
            self:onloadHead()
        end
    elseif type == 3 then --cancle
    end
end

function PersonInfoEditLayer:onTextFieldEvent(sender, eventType)
    if eventType == 0 then--ccui.TextFiledEventType.attach_with_ime
        print("attach with IME")
    elseif eventType == 1 then--ccui.TextFiledEventType.detach_with_ime
        print("detach with IME")
    elseif eventType == 2 then--ccui.TextFiledEventType.insert_text
        print("insert words")
    elseif eventType == 3 then--ccui.TextFiledEventType.delete_backward
        print("delete word")
    end
    self.signLabel:setString(self.signTextField:getString())
end

--提交更新资料
function PersonInfoEditLayer:onCommit()
    local user = GameManager:getUserSelf()
    local isChange = false
    if self.nameTextField:getString() ~= user:getNickName() then
        isChange = true
    elseif self.selectGender ~= user:getGender() then
        isChange = true
    elseif  self.signLabel:getString() ~= GameManager:getUserSelf():getsignature() then
        isChange = true
    end

    if isChange then
        --资料被修改，进行提交
--        GameManager:showLoading(self)
--        jt.CFrameData:getInstance():sendPacketWithModifyIndividual(
--            self.tf_nickname:getString(),self.targetGender,user:getUserID(),"",false)
            self:sendPacketWithModifyIndividual()
    else
        GameManager:showAlertSystem(self,"资料未进行修改，提交失败")
    end
end

function PersonInfoEditLayer:sendPacketWithModifyIndividual()
    GameManager:showLoading(self)
    local cmd = CMD_Server_Logon.CMD_GP_ModifyIndividual:create()
    cmd.cbGender = self.selectGender
    cmd.dwUserID = GameManager:getUserSelf():getUserID()
    cmd.szPassword = ""
    cmd.nickString = self.nameTextField:getString()
    cmd.szUnderWrite = self.signLabel:getString()
    local pFrameData = jt.CFrameData:createFrameData()
    pFrameData:doConnect()
    pFrameData:sendPacketWithCompilatio()
    pFrameData:sendSocketData(CFrameDataHandler:getInstance():createTCPBuffer(CMD_Server_Logon.MDM_GP_USER_SERVICE,303,cmd))
end

function PersonInfoEditLayer:onOperateSuccess(notify)
--    local notify = event._userData
    GameManager:hideLoading()
    local cmd = CMD_Server_Logon.CMD_GP_OperateSuccess:createWithNotify(notify)
    GameManager:showAlertSystem(self,cmd.szDescribeString)
    GameManager:getUserSelf():setNickName(self.tf_nickname:getString())
    GameManager:getUserSelf():setGender(self.targetGender)
    GameManager:getUserSelf():setsignature(self.txt_underwrite:getString())
    --更新游戏大厅
    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():updateGameView()
    end
    return true
end

function PersonInfoEditLayer:onOperateFailure(notify)
    --    local notify = event._userData
    GameManager:hideLoading()
    local cmd = CMD_Server_Logon.CMD_GP_OperateFailure:createWithNotify(notify)
    GameManager:showAlertSystem(self,cmd.szDescribeString)
    return true
end

function PersonInfoEditLayer:onTouch(event)
    BtnGroup:onTouchLayer(event,self.btnList)
    self.super.onTouch(self,event)

    return true
end

function PersonInfoEditLayer:onloadHead()
    if jt.SDKControl:getInstance().getSDKPlatform == nil then
        GameManager:showAlertSystem(self,"该功能暂未开放，尽请期待")
        return
    end

    local map = {}
    map.userID = GameManager:getUserSelf():getUserID()
    map.domainURL = "http://" .. GameManager:getProject().LoginAddress ..GameManager:getProject().URLPort
    SDKControlHandler:getInstance():sendMessage("CCUploadHead",map)

    if self.sdk ~= nil then
        return
    end
    local handle1,tag1
    self.sdk = jt.SDKControl:getInstance()
    handle1,tag1 = SDKControlHandler:getInstance():addSelector(self.sdk,SDKControlHandler.RecipientsList.ccNd_Notify,function(event)
        SDKControlHandler:getInstance():removeEventListener(tag1)
        self.sdk:removeSelectors(SDKControlHandler.RecipientsList.ccNd_Notify)
        self.sdk:removeFromParent()
        self.sdk = nil
        local map = event._userData
        if map.result == 1 then
            GameManager:getUserSelf():setFaceURL(map.url)
            self.img_userHead = MotionUtil:RepleaceWithURLPic(self.img_userHead,GameManager:getUserSelf(),cc.size(160,160),nil,true)
            --更新游戏大厅
            if GameManager:getGameDelegate() ~= nil then
                GameManager:getGameDelegate():updateGameView()
            end
        end
    end)
    self.sdk.tag = tag1
end

function PersonInfoEditLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/person_info.plist","hall/person_info.png")
    URLLoaderHandler:destroyInstance()
    CFrameDataHandler:getInstance():removeNotifyListener(self)
    if self.sdk ~= nil then
        SDKControlHandler:getInstance():removeEventListener(self.sdk.tag)
        self.sdk:removeSelectors(SDKControlHandler.RecipientsList.ccNd_Notify)
    end
end

return PersonInfoEditLayer
