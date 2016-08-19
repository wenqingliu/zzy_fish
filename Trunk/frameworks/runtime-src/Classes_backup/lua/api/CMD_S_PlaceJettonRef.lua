
--------------------------------
-- @module CMD_S_PlaceJettonRef
-- @extend CMD_BASE
-- @parent_module jt

--------------------------------
-- @overload self, bool         
-- @overload self         
-- @function [parent=#CMD_S_PlaceJettonRef] bIsAndroid
-- @param self
-- @param #bool VAR
-- @return CMD_S_PlaceJettonRef#CMD_S_PlaceJettonRef self (return value: CMD_S_PlaceJettonRef)

--------------------------------
-- @overload self, long long         
-- @overload self         
-- @function [parent=#CMD_S_PlaceJettonRef] lJettonScore
-- @param self
-- @param #long long VAR
-- @return CMD_S_PlaceJettonRef#CMD_S_PlaceJettonRef self (return value: CMD_S_PlaceJettonRef)

--------------------------------
-- @overload self, unsigned char         
-- @overload self         
-- @function [parent=#CMD_S_PlaceJettonRef] cbJettonArea
-- @param self
-- @param #unsigned char VAR
-- @return CMD_S_PlaceJettonRef#CMD_S_PlaceJettonRef self (return value: CMD_S_PlaceJettonRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_PlaceJettonRef] setStruct 
-- @param self
-- @param #CNotify notify
-- @return CMD_S_PlaceJettonRef#CMD_S_PlaceJettonRef self (return value: CMD_S_PlaceJettonRef)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_PlaceJettonRef] getSize 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- @overload self, unsigned short         
-- @overload self         
-- @function [parent=#CMD_S_PlaceJettonRef] wChairID
-- @param self
-- @param #unsigned short VAR
-- @return CMD_S_PlaceJettonRef#CMD_S_PlaceJettonRef self (return value: CMD_S_PlaceJettonRef)

--------------------------------
-- 
-- @function [parent=#CMD_S_PlaceJettonRef] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CMD_S_PlaceJettonRef] createWithNotify 
-- @param self
-- @return CMD_S_PlaceJettonRef#CMD_S_PlaceJettonRef ret (return value: CMD_S_PlaceJettonRef)
        
return nil
