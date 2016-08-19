
--------------------------------
-- @module CMD_S_StatusPlayRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] lEndUserScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] lBankerScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] lEndRevenue
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] cbTimeLeave
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusPlayRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] szGameRoomName
-- @param self
-- @param #char VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] lBankerWinScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- @overload self, bool         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] bEnableSysBanker
-- @param self
-- @param #bool VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusPlayRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_StatusPlayRef] lUserJettonScore 
-- @param self
-- @param #int index1
-- @return long long#long long ret (return value: long long)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] lApplyBankerCondition
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] lAreaLimitScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusPlayRef] lAllJettonScore 
-- @param self
-- @param #int index1
-- @return long long#long long ret (return value: long long)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] cbBankerTime
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] cbGameStatus
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] lEndBankerScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusPlayRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] lUserMaxScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusPlayRef] cbTableCardArray 
-- @param self
-- @param #int index1
-- @param #int index2
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] wBankerUser
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_StatusPlayRef] lEndUserReturnScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef self (return value: CMD_S_StatusPlayRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_StatusPlayRef] createWithNotify 
-- @param self
-- @return CMD_S_StatusPlayRef#CMD_S_StatusPlayRef ret (return value: CMD_S_StatusPlayRef)
        
return nil
