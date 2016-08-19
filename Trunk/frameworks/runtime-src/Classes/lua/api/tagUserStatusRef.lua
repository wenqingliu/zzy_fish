
--------------------------------
-- @module tagUserStatusRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#tagUserStatusRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return tagUserStatusRef#tagUserStatusRef self (return value: tagUserStatusRef)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#tagUserStatusRef] wTableID
-- @param self
-- @param #unsigned short VAR
-- @return tagUserStatusRef#tagUserStatusRef self (return value: tagUserStatusRef)

--------------------------------
-- 
-- @function [parent=#tagUserStatusRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#tagUserStatusRef] wChairID
-- @param self
-- @param #unsigned short VAR
-- @return tagUserStatusRef#tagUserStatusRef self (return value: tagUserStatusRef)

--------------------------------
-- 
-- @function [parent=#tagUserStatusRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#tagUserStatusRef] cbUserStatus
-- @param self
-- @param #unsigned char VAR
-- @return tagUserStatusRef#tagUserStatusRef self (return value: tagUserStatusRef)

--------------------------------
-- 
-- @function [parent=#tagUserStatusRef] createWithNotify 
-- @param self
-- @return tagUserStatusRef#tagUserStatusRef ret (return value: tagUserStatusRef)
        
return nil
