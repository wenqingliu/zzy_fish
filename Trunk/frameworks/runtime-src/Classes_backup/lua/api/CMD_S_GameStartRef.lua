
--------------------------------
-- @module CMD_S_GameStartRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_GameStartRef] lBankerScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_GameStartRef#CMD_S_GameStartRef self (return value: CMD_S_GameStartRef)

--------------------------------
-- @overload self, bool         
-- @overload self         
-- @function [parent=#CMD_S_GameStartRef] bContiueCard
-- @param self
-- @param #bool VAR
-- @return CMD_S_GameStartRef#CMD_S_GameStartRef self (return value: CMD_S_GameStartRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_GameStartRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_GameStartRef#CMD_S_GameStartRef self (return value: CMD_S_GameStartRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_GameStartRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, int         
-- @overload self         
-- @function [parent=#CMD_S_GameStartRef] nChipRobotCount
-- @param self
-- @param #int VAR
-- @return CMD_S_GameStartRef#CMD_S_GameStartRef self (return value: CMD_S_GameStartRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_GameStartRef] cbTimeLeave
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_GameStartRef#CMD_S_GameStartRef self (return value: CMD_S_GameStartRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_GameStartRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_GameStartRef] lUserMaxScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_GameStartRef#CMD_S_GameStartRef self (return value: CMD_S_GameStartRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_GameStartRef] wBankerUser
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_GameStartRef#CMD_S_GameStartRef self (return value: CMD_S_GameStartRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_GameStartRef] createWithNotify 
-- @param self
-- @return CMD_S_GameStartRef#CMD_S_GameStartRef ret (return value: CMD_S_GameStartRef)
        
return nil
