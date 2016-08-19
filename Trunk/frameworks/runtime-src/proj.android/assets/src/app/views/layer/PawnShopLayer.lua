local BaseLayer = import("app/views/layer/BaseLayer.lua")
local PawnShopLayer = class("PawnShopLayer",BaseLayer)
local CMD_Server_Gift = import("app/cmd/loginSever/CMD_Server_Gift.lua") 
local LuaUtil = import("app/library/LuaUtil")

PawnShopLayer.PRODUCT_COUNT = 8
PawnShopLayer.events = {
    ccND_Storage_Info = "ccND_Storage_Info",
    ccND_Pawn_Back = "ccND_Pawn_Back",                   --典当请求返回
    ccND_SendGift = "ccND_SendGift",                     --送礼请求返回
}

PawnShopLayer.pic = {2,1,3,5,4,6,7,8}
PawnShopLayer.name = {  
    "layer_pawnshop/kafe.png",
    "layer_pawnshop/hua.png",
    "layer_pawnshop/xiangshui.png",
    "layer_pawnshop/bb.png",
    "layer_pawnshop/jiez.png",
    "layer_pawnshop/paoche.png",
    "layer_pawnshop/bieshu.png",
    "layer_pawnshop/huangguan.png"
}

function PawnShopLayer:ctor(user)
	self.super.ctor(self)
    self.user = user == nil and GameManager:getUserSelf() or user
    self.btnList = {}
    self.giftList = {}
    self:init()
    self.currentIndex = 1
--    self:show()
--    GameManager:showLoading(self)
    
--    jt.CFrameData:getInstance():sendPacketWithGPPawnShopLayer(1,1,1)--查当铺
    CFrameDataHandler:getInstance():addEventListener(PawnShopLayer.events.ccND_Storage_Info,handler(self,self.onGiftInfo))
    CFrameDataHandler:getInstance():addEventListener(PawnShopLayer.events.ccND_Pawn_Back,handler(self,self.PawnCallBack))
    CFrameDataHandler:getInstance():addEventListener(PawnShopLayer.events.ccND_SendGift,handler(self,self.onSendGiftCallBack))
    
    CFrameDataHandler:getInstance():sendSocketGift()
--    if self.user ~= GameManager:getUserSelf() then
--        jt.CFrameData:getInstance():sendPacketWithGPPawnShopLayer(1,1,1)--查当铺
--    else
--        CFrameDataHandler:getInstance():sendSocketGift()
--    end
end

function PawnShopLayer:init()
    self.root = Resources:createNodeAndDoLayout("layer/system_pawnshop/layout_pawnshop.csb"):addTo(self)
    self.panel = self.root:getChildByName("panel")
    local panel_left = self.root:getChildByName("panel_left")
    local panel_top = self.root:getChildByName("panel_top")
    self.panel_left = panel_left
    
    self.spr_return = panel_top:getChildByName("spr_return")
    self.spr_gift_left = panel_left:getChildByName("spr_gift_left")
    self.spr_gift_right = panel_left:getChildByName("spr_gift_right")
    self.spr_btn_commit = panel_left:getChildByName("spr_btn_commit")
    self.tf_input = panel_left:getChildByName("tf_input")
    self.txt_desc = panel_left:getChildByName("txt_desc")
    self.tf_input:setVisible(false)
    
    --送礼
    if self.user ~= nil and self.user ~= GameManager:getUserSelf() then
        panel_top:getChildByName("spr_title"):setTexture("layer/system_pawnshop/layer_title_lwgoumai.png")
        self.spr_btn_commit:getChildByName("txt_content"):setString("赠　送")
        panel_left:getChildByName("txt_num"):setVisible(false)
        panel_left:getChildByName("txt_total"):setString("共计：0")
        
        for i=1,PawnShopLayer.PRODUCT_COUNT do
            local panel_item = nil
            if i<=4 then
                panel_item = self.panel:getChildByName("panel_item_1")
            else
                panel_item = self.panel:getChildByName("panel_item_2")
            end
            panel_item:getChildByName("txt_num_dec_"..i):setVisible(false)
            panel_item:getChildByName("txt_num_"..i):setVisible(false)
        end
    end
    
    --适配
    local bg = self.root:getChildByName("spr_bg")
    Resources:setFullScaleY(bg)
    local left_spr_bg = panel_left:getChildByName("spr_bg")
    Resources:setFullScaleY(left_spr_bg)
    local panel_item_1 = self.panel:getChildByName("panel_item_1")
    local scaleY = panel_item_1:getPositionY() / 720
    panel_item_1:setPositionY(display.height * scaleY)
    local panel_item_2 = self.panel:getChildByName("panel_item_2")
    local scaleY = panel_item_2:getPositionY() / 720
    panel_item_2:setPositionY(display.height * scaleY)
    
    --按钮
    self.btnList = {self.spr_return,self.spr_gift_left,self.spr_gift_right,self.spr_btn_commit}
    

    self.tf_input:addEventListener(handler(self,self.onTextFieldEvent))
    
