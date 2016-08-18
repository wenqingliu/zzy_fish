local GameDelegate = import("app/views/deleage/GameDelegate.lua")
local FishGameScene = class("FishGameScene",GameDelegate)
local FishGameView = import("app/views/game/fish/FishGameView.lua")
local CMD_GAME_FISH = import("app/cmd/game/fish/CMD_GAME_FISH")

function FishGameScene:onCreate()
    FishGameScene.super.onCreate(self)
    self.m_GameClientView = FishGameView:create(self):addTo(self)
    FishGameManager:init(self.m_GameClientView )
    --启用游戏代理
    GameManager:setGameDelegate(self)
end

function FishGameScene:onEnter()
    FishGameScene.super.onEnter(self)
    --游戏音乐
    --TODO
end

-----------
-- 游戏场景消息(刚进入游戏时消息事件)
function FishGameScene:OnEventSceneMessage(sub,notify)
    FishGameManager:onGameMessageWithScene(sub,notify)
end

-----------
--游戏消息处理
function FishGameScene:OnEventGameMessage(sub,obj)
     FishGameManager:onGameMessageWithCmdID(sub,obj)
    -- local func = function(sub,obj) FishGameManager:onGameMessageWithCmdID(sub,obj) end
    -- local callfun = cc.CallFunc:create(func)
    -- self:runAction(cc.Sequence:create(callfun))
    -- self.m_GameClientView:onGameMessageWithCmdID(sub,obj)
end

----------
-- 系统消息
function FishGameScene:onSubSystemMessage(szString,system,vipLevel)
    self.m_GameClientView:onSubSystemMessage(szString,system,vipLevel)
end

function FishGameScene:onUpdateScore()
    self.m_GameClientView:onUpdateScore()
end

function FishGameScene:updateGameView(pUser)
    self.m_GameClientView:updateGameView(pUser)
end

function FishGameScene:onKeyboard(keyCode,event)
    FishGameScene.super.onKeyboard(self,keyCode,event)
    if keyCode == cc.KeyCode.KEY_ESCAPE or keyCode == cc.KeyCode.KEY_BACKSPACE
        or keyCode == 6 then
        self:onGameBack()
    end
end

function FishGameScene:onGameBack()
    CFrameDataHandler:getInstance():sendPacketWithStandUpLeave()
end

-- function FishGameScene:onEnter()
--     FishGameScene.super.onEnter(self)
-- end

function FishGameScene:onCleanup()
    GameManager:setGameDelegate(nil)--移除代理设置
end

return FishGameScene
