
--------------------------------
-- @module CFrameData
-- @extend TCPSocketDelegate,CAccountDataDelegate
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithGameOption 
-- @param self
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGRConfigServer 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGRLogonFailure 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getGameClientStatus 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGRConfigFinish 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubLogonFailure 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithGPTakeScore 
-- @param self
-- @param #long long lTakeScore
-- @param #char pPassword
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainMBUserProps 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainGRLogon 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainGRUser 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithRequestUserInfo 
-- @param self
-- @param #unsigned int dwUserID
-- @param #unsigned short wTableID
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithUserStatus 
-- @param self
-- @param #unsigned char cbStatus
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- @overload self, char, unsigned short         
-- @overload self         
-- @function [parent=#CFrameData] doConnect
-- @param self
-- @param #char domain
-- @param #unsigned short wPort
-- @return CFrameData#CFrameData self (return value: CFrameData)

--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubUserStatus 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMDMGPUserService 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setSocketClose 
-- @param self
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGPBankSucceed 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 等待分配
-- @function [parent=#CFrameData] OnSocketSubRequestDistribute 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getLoginAddress 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getHotVersion 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubLogonAward 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGRLogonSuccess 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGRConfigPropepty 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainGPLogon 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, char         
-- @overload self         
-- @function [parent=#CFrameData] sendPacketWithCompilatio
-- @param self
-- @param #char ValidateKey
-- @return CFrameData#CFrameData self (return value: CFrameData)

--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGRConfigColumn 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkWithMBDataLoad 
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithUserChat 
-- @param self
-- @param #unsigned int dwTagerUserID
-- @param #char chat
-- @param #unsigned short wSize
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setLoginAddress 
-- @param self
-- @param #string loginAddress
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getDeviceType 
-- @param self
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getPlazaVersion 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubSpeakerNews 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubUserGold 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGPBankFailure 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithRequestChairUserInfo 
-- @param self
-- @param #unsigned short wTableID
-- @param #unsigned short wChairID
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubLogonSuccess 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainMBServerList 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainMBLogon 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithCutoverTable 
-- @param self
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubUserScore 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGRLogonFinish 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] isEnterBackground 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainGRConfig 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubRequestFailure 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithQuickStart 
-- @param self
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithGPSaveScore 
-- @param self
-- @param #long long lSaveScore
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithUserExpression 
-- @param self
-- @param #unsigned int dwTargetUserID
-- @param #unsigned short index
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getDataArraySize 
-- @param self
-- @return long#long ret (return value: long)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithGPTransferScore 
-- @param self
-- @param #long long lTransferScore
-- @param #char pPassword
-- @param #unsigned char cbType
-- @param #char pNickName
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getSocketConnect 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setKindID 
-- @param self
-- @param #unsigned int dwKindID
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkWithGRDataRoom 
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setValidateKey 
-- @param self
-- @param #string validateKey
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setIsEnterBackground 
-- @param self
-- @param #bool bIsEnterBackground
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- @overload self, char, char         
-- @overload self, char         
-- @function [parent=#CFrameData] sendUserHorn
-- @param self
-- @param #char szNickName
-- @param #char szchat
-- @return CFrameData#CFrameData self (return value: CFrameData)

--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGPInsureInfo 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithModifyIndividual 
-- @param self
-- @param #char nickString
-- @param #unsigned char cbGender
-- @param #unsigned int dwUserID
-- @param #char szPassword
-- @param #bool isMd5
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGFSystemMessage 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setHotVersion 
-- @param self
-- @param #char szHotVer
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubUserEnter 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getLoginPort 
-- @param self
-- @return unsigned short#unsigned short ret (return value: unsigned short)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainGFFrame 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithUserLogon 
-- @param self
-- @param #CLogonData logonData
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getSender 
-- @param self
-- @return Ref#Ref ret (return value: cc.Ref)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setSocketLogic 
-- @param self
-- @param #bool isNextLogic
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubMBGetPropsInfo 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, void, unsigned short         
-- @overload self, CMD_BASE         
-- @overload self, unsigned short, unsigned short, CMD_BASE         
-- @overload self, unsigned short, unsigned short, void, unsigned short         
-- @function [parent=#CFrameData] sendData
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #void buffer
-- @param #unsigned short wSize
-- @return CFrameData#CFrameData self (return value: CFrameData)

--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubMBUpdateNotify 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkGRBankInsure 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubListKind 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainGame 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithRankInfo 
-- @param self
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGFGameStatus 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGFUserChat 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubListFinish 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] SocketDelegateWithCloseNotify 
-- @param self
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setLoginPort 
-- @param self
-- @param #unsigned short loginPort
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendSocketData 
-- @param self
-- @param #TCP_BufferRef buffer
-- @param #unsigned short wSize
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithSitDown 
-- @param self
-- @param #unsigned short wTableID
-- @param #unsigned short wChairID
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] SocketDelegateWithRecvData 
-- @param self
-- @param #CSpriteData pData
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGFGameScene 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainGRStatus 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithGPTransferRecord 
-- @param self
-- @param #unsigned int dwGameID
-- @param #unsigned int dwTargetID
-- @param #unsigned short wNumber
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setPlazaVersion 
-- @param self
-- @param #unsigned int dwPlazaVersion
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithGPInsureInfo 
-- @param self
-- @param #char pszInsurePass
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithQuickJin 
-- @param self
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubGFUserExpression 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] SocketDelegateWithConnectNotfiy 
-- @param self
-- @param #bool isConnect
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getValidateKey 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithEnterRoomPageCount 
-- @param self
-- @param #unsigned short wBehaviorFlags
-- @param #tagGameServerRef server
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithStandUpLeave 
-- @param self
-- @param #unsigned char cbForce
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] setDeviceType 
-- @param self
-- @param #unsigned char cbDevice
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] sendPacketWithUserRule 
-- @param self
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainCMSystem 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNetworkMainMBVerify 
-- @param self
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getKindID 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnTCPNewordkWithKNCommon 
-- @param self
-- @param #unsigned short wMainCmdID
-- @param #unsigned short wSubCmdID
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] OnSocketSubListServer 
-- @param self
-- @param #void pData
-- @param #unsigned short wSize
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] createFrameData 
-- @param self
-- @return CFrameData#CFrameData ret (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] getInstance 
-- @param self
-- @return CFrameData#CFrameData ret (return value: CFrameData)
        
--------------------------------
-- 
-- @function [parent=#CFrameData] CFrameData 
-- @param self
-- @return CFrameData#CFrameData self (return value: CFrameData)
        
return nil
