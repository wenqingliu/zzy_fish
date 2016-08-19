local update = class("update")

require "app/manager/GameManager.lua"
local scheduler = import("app/library/scheduler.lua")
local URLLoaderHandler = import("app/handler/URLLoaderHandler.lua")
local json = import("app/library/cjson")

update.isChecked = false

--自动更新界面
local vData = {}
local updateEngine = nil
local nowVersion = nil

--c++更新信息回调
update.ErrorCode =
{
    NETWORK = 0,
    CREATE_FILE = 1,
    NO_NEW_VERSION = 2,
    UNDOWNED = 3,
    UNCOMPRESS = 4,
}

function update:destroryUpdateEngine()
    if updateEngine ~= nil then
        local delegate = updateEngine:getDelegate()
        ScriptHandlerMgr:getInstance():unregisterScriptHandler(delegate,cc.Handler.CALLFUNC)
        delegate:release()
        updateEngine:release()
        updateEngine = nil
    end
end

function update:resetSearchPaths()

    --重置搜索目录
    cc.FileUtils:getInstance():setSearchPaths({})
    local writablePath = cc.FileUtils:getInstance():getWritablePath()
    cc.FileUtils:getInstance():addSearchPath(writablePath.."download/src/")
    cc.FileUtils:getInstance():addSearchPath(writablePath.."download/res/")
    cc.FileUtils:getInstance():addSearchPath("src/")
    cc.FileUtils:getInstance():addSearchPath("res/")

end

function update:resetGame()
    GameManager:destroy()

    self:resetSearchPaths()
    local HotSwap = import("app/library/HotSwap.lua")
    --重新加载app文件夹代码
    HotSwap:reloadScriptFiles_app()
    require "config"
    require "cocos.init"

    --全局定义--
    require "cocos/cocos2d/bitExtend.lua"
    require "app/library/BtnGroup.lua"
    require "app/library/MotionUtil.lua"
    require "app/library/Resources.lua"
    require "app/library/bit.lua"
    require "app/handler/CFrameDataHandler.lua"
    require "app/models/protocol/Protocol.lua"
    require "app/manager/GameManager.lua"
    --/

    --设置客户端通讯版本
    GameManager:getProject().Versions = cc.UserDefault:getInstance():getStringForKey("current-version-code",GameManager:getProject().Versions)
    CFrameDataHandler:getInstance():initConfig()

end

function update:getUpdateEngine()
	if updateEngine == nil then
        updateEngine = jt.UpdateEngine:create()
        updateEngine:retain()

        local function onResponse(notify)
            print("onResponse:",notify:getMainType(),notify:getSubType())
            if notify:getMainType() == 0 then--进度
                local percent = notify:getSubType()
                percent = percent < 0 and 0 or percent
                local per = math.floor(self.updateCount / self.totalCount * 100) + percent / self.totalCount
                print("percent:",per,percent)
                self.delegate:onProgress(per)
            elseif notify:getMainType() == 1 then--成功
                self.updateCount = self.updateCount + 1
                print("onResponse-onSuccess",self.updateCount)
                if self.updateCount == self.totalCount then--更新完毕
                    if not self.isRestartGame then
                        --开始游戏
                        self.delegate:onSuccess()
                        if self.isResetLua then
                            self.isResetLua = false
                            update:resetGame()
                        else
                            self:resetSearchPaths()
                        end
                        self.delegate:playGame(true)
                    elseif self.isRestartGame then --重启游戏
                        GameManager:showAlertSystem(cc.Director:getInstance():getRunningScene(),"更新完毕，点击重新进入游戏",function()
                            jt.SDKControl:getInstance():exitGame()
                        end)
                    end
                end
            elseif notify:getMainType() == 2 then--下载
                self.delegate:onDownload(notify)
            elseif notify:getMainType() == 3 then--解压文件
                self.delegate:onUncompress(notify)
            elseif notify:getMainType() == 4 then--错误
                self.delegate:onError(notify:getSubType())
            end
        end
        local delegate = jt.UpdateEngineDelegate:create()
        delegate:retain()
        updateEngine:setDelegate(delegate)
        ScriptHandlerMgr:getInstance():registerScriptHandler(delegate,onResponse,cc.Handler.CALLFUNC)

	end

    return updateEngine
end

