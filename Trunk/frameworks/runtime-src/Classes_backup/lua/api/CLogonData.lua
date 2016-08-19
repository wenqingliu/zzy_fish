
--------------------------------
-- @module CLogonData
-- @extend Ref
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CLogonData] setAvatarURL 
-- @param self
-- @param #string var
-- @return CLogonData#CLogonData self (return value: CLogonData)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] setDeviceid 
-- @param self
-- @param #string var
-- @return CLogonData#CLogonData self (return value: CLogonData)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] setGender 
-- @param self
-- @param #unsigned char var
-- @return CLogonData#CLogonData self (return value: CLogonData)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] setUUID 
-- @param self
-- @param #string var
-- @return CLogonData#CLogonData self (return value: CLogonData)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] setPasswd 
-- @param self
-- @param #string var
-- @return CLogonData#CLogonData self (return value: CLogonData)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] getLogonType 
-- @param self
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] getDeviceid 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] getGender 
-- @param self
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] getNickName 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] getAvatarURL 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] getUUID 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] getPasswd 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] setLogonType 
-- @param self
-- @param #unsigned char var
-- @return CLogonData#CLogonData self (return value: CLogonData)
        
--------------------------------
-- 
-- @function [parent=#CLogonData] setNickName 
-- @param self
-- @param #string var
-- @return CLogonData#CLogonData self (return value: CLogonData)
        
--------------------------------
-- @overload self, unsigned char, string, string, string         
-- @overload self         
-- @overload self, unsigned char, string, string         
-- @overload self, unsigned char, unsigned char, string, string, string, string         
-- @function [parent=#CLogonData] create
-- @param self
-- @param #unsigned char cbLogonType
-- @param #unsigned char cbGender
-- @param #string UUID
-- @param #string nickName
-- @param #string avatarURL
-- @param #string deviceid
-- @return CLogonData#CLogonData ret (return value: CLogonData)

--------------------------------
-- 
-- @function [parent=#CLogonData] CLogonData 
-- @param self
-- @return CLogonData#CLogonData self (return value: CLogonData)
        
return nil
