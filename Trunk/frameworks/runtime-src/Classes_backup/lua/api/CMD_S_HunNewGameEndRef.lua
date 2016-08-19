
--------------------------------
-- @module CMD_S_HunNewGameEndRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] getTagAwardFirst 
-- @param self
-- @return tagAwardFirstRef#tagAwardFirstRef ret (return value: tagAwardFirstRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] lRevenue
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] bcFirstCard
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] gettagWinInfo 
-- @param self
-- @param #int index
-- @return tagUserWLInfoRef#tagUserWLInfoRef ret (return value: tagUserWLInfoRef)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] lBankerScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] settagLoseInfo 
-- @param self
-- @param #tagUserWLInfoRef var
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] cbTableCardArray 
-- @param self
-- @param #int index1
-- @param #int index2
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- @overload self, int         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] nBankerTime
-- @param self
-- @param #int VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] lStorageStart
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] setTagAwardFirst 
-- @param self
-- @param #tagAwardFirstRef var
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] initRef 
-- @param self
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)
        
--------------------------------
-- @overload self, int         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] nRedPackage
-- @param self
-- @param #int VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] settagWinInfo 
-- @param self
-- @param #tagUserWLInfoRef var
-- @param #int index
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] gettagLoseInfo 
-- @param self
-- @return tagUserWLInfoRef#tagUserWLInfoRef ret (return value: tagUserWLInfoRef)
        
--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] lExtraScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] lUserReturnScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] lBankerTotallScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] cbRedTimeLeave
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] cbLeftCardCount
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] lUserScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_HunNewGameEndRef] cbTimeLeave
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef self (return value: CMD_S_HunNewGameEndRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_HunNewGameEndRef] createWithNotify 
-- @param self
-- @return CMD_S_HunNewGameEndRef#CMD_S_HunNewGameEndRef ret (return value: CMD_S_HunNewGameEndRef)
        
return nil