function update:startUpdate()
    if self.isLoading then
        --延迟更新
        self.isStartUpdate = true
        return
    end
    if self:getUpdateEngine():checkUpdate() then
        return self:getUpdateEngine():update()
    else
        print("无更新内容，进入游戏")
        return self.delegate:playGame(false)
    end
end

function update:checkUpdate()
    return self:getUpdateEngine():checkUpdate()
end

--添加无版本号纯zip包
function update:pushZIP(zipURL)
    self:getUpdateEngine():pushZIP(zipURL)
    self.totalCount = self.totalCount + 1
end

function update:loadVersions()
     local function onResponse(urlData)
        self.isLoading = nil
        local isNeedUpdate = false
        if urlData:getStatusCode() == URLLoaderHandler.STATUS_CODES.SUCCESS then
            local proData = urlData:getData()

            local status, result = pcall(function()
                vData = json.decode(urlData:getData())
            end)
            if not status then
                GameManager:showAlertSystem(cc.Director:getInstance():getRunningScene(),"版本资料加载失败，数据格式有误")
                self.delegate:playGame(true)
                return
            end

            local vList = vData.versionList
            for i=1,#vList do
                local item = vList[i]
                local targetV = {GameManager:getProject():getVersionList(item.version)}
                local nowV = {GameManager:getProject():getVersionList(nowVersion)}
                if tonumber(targetV[1]) > tonumber(nowV[1]) then
                    --大版本更新了
                    GameManager:showAlertSystem(cc.Director:getInstance():getRunningScene(),"当前版本已不可用，请更新至最新版本")
                    self.delegate:playGame(true)
                    return
                elseif ( targetV[2] == tonumber(nowV[2]) and tonumber(targetV[3]) > tonumber(nowV[3]) ) then
                    --小版本更新
                    if item.skipUpdate ~= true then
                        isNeedUpdate = true
                        print("待更新版本:",item.version)
                        if string.find(item.downloadURL,"http") == nil then
                            item.downloadURL = "http://".. GameManager:getProject().LoginAddress .. GameManager:getProject().URLPort .. item.downloadURL
                        end
                        self:getUpdateEngine():pushVersionQueue(item.version,item.downloadURL)--添加待更新版本
                        self.totalCount = self.totalCount + 1
                        self.isResetLua = true
                        if item.isRestartGame == true then
                            --需要重启游戏
                            self.isRestartGame = true
                        end
                    end
                else
                    print("当前版本:"..nowVersion.." 目标版本:"..item.version)
                end
            end

            if isNeedUpdate and self.isStartUpdate then
                self.isStartUpdate = false
                self:startUpdate()
            else
                self.delegate:playGame(false)
            end

        elseif urlData:getStatusCode() == URLLoaderHandler.STATUS_CODES.NOT_FOUND then
            self.delegate:onError(URLLoaderHandler.STATUS_CODES.NOT_FOUND)
            return
        else
            self.delegate:onError(update.ErrorCode.NETWORK)
        end
    end

    print("正在检查新版本，请稍等")
    local bigV = GameManager:getProject():getVersionList(GameManager:getProject().Versions)
--    local vURL = "http://192.168.1.115:80/version/"..bigV.."/version.txt"
    local vURL = "http://".. GameManager:getProject().LoginAddress .. GameManager:getProject().URLPort .. "/version/"..bigV.."/version.txt"
--    local vURL = GameManager:getProject().domainURL .. "/version/"..bigV.."/version.txt"
    self.isLoading = true
    URLLoaderHandler:load(vURL,onResponse)
end

function update:ctor()
    self:initValue()
end

function update:initValue()
    self.updateCount = 0
    self.totalCount = 0
    self.delegate = nil
    self.isRestartGame = nil
    self.isLoading = nil
    self.isStartUpdate = nil
    self.isResetLua = nil
end

function update:setDelegate(delegate)
    self.delegate = delegate
end

function update:start()
--    cc.UserDefault:getInstance():setStringForKey("current-version-code","1.2.0")
    nowVersion = cc.UserDefault:getInstance():getStringForKey("current-version-code","")
    if nowVersion == "" then
        nowVersion = GameManager:getProject().Versions
        cc.UserDefault:getInstance():setStringForKey("current-version-code",nowVersion)
        cc.UserDefault:getInstance():flush()
    end
    self:loadVersions()
end

function update:getInstance()
    if self._instance == nil then
        self._instance = update:create()
    end
    return self._instance
end

function update:destrory()
    self:destroryUpdateEngine()
    self:initValue()
    self._instance = nil
end

return update
