
--------------------------------
-- @module tagGameServerRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#tagGameServerRef] szServerName
-- @param self
-- @param #char VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#tagGameServerRef] wSortID
-- @param self
-- @param #unsigned short VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- @overload self, int         
-- @overload self         
-- @function [parent=#tagGameServerRef] lCellScore
-- @param self
-- @param #int VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#tagGameServerRef] dwFullCount
-- @param self
-- @param #unsigned int VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- 
-- @function [parent=#tagGameServerRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#tagGameServerRef] wServerID
-- @param self
-- @param #unsigned short VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#tagGameServerRef] wKindID
-- @param self
-- @param #unsigned short VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#tagGameServerRef] wNodeID
-- @param self
-- @param #unsigned short VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- 
-- @function [parent=#tagGameServerRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#tagGameServerRef] dwOnLineCount
-- @param self
-- @param #unsigned int VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#tagGameServerRef] szServerAddr
-- @param self
-- @param #char VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#tagGameServerRef] wServerPort
-- @param self
-- @param #unsigned short VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#tagGameServerRef] lMaxEnterScore
-- @param self
-- @param #long long VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#tagGameServerRef] lMinEnterScore
-- @param self
-- @param #long long VAR
-- @return tagGameServerRef#tagGameServerRef self (return value: tagGameServerRef)

--------------------------------
-- 
-- @function [parent=#tagGameServerRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#tagGameServerRef] createWithDataArray 
-- @param self
-- @param #CNotify notify
-- @param #int index
-- @return tagGameServerRef#tagGameServerRef ret (return value: tagGameServerRef)
        
--------------------------------
-- 
-- @function [parent=#tagGameServerRef] createWithNotify 
-- @param self
-- @return tagGameServerRef#tagGameServerRef ret (return value: tagGameServerRef)
        
return nil
