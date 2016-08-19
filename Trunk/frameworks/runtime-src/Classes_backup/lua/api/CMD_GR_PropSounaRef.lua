
--------------------------------
-- @module CMD_GR_PropSounaRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GR_PropSounaRef] playerID
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GR_PropSounaRef#CMD_GR_PropSounaRef self (return value: CMD_GR_PropSounaRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_GR_PropSounaRef] wGameID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_GR_PropSounaRef#CMD_GR_PropSounaRef self (return value: CMD_GR_PropSounaRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_PropSounaRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_GR_PropSounaRef#CMD_GR_PropSounaRef self (return value: CMD_GR_PropSounaRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_PropSounaRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_GR_PropSounaRef] szNickName
-- @param self
-- @param #char VAR
-- @return CMD_GR_PropSounaRef#CMD_GR_PropSounaRef self (return value: CMD_GR_PropSounaRef)

--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_GR_PropSounaRef] wSuonaType
-- @param self
-- @param #unsigned short VAR
-- @return CMD_GR_PropSounaRef#CMD_GR_PropSounaRef self (return value: CMD_GR_PropSounaRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_PropSounaRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CMD_GR_PropSounaRef] szMsg
-- @param self
-- @param #char VAR
-- @return CMD_GR_PropSounaRef#CMD_GR_PropSounaRef self (return value: CMD_GR_PropSounaRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_PropSounaRef] createWithNotify 
-- @param self
-- @return CMD_GR_PropSounaRef#CMD_GR_PropSounaRef ret (return value: CMD_GR_PropSounaRef)
        
return nil
