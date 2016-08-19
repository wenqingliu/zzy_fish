-----
--新年抽奖层
--喇叭层
local BaseLayer = import("app/views/layer/BaseLayer.lua")
local NewYearDrawLayer = class("NewYearDrawLayer",BaseLayer)
local CMD_Server_NewYear = import("app/cmd/loginSever/CMD_Server_NewYear.lua")

NewYearDrawLayer.events = {
    ccNd_NewYearDraw_INFO = "ccNd_NewYearDraw_INFO",            --抽奖信息
    ccNd_NewYearDraw_Data = "ccNd_NewYearDraw_Data"             --抽奖开始返回
}

NewYearDrawLayer.rewardList = {
    "谢谢参与",
    "50万金币",
    "5个喇叭",
    "10万金币",
    "100个钻石",
    "5万金币",
    "2个喇叭",
    "50个钻石",
}
function NewYearDrawLayer:ctor()
    self.super.ctor(self)


    self:initData()
    self:initView()
end

function NewYearDrawLayer:initView()
    self.root = Resources:createNodeAndDoLayout("layer/newyearDraw/layer_newyear.csb"):addTo(self)
    self.panel = self.root:getChildByName("Panel_1")
    self.RotateNode = self.panel:getChildByName("rotate_node")

    local bg = self.panel:getChildByName("spr_bg")
    self:setRootBg(bg)  
    
    self.btnList = {}
    self.btnList[#self.btnList + 1] = self.panel:getChildByName("close_btn")
    self.btnList[#self.btnList + 1] = self.panel:getChildByName("go_btn")
    
    self.playTimes_txt = self.panel:getChildByName("playNum_txt")
    self.drawTimes_txt = self.panel:getChildByName("drawNum_txt")
    
    self.playTimes_txt_word = self.panel:getChildByName("Text_4")
    
    self.txt_2 = self.panel:getChildByName("txt_2")
    
    self.lights = {}        --灯
    local lightNode = self.panel:getChildByName("lightNode")
    for i=1, 16 do
        table.insert(self.lights,lightNode:getChildByName("light_"..i))
    end
    self.m_isRotating = false       --是否正在旋转
    self:show()
end

function NewYearDrawLayer:initData()
	self.light_schedule = nil
	self.lightTime = 0
	self.playTimes = 0      --游戏次数
	self.drwaTimes = 0      --剩余抽奖次数
	
	self.maxPlay = 20
	math.randomseed(os.time())
    CFrameDataHandler:getInstance():addEventListener(NewYearDrawLayer.events.ccNd_NewYearDraw_INFO,handler(self,self.onGetData))
    CFrameDataHandler:getInstance():addEventListener(NewYearDrawLayer.events.ccNd_NewYearDraw_Data,handler(self,self.onStart))
    
    CFrameDataHandler:getInstance():SendSocketData(CMD_Server_NewYear.MDM_GR_QUERY,CMD_Server_NewYear.SUB_GF_LOTTERY_REQUEST,nil)
end

function NewYearDrawLayer:onTouch(event)
    BtnGroup:onTouchLayer(event,self.btnList)
    self.super.onTouch(self,event)
    if event.name ~= "ended" then return true end
    
    return true
end

function NewYearDrawLayer:onClick(event)
    if MotionUtil:checkPointToNode(self.panel:getChildByName("close_btn"),event) then
        self:hide()
    elseif MotionUtil:checkPointToNode(self.panel:getChildByName("go_btn"),event) then
        if not self.m_isRotating then
            if self.drwaTimes > 0 then
                self:go()
            else
                GameManager:showAlertSystem(self,"剩余抽奖次数不足")
            end

        end
    end
    return true
end
--点击开始（请求数据）
function NewYearDrawLayer:go()
--    local cmd = CMD_Server_NewYear.CMD_MB_C_UserLottery:create()
--    cmd.dwUserID = GameManager:getUserSelf():getUserID()
--    cmd.dwPlayerID = GameManager:getUserSelf():getGameID()
    CFrameDataHandler:getInstance():SendSocketData(CMD_Server_NewYear.MDM_GR_QUERY,CMD_Server_NewYear.SUB_MB_USER_LOTTERY,nil)
end

--转盘开始
function NewYearDrawLayer:start(endIndex)
    local function reset(node)
        local n = math.floor(self.RotateNode:getRotationSkewX()/360)*360
        self.RotateNode:setRotationSkewX(self.RotateNode:getRotationSkewX() - n)
    	if self.light_schedule then
            cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.light_schedule)
            self.light_schedule = nil
        end
        for i=1, 16 do
            self.lights[i]:setVisible(false)
        end
        self:showRewardEffect(endIndex)
    end
    self.m_isRotating = true
    local ran = math.random(5,40)
    local roX = 720 - (self.RotateNode:getRotationSkewX() + 45*(endIndex - 1)) - ran
    local endRotation = cc.EaseSineOut:create(cc.RotateBy:create(roX/360,roX))
    self.RotateNode:runAction(cc.Sequence:create(cc.Repeat:create(cc.RotateBy:create(0.6,360),4),endRotation,cc.CallFunc:create(reset)))
    self.light_schedule = cc.Director:getInstance():getScheduler():scheduleScriptFunc(handler(self,self.lightEffect),0.3,false)
end

function NewYearDrawLayer:showRewardEffect(endIndex)
    local effNode = self.RotateNode:getChildByName("effectNode")
    effNode:setRotation(45*(endIndex - 1))
    local spr_2 = cc.Sprite:createWithSpriteFrameName("layer_newyearDraw/choose.png"):addTo(effNode):setPosition(49.5,123):setRotation(25)
    spr_2:setOpacity(0)
    local spr_1 = cc.ProgressTimer:create(cc.Sprite:createWithSpriteFrameName("layer_newyearDraw/choose_1.png")):addTo(effNode)
    spr_1:setPosition(55,124):setRotation(25)
    spr_1:setType(1)
    spr_1:setMidpoint(cc.p(0.5, 0))
    spr_1:setBarChangeRate(cc.p(0, 1))
    spr_1:setPercentage(0)
    local call_1 = cc.CallFunc:create(function() spr_2:runAction(cc.Sequence:create(cc.FadeIn:create(0.3),cc.DelayTime:create(0.2),cc.FadeOut:create(0.3))) end)
    local call_2 = cc.CallFunc:create(function() 
        effNode:removeAllChildren() 
        self:showReward(endIndex)
        self.m_isRotating = false
    end)
    spr_1:runAction(cc.Sequence:create(cc.ProgressTo:create(0.3,100),call_1,cc.DelayTime:create(0.8),call_2))
    
    
end

--显示中奖奖品
function NewYearDrawLayer:showReward(endIndex)
    local node = cc.Node:create()
    local txt = cc.Label:createWithSystemFont("","",40):addTo(node):setAnchorPoint(0,0.5):setPositionX(20):setColor(cc.c3b(255,255,0))
    local spr = nil
    if endIndex == 2 then
        spr = cc.Sprite:createWithSpriteFrameName("layer_newyearDraw/50W.png")
        txt:setString("X 50万")
    elseif endIndex == 3 then
        spr = cc.Sprite:create("image/lbxiao.png")
        txt:setString("X 5个")
    elseif endIndex == 4 then
        spr = cc.Sprite:createWithSpriteFrameName("layer_newyearDraw/10W.png")
        txt:setString("X 10万")
    elseif endIndex == 5 then
        spr = cc.Sprite:createWithSpriteFrameName("layer_newyearDraw/diamond_1.png")
        txt:setString("X 100个")
    elseif endIndex == 6 then
        spr = cc.Sprite:createWithSpriteFrameName("layer_newyearDraw/5W.png")
        txt:setString("X 5万")
    elseif endIndex == 7 then
        spr = cc.Sprite:create("image/lbxiao.png")
        txt:setString("X 2个")
    elseif endIndex == 8 then
        spr = cc.Sprite:createWithSpriteFrameName("layer_newyearDraw/diamond_2.png")
        txt:setString("X 50个")
    else
        spr = cc.Sprite:createWithSpriteFrameName("layer_newyearDraw/thanks.png")
    end
    spr:addTo(node)
    if endIndex >= 2 and endIndex <= 8 then
        spr:setPositionX(-100)
        spr:setScale(1.5)
    end
	GameManager:showAlert(self,"中奖提示",""):addNodeContent(node)
    --更新游戏大厅
    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():updateGameView()
    end
end

--更新视图
function NewYearDrawLayer:refreshView()
    self.playTimes_txt_word:setVisible(true)
    self.playTimes_txt:setVisible(true)
    self.playTimes_txt:setString(self.playTimes)
    self.drawTimes_txt:setString(self.drwaTimes)
    if self.playTimes >= self.maxPlay then
    	self.playTimes_txt_word:setVisible(false)
        self.playTimes_txt:setVisible(false)
    end
--    if self.drwaTimes <= 0 then
--        self.panel:getChildByName("go_btn"):setColor(BtnGroup.COLOR_DOWN)
--    end
end

--刚进去获取数据
function NewYearDrawLayer:onGetData(event)
    local notify = event._userData
    if notify:getSize() ~= 0 then
        local cmd = CMD_Server_NewYear.CMD_GR_S_LottreyRequest:createWithNotify(notify)
        local str = string.format("2.游戏中任意完成游戏%d局、%d局、%d局可各获得一次抽奖机会。",cmd.info.nValue1,cmd.info.nValue2,cmd.info.nValue3)  
        self.maxPlay = cmd.info.nValue3
        self.txt_2:setString(str)
        self.playTimes = cmd.info.nGameCount
        self.drwaTimes = cmd.info.nLotteryCount - cmd.info.nDrawCount
        if self.drwaTimes < 0 then
        	self.drwaTimes = 0
        end 
        self:refreshView()
    end
end

--转盘开始获取数据
function NewYearDrawLayer:onStart(event)
    local notify = event._userData
    if notify:getSize() ~= 0 then
        self.drwaTimes = self.drwaTimes - 1
        if self.drwaTimes < 0 then
            self.drwaTimes = 0
        end 
        self:refreshView()
        local cmd = CMD_Server_NewYear.CMD_MB_S_UserLottery:createWithNotify(notify)
        self:start(cmd.info.ItemType)
        if cmd.info.ItemType == 2 or cmd.info.ItemType == 4 or cmd.info.ItemType == 6 then
            GameManager:getUserSelf():setScore(GameManager:getUserSelf():getScore() + cmd.info.nGiftCount)
        elseif cmd.info.ItemType == 5 or cmd.info.ItemType == 8 then
            GameManager:getUserSelf():setDiamond(GameManager:getUserSelf():getDiamond() + cmd.info.nGiftCount)
        end
        
    end
end

--灯光效果
function NewYearDrawLayer:lightEffect()
    self.lightTime = self.lightTime  + 1 
    for i=1, 16 do
        if math.fmod(self.lightTime,2)  == 0 then
            if math.fmod(i,2) == 0 then
                self.lights[i]:setVisible(false)
            else
                self.lights[i]:setVisible(true)
            end
        else
            if math.fmod(i,2) == 0 then
                self.lights[i]:setVisible(true)
            else
                self.lights[i]:setVisible(false)
            end
        end
    end
end

function NewYearDrawLayer:onCleanup()
    if self.light_schedule then
        cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self.light_schedule)
    end
    CFrameDataHandler:getInstance():removeEventListenerByList(self.events) 
end

return NewYearDrawLayer