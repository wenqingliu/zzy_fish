
--------------------------------
-- @module CMD_S_HunChangeUserScoreRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_HunChangeUserScoreRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_HunChangeUserScoreRef#CMD_S_HunChangeUserScoreRef self (return value: CMD_S_HunChangeUserScoreRef)
        
--------------------------------
-- @overload self, double         
-- @overload self         
-- @function [parent=#CMD_S_HunChangeUserScoreRef] lScore
-- @param self
-- @param #double VAR
-- @return CMD_S_HunChangeUserScoreRef#CMD_S_HunChangeUserScoreRef self (return value: CMD_S_HunChangeUserScoreRef)

--------------------------------
-- @overload self, double         
-- @overload self         
-- @function [parent=#CMD_S_HunChangeUserScoreRef] lCurrentBankerScore
-- @param self
-- @param #double VAR
-- @return CMD_S_HunChangeUserScoreRef#CMD_S_HunChangeUserScoreRef self (return value: CMD_S_HunChangeUserScoreRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunChangeUserScoreRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_HunChangeUserScoreRef] wChairID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_HunChangeUserScoreRef#CMD_S_HunChangeUserScoreRef self (return value: CMD_S_HunChangeUserScoreRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_HunChangeUserScoreRef] wCurrentBankerChairID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_HunChangeUserScoreRef#CMD_S_HunChangeUserScoreRef self (return value: CMD_S_HunChangeUserScoreRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_HunChangeUserScoreRef] cbBankerTime
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_HunChangeUserScoreRef#CMD_S_HunChangeUserScoreRef self (return value: CMD_S_HunChangeUserScoreRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunChangeUserScoreRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_HunChangeUserScoreRef] createWithNotify 
-- @param self
-- @return CMD_S_HunChangeUserScoreRef#CMD_S_HunChangeUserScoreRef ret (return value: CMD_S_HunChangeUserScoreRef)
        
return nil
