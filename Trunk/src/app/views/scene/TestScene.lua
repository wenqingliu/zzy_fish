local TestScene = class("TestScene",cc.load("mvc").ViewBase)
local chatLayer = import("app/views/game/hundred/HundredChatLayer.lua")
local FriendsLayer = import("app/views/layer/FriendsLayer.lua")
local UserData = import("app/models/data/UserData.lua")
function TestScene:onCreate()
	self.root = Resources:createNodeAndDoLayout("scene/test_scene.csb"):addTo(self)
    self.spr_commit = self.root:getChildByName("spr_commit")
    self.spr_commit:addClickEventListener(handler(self,self.onClick))
    
    
--    local rect = cc.rect(17,14,15,16)
    local img = self.root:getChildByName("Image_1")--:addTo(self)
    img:setCapInsets(cc.rect(40,15,147,24))
    local rect = img:getCapInsets()
--    ccui.ImageView:setCapInsets(cc.rect(40,15,147,24))--{["height"] = 24,["width"] = 147,["x"] = 40,["y"] = 15}
    --添加好友
    local function onClickAdd(parameters)
--        local gameid = self.root:getChildByName("dwgameid"):getString()
--        local dw_friendsid = self.root:getChildByName("dw_friendsid"):getString()
--        if dw_friendsid == "" then
--            dw_friendsid = 123456
--        end
--        jt.CFrameData:getInstance():sendPacketWithAddFriends(tonumber(dw_friendsid))
          chatLayer:create():addTo(self)
          --jt.CFrameData:getInstance():sendPacketWithUserChat(1,"aa",1)
    end
    --//
    
    --删除好友
    local function sendPacketDeleteFriendly(parameters)
        local gameid = self.root:getChildByName("dwgameid"):getString()
        local dw_friendsid = self.root:getChildByName("dw_friendsid"):getString()
        if dw_friendsid == "" then
            dw_friendsid = 123456
        end
        jt.CFrameData:getInstance():sendPacketDeleteFriendly(tonumber(dw_friendsid))
    end
    --//
    
    --添加黑名单
    local function sendPacketWithAddBlackList(parameters)
        local gameid = self.root:getChildByName("dwgameid"):getString()
        local dw_friendsid = self.root:getChildByName("dw_friendsid"):getString()
        if dw_friendsid == "" then
            dw_friendsid = 123456
        end
--        jt.CFrameData:getInstance():sendPacketWithAddBlackList(tonumber(dw_friendsid))
          local user = UserData:create()
        user:setFaceURL("http://112.74.75.156:100/upload/mm.jpg")
        user:setGameID("444444")
        MotionUtil:RepleaceWithURLPic(self.root:getChildByName("dw_friendsid"),user,cc.size(100,100))
    end
    
    --移除黑名单
    local function sendPacketWithRemoveBlackList(parameters)
        local gameid = self.root:getChildByName("dwgameid"):getString()
        local dw_friendsid = self.root:getChildByName("dw_friendsid"):getString()
        if dw_friendsid == "" then
            dw_friendsid = 123456
        end
        jt.CFrameData:getInstance():sendPacketWithRemoveBlackList(tonumber(dw_friendsid))
    end
    
    --好友列表
    local function sendPacketWithLoadFriendList(parameters)
        --jt.CFrameData:getInstance():sendPacketWithLoadFriendList(GameManager:getRoomServer():getMessageServer())
        FriendsLayer:create():addTo(self)
    end
    
    --好友聊天
    local function sendPacketWithFriendChat(parameters)
        local dw_friendsid = self.root:getChildByName("dw_friendsid"):getString()
        local tf_input = self.root:getChildByName("tf_input"):getString()
        if dw_friendsid == "" then
            dw_friendsid = 123456
        end
        if tf_input == "" then
            tf_input = "abc"
        end
        jt.CFrameData:getInstance():sendPacketWithFriendChat(GameManager:getRoomServer():getMessageServer(),tonumber(dw_friendsid),tf_input)
    end
    
    --好友推荐
    local function sendPacketWithSysRecommen(parameters)
        jt.CFrameData:getInstance():sendPacketWithSysRecommen()
    end
    
    --黑名单列表
    local function sendPacketWithLoadBlackList(parameters)
        jt.CFrameData:getInstance():sendPacketWithLoadBlackList()
    end
    
    self.dwgameid = self.root:getChildByName("dwgameid")
    self.dwgameid:addClickEventListener(handler(self,self.onClick))
    
    self.spr_add = self.root:getChildByName("spr_add")
    self.spr_add:addClickEventListener(onClickAdd)
    
    self.btn_add_blacklist = self.root:getChildByName("btn_add_blacklist")
    self.btn_add_blacklist:addClickEventListener(sendPacketWithAddBlackList)
    
    self.btn_add_blacklist = self.root:getChildByName("btn_remove_blacklist")
    self.btn_add_blacklist:addClickEventListener(sendPacketWithRemoveBlackList)
    
    self.spr_del = self.root:getChildByName("spr_del")
    self.spr_del:addClickEventListener(sendPacketDeleteFriendly)
    
    self.spr_list = self.root:getChildByName("spr_list")
    self.spr_list:addClickEventListener(sendPacketWithLoadFriendList)
    
    self.spr_sendmsg = self.root:getChildByName("spr_sendmsg")
    self.spr_sendmsg:addClickEventListener(sendPacketWithFriendChat)
    
    self.spr_sendmsg = self.root:getChildByName("spr_tuijian")
    self.spr_sendmsg:addClickEventListener(sendPacketWithSysRecommen)
    
    self.spr_sendmsg = self.root:getChildByName("btn_blacklist_all")
    self.spr_sendmsg:addClickEventListener(sendPacketWithLoadBlackList)
    
end

function TestScene:onClick(btn,eventType)
    local gameid = self.root:getChildByName("dwgameid"):getString()
    local dw_friendsid = self.root:getChildByName("dw_friendsid"):getString()
    if dw_friendsid == "" then
        dw_friendsid = 123456
    end
    jt.CFrameData:getInstance():sendPacketWithQueryFriends(tonumber(dw_friendsid))
end

return TestScene