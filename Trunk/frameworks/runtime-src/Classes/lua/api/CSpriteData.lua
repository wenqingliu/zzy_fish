
--------------------------------
-- @module CSpriteData
-- @extend Ref
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CSpriteData] getBuffer 
-- @param self
-- @return void#void ret (return value: void)
        
--------------------------------
-- 
-- @function [parent=#CSpriteData] setSubCmdID 
-- @param self
-- @param #unsigned short value
-- @return CSpriteData#CSpriteData self (return value: CSpriteData)
        
--------------------------------
-- 
-- @function [parent=#CSpriteData] getType 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CSpriteData] getSize 
-- @param self
-- @return unsigned short#unsigned short ret (return value: unsigned short)
        
--------------------------------
-- 
-- @function [parent=#CSpriteData] getMainCmdID 
-- @param self
-- @return unsigned short#unsigned short ret (return value: unsigned short)
        
--------------------------------
-- 
-- @function [parent=#CSpriteData] setMainCmdID 
-- @param self
-- @param #unsigned short value
-- @return CSpriteData#CSpriteData self (return value: CSpriteData)
        
--------------------------------
-- 
-- @function [parent=#CSpriteData] getSubCmdID 
-- @param self
-- @return unsigned short#unsigned short ret (return value: unsigned short)
        
--------------------------------
-- 
-- @function [parent=#CSpriteData] getData 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- @overload self, unsigned short, unsigned short, char, unsigned short         
-- @overload self, char, unsigned short, int         
-- @function [parent=#CSpriteData] socketData
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #char pData
-- @param #unsigned short wSize
-- @return CSpriteData#CSpriteData ret (return value: CSpriteData)

--------------------------------
-- @overload self, char, unsigned short, int         
-- @overload self, unsigned short, unsigned short, char, unsigned short         
-- @function [parent=#CSpriteData] spriteData
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #char pData
-- @param #unsigned short wSize
-- @return CSpriteData#CSpriteData ret (return value: CSpriteData)

--------------------------------
-- @overload self, char, unsigned short, int         
-- @overload self, CSpriteData         
-- @overload self, unsigned short, unsigned short, char, unsigned short         
-- @function [parent=#CSpriteData] CSpriteData
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #char pData
-- @param #unsigned short wSize
-- @return CSpriteData#CSpriteData self (return value: CSpriteData)

return nil
