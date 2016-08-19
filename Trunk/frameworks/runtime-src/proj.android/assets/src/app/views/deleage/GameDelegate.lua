local BaseScene = import("app/views/scene/BaseScene")
local GameDelegate = class("GameDelegate",BaseScene)

function GameDelegate:onCreate()
    self._isShow = false
end

--用户聊天
function GameDelegate:onUserChat(notify) return true end

--用户表情
function GameDelegate:onUserImage(notify) return true end

--游戏消息处理
function GameDelegate:OnEventGameMessage(sub,notify) return true end

--游戏场景消息(刚进入游戏时消息事件)
function GameDelegate:OnEventSceneMessage(sub,notify) return end

-- 系统消息
function GameDelegate:onSubSystemMessage(szString,system,vipLevel) return end

--更新游戏显示
function GameDelegate:updateGameView() return true end

function GameDelegate:onUpdateScore() return end

function GameDelegate:onReSetGame() return end

function GameDelegate:isShow() return self._isShow end

function GameDelegate:onEnter()
    self._isShow = true
end

function GameDelegate:onExit()
    self._isShow = false
end



return GameDelegate