local BaseSceneData = import("app/models/data/BaseSceneData.lua")
local LoginSceneData = class("LoginSceneData",BaseSceneData)

--游戏场景
LoginSceneData.targetScene = "scene/LoginScene"

LoginSceneData.plistList = {}

LoginSceneData.picList = {}

LoginSceneData.musicList = {}

LoginSceneData.soundList = {}

function LoginSceneData:ctor(prevSceneName)
    LoginSceneData.super.ctor(self,prevSceneName)
end

return LoginSceneData