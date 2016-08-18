--游戏场景数据:捕鱼
local BaseSceneData = import("app/models/data/BaseSceneData.lua")
local FishSceneData = class("FishSceneData",BaseSceneData)

--游戏场景
FishSceneData.targetScene = "game/fish/FishGameScene.lua"

FishSceneData.plistList = {}

FishSceneData.picList = {}

FishSceneData.musicList = {}

FishSceneData.soundList = {

}

function FishSceneData:ctor(parameters)
    FishSceneData.super.ctor(self,parameters)
end

function FishSceneData:getKindID()
    return KIND_ID_FISH
end

function FishSceneData:getMainFile()
    return ""
end

return FishSceneData
