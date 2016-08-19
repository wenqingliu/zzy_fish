local BaseLayer = import("app/views/layer/BaseLayer.lua")
local GameHelpLayer = class("GameHelpLayer",BaseLayer)
GameHelpLayer.info = {}
local info_hall = {}
info_hall.word = {"欢迎您进入皇家游戏，我是您的游戏顾问，我叫牛妞！",
                      "现在我就为您讲解下，皇家游戏的趣味之处吧！",
                      "皇家游戏是由个人中心、排行榜、游戏中心、及功能按钮4个部分组成哦。",
                      "亲！可根据自己的需求，来满足游戏中的各种需求哦！"}
info_hall.sound = { "hall/01",
                        "hall/02",
                        "hall/04",
                        "hall/03",}
info_hall.pic = {nil,nil,"dating.png","dating.png"}

local info_hundred = {}
info_hundred.word = {"百人大战有两种玩法哦，富豪和欢乐。",
    "游戏自动发牌，自动结算，您只需要下注就行了。欢乐最高8倍，而富豪最高10倍，更加刺激哦。",
    "您也可以选择点击申请上庄，对决其他玩家呢。"}
    
info_hundred.sound = {  "hundredGame/05",
                        "hundredGame/06",
                        "hundredGame/07",}
    
info_hundred.pic = {nil,"bairen.png","bairen.png"}

local info_kanpai = {}
info_kanpai.word = {"亲，看牌抢庄是现在热门的牛牛玩法。可以先看手牌，再选择倍数，决定要不要抢庄呢！",
                    "让我们组合牛牛牌型，与其他玩家一决胜负吧！"}

info_kanpai.sound = { "kanpai/08",
    "kanpai/09",}

info_kanpai.pic = {"kanpai.jpg","kanpai.jpg"}

local info_gongpo = {}
info_gongpo.word = {"功夫场?公婆大战?真是有意思呢！",
    "公赢？婆赢？还是平局？快来体验看看吧！",
    "还支持玩家上庄哦，有条件自信就坐庄试试吧！"}

info_gongpo.sound = { "gongpo/012",
    "gongpo/013",
    "gongpo/014"}

info_gongpo.pic = {"gongpo.jpg","gongpo.jpg","gongpo.jpg"}

local info_slotMachine = {}
info_slotMachine.word = {"哎呀呀，好熟悉的音乐，这个就是传说中的水果机了。大三元，大四喜，大火车，双天至尊…，真是惊喜啊！",
    "亲，下注后点击开始即可，操作真是简单，还支持赌大小哦。"}

info_slotMachine.sound = { "slotMachine/015",
    "slotMachine/016"}

info_slotMachine.pic = {"shuiguoji.png","shuiguoji.png"}

local info_yyl = {}
info_yyl.word = {"亲，传统游戏摇摇乐哦，买定离手，超大赔率！",
                "可以买大小，赌点数，选单骰，压豹子，玩法应有尽有！而且结算可以查看中奖选项和奖金排行哦。"}

info_yyl.sound = { "yyl/010",
                    "yyl/011"}

info_yyl.pic = {"yyl.jpg","yyl1.jpg"}

local info_feiqin = {}
info_feiqin.word = {"飞禽走兽，这风靡一时的街机玩法呢！",
    "可以选择飞禽或走兽，选择单个动物赔率更高哦！打中蓝鲨送灯，金鲨送彩金大奖呢，还有机会庄家通赔哦。",
    "亲，倍率是种族2倍，动物6-12倍，蓝鲨24倍，金鲨100倍呢？结算界面可以查看本局的详细情况哦，还支持玩家上庄呢！"}

info_feiqin.sound = { "feiqin/017",
    "feiqin/018",
    "feiqin/019"}

info_feiqin.pic = {"feiqin.png","feiqin.png","feiqin1.jpg"}

GameHelpLayer.info["hall"] = info_hall
GameHelpLayer.info["hundred"] = info_hundred
GameHelpLayer.info["kanpai"] = info_kanpai
GameHelpLayer.info["gongpo"] = info_gongpo
GameHelpLayer.info["slotMachine"] = info_slotMachine
GameHelpLayer.info["yyl"] = info_yyl
GameHelpLayer.info["feiqin"] = info_feiqin

