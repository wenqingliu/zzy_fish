local BaseLayer = import("app/views/layer/BaseLayer.lua")
local PermissionLayer = class("PermissionLayer",BaseLayer)
function PermissionLayer:ctor(which)              --1：  游戏许可   2 ：  游戏公告
    self.super.ctor(self)
    self.which = which
    self:init()
end

function PermissionLayer:init()
--    if self.which == 1 then
        self.root = Resources:createNodeAndDoLayout("layer/layer_permission/layer_permission.csb"):addTo(self)
--    else
--        self.root = Resources:createNodeAndDoLayout("layer/layer_permission/layer_notice.csb"):addTo(self)
--    end
    self.panel = self.root:getChildByName("Panel_1")
    self.scrollView = self.panel:getChildByName("word_scroll")
    self.spr_close = self.panel:getChildByName("spr_close")
    local bg = self.panel:getChildByName("spr_bg")

    self:addWord()
    self:setRootBg(bg)
    self.btnList = {self.spr_close}
    self:show()
end

function PermissionLayer:onTouch(event)
    BtnGroup:onTouchLayer(event,self.btnList)
    self.super.onTouch(self,event)
    return true
end

function PermissionLayer:onClick(event)
    if MotionUtil:checkPointToNode(self.spr_close,event) then
        self:hide()
    end
end

function PermissionLayer:addWord()
    if self.which == 1 then
        local totalHeight = 0
        for i=5, 1,-1 do
            local word_ = cc.FileUtils:getInstance():getStringFromFile(cc.FileUtils:getInstance():fullPathForFilename("txt/Permission_"..i..".txt"))

            local label_word = cc.Label:createWithSystemFont(word_,"",25,cc.size(850,0)):addTo(self.scrollView)
            label_word:setAnchorPoint(0,1)
            label_word:setColor(cc.c3b(215,203,250))
            totalHeight = totalHeight + label_word:getContentSize().height

            label_word:setPosition(0,totalHeight)
        end
        self.scrollView:setInnerContainerSize(cc.size(850,totalHeight))

    end
end
return PermissionLayer