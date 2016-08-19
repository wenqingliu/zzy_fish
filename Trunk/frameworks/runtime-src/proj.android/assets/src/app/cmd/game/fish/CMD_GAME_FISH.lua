local CMDBase = import("app/cmd/CMDBase.lua")
local CMD_GAME_FISH = {}

----------------------------------------------------------
-- 服务端命令

CMD_GAME_FISH.SUB_S_SCENE_END               = 1700  --未处理
CMD_GAME_FISH.SUB_S_STOCK_OPERATE_RESULT    = 1701  --未处理
CMD_GAME_FISH.SUB_S_SWITCH_SCENE            = 1702
CMD_GAME_FISH.SUB_S_HIT_FISH_LK             = 1703
CMD_GAME_FISH.SUB_S_CATCH_SWEEP_FISH_RESULT = 1704
CMD_GAME_FISH.SUB_S_CATCH_SWEEP_FISH        = 1705  --未处理
CMD_GAME_FISH.SUB_S_LOCK_TIMEOUT            = 1706
CMD_GAME_FISH.SUB_S_BULLET_ION_TIMEOUT      = 1707
CMD_GAME_FISH.SUB_S_CATCH_FISH              = 1708
CMD_GAME_FISH.SUB_S_USER_FIRE               = 1709
CMD_GAME_FISH.SUB_S_EXCHANGE_FISHSCORE      = 1710
CMD_GAME_FISH.SUB_S_FISH_TRACE              = 1711  --done
CMD_GAME_FISH.SUB_S_GAME_CONFIG             = 1712  --done
CMD_GAME_FISH.SUB_S_FISH_GROUP              = 1714

CMD_GAME_FISH.FPoint = class("FPoint",CMDBase)
function CMD_GAME_FISH.FPoint:readFormByteArray(ba)
    self.x = ba:readFloat()
    self.y = ba:readFloat()
end

CMD_GAME_FISH.CMD_S_GameStatus = class("CMD_S_GameStatus",CMDBase)
function CMD_GAME_FISH.CMD_S_GameStatus:readFormByteArray(ba)
    self.scene_kind = ba:readDWORD()
    self.fish_score = {}
    for i=1,GAME_PLAYER do
		self.fish_score[i] = ba:readLONGLONG()
	end

    self.exchange_fish_score = {}
    for i=1,GAME_PLAYER do
		self.exchange_fish_score[i] = ba:readLONGLONG()
	end

    self.null_data = ba:readBool()
end

CMD_GAME_FISH.CMD_S_FishGroup = class("CMD_S_FishGroup",CMDBase) --1714
function CMD_GAME_FISH.CMD_S_FishGroup:readFormByteArray(ba)
    self.group_id      = ba:readInt()
    self.fish_id_start = ba:readInt()
    -- self.fish_id_end   = ba:readInt()
end

CMD_GAME_FISH.CMD_S_GameConfig = class("CMD_S_GameConfig",CMDBase) --1712
function CMD_GAME_FISH.CMD_S_GameConfig:readFormByteArray(ba)
    self.exchange_ratio_userscore = ba:readInt()
    self.exchange_ratio_fishscore = ba:readInt()
    self.exchange_count           = ba:readInt()
    self.null_data                = ba:readBool()
    self.min_bullet_multiple      = ba:readUINT()
    self.max_bullet_multiple      = ba:readUINT()
    self.baseScore                = ba:readInt()        --后加 房间底分

    self.bomb_range_width         = ba:readInt()
    self.bomb_range_height        = ba:readInt()

    self.fish_multiple = {}
    for i = 0, FISH_KIND_COUNT-1 do
        self.fish_multiple[i] = ba:readInt()
    end

    self.fish_speed = {}
    for i = 0, FISH_KIND_COUNT-1 do
        self.fish_speed[i] = ba:readInt()
    end

    self.fish_bounding_box_width = {}
    for i = 0, FISH_KIND_COUNT-1 do
        self.fish_bounding_box_width[i] = ba:readInt()
    end

    self.fish_bounding_box_height = {}
    for i = 0, FISH_KIND_COUNT-1 do
        self.fish_bounding_box_height[i] = ba:readInt()
    end

    self.fish_hit_radius = {}
    for i = 0, FISH_KIND_COUNT-1 do
        self.fish_hit_radius[i] = ba:readInt()
    end

    self.bullet_speed = {}
    for i = 0, BULLET_KIND_COUNT-1 do
        self.bullet_speed[i] = ba:readInt()
    end

    self.net_radius = {}
    for i = 0, BULLET_KIND_COUNT-1 do
        self.net_radius[i] = ba:readInt()
    end
