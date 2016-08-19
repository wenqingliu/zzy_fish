nf = nf or {} -- nf : new fishjoy

nf.widthScale  = display.width / 1280
nf.heightScale = display.height / 720

nf.resolutionWidth = 1280
nf.resolutionHeight = 720

nf.bgScale = 1
if display.width > 1280 and display.height == 720 then
	nf.bgScale = display.width / 1280
elseif display.height > 720 and display.width == 1280 then
	nf.bgScale = display.height / 720
end

--同时玩家人数
nf.playerNum = 2

-- FishGameManager = import("app.module.game.FishGameManager").new()
AnimateManager = import(".views.game.fish.AnimateManager").new()
ArmatureManager = import(".views.game.fish.ArmatureManager").new()

GAME_PLAYER           = 2
FISH_KIND_COUNT       = 21
BULLET_KIND_COUNT     = 1
MAX_FISH_CATCH_COUNT  = 2
MAX_BULLET_FIRE_COUNT = 15
TRACE_LINEAR          = 0

return nf
