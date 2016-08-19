
--------------------------------
-- @module CMD_MB_UpdateNotifyRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_MB_UpdateNotifyRef] cbAdviceUpdate
-- @param self
-- @param #unsigned char VAR
-- @return CMD_MB_UpdateNotifyRef#CMD_MB_UpdateNotifyRef self (return value: CMD_MB_UpdateNotifyRef)

--------------------------------
-- 
-- @function [parent=#CMD_MB_UpdateNotifyRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_MB_UpdateNotifyRef#CMD_MB_UpdateNotifyRef self (return value: CMD_MB_UpdateNotifyRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_MB_UpdateNotifyRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_MB_UpdateNotifyRef] cbMustUpdate
-- @param self
-- @param #unsigned char VAR
-- @return CMD_MB_UpdateNotifyRef#CMD_MB_UpdateNotifyRef self (return value: CMD_MB_UpdateNotifyRef)

--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_MB_UpdateNotifyRef] dwCurrentVersion
-- @param self
-- @param #unsigned int VAR
-- @return CMD_MB_UpdateNotifyRef#CMD_MB_UpdateNotifyRef self (return value: CMD_MB_UpdateNotifyRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_MB_UpdateNotifyRef] cbHotUpdate
-- @param self
-- @param #unsigned char VAR
-- @return CMD_MB_UpdateNotifyRef#CMD_MB_UpdateNotifyRef self (return value: CMD_MB_UpdateNotifyRef)

--------------------------------
-- 
-- @function [parent=#CMD_MB_UpdateNotifyRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_MB_UpdateNotifyRef] szHotVer
-- @param self
-- @param #char VAR
-- @return CMD_MB_UpdateNotifyRef#CMD_MB_UpdateNotifyRef self (return value: CMD_MB_UpdateNotifyRef)

--------------------------------
-- 
-- @function [parent=#CMD_MB_UpdateNotifyRef] createWithNotify 
-- @param self
-- @return CMD_MB_UpdateNotifyRef#CMD_MB_UpdateNotifyRef ret (return value: CMD_MB_UpdateNotifyRef)
        
return nil
