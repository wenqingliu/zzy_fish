-------
--热加载
local HotSawp = class("HotSawp")

HotSawp.SCRIPT_ENTER = "src/main"

-------
--更新app文件夹
function HotSawp:reloadScriptFiles_app()
    for path,key in pairs(package.loaded) do
        if string.find(path,"app/") ~= nil then
            print(path,key)
            package.loaded[path] = nil
--            require(path)
        end
    end
    package.loaded["update.lua"] = nil
    return true
end

---------
--重启APP
function HotSawp:restartApp()
    package.loaded[HotSawp.SCRIPT_ENTER] = nil
    require(HotSawp.SCRIPT_ENTER)
end

return HotSawp