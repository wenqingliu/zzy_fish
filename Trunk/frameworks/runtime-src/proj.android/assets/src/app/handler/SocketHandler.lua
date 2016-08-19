SocketHandler = SocketHandler or {}
local TAG = "SocketHandler"

function SocketHandler:new(o)
    o = o or {}
    setmetatable(o,self)
    self.__index = self
    

    ScriptHandlerMgr:getInstance():registerScriptHandler(jt.LuaSocket:getInstance():getSender(),
        handler(self,self.SocketDelegateWithRecvData),cc.Handler.CALLFUNC)
        
    return o
end

function SocketHandler:doConnect()
    jt.LuaSocket:getInstance():doConnect(Project.LoginAddress,Project.LoginPort)
    jt.LuaSocket:getInstance():sendPacketWithCompilatio(Project.LogonValidateKey)
end

function SocketHandler:sendData(wMainCmdID,wSubCmdID,cmd)
    jt.LuaSocket:getInstance():sendData(wMainCmdID,wSubCmdID,cmd)
end

---------------------------
-- socket数据处理
-- @param self
-- @param #jt.CNotify data
function SocketHandler:SocketDelegateWithRecvData(data)
    if jt.LuaSocket:getInstance():getSocketConnect() == false then
        self:setSocketClose()
        return
    end

    local name = data:getEventName()
    
    local m1 =  data:getMainType()
    local m2 = data:getSubType() 
    local m3 = data:getTypeData()
    local m4 = data:getResult()
    local m5 = data:getSize()
    
    local type = data:getType()
    local main = data:getMainCmdID()
    local sub = data:getSubCmdID()
    print(TAG,"数据类型",type,main,sub)
    --数据状态
    if type == DATA_TYPE.Data_Default then
        print(TAG,"数据无效")
    elseif type == DATA_TYPE.Data_Load then
        --数据接收
        self:OnTCPNetworkWithMBDataLoad(main,sub,data)
    elseif type == DATA_TYPE.Data_Room then
       
    else
        print(TAG,"状态分类:未处理的case状态");
    end
end

---------------------------
-- 大厅登录
-- @param self
-- @param #int
-- @param #int
-- @param #jt.CSpriteData data
function SocketHandler:OnTCPNetworkWithMBDataLoad(mainCmdID,subCmdID,data)
   if mainCmdID == MDM_TYPE.MDM_GP_LOGON then   --PC原有命令码
        --PC登录
   elseif mainCmdID == MDM_TYPE.MDM_MB_LOGON then       --广场登录 
        self:OnTCPNetworkMainMBLogon(subCmdID,data)
   else
        print(false, "LuaSocket: 没有处理的case");
   end
end

---------------------------
-- @param self
-- @param #int
-- @param #int
-- @param #jt.CSpriteData data
function SocketHandler:OnTCPNetworkMainMBLogon(subCmdID,pData)
    if subCmdID == SUB_MB_LOGON_SUCCESS then         --登录成功  100
        return self:OnSocketSubLogonSuccess(pData);
    elseif subCmdID == SUB_MB_LOGON_FAILURE then   --登录失败  101
        return self:OnSocketSubLogonFailure(pData);
    end
        
end

---------------------------
-- @param self
-- @param #jt.CSpriteData data
function SocketHandler:OnSocketSubLogonSuccess(data)
    local suc = jt.CMD_MB_LogonSuccessRef:createWithData(data)
    local url = suc:szNickName()
    print(TAG,"登录成功:",url)
end

---------------------------
-- @param self
-- @param #jt.CSpriteData data
function SocketHandler:OnSocketSubLogonFailure(data)
   local err = jt.CMD_MB_LogonFailureRef:createWithData(data)
   print(TAG,err:szDescribeString())
end

function SocketHandler:setSocketClose()
    print("链接关闭")
end

----------------------
-- 
-- @return SocketHandler#SocketHandler ret (return value: SocketHandler)
function SocketHandler:getInstance()
    if self._instance == nil then
        self._instance = self:new()
    end
    return self._instance
end 

return SocketHandler