end

CMD_GAME_FISH.CMD_S_FishTrace = class("CMD_S_FishTrace",CMDBase) --1711
function CMD_GAME_FISH.CMD_S_FishTrace:readFormByteArray(ba)
    self.init_count = ba:readInt()
    self.fish_id    = ba:readInt()
    self.null_data  = ba:readBool()
    self.trace_type = ba:readInt()
    self.fish_kind  = ba:readInt()
    self.trace_id  = ba:readInt()   --后加 id

    --原有 删除
    -- self.init_pos = {}
    -- for i = 1, 5 do
    --     self.init_pos[i] = CMD_GAME_FISH.FPoint:create()
    --     self.init_pos[i]:readFormByteArray(ba)
    -- end
end

function CMD_GAME_FISH.CMD_S_FishTrace:getSize()
    return 21--57
end

---------------------------------------------------------------------
CMD_GAME_FISH.FPointAngle = class("FPointAngle",CMDBase)
function CMD_GAME_FISH.FPointAngle:readFormByteArray(ba)
    self.x = ba:readFloat()
    self.y = ba:readFloat()
    self.angle = ba:readFloat()
end

CMD_GAME_FISH.CMD_S_Trace = class("CMD_S_Trace",CMDBase)
function CMD_GAME_FISH.CMD_S_Trace:readFormByteArray(ba)
    self.count = ba:readInt()
    self.pos = {}
    for i = 1, self.count do
        self.pos[i] = CMD_GAME_FISH.FPointAngle:create()
        self.pos[i]:readFormByteArray(ba)
    end
end

-- function CMD_GAME_FISH.CMD_S_Trace:getSize(count)
--     return 4 + 12*count
-- end
---------------------------------------------------------------------

CMD_GAME_FISH.CMD_S_SwitchScene = class("CMD_S_SwitchScene",CMDBase) --1702
function CMD_GAME_FISH.CMD_S_SwitchScene:readFormByteArray(ba)
    self.fish_count = ba:readInt()
    self.scene_kind = ba:readInt()

    self.fish_kind = {}
    for  i = 1, 300 do
        self.fish_kind[i] = ba:readInt()
    end
    self.fish_id = {}
    for  i = 1, 300 do
        self.fish_id[i] = ba:readInt()
    end
    self.null_data  = ba:readBool()
end

CMD_GAME_FISH.CMD_S_HitFishLK = class("CMD_S_HitFishLK",CMDBase) --1703
function CMD_GAME_FISH.CMD_S_HitFishLK:readFormByteArray(ba)
    self.fish_id       = ba:readInt()
    self.chair_id      = ba:readWORD()
    self.fish_mulriple = ba:readInt()
    self.null_data     = ba:readBool()
end

CMD_GAME_FISH.CMD_S_CatchSweepFish = class("CMD_S_CatchSweepFish",CMDBase) --1705
function CMD_GAME_FISH.CMD_S_CatchSweepFish:readFormByteArray(ba)
    self.fish_id = ba:readInt()
    self.chair_id = ba:readWORD()
    self.null_data  = ba:readBool()
end


CMD_GAME_FISH.CMD_S_CatchSweepFishResult = class("CMD_S_CatchSweepFishResult",CMDBase) --1704
function CMD_GAME_FISH.CMD_S_CatchSweepFishResult:readFormByteArray(ba)
    self.fish_id = ba:readInt()
    self.chair_id = ba:readWORD()
    self.fish_score = ba:readLONGLONG()
    self.catch_fish_count = ba:readInt()
    self.catch_fish_id = {}
    for  i = 1, self.catch_fish_count do
        self.catch_fish_id[i] = ba:readInt()
    end
    self.null_data  = ba:readBool()
end

CMD_GAME_FISH.CMD_S_BulletIonTimeout = class("CMD_S_BulletIonTimeout",CMDBase) --1707
function CMD_GAME_FISH.CMD_S_BulletIonTimeout:readFormByteArray(ba)
    self.chair_id = ba:readWORD()
end

CMD_GAME_FISH.CMD_S_CatchFish = class("CMD_S_CatchFish",CMDBase) --1708
function CMD_GAME_FISH.CMD_S_CatchFish:readFormByteArray(ba)
    self.chair_id   = ba:readWORD()
    self.fish_score = ba:readLONGLONG()
    self.fish_id    = ba:readInt()
    self.bullet_ion = ba:readBool()
    self.fish_kind  = ba:readInt()
    self.null_data  = ba:readBool()
