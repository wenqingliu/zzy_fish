
--------------------------------
-- @module tagUserWLInfoRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#tagUserWLInfoRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#tagUserWLInfoRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return tagUserWLInfoRef#tagUserWLInfoRef self (return value: tagUserWLInfoRef)
        
--------------------------------
-- 
-- @function [parent=#tagUserWLInfoRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#tagUserWLInfoRef] wChairID
-- @param self
-- @param #unsigned short VAR
-- @return tagUserWLInfoRef#tagUserWLInfoRef self (return value: tagUserWLInfoRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#tagUserWLInfoRef] lJettonScore
-- @param self
-- @param #long long VAR
-- @return tagUserWLInfoRef#tagUserWLInfoRef self (return value: tagUserWLInfoRef)

--------------------------------
-- 
-- @function [parent=#tagUserWLInfoRef] createWithNotify 
-- @param self
-- @return tagUserWLInfoRef#tagUserWLInfoRef ret (return value: tagUserWLInfoRef)
        
return nil
