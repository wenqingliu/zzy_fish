--
-- Author: Wenqing
-- Date: 2016-04-21 18:10:33
--

CannonConfig = CannonConfig or {}

--动画类型定义
CannonConfig.ANI_TYPE = {NORMAL = 1, ARMATURE = 2, FRAME = 3}

--炮台类型
CannonConfig.KIND = {}
CannonConfig.KIND.BULLET1 = 0
CannonConfig.KIND.BULLET2 = 1

--子弹动画类型
CannonConfig.BULLET_ANI_TYPE = {}
CannonConfig.BULLET_ANI_TYPE[CannonConfig.KIND.BULLET1] = CannonConfig.ANI_TYPE.NORMAL
CannonConfig.BULLET_ANI_TYPE[CannonConfig.KIND.BULLET2] = CannonConfig.ANI_TYPE.NORMAL


--网（子弹爆炸）动画类型
CannonConfig.NET_ANI_TYPE = {}
CannonConfig.NET_ANI_TYPE[CannonConfig.KIND.BULLET1] = CannonConfig.ANI_TYPE.NORMAL
CannonConfig.NET_ANI_TYPE[CannonConfig.KIND.BULLET2] = CannonConfig.ANI_TYPE.FRAME

--网半径
CannonConfig.NET_RADIUS = {}
CannonConfig.NET_RADIUS[CannonConfig.KIND.BULLET1] = 150
CannonConfig.NET_RADIUS[CannonConfig.KIND.BULLET2] = 200

--炮筒图片资源
CannonConfig.GUN_RES = {}
CannonConfig.GUN_RES[CannonConfig.KIND.BULLET1] = "#gun1.png"
CannonConfig.GUN_RES[CannonConfig.KIND.BULLET2] = "#gun2.png"

--子弹图片资源/动画资源
CannonConfig.BULLET_RES = {}
CannonConfig.BULLET_RES[CannonConfig.KIND.BULLET1] = "#bullet1.png"--{"bullet2_ion","bullet1_ion","bullet1_ion"}
CannonConfig.BULLET_RES[CannonConfig.KIND.BULLET2] = "#bullet1.png"

CannonConfig.NET_RES = {}
CannonConfig.NET_RES[CannonConfig.KIND.BULLET1] = "#wang.png"
CannonConfig.NET_RES[CannonConfig.KIND.BULLET2] = {"guang",1,8,24} --图片名，起始帧，结束帧，帧率

return CannonConfig
