
--------------------------------
-- @module tagLoginAwardRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#tagLoginAwardRef] cbLoginCount
-- @param self
-- @param #unsigned char VAR
-- @return tagLoginAwardRef#tagLoginAwardRef self (return value: tagLoginAwardRef)

--------------------------------
-- 
-- @function [parent=#tagLoginAwardRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return tagLoginAwardRef#tagLoginAwardRef self (return value: tagLoginAwardRef)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#tagLoginAwardRef] wAwardCount
-- @param self
-- @param #unsigned short VAR
-- @return tagLoginAwardRef#tagLoginAwardRef self (return value: tagLoginAwardRef)

--------------------------------
-- 
-- @function [parent=#tagLoginAwardRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#tagLoginAwardRef] cbAwardType
-- @param self
-- @param #unsigned char VAR
-- @return tagLoginAwardRef#tagLoginAwardRef self (return value: tagLoginAwardRef)

--------------------------------
-- 
-- @function [parent=#tagLoginAwardRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#tagLoginAwardRef] cbAwardSubType
-- @param self
-- @param #unsigned char VAR
-- @return tagLoginAwardRef#tagLoginAwardRef self (return value: tagLoginAwardRef)

--------------------------------
-- 
-- @function [parent=#tagLoginAwardRef] createWithNotify 
-- @param self
-- @return tagLoginAwardRef#tagLoginAwardRef ret (return value: tagLoginAwardRef)
        
return nil
