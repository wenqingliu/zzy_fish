
--------------------------------
-- @module CMD_S_HunGameEndRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunGameEndRef] lBankerScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunGameEndRef] lRevenue
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunGameEndRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)
        
--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_HunGameEndRef] cbLeftCardCount
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)

--------------------------------
-- @overload self, int         
-- @overload self         
-- @function [parent=#CMD_S_HunGameEndRef] nBankerTime
-- @param self
-- @param #int VAR
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunGameEndRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunGameEndRef] lUserScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_HunGameEndRef] bcFirstCard
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_HunGameEndRef] cbTimeLeave
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunGameEndRef] lUserReturnScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunGameEndRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_HunGameEndRef] cbTableCardArray 
-- @param self
-- @param #int index1
-- @param #int index2
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunGameEndRef] lBankerTotallScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef self (return value: CMD_S_HunGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunGameEndRef] createWithNotify 
-- @param self
-- @return CMD_S_HunGameEndRef#CMD_S_HunGameEndRef ret (return value: CMD_S_HunGameEndRef)
        
return nil
