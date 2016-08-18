local SceneData = class("SceneData")

-- local HundredSceneData     = import("app/models/data/hundred/HundredSceneData.lua")
-- local HundredNewSceneData  = import("app/models/data/hundred/HundredNewSceneData.lua")
-- local YYLGameSceneData     = import("app/models/data/yyl/YYLGameSceneData.lua")
-- local slotMachineSceneData = import("app/models/data/slotMachine/slotMachineSceneData.lua")
-- local VSSceneData          = import("app/models/data/vs/VSSceneData.lua")
-- local KPQZGameSceneData    = import("app/models/data/kpqz/KPQZGameSceneData.lua")
-- local GongpoSceneData      = import("app/models/data/gongpo/GongpoSceneData.lua")
-- local FeiQinSceneData      = import("app/models/data/feiqin/forestParty.lua")
local FishSceneData        = import("app/models/data/fish/FishSceneData.lua")

function SceneData:ctor(prevSceneName)
    self.prevSceneName = prevSceneName  --上一场景
    self.targetScene   = nil            --目标场景
    self.plistList     = nil            --plist列表
    self.picList       = nil            --图片列表
    self.musicList     = nil            --音乐列表
    self.soundList     = nil            --声音列表
end

function SceneData:createWithRoom(item)

    local room = nil
    local isStartEnable = true--启用自动坐下
    local prevScene = "scene/HallScene"
    -- if item:szServerName():find(GameManager:getProject().RoomNameList[1]) ~= nil then
    --     --富豪百人
    --     room = HundredSceneData:create(prevScene)
    -- elseif item:szServerName():find(GameManager:getProject().RoomNameList[2]) ~= nil then
    --     --摇摇乐
    --     room = YYLGameSceneData:create(prevScene)
    -- elseif item:szServerName():find(GameManager:getProject().RoomNameList[5]) ~= nil then
    --     --欢乐百人
    --     room = HundredNewSceneData:create(prevScene)
    -- elseif item:szServerName():find(GameManager:getProject().RoomNameList[6]) ~= nil then
    --     --老虎机
    --     room = slotMachineSceneData:create(prevScene)
    --     isStartEnable = false
    -- elseif item:szServerName():find(GameManager:getProject().RoomNameList[7]) ~= nil then
    --     --对战场
    --     room = VSSceneData:create(prevScene)
    --     isStartEnable = false
    -- elseif item:szServerName():find(GameManager:getProject().RoomNameList[9]) ~= nil then
    --     --公婆场
    --     room = GongpoSceneData:create(prevScene)
    -- elseif item:szServerName():find(GameManager:getProject().RoomNameList[10]) ~= nil then
    --     --看牌抢庄
    --     room = KPQZGameSceneData:create(prevScene)
    --     isStartEnable = false
    -- elseif item:szServerName():find(GameManager:getProject().RoomNameList[11]) ~= nil then
    --     --飞禽走兽
    --     room = FeiQinSceneData:create(prevScene)
    --     isStartEnable = false
    -- else
        if item:szServerName():find("李逵劈鱼") ~= nil then
        --捕鱼
        room = FishSceneData:create(prevScene)
    end

    return room,isStartEnable
end

return SceneData
