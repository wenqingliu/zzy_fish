
--------------------------------
-- @module CMD_CM_SystemMessageRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_CM_SystemMessageRef] wLength
-- @param self
-- @param #unsigned short VAR
-- @return CMD_CM_SystemMessageRef#CMD_CM_SystemMessageRef self (return value: CMD_CM_SystemMessageRef)

--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_CM_SystemMessageRef] szString
-- @param self
-- @param #char VAR
-- @return CMD_CM_SystemMessageRef#CMD_CM_SystemMessageRef self (return value: CMD_CM_SystemMessageRef)

--------------------------------
-- 
-- @function [parent=#CMD_CM_SystemMessageRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_CM_SystemMessageRef#CMD_CM_SystemMessageRef self (return value: CMD_CM_SystemMessageRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_CM_SystemMessageRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CMD_CM_SystemMessageRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_CM_SystemMessageRef] wType
-- @param self
-- @param #unsigned short VAR
-- @return CMD_CM_SystemMessageRef#CMD_CM_SystemMessageRef self (return value: CMD_CM_SystemMessageRef)

--------------------------------
-- 
-- @function [parent=#CMD_CM_SystemMessageRef] createWithNotify 
-- @param self
-- @return CMD_CM_SystemMessageRef#CMD_CM_SystemMessageRef ret (return value: CMD_CM_SystemMessageRef)
        
return nil
