local BaseSceneData = class("BaseSceneData")

function BaseSceneData:ctor(prevSceneName)
    self.prevSceneName = prevSceneName  --上一场景
    self.targetScene = nil    --目标场景
    
    self.plistList = nil    --plist列表
    self.picList = nil      --图片列表
    self.musicList = nil    --音乐列表
    self.soundList = nil    --声音列表
end

--获取文件目录是否存在
function BaseSceneData:isExistRes()
    local dire = self:getMainFile()
    if dire == "" then
        return true
    end
    local fullpath = cc.FileUtils:getInstance():fullPathForFilename(dire)
    local writablePath = cc.FileUtils:getInstance():getWritablePath()
    local fullpath2 = cc.FileUtils:getInstance():fullPathForFilename(writablePath.."download/res/"..dire)
    if string.len(fullpath) ~= 0 or string.len(fullpath) ~= 0 then
        return true
    end
    
    return false
end

function BaseSceneData:onEnter()
    GameManager:setKindID(self:getKindID())
    CC_DESIGN_RESOLUTION.setRequestedOrientation(self:getOrientation())
end

function BaseSceneData:getOrientation()
	return 0
end

function BaseSceneData:getMainFile()
    return ""
end

function BaseSceneData:getZipURL()
    return ""
end

function BaseSceneData:getZipSize()
    return ""
end

function BaseSceneData:getPlatformPath()
	if device.platform ~= "ios" then
	   return "android"
	end
    return device.platform
end

return BaseSceneData