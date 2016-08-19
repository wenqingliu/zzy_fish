
--------------------------------
-- @module CMD_S_ApplySitRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_ApplySitRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_ApplySitRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_ApplySitRef#CMD_S_ApplySitRef self (return value: CMD_S_ApplySitRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_ApplySitRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_ApplySitRef] wSitChairID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_ApplySitRef#CMD_S_ApplySitRef self (return value: CMD_S_ApplySitRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_ApplySitRef] wApplySitID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_ApplySitRef#CMD_S_ApplySitRef self (return value: CMD_S_ApplySitRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_ApplySitRef] createWithNotify 
-- @param self
-- @return CMD_S_ApplySitRef#CMD_S_ApplySitRef ret (return value: CMD_S_ApplySitRef)
        
return nil