end

function PawnShopLayer:onTouch(event)
    BtnGroup:onTouchLayer(event,self.btnList)                                                                                                           
    self.super.onTouch(self,event)
    return true
end

function PawnShopLayer:onClick(event)
    if MotionUtil:checkPointToNode(self.spr_return,event) then
        self:hide()
        return
    end
    
    if #self.giftList > 0 then
        local num = tonumber(self.txt_desc:getString())
        if MotionUtil:checkPointToNode(self.spr_gift_left,event) then
            if num > 0 then
                num = num - 1
                self.txt_desc:setString(num)
                self.tf_input:setString(num)
                if self.user == GameManager:getUserSelf() then
                    --典当
                else
                   --送礼
                    local price = ("共计：" ..  LuaUtil:parseLong(num * self.giftList[self.currentIndex].giftBuyPrice))
                    self.panel_left:getChildByName("txt_total"):setString(price)
                end
             end
        elseif MotionUtil:checkPointToNode(self.spr_gift_right,event) then
            if self.user == GameManager:getUserSelf() then
                --典当
                if num < self.giftList[self.currentIndex].giftNum then
                    num = num + 1
                end
            else
                --送礼
                if (num+1) * self.giftList[self.currentIndex].giftBuyPrice <= GameManager:getUserSelf():getScore() then
                    num = num + 1
                    local price = ("共计：" .. LuaUtil:parseLong(num * self.giftList[self.currentIndex].giftBuyPrice))
                    self.panel_left:getChildByName("txt_total"):setString(price)
                end
            end
            self.tf_input:setString(num)
            self.txt_desc:setString(num)
        elseif MotionUtil:checkPointToNode(self.spr_btn_commit,event) then
            if num > 0 then
                if self.user == GameManager:getUserSelf() then
                    CFrameDataHandler:getInstance():sendSocketPawn(self.giftList[self.currentIndex].giftType,num)
                else
                    local price = num * self.giftList[self.currentIndex].giftBuyPrice
                    local num = tonumber(self.txt_desc:getString())
                    CFrameDataHandler:getInstance():giveGift(self.user,self.giftList[self.currentIndex].giftType,num,price)
                end
            end
        end
    end
    
    
    for i=1,PawnShopLayer.PRODUCT_COUNT do
        local panel_item = nil
        if i<=4 then
            panel_item = self.panel:getChildByName("panel_item_1")
        else
            panel_item = self.panel:getChildByName("panel_item_2")
        end
        local spr_item_bg = panel_item:getChildByName("spr_item_bg_"..i)
        if self.currentIndex ~= i and MotionUtil:checkPointToNode(spr_item_bg,event) then
--            self:hideLight(self.currentIndex)
            self:switchLight(i)
            local light = panel_item:getChildByName("spr_item_light")
            light:setVisible(true)
            light:move(spr_item_bg:getPositionX(),spr_item_bg:getPositionY())
        end
    end
    
    
end

