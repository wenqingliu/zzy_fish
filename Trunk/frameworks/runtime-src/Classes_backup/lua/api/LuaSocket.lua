
--------------------------------
-- @module LuaSocket
-- @extend TCPSocketDelegate
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#LuaSocket] SocketDelegateWithConnectNotfiy 
-- @param self
-- @param #bool isConnect
-- @return LuaSocket#LuaSocket self (return value: LuaSocket)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] setSocketClose 
-- @param self
-- @return LuaSocket#LuaSocket self (return value: LuaSocket)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] SocketDelegateWithCloseNotify 
-- @param self
-- @return LuaSocket#LuaSocket self (return value: LuaSocket)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] OnTCPNetworkMainMBLogon 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] doConnect 
-- @param self
-- @param #char domain
-- @param #unsigned short wPort
-- @return LuaSocket#LuaSocket self (return value: LuaSocket)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] OnSocketSubLogonFailure 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] sendPacketWithCompilatio 
-- @param self
-- @param #char ValidateKey
-- @return LuaSocket#LuaSocket self (return value: LuaSocket)
        
--------------------------------
-- @overload self, void, unsigned short         
-- @overload self, CMD_BASE         
-- @overload self, unsigned short, unsigned short, CMD_BASE         
-- @overload self, unsigned short, unsigned short, void, unsigned short         
-- @function [parent=#LuaSocket] sendData
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #void buffer
-- @param #unsigned short wSize
-- @return LuaSocket#LuaSocket self (return value: LuaSocket)

--------------------------------
-- 
-- @function [parent=#LuaSocket] getSender 
-- @param self
-- @return Ref#Ref ret (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] OnTCPNewordkWithKNCommon 
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] OnSocketSubLogonSuccess 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] SocketDelegateWithRecvData 
-- @param self
-- @param #CSpriteData pData
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] setSocketLogic 
-- @param self
-- @param #bool isNextLogic
-- @return LuaSocket#LuaSocket self (return value: LuaSocket)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] getSocketConnect 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] OnTCPNetworkWithMBDataLoad 
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] createFrameData 
-- @param self
-- @return LuaSocket#LuaSocket ret (return value: LuaSocket)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] getInstance 
-- @param self
-- @return LuaSocket#LuaSocket ret (return value: LuaSocket)
        
--------------------------------
-- 
-- @function [parent=#LuaSocket] LuaSocket 
-- @param self
-- @return LuaSocket#LuaSocket self (return value: LuaSocket)
        
return nil
