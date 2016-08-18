local baseLayer = import("app/views/layer/BaseLayer.lua")
local sendGiftLayer = class("sendGiftLayer",baseLayer)
local CMD_Server_Gift = import("app/cmd/loginSever/CMD_Server_Gift.lua")
sendGiftLayer.pic = {2,0,5,6,1,3,4,7}
sendGiftLayer.name = {  "layer_shop/coffee.png",
                        "layer_shop/flower.png",
                        "layer_shop/perfume.png",
                        "layer_shop/bag.png",
                        "layer_shop/ring.png",
                        "layer_shop/car.png",
                        "layer_shop/villa.png",
                        "layer_shop/crown.png"
                     }
function sendGiftLayer:ctor(user,gift_type,price)
    self.super.ctor(self)
    self.user = user
    self.giftType = gift_type
    self.price = price
    self.num = 0
    self.maxNum = math.floor(GameManager:getUserSelf():getScore()/price)
    self.node = nil
    self.cost = 0
    self.btnList = {}
	self:init()
    
end

function sendGiftLayer:init()
    self.node = cc.CSLoader:createNode("layer/system_shop/layer_sendGift.csb"):addTo(self):setPosition(0,0):getChildByName("panel")
    self:setRootBg(self.node:getChildByName("layer_shop_kuang_1"))
    self.node:getChildByName("num_txt"):setString("0")
    local price_str = self.price
    if self.price >= 10000 then
        price_str = (self.price/10000).."万"
    end
    self.node:getChildByName("price_txt"):setString(price_str)
    self.node:getChildByName("pic"):setSpriteFrame("user_info_gift_"..sendGiftLayer.pic[self.giftType]..".png")
    self.node:getChildByName("name"):setSpriteFrame(sendGiftLayer.name[self.giftType])
    self.btnList[#self.btnList + 1] = self.node:getChildByName("reduce_btn")
    self.btnList[#self.btnList + 1] = self.node:getChildByName("add_btn")
    self.btnList[#self.btnList + 1] = self.node:getChildByName("give_btn")
    self.btnList[#self.btnList + 1] = self.node:getChildByName("cancel_btn")
    print("aaa")
end

function sendGiftLayer:onTouch(event)
    BtnGroup:onTouchLayer(event,self.btnList)                                                                                                           
    self.super.onTouch(self,event)
    if event.name ~= "ended" then return true end
    
	return true
end

function sendGiftLayer:onClick(event)
    if MotionUtil:checkPointToNode(self.node:getChildByName("reduce_btn"),event) then         --减                                                 
        if self.num <= 0 then
            return true
    end
    self.num = self.num - 1
    self.cost = self.price * self.num 
    self.node:getChildByName("num_txt"):setString(self.num) 
    local cost_str = self.cost
    if self.cost >= 10000 then
        cost_str = (self.cost/10000).."万"
    end
    self.node:getChildByName("cost_txt"):setString(cost_str)                                                                                                                          
    elseif MotionUtil:checkPointToNode(self.node:getChildByName("add_btn"),event) then      --加                                                 
        if self.num >= self.maxNum then
            return true
    end
    self.num = self.num + 1 
    self.cost = self.price * self.num 
    self.node:getChildByName("num_txt"):setString(self.num)
    local cost_str = self.cost
    if self.cost >= 10000 then
        cost_str = (self.cost/10000).."万"
    end
    self.node:getChildByName("cost_txt"):setString(cost_str)
    elseif MotionUtil:checkPointToNode(self.node:getChildByName("give_btn"),event) then      --送出  
        if self.num > 0 then
            CFrameDataHandler:getInstance():giveGift(self.user,CMD_Server_Gift.need[self.giftType],self.num,self.price)
            self:hide()
    end                                                
    elseif MotionUtil:checkPointToNode(self.node:getChildByName("cancel_btn"),event) then   --取消
        self:hide()                                                                                                                                       
    end  
    return true
end
return sendGiftLayer