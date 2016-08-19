local BaseSceneData = import("app/models/data/BaseSceneData.lua")
local HallSceneData = class("HallSceneData",BaseSceneData)

--游戏场景
HallSceneData.targetScene = "scene/HallScene.lua"

HallSceneData.plistList = {}

HallSceneData.picList = {}

HallSceneData.musicList = {}

HallSceneData.soundList = {}

function HallSceneData:ctor(prevSceneName)
    HallSceneData.super.ctor(self,prevSceneName)
end

function HallSceneData:getKindID()
    return KIND_ID_MSG
end

return HallSceneData
