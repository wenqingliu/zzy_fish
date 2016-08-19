
--------------------------------
-- @module CNotify
-- @extend Ref,CSpriteParamData
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CNotify] getMainType 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CNotify] getObject 
-- @param self
-- @return Ref#Ref ret (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#CNotify] setTypeData 
-- @param self
-- @param #int nTypeData
-- @return CNotify#CNotify self (return value: CNotify)
        
--------------------------------
-- 
-- @function [parent=#CNotify] setObject 
-- @param self
-- @param #cc.Ref object
-- @return CNotify#CNotify self (return value: CNotify)
        
--------------------------------
-- 
-- @function [parent=#CNotify] getMainString 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CNotify] getEventName 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CNotify] getSubType 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CNotify] setMainType 
-- @param self
-- @param #int nMainType
-- @return CNotify#CNotify self (return value: CNotify)
        
--------------------------------
-- 
-- @function [parent=#CNotify] getResult 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CNotify] getTypeData 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CNotify] getSize 
-- @param self
-- @return unsigned short#unsigned short ret (return value: unsigned short)
        
--------------------------------
-- 
-- @function [parent=#CNotify] setEventName 
-- @param self
-- @param #string name
-- @return CNotify#CNotify self (return value: CNotify)
        
--------------------------------
-- 
-- @function [parent=#CNotify] getSubString 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CNotify] getData 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CNotify] setSubType 
-- @param self
-- @param #int nSubType
-- @return CNotify#CNotify self (return value: CNotify)
        
--------------------------------
-- @overload self, void         
-- @overload self, void, unsigned short, int         
-- @overload self         
-- @function [parent=#CNotify] create
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @param #int result
-- @return CNotify#CNotify ret (return value: CNotify)

--------------------------------
-- @overload self, void, unsigned short, int         
-- @overload self         
-- @function [parent=#CNotify] CNotify
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @param #int result
-- @return CNotify#CNotify self (return value: CNotify)

return nil
