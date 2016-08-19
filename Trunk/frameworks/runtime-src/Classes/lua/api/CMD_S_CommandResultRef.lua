
--------------------------------
-- @module CMD_S_CommandResultRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_CommandResultRef] cbExtendData 
-- @param self
-- @param #int index1
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_CommandResultRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_CommandResultRef#CMD_S_CommandResultRef self (return value: CMD_S_CommandResultRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_CommandResultRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_CommandResultRef] cbAckType
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_CommandResultRef#CMD_S_CommandResultRef self (return value: CMD_S_CommandResultRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_CommandResultRef] cbResult
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_CommandResultRef#CMD_S_CommandResultRef self (return value: CMD_S_CommandResultRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_CommandResultRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_CommandResultRef] createWithNotify 
-- @param self
-- @return CMD_S_CommandResultRef#CMD_S_CommandResultRef ret (return value: CMD_S_CommandResultRef)
        
return nil
