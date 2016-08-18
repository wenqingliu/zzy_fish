FishConfig = FishConfig or {}

--鱼种类
FishConfig.KIND = {}

FishConfig.KIND.HUANGQIYU  = 0 --黄鳍鱼
FishConfig.KIND.HONGTOUYU  = 1 --红头鱼
FishConfig.KIND.XIAOCHOUYU = 2 --小丑鱼
FishConfig.KIND.HEIDIAOYU  = 3 --黑鲷鱼
FishConfig.KIND.SHUIMU     = 4 --水母
FishConfig.KIND.HETUN      = 5 --河豚
FishConfig.KIND.XUEYU      = 6 --鳕鱼
FishConfig.KIND.WUZEI      = 7 --乌贼
FishConfig.KIND.HAIGUI     = 8 --海龟
FishConfig.KIND.DIANMAN    = 9 --电鳗
FishConfig.KIND.SHIBANYU   = 10 --石斑鱼
FishConfig.KIND.QIE        = 11 --企鹅
FishConfig.KIND.SHIZIYU    = 12 --狮子鱼
FishConfig.KIND.PANGXIE    = 13 --螃蟹
FishConfig.KIND.HAITUN     = 14 --海豚
FishConfig.KIND.MOGUIYU    = 15 --魔鬼鱼
FishConfig.KIND.SHAYU      = 16 --鲨鱼
FishConfig.KIND.MEIRENYU   = 17 --美人鱼
FishConfig.KIND.DIWANGXIE  = 18 --帝王蟹
FishConfig.KIND.JINGUI     = 19 --金龟
FishConfig.KIND.JINSHA     = 20 --金鲨

--资源名
FishConfig.RES = {}

FishConfig.RES[FishConfig.KIND.HUANGQIYU]  = "huangqiyu"
FishConfig.RES[FishConfig.KIND.XIAOCHOUYU] = "xiaochouyu"
FishConfig.RES[FishConfig.KIND.HONGTOUYU]  = "hongtouyu"
FishConfig.RES[FishConfig.KIND.HEIDIAOYU]  = "heidiaoyu"
FishConfig.RES[FishConfig.KIND.SHUIMU]     = "shuimu"
FishConfig.RES[FishConfig.KIND.DIANMAN]    = "dianman"
FishConfig.RES[FishConfig.KIND.HAIGUI]     = "haigui"
FishConfig.RES[FishConfig.KIND.HETUN]      = "hetun"
FishConfig.RES[FishConfig.KIND.XUEYU]      = "xueyu"
FishConfig.RES[FishConfig.KIND.WUZEI]      = "wuzei"
FishConfig.RES[FishConfig.KIND.SHIBANYU]   = "shibanyu"
FishConfig.RES[FishConfig.KIND.HAITUN]     = "haitun"
FishConfig.RES[FishConfig.KIND.SHAYU]      = "shayu"
FishConfig.RES[FishConfig.KIND.MOGUIYU]    = "moguiyu"
FishConfig.RES[FishConfig.KIND.SHIZIYU]    = "shiziyu"
FishConfig.RES[FishConfig.KIND.QIE]        = "qie"
FishConfig.RES[FishConfig.KIND.PANGXIE]    = "pangxie"
FishConfig.RES[FishConfig.KIND.MEIRENYU]   = "meirenyu"
FishConfig.RES[FishConfig.KIND.DIWANGXIE]  = "diwangxie"
FishConfig.RES[FishConfig.KIND.JINGUI]     = "jingui"
FishConfig.RES[FishConfig.KIND.JINSHA]     = "jinsha"

--游泳动画帧 {起始帧，结束帧，帧率}
FishConfig.SWIM_ANIM_FRAME = {}

local frame = 12

FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.HUANGQIYU]  = {1,10,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.XIAOCHOUYU] = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.HONGTOUYU]  = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.HEIDIAOYU]  = {1,10,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.SHUIMU]     = {1,18,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.DIANMAN]    = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.HAIGUI]     = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.HETUN]      = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.XUEYU]      = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.WUZEI]      = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.SHIBANYU]   = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.HAITUN]     = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.SHAYU]      = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.MOGUIYU]    = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.SHIZIYU]    = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.QIE]        = {1,11,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.PANGXIE]    = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.DIWANGXIE]  = {1,13,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.MEIRENYU]   = {1,15,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.JINGUI]     = {1,15,frame}
FishConfig.SWIM_ANIM_FRAME[FishConfig.KIND.JINSHA]     = {1,13,frame}

