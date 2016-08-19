
--------------------------------
-- @module CMD_S_ChangeBankerRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_ChangeBankerRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_ChangeBankerRef] lBankerScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_ChangeBankerRef#CMD_S_ChangeBankerRef self (return value: CMD_S_ChangeBankerRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_ChangeBankerRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_ChangeBankerRef#CMD_S_ChangeBankerRef self (return value: CMD_S_ChangeBankerRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_ChangeBankerRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_ChangeBankerRef] wBankerUser
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_ChangeBankerRef#CMD_S_ChangeBankerRef self (return value: CMD_S_ChangeBankerRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_ChangeBankerRef] createWithNotify 
-- @param self
-- @return CMD_S_ChangeBankerRef#CMD_S_ChangeBankerRef ret (return value: CMD_S_ChangeBankerRef)
        
return nil
