
--------------------------------
-- @module CMD_S_CancelBankerRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_CancelBankerRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_S_CancelBankerRef] szCancelUser
-- @param self
-- @param #char VAR
-- @return CMD_S_CancelBankerRef#CMD_S_CancelBankerRef self (return value: CMD_S_CancelBankerRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_CancelBankerRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_CancelBankerRef#CMD_S_CancelBankerRef self (return value: CMD_S_CancelBankerRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_CancelBankerRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_CancelBankerRef] wChairID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_CancelBankerRef#CMD_S_CancelBankerRef self (return value: CMD_S_CancelBankerRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_CancelBankerRef] createWithNotify 
-- @param self
-- @return CMD_S_CancelBankerRef#CMD_S_CancelBankerRef ret (return value: CMD_S_CancelBankerRef)
        
return nil
