
--------------------------------
-- @module CMD_S_CancelSitRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_CancelSitRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_CancelSitRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_CancelSitRef#CMD_S_CancelSitRef self (return value: CMD_S_CancelSitRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_CancelSitRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_CancelSitRef] wSitChairID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_CancelSitRef#CMD_S_CancelSitRef self (return value: CMD_S_CancelSitRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_CancelSitRef] wCancelID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_CancelSitRef#CMD_S_CancelSitRef self (return value: CMD_S_CancelSitRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_CancelSitRef] createWithNotify 
-- @param self
-- @return CMD_S_CancelSitRef#CMD_S_CancelSitRef ret (return value: CMD_S_CancelSitRef)
        
return nil
