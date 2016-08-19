
--------------------------------
-- @module CMD_S_SendCardRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_SendCardRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_SendCardRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_SendCardRef#CMD_S_SendCardRef self (return value: CMD_S_SendCardRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_SendCardRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, int, int, unsigned char         
-- @overload self, int, int         
-- @function [parent=#CMD_S_SendCardRef] cbCardData
-- @param self
-- @param #int index1
-- @param #int index2
-- @param #unsigned char VAR
-- @return CMD_S_SendCardRef#CMD_S_SendCardRef self (return value: CMD_S_SendCardRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_SendCardRef] create 
-- @param self
-- @return CMD_S_SendCardRef#CMD_S_SendCardRef ret (return value: CMD_S_SendCardRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_SendCardRef] createWithNotify 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_SendCardRef#CMD_S_SendCardRef ret (return value: CMD_S_SendCardRef)
        
return nil
