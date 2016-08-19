
--------------------------------
-- @module CMD_S_GameEndRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_GameEndRef] lBankerScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_GameEndRef] lRevenue
-- @param self
-- @param #long long VAR
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_GameEndRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)
        
--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_GameEndRef] cbLeftCardCount
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)

--------------------------------
-- @overload self, int         
-- @overload self         
-- @function [parent=#CMD_S_GameEndRef] nBankerTime
-- @param self
-- @param #int VAR
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_GameEndRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_GameEndRef] lUserScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_GameEndRef] bcFirstCard
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_GameEndRef] cbTimeLeave
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_GameEndRef] lUserReturnScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_GameEndRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_GameEndRef] cbTableCardArray 
-- @param self
-- @param #int index1
-- @param #int index2
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_GameEndRef] lBankerTotallScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef self (return value: CMD_S_GameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_GameEndRef] createWithNotify 
-- @param self
-- @return CMD_S_GameEndRef#CMD_S_GameEndRef ret (return value: CMD_S_GameEndRef)
        
return nil