--死亡动画帧
FishConfig.DIE_ANIM_FRAME = {}

FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.HUANGQIYU]  = {1,8,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.XIAOCHOUYU] = {1,8,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.HONGTOUYU]  = {1,8,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.HEIDIAOYU]  = {1,8,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.SHUIMU]     = {1,9,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.DIANMAN]    = {1,6,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.HAIGUI]     = {1,5,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.HETUN]      = {1,9,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.XUEYU]      = {1,5,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.WUZEI]      = {1,5,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.SHIBANYU]   = {1,9,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.HAITUN]     = {1,5,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.SHAYU]      = {1,9,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.MOGUIYU]    = {1,10,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.SHIZIYU]    = {1,9,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.QIE]        = {1,9,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.PANGXIE]    = {1,8,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.DIWANGXIE]  = {1,8,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.MEIRENYU]   = {1,14,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.JINGUI]     = {1,9,frame}
FishConfig.DIE_ANIM_FRAME[FishConfig.KIND.JINSHA]     = {1,13,frame}

--BoundingBox size
FishConfig.BOUNDINGBOX = {}

FishConfig.BOUNDINGBOX[FishConfig.KIND.HUANGQIYU]  = { w = 54, h = 40}
FishConfig.BOUNDINGBOX[FishConfig.KIND.XIAOCHOUYU] = { w = 75, h = 48}
FishConfig.BOUNDINGBOX[FishConfig.KIND.HONGTOUYU]  = { w = 60, h = 46}
FishConfig.BOUNDINGBOX[FishConfig.KIND.HEIDIAOYU]  = { w = 115, h = 84}
FishConfig.BOUNDINGBOX[FishConfig.KIND.SHUIMU]     = { w = 118, h = 130}
FishConfig.BOUNDINGBOX[FishConfig.KIND.DIANMAN]    = { w = 180, h = 67}
FishConfig.BOUNDINGBOX[FishConfig.KIND.HAIGUI]     = { w = 130, h = 150}
FishConfig.BOUNDINGBOX[FishConfig.KIND.HETUN]      = { w = 120, h = 79}
FishConfig.BOUNDINGBOX[FishConfig.KIND.XUEYU]      = { w = 130, h = 63}
FishConfig.BOUNDINGBOX[FishConfig.KIND.WUZEI]      = { w = 164, h = 190}
FishConfig.BOUNDINGBOX[FishConfig.KIND.SHIBANYU]   = { w = 140, h = 79}
FishConfig.BOUNDINGBOX[FishConfig.KIND.HAITUN]     = { w = 350, h = 152}
FishConfig.BOUNDINGBOX[FishConfig.KIND.SHAYU]      = { w = 410, h = 184}
FishConfig.BOUNDINGBOX[FishConfig.KIND.MOGUIYU]    = { w = 350, h = 291}
FishConfig.BOUNDINGBOX[FishConfig.KIND.SHIZIYU]    = { w = 170, h = 158}
FishConfig.BOUNDINGBOX[FishConfig.KIND.QIE]        = { w = 105, h = 108}
FishConfig.BOUNDINGBOX[FishConfig.KIND.PANGXIE]    = { w = 135, h = 113}
FishConfig.BOUNDINGBOX[FishConfig.KIND.DIWANGXIE]  = { w = 360, h = 302}
FishConfig.BOUNDINGBOX[FishConfig.KIND.MEIRENYU]   = { w = 500, h = 302}
FishConfig.BOUNDINGBOX[FishConfig.KIND.JINGUI]     = { w = 288, h = 310}
FishConfig.BOUNDINGBOX[FishConfig.KIND.JINSHA]     = { w = 430, h = 195}

--路线数量
FishConfig.TRACE_COUNT = {}

