local BaseLayer = import("app/views/layer/BaseLayer.lua")
local RoomSelectLayer = class("RoomSelectLayer",BaseLayer)

local LuaUtil = import("app/library/LuaUtil.lua")

RoomSelectLayer.ROOM_BR=1       --富豪百人
--RoomSelectLayer.ROOM_YY=2
RoomSelectLayer.ROOM_VS=3       --对战场
RoomSelectLayer.ROOM_ZHUANG=4   --抢庄场
RoomSelectLayer.ROOM_HUANLE=5   --欢乐百人

function RoomSelectLayer:ctor(index)
    self.super.ctor(self)
    self._index = index
    self.choose_index = 1
    
    self.root = Resources:createNodeAndDoLayout("layer/room_select/layer_room_100.csb"):addTo(self)
--    if index == RoomSelectLayer.ROOM_BR then
--        self.root = Resources:createNodeAndDoLayout("layer/room_select/layer_room_100.csb"):addTo(self)
--    elseif index == RoomSelectLayer.ROOM_VS then
--        self.root = Resources:createNodeAndDoLayout("layer/room_select/layer_room_vs.csb"):addTo(self)
--    elseif index == RoomSelectLayer.ROOM_ZHUANG then
--        self.root = Resources:createNodeAndDoLayout("layer/room_select/layer_room_zhuang.csb"):addTo(self)
--    elseif index == RoomSelectLayer.ROOM_HUANLE then
--        self.root = Resources:createNodeAndDoLayout("layer/room_select/layer_room_huanle.csb"):addTo(self)
--    end
    
    self.panel = self.root:getChildByName("panel")
    self.panel_top = self.root:getChildByName("panel_top")
    self.spr_return = self.root:getChildByName("spr_return")
    Resources:setFullScaleY(self.root:getChildByName("spr_bg"))
    Resources:setFullScaleY(self.root:getChildByName("spr_table"))
    
    local spr_name = self.root:getChildByName("spr_name")
    local scaleY = spr_name:getPositionY() / 720
    spr_name:setPositionY(display.height * scaleY)
    
    self.choose = {self.panel:getChildByName("spr_room_1"),self.panel:getChildByName("spr_room_2")}
    self.btnList = {self.spr_return,self.panel:getChildByName("spr_btn_start"),self.choose[1],self.choose[2]}

    if index == RoomSelectLayer.ROOM_ZHUANG then
        --看牌抢庄
        self.choose[1]:setVisible(false)
        self.choose[2]:setVisible(false)
        self.panel:getChildByName("spr_room_3"):setVisible(true)
        spr_name:setSpriteFrame("layer_room_select/qz.png")
    end
    
    -- bind the "event" component
end

function RoomSelectLayer:setData(roomList)
    self.allRoomList = {}
    for j = 1,#GameManager:getProject().RoomNameList do
        local threeList = {}
        for i = 1,#roomList do
            local item = roomList[i]
            local name = GameManager:getProject().RoomNameList[j]
            if item:szServerName():find(name) ~= nil then
                threeList[#threeList+1] = item;
            end
        end
        self.allRoomList[#self.allRoomList+1] = threeList
    end
    
    --绑定数据
    local threeList = self.allRoomList[1]           --富豪
    local txtMin = nil
    local txtOnline = nil
    for i = 1,#threeList do
        if i > 2 then break end
        local txtMin = self.panel:getChildByName("spr_room_"..i):getChildByName("fnt_shang")
        local cmd = jt.tagGameServerRef
        cmd = threeList[i]
--        txtMin:setString("最少携带:"..cmd:lMinEnterScore())
        if cmd:lMinEnterScore() >= 100000 then
            txtMin:setString("最少携带:"..LuaUtil:parseJetton(cmd:lMinEnterScore()))
        else
            txtMin:setString("最少携带:"..cmd:lMinEnterScore())
        end
    end
end

function RoomSelectLayer:panelShow(index)
    if self.choose_index == index then
        return
    end
    self.choose_index = index
    local threeList = nil
    
    if index == 1 then
        self.choose[1]:getChildByName("spr_room_city"):setSpriteFrame("layer_room_select/sz.png")
        self.choose[2]:getChildByName("spr_room_city"):setSpriteFrame("layer_room_select/sh.png")
        self.panel_top:getChildByName("spr_choose_1"):setSpriteFrame("layer_room_select/fuhao.png")
        self.panel_top:getChildByName("spr_choose_2"):setSpriteFrame("layer_room_select/huanle1.png")
        self.root:getChildByName("spr_name"):setSpriteFrame("layer_room_select/fh.png")
        threeList = self.allRoomList[1]           --富豪
    else
        self.choose[1]:getChildByName("spr_room_city"):setSpriteFrame("layer_room_select/bj.png")
        self.choose[2]:getChildByName("spr_room_city"):setSpriteFrame("layer_room_select/am.png")
        self.panel_top:getChildByName("spr_choose_1"):setSpriteFrame("layer_room_select/fuhao1.png")
        self.panel_top:getChildByName("spr_choose_2"):setSpriteFrame("layer_room_select/huanle.png")
        self.root:getChildByName("spr_name"):setSpriteFrame("layer_room_select/hl.png")
        threeList = self.allRoomList[5]           --欢乐
    end
    
    --绑定数据
    local txtMin = nil
    local txtOnline = nil
    for i = 1,#threeList do
        if i > 2 then break end
        local txtMin = self.panel:getChildByName("spr_room_"..i):getChildByName("fnt_shang")
        local cmd = jt.tagGameServerRef
        cmd = threeList[i]
        if cmd:lMinEnterScore() >= 100000 then
            txtMin:setString("最少携带:"..LuaUtil:parseJetton(cmd:lMinEnterScore()))
        else
            txtMin:setString("最少携带:"..cmd:lMinEnterScore())
        end
    end
end

function RoomSelectLayer:onTouch(event)
    BtnGroup:onTouchLayer(event,self.btnList)
    self.super.onTouch(self,event)
    return true
end

function RoomSelectLayer:onClick(event)
    local isStart = false
    local index = 1
    for i = 1,2 do
        if MotionUtil:checkPointToNode(self.panel:getChildByName("spr_room_"..i),event) then
            isStart = true
            index = i
        end
    end

    if MotionUtil:checkPointToNode(self.spr_return,event) then
        self:hide()
    elseif MotionUtil:checkPointToNode(self.panel_top:getChildByName("spr_choose_1"),event) then
        self:panelShow(1)
    elseif MotionUtil:checkPointToNode(self.panel_top:getChildByName("spr_choose_2"),event) then
        self:panelShow(2)
    end

    if MotionUtil:checkPointToNode(self.panel:getChildByName("spr_btn_start"),event) then
        isStart = true
    end

    if isStart then
        local room = nil
        if self.choose_index == 1 then
            self._index = 1
        else
            self._index = 5
        end
        if (index) > #self.allRoomList[self._index]  then
            print("敬请期待")
            GameManager:showAlertSystem(self,"尚未开放，敬请期待")
        else
            room = self.allRoomList[self._index][index]
            GameManager:getGameDelegate():loginRoom(room)
            self:hide()
        end
    end

end

return RoomSelectLayer