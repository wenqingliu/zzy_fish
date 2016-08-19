
--------------------------------
-- @module CMD_GR_UserStatusRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_GR_UserStatusRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_GR_UserStatusRef#CMD_GR_UserStatusRef self (return value: CMD_GR_UserStatusRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserStatusRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserStatusRef] initRef 
-- @param self
-- @return CMD_GR_UserStatusRef#CMD_GR_UserStatusRef self (return value: CMD_GR_UserStatusRef)
        
--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GR_UserStatusRef] dwUserID
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GR_UserStatusRef#CMD_GR_UserStatusRef self (return value: CMD_GR_UserStatusRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_UserStatusRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserStatusRef] setUserStatus 
-- @param self
-- @param #tagUserStatusRef var
-- @return CMD_GR_UserStatusRef#CMD_GR_UserStatusRef self (return value: CMD_GR_UserStatusRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserStatusRef] getUserStatus 
-- @param self
-- @return tagUserStatusRef#tagUserStatusRef ret (return value: tagUserStatusRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserStatusRef] createWithNotify 
-- @param self
-- @return CMD_GR_UserStatusRef#CMD_GR_UserStatusRef ret (return value: CMD_GR_UserStatusRef)
        
return nil