FishConfig.TRACE_COUNT[FishConfig.KIND.HUANGQIYU]  = 10 --黄鳍鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.XIAOCHOUYU] = 10 --小丑鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.HONGTOUYU]  = 10 --红头鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.HEIDIAOYU]  = 10 --黑鲷鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.SHUIMU]     = 10 --水母
FishConfig.TRACE_COUNT[FishConfig.KIND.DIANMAN]    = 10 --电鳗
FishConfig.TRACE_COUNT[FishConfig.KIND.HAIGUI]     = 10 --海龟
FishConfig.TRACE_COUNT[FishConfig.KIND.HETUN]      = 10 --河豚
FishConfig.TRACE_COUNT[FishConfig.KIND.XUEYU]      = 10 --鳕鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.WUZEI]      = 10 --乌贼
FishConfig.TRACE_COUNT[FishConfig.KIND.SHIBANYU]   = 10 --石斑鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.HAITUN]     = 10 --海豚
FishConfig.TRACE_COUNT[FishConfig.KIND.SHAYU]      = 10 --鲨鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.MOGUIYU]    = 10 --魔鬼鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.SHIZIYU]    = 10 --狮子鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.QIE]        = 10 --企鹅
FishConfig.TRACE_COUNT[FishConfig.KIND.PANGXIE]    = 10 --螃蟹
FishConfig.TRACE_COUNT[FishConfig.KIND.MEIRENYU]   = 11 --美人鱼
FishConfig.TRACE_COUNT[FishConfig.KIND.DIWANGXIE]  = 6 --帝王蟹
FishConfig.TRACE_COUNT[FishConfig.KIND.JINGUI]     = 6 --金龟
FishConfig.TRACE_COUNT[FishConfig.KIND.JINSHA]     = 6 --金鲨

--路线
FishConfig.TRACE = {}

FishConfig.TRACE[FishConfig.KIND.HUANGQIYU]  = {}
FishConfig.TRACE[FishConfig.KIND.XIAOCHOUYU] = {}
FishConfig.TRACE[FishConfig.KIND.HONGTOUYU]  = {}
FishConfig.TRACE[FishConfig.KIND.HEIDIAOYU]  = {}
FishConfig.TRACE[FishConfig.KIND.SHUIMU]     = {}
FishConfig.TRACE[FishConfig.KIND.DIANMAN]    = {}
FishConfig.TRACE[FishConfig.KIND.HAIGUI]     = {}
FishConfig.TRACE[FishConfig.KIND.HETUN]      = {}
FishConfig.TRACE[FishConfig.KIND.XUEYU]      = {}
FishConfig.TRACE[FishConfig.KIND.WUZEI]      = {}
FishConfig.TRACE[FishConfig.KIND.SHIBANYU]   = {}
FishConfig.TRACE[FishConfig.KIND.HAITUN]     = {}
FishConfig.TRACE[FishConfig.KIND.SHAYU]      = {}
FishConfig.TRACE[FishConfig.KIND.MOGUIYU]    = {}
FishConfig.TRACE[FishConfig.KIND.SHIZIYU]    = {}
FishConfig.TRACE[FishConfig.KIND.QIE]        = {}
FishConfig.TRACE[FishConfig.KIND.PANGXIE]    = {}
FishConfig.TRACE[FishConfig.KIND.DIWANGXIE]  = {}
FishConfig.TRACE[FishConfig.KIND.MEIRENYU]   = {}
FishConfig.TRACE[FishConfig.KIND.JINGUI]     = {}
FishConfig.TRACE[FishConfig.KIND.JINSHA]     = {}

--鱼潮
FishConfig.TRACE_COUNT[101] = 210 --一个圈里面有花从右边游出来
FishConfig.TRACE_COUNT[102] = 214 --上下两排很多鱼
FishConfig.TRACE_COUNT[103] = 242 --两个圈从两边游出来
FishConfig.TRACE_COUNT[104] = 64 --两排两排鱼斜面游出来
FishConfig.TRACE_COUNT[105] = 236 --两个层叠圆圈

FishConfig.TRACE[101] = {}
FishConfig.TRACE[102] = {}
FishConfig.TRACE[103] = {}
FishConfig.TRACE[104] = {}
FishConfig.TRACE[105] = {}

return FishConfig
