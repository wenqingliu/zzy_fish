
--------------------------------
-- @module CMD_S_ChangeUserScoreRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_ChangeUserScoreRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_ChangeUserScoreRef#CMD_S_ChangeUserScoreRef self (return value: CMD_S_ChangeUserScoreRef)
        
--------------------------------
-- @overload self, double         
-- @overload self         
-- @function [parent=#CMD_S_ChangeUserScoreRef] lScore
-- @param self
-- @param #double VAR
-- @return CMD_S_ChangeUserScoreRef#CMD_S_ChangeUserScoreRef self (return value: CMD_S_ChangeUserScoreRef)

--------------------------------
-- @overload self, double         
-- @overload self         
-- @function [parent=#CMD_S_ChangeUserScoreRef] lCurrentBankerScore
-- @param self
-- @param #double VAR
-- @return CMD_S_ChangeUserScoreRef#CMD_S_ChangeUserScoreRef self (return value: CMD_S_ChangeUserScoreRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_ChangeUserScoreRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_ChangeUserScoreRef] wChairID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_ChangeUserScoreRef#CMD_S_ChangeUserScoreRef self (return value: CMD_S_ChangeUserScoreRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_ChangeUserScoreRef] wCurrentBankerChairID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_ChangeUserScoreRef#CMD_S_ChangeUserScoreRef self (return value: CMD_S_ChangeUserScoreRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_ChangeUserScoreRef] cbBankerTime
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_ChangeUserScoreRef#CMD_S_ChangeUserScoreRef self (return value: CMD_S_ChangeUserScoreRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_ChangeUserScoreRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_ChangeUserScoreRef] createWithNotify 
-- @param self
-- @return CMD_S_ChangeUserScoreRef#CMD_S_ChangeUserScoreRef ret (return value: CMD_S_ChangeUserScoreRef)
        
return nil