function PawnShopLayer:onTouchButton(btn,eventType)
    BtnGroup:onTouchButton(btn,eventType)
    local index = btn:getTag()

    --典当操作

    return true
end

function PawnShopLayer:onTextFieldEvent(sender, eventType)
    local bool,num = self:checkFromatSource(sender:getString())
    if bool and #self.giftList > 0 then
        num = math.floor(tonumber(num))
        if num > self.giftList[self.currentIndex].giftNum then 
            self.tf_input:setString(self.giftList[self.currentIndex].giftNum)
        elseif num < 0 then
            self.tf_input:setString("0")
        elseif num >= 0 and num <= self.giftList[self.currentIndex].giftNum then
--            self.tf_input:setString(num)
            self.txt_desc:setString(num)
        end
    else
        self.tf_input:setString(self.txt_desc:getString())
        self.txt_desc:setString(self.tf_input:getString())
    end
--    self:updateGift()
end

---------------                                                                                                                                         
-- 检测输入框金额格式                                                                                                                                            
-- @return #bool #string                                                                                                                                
function PawnShopLayer:checkFromatSource(str)                                                                                                            
    if string.len(str) == 0 then                                                                                                                        
        return false,"数值不能为空"                                                                                                                            
    end                                                                                                                                                 

    local num = tonumber(str)                                                                                                                           
    if num == nil then                                                                                                                                  
        return false,"输入数值有误"                                                                                                                           
    end                                                                                                                                                 
                                                                                                                               
    return true,str                                                                                                                                
end

function PawnShopLayer:switchLight(i)
    self:hideLight(self.currentIndex)
    self.currentIndex = i
    self.panel_left:getChildByName("spr_gift_name"):setSpriteFrame(PawnShopLayer.name[i])
    
    self.panel_left:getChildByName("spr_gift"):setSpriteFrame("gift/_gift_"..PawnShopLayer.pic[i]..".png")
    if #self.giftList == 0 then
        return
    end
--    self.txt_desc:setString(self.giftList[self.currentIndex].giftNum)
--    self.tf_input:setString(self.giftList[self.currentIndex].giftNum)
    self.txt_desc:setString("0")
    self.tf_input:setString("0")
    if self.user ~= GameManager:getUserSelf() then
        self.panel_left:getChildByName("txt_total"):setString("共计：0")
    end
    self.panel_left:getChildByName("txt_num"):setString(self.giftList[i].giftNum)
end

function PawnShopLayer:hideLight(index)
    local panel_item = nil
    if index<=4 then
        panel_item = self.panel:getChildByName("panel_item_1")
    else
        panel_item = self.panel:getChildByName("panel_item_2")
    end
    panel_item:getChildByName("spr_item_light"):setVisible(false)
end

