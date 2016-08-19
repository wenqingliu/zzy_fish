
--------------------------------
-- @module CMD_GR_RequestFailureRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_GR_RequestFailureRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_RequestFailureRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_GR_RequestFailureRef#CMD_GR_RequestFailureRef self (return value: CMD_GR_RequestFailureRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_RequestFailureRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_GR_RequestFailureRef] szDescribeString
-- @param self
-- @param #char VAR
-- @return CMD_GR_RequestFailureRef#CMD_GR_RequestFailureRef self (return value: CMD_GR_RequestFailureRef)

--------------------------------
-- @overload self, int         
-- @overload self         
-- @function [parent=#CMD_GR_RequestFailureRef] lErrorCode
-- @param self
-- @param #int VAR
-- @return CMD_GR_RequestFailureRef#CMD_GR_RequestFailureRef self (return value: CMD_GR_RequestFailureRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_RequestFailureRef] createWithNotify 
-- @param self
-- @return CMD_GR_RequestFailureRef#CMD_GR_RequestFailureRef ret (return value: CMD_GR_RequestFailureRef)
        
return nil