function GameHelpLayer:ctor(scene_name,parentScene,item,params)
    GameHelpLayer.super.ctor(self)
    local function endfindSceneData()
        for k,v in pairs(GameHelpLayer.info) do
            if k == scene_name then
                self.data = v
                self.userDefualtKey = k
                return true
            end
        end
        return false
    end
    if not endfindSceneData() then
    	self:hide()
    end
    self.hallScene = parentScene
    self.hallScene_item = item
    self.hallScene_params = params
    
    self.girl_spr = cc.Sprite:create("layer/layer_game_help/niumei.png"):addTo(self):setAnchorPoint(0.5,0):setPosition(180,0):setLocalZOrder(2)
    self.word_kuang = cc.Sprite:create("layer/layer_game_help/shurukuang.png"):addTo(self):setPosition(350,650):setLocalZOrder(2)
    self.word_txt = cc.Label:createWithSystemFont("","",15,cc.size(180,0))
    self.word_txt:addTo(self):setPosition(350,660):setColor(cc.c3b(0,0,0)):setAnchorPoint(0.5,0.5):setLocalZOrder(2)
    
    self.return_btn = cc.Sprite:create("layer/layer_game_help/tiaoguo.png"):addTo(self):setPosition(display.width - 200,50):setLocalZOrder(2)
    self.jiantou = cc.Sprite:create("layer/layer_game_help/jiantou.png"):addTo(self):setPosition(display.width - 350,50):setLocalZOrder(2)
    local call = cc.CallFunc:create(function() self.jiantou:setPosition(display.width - 350,50) end)
    self.jiantou:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.Show:create(),cc.MoveBy:create(1,cc.p(50,0)),call,cc.Hide:create(),cc.DelayTime:create(0.5))))
    
    self.hand = cc.Sprite:create("layer/layer_game_help/hand.png"):addTo(self):setPosition(display.width/2,display.height/2):setLocalZOrder(2)
    self.hand:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.FadeOut:create(1),cc.FadeIn:create(1))))
    self.btnList = {}
    self.btnList[#self.btnList + 1] = self.return_btn
    self.content_spr = nil
    self.index = 1
    self.sound_now = nil

    self:next()
end


function GameHelpLayer:init()

end

function GameHelpLayer:onTouch(event)
    GameHelpLayer.super.onTouch(self,event)
    BtnGroup:onTouchLayer(event,self.btnList)
	if event.name ~= "began" then return end
   
    return true
end

function GameHelpLayer:onClick(event)
    if MotionUtil:checkPointToNode(self.return_btn,event) then
        cc.UserDefault:getInstance():setBoolForKey(self.userDefualtKey,true)
        if self.hallScene then              --结束之后进入游戏
            self.hallScene:loginRoom(self.hallScene_item,self.hallScene_params)
        end
        if self.sound_now then
            ccexp.AudioEngine:stop(self.sound_now)
        end
        if device.platform == "android" then
            self.sound_now = ccexp.AudioEngine:play2d(("music/guideSound/endsay.ogg"),false)
        elseif device.platform == "ios" then
            audio.stopAllSounds()
            audio.playSound("music/guideSound/endsay")
        end
        self:removeFromParent()
        return
    end
     self:next()
end
function GameHelpLayer:next()

    if self.sound_now then
        ccexp.AudioEngine:stop(self.sound_now)
    end
    if self.index > #self.data.word then
        self.index = self.index + 1
        cc.UserDefault:getInstance():setBoolForKey(self.userDefualtKey,true)
        if self.hallScene then              --结束之后进入游戏
            self.hallScene:loginRoom(self.hallScene_item,self.hallScene_params)
        end
        if device.platform == "android" then
            self.sound_now = ccexp.AudioEngine:play2d(("music/guideSound/endsay.ogg"),false)
        elseif device.platform == "ios" then
            audio.stopAllSounds()
            audio.playSound("music/guideSound/endsay")
        end
        self:removeFromParent()
        return
    end
    self.word_txt:setString(self.data.word[self.index])

    if device.platform == "android" then
        self.sound_now = ccexp.AudioEngine:play2d(("music/guideSound/"..self.data.sound[self.index]..".ogg"),false)
    elseif device.platform == "ios" then
        -- self.sound_now = ccexp.AudioEngine:play2d(("music/guideSound/"..self.data.sound[self.index]..".mp3"),false)
        audio.stopAllSounds()
        audio.playSound("music/guideSound/"..self.data.sound[self.index])
    end
    
    if self.content_spr then
    	self.content_spr:removeFromParent()
    	self.content_spr = nil
    end
    if self.data.pic[self.index] then
        self.content_spr = cc.Sprite:create("layer/layer_game_help/"..self.data.pic[self.index]):addTo(self)
        self.content_spr:setPosition(display.width - self.content_spr:getContentSize().width/2 - 50,display.height/2)
    end
    self.index = self.index + 1
end

function GameHelpLayer:setOnExitCallBack(callBack)
    self.onExitCallBack = callBack
end

function GameHelpLayer:onExit()
    if self.onExitCallBack ~= nil then
        self.onExitCallBack()
    end
end

function GameHelpLayer:onCleanup()
--    if self.index <= #self.data.word + 1 then
--        if self.sound_now then
--            audio.stopAllSounds()
--            ccexp.AudioEngine:stop(self.sound_now)
--        end
--    end
end
return GameHelpLayer