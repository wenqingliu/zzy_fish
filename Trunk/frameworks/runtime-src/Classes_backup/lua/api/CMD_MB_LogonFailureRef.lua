
--------------------------------
-- @module CMD_MB_LogonFailureRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_MB_LogonFailureRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CMD_MB_LogonFailureRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_MB_LogonFailureRef#CMD_MB_LogonFailureRef self (return value: CMD_MB_LogonFailureRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_MB_LogonFailureRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_MB_LogonFailureRef] szDescribeString
-- @param self
-- @param #char VAR
-- @return CMD_MB_LogonFailureRef#CMD_MB_LogonFailureRef self (return value: CMD_MB_LogonFailureRef)

--------------------------------
-- @overload self, int         
-- @overload self         
-- @function [parent=#CMD_MB_LogonFailureRef] lResultCode
-- @param self
-- @param #int VAR
-- @return CMD_MB_LogonFailureRef#CMD_MB_LogonFailureRef self (return value: CMD_MB_LogonFailureRef)

--------------------------------
-- 
-- @function [parent=#CMD_MB_LogonFailureRef] createWithNotify 
-- @param self
-- @return CMD_MB_LogonFailureRef#CMD_MB_LogonFailureRef ret (return value: CMD_MB_LogonFailureRef)
        
return nil
