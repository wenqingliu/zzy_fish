
--------------------------------
-- @module CMD_S_StatusFreeRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] lBankerScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusFreeRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] szGameRoomName
-- @param self
-- @param #char VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] lBankerWinScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- @overload self, bool         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] bEnableSysBanker
-- @param self
-- @param #bool VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusFreeRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] lApplyBankerCondition
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] lAreaLimitScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] cbTimeLeave
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] cbBankerTime
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusFreeRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] lUserMaxScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_StatusFreeRef] wBankerUser
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef self (return value: CMD_S_StatusFreeRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusFreeRef] createWithNotify 
-- @param self
-- @return CMD_S_StatusFreeRef#CMD_S_StatusFreeRef ret (return value: CMD_S_StatusFreeRef)
        
return nil
