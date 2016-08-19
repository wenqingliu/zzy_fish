
--------------------------------
-- @module CMD_S_HunCancelBankerRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_HunCancelBankerRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_S_HunCancelBankerRef] szCancelUser
-- @param self
-- @param #char VAR
-- @return CMD_S_HunCancelBankerRef#CMD_S_HunCancelBankerRef self (return value: CMD_S_HunCancelBankerRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunCancelBankerRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_HunCancelBankerRef#CMD_S_HunCancelBankerRef self (return value: CMD_S_HunCancelBankerRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_HunCancelBankerRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_HunCancelBankerRef] wChairID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_HunCancelBankerRef#CMD_S_HunCancelBankerRef self (return value: CMD_S_HunCancelBankerRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunCancelBankerRef] createWithNotify 
-- @param self
-- @return CMD_S_HunCancelBankerRef#CMD_S_HunCancelBankerRef ret (return value: CMD_S_HunCancelBankerRef)
        
return nil
