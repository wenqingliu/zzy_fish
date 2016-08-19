
--------------------------------
-- @module CMD_GF_S_UserExpressionRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GF_S_UserExpressionRef] dwTargetUserID
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GF_S_UserExpressionRef#CMD_GF_S_UserExpressionRef self (return value: CMD_GF_S_UserExpressionRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_GF_S_UserExpressionRef] wItemIndex
-- @param self
-- @param #unsigned short VAR
-- @return CMD_GF_S_UserExpressionRef#CMD_GF_S_UserExpressionRef self (return value: CMD_GF_S_UserExpressionRef)

--------------------------------
-- 
-- @function [parent=#CMD_GF_S_UserExpressionRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_GF_S_UserExpressionRef#CMD_GF_S_UserExpressionRef self (return value: CMD_GF_S_UserExpressionRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GF_S_UserExpressionRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GF_S_UserExpressionRef] dwSendUserID
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GF_S_UserExpressionRef#CMD_GF_S_UserExpressionRef self (return value: CMD_GF_S_UserExpressionRef)

--------------------------------
-- 
-- @function [parent=#CMD_GF_S_UserExpressionRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_GF_S_UserExpressionRef] createWithNotify 
-- @param self
-- @return CMD_GF_S_UserExpressionRef#CMD_GF_S_UserExpressionRef ret (return value: CMD_GF_S_UserExpressionRef)
        
return nil
