
--------------------------------
-- @module CMD_GR_S_UserChatRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GR_S_UserChatRef] dwChatColor
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GR_S_UserChatRef#CMD_GR_S_UserChatRef self (return value: CMD_GR_S_UserChatRef)

--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GR_S_UserChatRef] dwTargetUserID
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GR_S_UserChatRef#CMD_GR_S_UserChatRef self (return value: CMD_GR_S_UserChatRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_S_UserChatRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_GR_S_UserChatRef#CMD_GR_S_UserChatRef self (return value: CMD_GR_S_UserChatRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_S_UserChatRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GR_S_UserChatRef] dwSendUserID
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GR_S_UserChatRef#CMD_GR_S_UserChatRef self (return value: CMD_GR_S_UserChatRef)

--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_GR_S_UserChatRef] szChatString
-- @param self
-- @param #char VAR
-- @return CMD_GR_S_UserChatRef#CMD_GR_S_UserChatRef self (return value: CMD_GR_S_UserChatRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_S_UserChatRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_GR_S_UserChatRef] wChatLength
-- @param self
-- @param #unsigned short VAR
-- @return CMD_GR_S_UserChatRef#CMD_GR_S_UserChatRef self (return value: CMD_GR_S_UserChatRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_S_UserChatRef] createWithNotify 
-- @param self
-- @return CMD_GR_S_UserChatRef#CMD_GR_S_UserChatRef ret (return value: CMD_GR_S_UserChatRef)
        
return nil
