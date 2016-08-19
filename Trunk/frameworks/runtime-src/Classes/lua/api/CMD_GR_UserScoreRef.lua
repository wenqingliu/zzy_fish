
--------------------------------
-- @module CMD_GR_UserScoreRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CMD_GR_UserScoreRef] setUserScore 
-- @param self
-- @param #tagUserScoreRef var
-- @return CMD_GR_UserScoreRef#CMD_GR_UserScoreRef self (return value: CMD_GR_UserScoreRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserScoreRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_GR_UserScoreRef#CMD_GR_UserScoreRef self (return value: CMD_GR_UserScoreRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserScoreRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned int         
-- @overload self         
-- @function [parent=#CMD_GR_UserScoreRef] dwUserID
-- @param self
-- @param #unsigned int VAR
-- @return CMD_GR_UserScoreRef#CMD_GR_UserScoreRef self (return value: CMD_GR_UserScoreRef)

--------------------------------
-- 
-- @function [parent=#CMD_GR_UserScoreRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserScoreRef] getUserScore 
-- @param self
-- @return tagUserScoreRef#tagUserScoreRef ret (return value: tagUserScoreRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserScoreRef] initRef 
-- @param self
-- @return CMD_GR_UserScoreRef#CMD_GR_UserScoreRef self (return value: CMD_GR_UserScoreRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_GR_UserScoreRef] createWithNotify 
-- @param self
-- @return CMD_GR_UserScoreRef#CMD_GR_UserScoreRef ret (return value: CMD_GR_UserScoreRef)
        
return nil
