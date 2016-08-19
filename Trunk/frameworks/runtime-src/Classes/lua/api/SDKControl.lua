
--------------------------------
-- @module SDKControl
-- @extend Node
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#SDKControl] getValueFromPlatform 
-- @param self
-- @param #unsigned int notifyCode
-- @param #char notifyName
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] isAppDebug 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] printError 
-- @param self
-- @param #char msg
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] printInfo 
-- @param self
-- @param #char tag
-- @param #char msg
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] initUmengShareSDK 
-- @param self
-- @param #string ShareWord
-- @param #string sharePng
-- @param #string shareURL
-- @param #string title
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] getSDKPlatform 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] isCocosDebug 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] getWifiState 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] exitGame 
-- @param self
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] setVersionCode 
-- @param self
-- @param #int code
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] removeSelectors 
-- @param self
-- @param #char name
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
--------------------------------
-- @overload self, char, char         
-- @overload self, char         
-- @overload self, char, ValueMapRef         
-- @function [parent=#SDKControl] sendMessage
-- @param self
-- @param #char nativeMethod
-- @param #ValueMapRef valueMap
-- @return SDKControl#SDKControl self (return value: SDKControl)

--------------------------------
-- 
-- @function [parent=#SDKControl] getVersionCode 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] handleMessage 
-- @param self
-- @param #cc.Node sender
-- @param #cc.Value data
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] getStringFromPlatform 
-- @param self
-- @param #unsigned int notifyCode
-- @param #char notifyName
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] getVersion 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] addSelector 
-- @param self
-- @param #char name
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] setVersion 
-- @param self
-- @param #string version
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] create 
-- @param self
-- @return SDKControl#SDKControl ret (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] getInstance 
-- @param self
-- @return SDKControl#SDKControl ret (return value: SDKControl)
        
--------------------------------
-- 
-- @function [parent=#SDKControl] SDKControl 
-- @param self
-- @return SDKControl#SDKControl self (return value: SDKControl)
        
return nil