function PawnShopLayer:onGiftInfo(event)
--    GameManager:hideLoading()
    local notify = event._userData
    if notify:getSize() == 0 then
        print("没有数据")
    else
        local cmd = CMD_Server_Gift.CMD_MB_GiftInfo:createWithNotify(notify)
        local index = 0
        for i=1,CMD_Server_Gift.LEN_GIFT_NUM do
            local gift_ = {}
            if not cmd.info.dwNotPawn[i] then
                gift_.giftType = cmd.info.giftTpye[i]
                gift_.giftNum = cmd.info.giftNum[i]
                gift_.giftBuyPrice = cmd.info.giftBuyPrice[i]
                gift_.giftPawnPrice = cmd.info.giftPawnPrice[i]
                self.giftList[#self.giftList + 1] = gift_
            end

        end
        self:updateGift()
    end
end

function PawnShopLayer:ShowGiftInfo(gift)
    local index = 1
    for i=1, CMD_Server_Gift.LEN_GIFT_NUM do
        if not gift.dwNotPawn[i] then
            local button_ = self.contentNode:getChildByName("shop_scroll"):getChildByTag(index)
            button_.price = gift.giftBuyPrice[i]

            local price = gift.giftBuyPrice[index]
            if price >= 10000 then
                price = (price/10000).."W"
            end
            self.contentNode:getChildByName("shop_scroll"):getChildByName("price_"..index):setString(price)
            index = index + 1
        end

    end
end

function PawnShopLayer:updateGift()
--    self.txt_desc:setString(self.giftList[self.currentIndex].giftNum)
    self.panel_left:getChildByName("txt_num"):setString(self.giftList[self.currentIndex].giftNum)
    for i=1,PawnShopLayer.PRODUCT_COUNT do
        local panel_item = nil
        if i<=4 then
            panel_item = self.panel:getChildByName("panel_item_1")
        else
            panel_item = self.panel:getChildByName("panel_item_2")
        end
        panel_item:getChildByName("txt_num_"..i):setString(self.giftList[i].giftNum)--self.giftList[self.currentIndex].giftPawnPrice
        local price = 0
        if self.user == GameManager:getUserSelf() then
            price = LuaUtil:parseScore(self.giftList[i].giftPawnPrice)
        else
            price = LuaUtil:parseLong(self.giftList[i].giftBuyPrice)
        end
        panel_item:getChildByName("spr_btn_"..i):getChildByName("txt_score"):setString(price)
    end
end
function PawnShopLayer:reduce(btn,eventType)     --减
    BtnGroup:onTouchButton(btn,eventType)
    if eventType == 2 then
--        local tag = btn:getTag()
        if tonumber(btn.text:getString()) > 0 then
        	btn.text:setString(tonumber(btn.text:getString()) - 1)
            local money_str = tonumber(btn.text:getString())*btn.price
            if money_str >= 10000 then
        		money_str = (money_str/10000).."万"
        	end
            btn.moneyText:setString(money_str)
        end
    end
    return true
end

function PawnShopLayer:add(btn,eventType)        --加
    BtnGroup:onTouchButton(btn,eventType)
    if eventType == 2 then
        if tonumber(btn.text:getString()) < btn.max then
            btn.text:setString(tonumber(btn.text:getString()) + 1)
            local money_str = tonumber(btn.text:getString())*btn.price
            if money_str >= 10000 then
                money_str = (money_str/10000).."万"
            end
            btn.moneyText:setString(money_str)
        end
    end
    return true
end

function PawnShopLayer:pawn(btn,eventType)   --典当
    BtnGroup:onTouchButton(btn,eventType)
    if eventType == 2 then
        if tonumber(btn.text:getString()) <= 0 then
    	   return
        end
        CFrameDataHandler:getInstance():sendSocketPawn(btn.GiftType,tonumber(btn.text:getString()))
    end
    return true
end

function PawnShopLayer:PawnCallBack(event)
	local notify = event._userData
    if notify:getSize() == 0 then
        print("没有数据")
    else
        local cmd = CMD_Server_Gift.CMD_MB_GiftOption:createWithNotify(notify)
        local c = cmd.info.stateCode
        local c1 = cmd.info.userScore
        local c2 = cmd.info.itemType
        local c3 = cmd.info.itemCount
        if cmd.info.stateCode == 1 then
            GameManager:getUserSelf():setScore(cmd.info.userScore)
            local index = self:getIndexByType(cmd.info.itemType)
            if index then
            	self.giftList[index].giftNum = cmd.info.itemCount
            end
            self:updateGift()
            --更新游戏大厅                                                                                                                                         
            if GameManager:getGameDelegate() ~= nil then
                GameManager:getGameDelegate():updateGameView()
            end
            
            GameManager:showAlertSystem(self,"典当成功")
        else
            GameManager:showAlertSystem(self,"典当失败，请重试！")
        end
    end
end

--赠送礼物返回
function PawnShopLayer:onSendGiftCallBack(event)
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

function PawnShopLayer:getIndexByType(giftType)
	for i = 1,#self.giftList do
		if self.giftList[i].giftType == giftType then
			return i
		end
	end
	return nil
end
function PawnShopLayer:onCleanup()
    CFrameDataHandler:getInstance():removeEventListenerByList(self.events) 
end
return PawnShopLayer