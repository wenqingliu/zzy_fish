local TableViewUtil = {}

function TableViewUtil:selected(tabList,tabImageList,panelList,index)
    for i = 1,#tabList do
        local tab = tabList[i]
        if i == index then
            tab:setSpriteFrame(tabImageList[i][2])
        else
            tab:setSpriteFrame(tabImageList[i][1])
        end
        
        local panel = panelList[i]
        if i == index then
            panel:setVisible(true) 
        else
            panel:setVisible(false)
        end
    end
end

--------
--示例
--local tabList = {
--    self.panel:getChildByName("tab_1"),
--    self.panel:getChildByName("tab_2"),
--    self.panel:getChildByName("tab_3")
--}
--local tabImageList = {
--    {"_bank_access.png","_bank_access_select.png"},
--    {"_bank_giving.png","_bank_giving_select.png"},
--    {"_bank_record.png","_bank_record_select.png"}
--} 
--local panelList = {
--    self.panel:getChildByName("panel_1"),
--    self.panel:getChildByName("panel_2"),
--    self.panel:getChildByName("panel_3")
--}
--TableViewUtil:selected(tabList,tabImageList,panelList,index)

return TableViewUtil