end

CMD_GAME_FISH.CMD_S_UserFire = class("CMD_S_UserFire",CMDBase) --1709
function CMD_GAME_FISH.CMD_S_UserFire:readFormByteArray(ba)
    self.null_data       = ba:readBool()
    self.chair_id        = ba:readWORD()
    self.bullet_id       = ba:readInt()
    self.bullet_mulriple = ba:readInt()
    self.lock_fishid     = ba:readInt()
    self.android_chairid = ba:readWORD()
    self.angle           = ba:readFloat()
    self.fish_score      = ba:readLONGLONG()
    self.bullet_kind     = ba:readInt()
end

CMD_GAME_FISH.CMD_S_ExchangeFishScore = class("CMD_S_ExchangeFishScore",CMDBase) --1710
function CMD_GAME_FISH.CMD_S_ExchangeFishScore:readFormByteArray(ba)
    self.chair_id            = ba:readWORD()
    self.null_data           = ba:readBool()
    self.exchange_fish_score = ba:readLONGLONG()
    self.swap_fish_score     = ba:readLONGLONG()
end

----------------------------------------------------------
-- 客户端命令

CMD_GAME_FISH.MDM_GF_GAME              = 200               --游戏消息(主命令)
CMD_GAME_FISH.SUB_C_ANDROID_BULLET_MUL = 71
CMD_GAME_FISH.SUB_C_FISH20_CONFIG      = 72
CMD_GAME_FISH.SUB_C_ANDROID_STAND_UP   = 73
CMD_GAME_FISH.SUB_C_USER_FILTER        = 74
CMD_GAME_FISH.SUB_C_STOCK_OPERATE      = 75
CMD_GAME_FISH.SUB_C_HIT_FISH_I         = 76
CMD_GAME_FISH.SUB_C_CATCH_SWEEP_FISH   = 77
CMD_GAME_FISH.SUB_C_CATCH_FISH         = 78
CMD_GAME_FISH.SUB_C_USER_FIRE          = 79
CMD_GAME_FISH.SUB_C_EXCHANGE_FISHSCORE = 80

CMD_GAME_FISH.CMD_C_UserFire = class("CMD_C_UserFire",CMDBase) --发炮
function CMD_GAME_FISH.CMD_C_UserFire:writeToByteArray(ba)
    ba:writeBool(self.null_data)
    ba:writeInt(self.bullet_mulriple)
    ba:writeInt(self.lock_fishid)
    ba:writeFloat(self.angle)
    ba:writeInt(self.bullet_kind)
end

CMD_GAME_FISH.CMD_C_CatchFish = class("CMD_C_CatchFish",CMDBase) --发炮
function CMD_GAME_FISH.CMD_C_CatchFish:writeToByteArray(ba)
    ba:writeWORD(self.chair_id)
    ba:writeBool(self.null_data)
    ba:writeInt(self.bullet_id)
    ba:writeInt(self.fish_id)
    ba:writeInt(self.bullet_mulriple)
    ba:writeInt(self.bullet_kind)
end

CMD_GAME_FISH.CMD_C_ExchangeFishScore = class("CMD_C_ExchangeFishScore",CMDBase) --换炮
function CMD_GAME_FISH.CMD_C_ExchangeFishScore:writeToByteArray(ba)
    ba:writeBool(self.null_data)
    ba:writeBool(self.increase)
end

CMD_GAME_FISH.CMD_C_CatchSweepFish = class("CMD_C_CatchSweepFish",CMDBase)
function CMD_GAME_FISH.CMD_C_CatchSweepFish:writeToByteArray(ba)
    ba:writeInt(self.fish_id)
    ba:writeWORD(self.chair_id)
    ba:writeBool(self.null_data)
    ba:writeInt(self.catch_fish_count)

    for  i = 1, self.catch_fish_count do
        ba:writeInt(self.catch_fish_id[i])
    end

    if self.catch_fish_count < 300 then
        for i = self.catch_fish_count + 1 ,300 do
            ba:writeInt(0)
        end
    end
end

CMD_GAME_FISH.CMD_C_HitFishLK = class("CMD_C_HitFishLK",CMDBase)
function CMD_GAME_FISH.CMD_C_HitFishLK:writeToByteArray(ba)
    ba:writeInt(self.fish_id)
end



return CMD_GAME_FISH
