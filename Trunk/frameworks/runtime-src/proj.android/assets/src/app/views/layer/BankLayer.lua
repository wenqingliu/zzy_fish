local BaseLayer = import("app/views/layer/BaseLayer.lua")
local BankLayer = class("BankLayer",BaseLayer)
local TableViewUtil = import("app/library/TabViewUtil.lua")
BankLayer.events = {
    ccNd_Bank_InsureInfo = "ccNd_Bank_InsureInfo", --银行资料
    ccNd_Bank_Result = "ccNd_Bank_Result"--银行操作结果
}

function BankLayer:ctor()
	self.super.ctor(self)
    
    self.root = Resources:createNodeAndDoLayout("layer/system_bank/layer_bank.csb"):addTo(self)
    self.panel = self.root:getChildByName("panel")
    local bg = self.panel:getChildByName("node_bg"):getChildByName("spr_bg")
    self:setRootBg(bg)
    
    self.tab1 = self.panel:getChildByName("tab_1")
    self.tab2 = self.panel:getChildByName("tab_2")
    self.tab3 = self.panel:getChildByName("tab_3")
    self.panel_base = self.panel:getChildByName("panel_base")
    self.panel1 = self.panel:getChildByName("panel_1")
    self.panel2 = self.panel:getChildByName("panel_2")
    
    --按钮列表
    self.btnList = {}
    self.btnList[#self.btnList + 1] = self.tab1
    self.btnList[#self.btnList + 1] = self.tab2
    self.btnList[#self.btnList + 1] = self.tab3
    self.btnList[#self.btnList + 1] = self.panel1:getChildByName("spr_save")
    self.btnList[#self.btnList + 1] = self.panel1:getChildByName("spr_out")
    self.btnList[#self.btnList + 1] = self.panel2:getChildByName("spr_give")
    --//
--    local panneList = 
--    TableViewUtil.selected(1)
    self:updataView()
    self:selected(1)
    
    jt.CFrameData:getInstance():sendPacketWithGPInsureInfo("0")
    CFrameDataHandler:getInstance():addEventListener(BankLayer.events.ccNd_Bank_InsureInfo,handler(self,self.onBankInsureInfo))
    CFrameDataHandler:getInstance():addEventListener(BankLayer.events.ccNd_Bank_Result,handler(self,self.onBankOperation))
    self:show()
end

function BankLayer:updataView()
    local user = GameManager:getUserSelf()
    self.panel_base:getChildByName("txt_score"):setString(user:getScore())
    self.panel_base:getChildByName("txt_insureScore"):setString(user:getInsureScore())
end

function BankLayer:onTouch(event)
	BtnGroup:onTouchLayer(event,self.btnList)
    self.super.onTouch(self,event)
	
	if event.name ~= "ended" then return true end
	
	if MotionUtil:checkPointToNode(self.tab1,event) then
	   self:selected(1)
    elseif MotionUtil:checkPointToNode(self.tab2,event) then
       self:selected(2)
    elseif MotionUtil:checkPointToNode(self.tab3,event) then
       self:selected(3)
	end
	
    if MotionUtil:checkPointToNode(self.panel1:getChildByName("spr_save"),event) then
	   self:saveSorce()
    elseif MotionUtil:checkPointToNode(self.panel1:getChildByName("spr_out"),event) then
       self:takeOutSorce()
	elseif MotionUtil:checkPointToNode(self.panel2:getChildByName("spr_give"),event) then
	   self:transferScore()
	end
	
	return true
end

------------
-- 存入银行
function BankLayer:saveSorce()
    local str = self.panel1:getChildByName("tf_input"):getString()
    local suc,content = self:checkFromatSource(str)
    if suc then
        GameManager:showLoading(self)
        jt.CFrameData:getInstance():sendPacketWithGPSaveScore(tonumber(str))
    else
        --数据有误
        GameManager:showAlertSystem(self,content)
    end
end

------------
-- 银行取出
function BankLayer:takeOutSorce()
    local str = self.panel1:getChildByName("tf_input"):getString()
    local suc,content = self:checkFromatSource(str)
    if suc then
        GameManager:showLoading(self)
        jt.CFrameData:getInstance():sendPacketWithGPTakeScore(tonumber(str),"888888")
    else
        --数据有误
        GameManager:showAlertSystem(self,content)
    end
end

-----------
--银行转账
function BankLayer:transferScore()
    local userid = self.panel2:getChildByName("tf_user_id"):getString()
    local tf_score_num = self.panel2:getChildByName("tf_score_num"):getString()
    local suc,content = self:checkFromatSource(userid)
    if suc then
        GameManager:showLoading(self)
        jt.CFrameData:getInstance():sendPacketWithGPTransferScore(
            tonumber(tf_score_num),"888888",0,userid)
    else
        --数据有误
        GameManager:showAlertSystem(self,content)
    end
end

------
-- 设置选中显示
function BankLayer:selected(index)
    if index < 1 or index > 3 then return end
    local tabList = {
        self.tab1,self.tab2,self.tab3
    }
    local tabImageList = {
    {"_bank_access.png","_bank_access_select.png"},
    {"_bank_giving.png","_bank_giving_select.png"},
    {"_bank_record.png","_bank_record_select.png"}
    } 
    local panelList = {
        self.panel:getChildByName("panel_1"),
        self.panel:getChildByName("panel_2"),
        self.panel:getChildByName("panel_3")
    }
    TableViewUtil:selected(tabList,tabImageList,panelList,index)
   
    --基础金额
    if index == 1 or index == 2 then
        self.panel_base:setVisible(true)
    else
        self.panel_base:setVisible(false)    
    end
    --//
    
    --转账记录
    if index == 3 then
--        local userSelf = GameManager:getUserSelf()
--        jt.CFrameData:getInstance():sendPacketWithGPTransferRecord(userSelf:getGameID(),0,15)
    end
    
end

function BankLayer:onBankInsureInfo(event)
    local notify = event._userData
    local cmd = jt.CMD_GP_UserInsureInfoRef:createWithNotify(notify)
    self.panel1:getChildByName("txt_out_rate"):setString(cmd:wRevenueTake().."%")
    self.panel2:getChildByName("txt_transfer_rate"):setString(cmd:wRevenueTransfer().."%")
    local user = GameManager:getUserSelf()
    user:setScore(cmd:lUserScore())
    user:setInsureScore(cmd:lUserInsure())
    --更新游戏大厅
    if GameManager:getGameDelegate() ~= nil then
        GameManager:getGameDelegate():updateGameView()
    end
    
    self:updataView()
end



-----
--存取款操作结果
function BankLayer:onBankOperation(event)
	local notify = event._userData
    GameManager:hideLoading()
    GameManager:showAlertSystem(self,notify:getMainString()) 
    if notify:getResult() == RT_SUCCESS then
	   local cmd = notify:getObject()
	   --更新用户金币
	   GameManager:getUserSelf():setScore(cmd:lUserScore())
       GameManager:getUserSelf():setInsureScore(cmd:lUserInsure())
	   self:updataView()
        --更新游戏大厅
        if GameManager:getGameDelegate() ~= nil then
            GameManager:getGameDelegate():updateGameView()
        end
	else
	   
	end
end

------
-- 转账记录
function BankLayer:onBankTransGoldRecord(event)
    local notify = event._userData
    local ref = jt.CMD_GR_S_TransGoldRecordInfoRef:createWithNotify()
    local size = ref:getSize()
    for i=1,notify:getSize()/size do
        local cmd = jt.CMD_GR_S_TransGoldRecordInfoRef:createWithDataArray(notify,i-1)
--        print(cmd:szDateTime(),cmd:)
    end
    
end

---------------
-- 检测输入框金额格式
-- @return #bool #string
function BankLayer:checkFromatSource(str)
    if string.len(str) == 0 then
        return false,"输入金额不能为空"
    end

    local num = tonumber(str)
    if num == nil then
        return false,"输入金额有误"
    end

    if num <= 0 then
        return false,"输入金额不能为0"
    end
    return true,""
end

function BankLayer:onCleanup()
    CFrameDataHandler:getInstance():removeEventListenerByList(self.events)
end

return BankLayer