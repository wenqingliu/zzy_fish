
--------------------------------
-- @module CMD_GR_S_SendTrumpetRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GR_S_SendTrumpetRef] TrumpetColor
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GR_S_SendTrumpetRef#CMD_GR_S_SendTrumpetRef self (return value: CMD_GR_S_SendTrumpetRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_GR_S_SendTrumpetRef] wPropertyIndex
-- @param self
-- @param #unsigned short VAR
-- @return CMD_GR_S_SendTrumpetRef#CMD_GR_S_SendTrumpetRef self (return value: CMD_GR_S_SendTrumpetRef)

--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_GR_S_SendTrumpetRef] szSendNickName
-- @param self
-- @param #char VAR
-- @return CMD_GR_S_SendTrumpetRef#CMD_GR_S_SendTrumpetRef self (return value: CMD_GR_S_SendTrumpetRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_S_SendTrumpetRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_GR_S_SendTrumpetRef#CMD_GR_S_SendTrumpetRef self (return value: CMD_GR_S_SendTrumpetRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_S_SendTrumpetRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_GR_S_SendTrumpetRef] szTrumpetContent
-- @param self
-- @param #char VAR
-- @return CMD_GR_S_SendTrumpetRef#CMD_GR_S_SendTrumpetRef self (return value: CMD_GR_S_SendTrumpetRef)

--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GR_S_SendTrumpetRef] dwSendUserID
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GR_S_SendTrumpetRef#CMD_GR_S_SendTrumpetRef self (return value: CMD_GR_S_SendTrumpetRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_S_SendTrumpetRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_S_SendTrumpetRef] createWithNotify 
-- @param self
-- @return CMD_GR_S_SendTrumpetRef#CMD_GR_S_SendTrumpetRef ret (return value: CMD_GR_S_SendTrumpetRef)
        
return nil
