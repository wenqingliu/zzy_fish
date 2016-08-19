SDKControlHandler = SDKControlHandler or class("SDKControlHandler",cc.load("mvc").ViewBase)
local cjson = import("app/library/cjson")

--发送调用列表
SDKControlHandler.SendMsgList = 
{
    CCVerision  = "CCVerision",                             --版本名称
    CCBundleVerision = "CCBundleVerision",                  --版本code
    CCLoginType = "CCLoginType",                            --登录类型
    CCGameLogin = "CCGameLogin",                            --登录
    CCSaveLogin = "CCSaveLogin",                            --保存登录信息
    CCGameLogout = "CCGameLogout",                          --注销
    CCPay = "CCPay",                                        --支付
    CCSendWanpu = "CCSendWanpu",                            --万普
    CCOpenApp = "CCOpenApp",                                --打开APP
    CCOpenBrowser = "CCOpenBrowser",                        --打开浏览器
    CCQueryExitGame = "CCQueryExitGame",                    --询问退出游戏
    CCShowTips = "CCShowTips",                              --调用平台弹窗显示
    CCSetRequestedOrientation = "CCSetRequestedOrientation",--设置屏幕方向
    CCSetJPushTag = "CCSetJPushTag",                        --设置推送TAG标签
    CCShare = "CCShare",                                    --分享
    CCNotify = "CCNotify"                                   --自定义通知
}

--接收列表
SDKControlHandler.RecipientsList = 
{
    ccNd_Version            = "ccNd_Version",                                   --版本名称响应
    ccNd_Bundle_Verision    = "ccNd_Bundle_Verision",                           --版本号响应          
    ccNd_PlatForm_LogonType = "ccNd_PlatForm_LogonType",                        --平台可登录类型
    ccNd_Platform_LogonResult = "ccNd_Platform_LogonResult",                    --登录结果
    ccNd_Platform_LogonLoading = "ccNd_Platform_LogonLoading",                  --加载资料
    ccNd_Shop_AppStore_Buy_Info_Result = "ccNd_Shop_AppStore_Buy_Info_Result",  --支付结果
    ccNd_Notify             = "ccNd_Notify",
    share = "share",
    ccNd_Share = "ccNd_Share"
}

function SDKControlHandler:onCreate()
    ScriptHandlerMgr:getInstance():registerScriptHandler(jt.SDKControl:getInstance(),
        handler(self,self.dispatchCustomEvent),cc.Handler.CALLFUNC)
    cc.bind(self, "event")
end

---------------------------
-- @param self
-- @param #jt.CNotify notify
function SDKControlHandler:dispatchCustomEvent(notify)
    if notify ~= nil and string.len(notify:getMainString()) > 0 then
        local str = notify:getMainString()
        local jobj = cjson.decode(str)
        self:dispatchEvent({name = jobj.methodToCall,_userData=jobj})
    end
end

function SDKControlHandler:addSelector(sdk,name,callback)
    sdk:addSelector(name)
    return self:addEventListener(name,callback)
end

function SDKControlHandler:removeSelectors(name)
	jt.SDKControl:getInstance():removeSelectors(name)
    self:removeEventListenersByEvent(name)
end

function SDKControlHandler:removeSelectorsBySDK(sdk,name)
    sdk:removeSelectors(name)
    self:removeEventListenersByEvent(name)
end

function SDKControlHandler:getInstance()
    if self._instance == nil then
        self._instance = SDKControlHandler:create()
        self._instance:retain()
    end
    return self._instance
end

function SDKControlHandler:sendMessage(nativeMethod,jobj)
    local jstr = jobj ~= nil and cjson.encode(jobj) or "{}"
    jt.SDKControl:getInstance():sendMessage(nativeMethod,jstr)
end

function SDKControlHandler:destroy()
    if self._instance ~= nil then
        self._instance:release()
        self._instance = nil
    end
    return self._instance
end 

return SDKControlHandler