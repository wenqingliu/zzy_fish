
--------------------------------
-- @module CMD_GR_ConfigServerRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_GR_ConfigServerRef] wChairCount
-- @param self
-- @param #unsigned short VAR
-- @return CMD_GR_ConfigServerRef#CMD_GR_ConfigServerRef self (return value: CMD_GR_ConfigServerRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_ConfigServerRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_GR_ConfigServerRef#CMD_GR_ConfigServerRef self (return value: CMD_GR_ConfigServerRef)
        
--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GR_ConfigServerRef] dwServerRule
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GR_ConfigServerRef#CMD_GR_ConfigServerRef self (return value: CMD_GR_ConfigServerRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_GR_ConfigServerRef] wServerType
-- @param self
-- @param #unsigned short VAR
-- @return CMD_GR_ConfigServerRef#CMD_GR_ConfigServerRef self (return value: CMD_GR_ConfigServerRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_ConfigServerRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_GR_ConfigServerRef] wTableCount
-- @param self
-- @param #unsigned short VAR
-- @return CMD_GR_ConfigServerRef#CMD_GR_ConfigServerRef self (return value: CMD_GR_ConfigServerRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_ConfigServerRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_ConfigServerRef] createWithNotify 
-- @param self
-- @return CMD_GR_ConfigServerRef#CMD_GR_ConfigServerRef ret (return value: CMD_GR_ConfigServerRef)
        
return nil
