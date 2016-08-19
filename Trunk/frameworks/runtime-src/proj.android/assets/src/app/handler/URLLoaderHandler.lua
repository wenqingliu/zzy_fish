local URLLoaderHandler = {}
URLLoaderHandler.STATUS_CODES = {
    SUCCESS = 200,
    NOT_FOUND = 404
}

---------------------------
--@param self
--@param url
--@param callback
--@return
function URLLoaderHandler:load(url,callBack)
    self.loaderArr = self.loaderArr or {}
    
	local loader = jt.URLLoader:create()
	local function onComplete(urlData)
		callBack(urlData)
        self:remove(loader)
	end
    ScriptHandlerMgr:getInstance():registerScriptHandler(loader,onComplete,cc.Handler.CALLFUNC)
	loader:load(url)
	loader:retain()
    self.loaderArr[loader] = loader
	
    return loader
end

function URLLoaderHandler:remove(loader)
    ScriptHandlerMgr:getInstance():unregisterScriptHandler(loader,cc.Handler.CALLFUNC)
    loader:release()
    self.loaderArr[loader] = nil
end

function URLLoaderHandler:destroyInstance()
    if self.loaderArr == nil then
        return 
    end
    jt.URLLoader:getInstance():destroyInstance()
    for key, var in pairs(self.loaderArr) do
        self:remove(var)
    end
    self.loaderArr = nil
end

return URLLoaderHandler