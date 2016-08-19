--
-- Author: wenqing
-- Date: 2016-04-21 16:59:54
--

local ArmatureManager = class("ArmatureManager")

function ArmatureManager:ctor()
end

--加载所有子弹的骨骼动画
function ArmatureManager:loadAllBulletArmature()
	for _,v in pairs(CannonConfig.KIND) do
		if CannonConfig.BULLET_ANI_TYPE[v] == CannonConfig.ANI_TYPE.ARMATURE then
			self:addAnimateArmature(CannonConfig.BULLET_RES[v][1])
		end
	end
end

--删除所有子弹的骨骼动画
function ArmatureManager:removeAllBulletArmature()
	for _,v in pairs(CannonConfig.KIND) do
		if CannonConfig.BULLET_ANI_TYPE[v] == CannonConfig.ANI_TYPE.ARMATURE then
			self:removeModelArmature(CannonConfig.BULLET_RES[v][1])
		end
	end
end

--加载动画
function ArmatureManager:addAnimateArmature(armatureName, callback)

	print("armatureName = "..armatureName)
	ccs.ArmatureDataManager:getInstance():addArmatureFileInfoAsync("armature/".. armatureName .. ".png",
		"armature/".. armatureName .. ".plist", "armature/".. armatureName .. ".xml", function()
		if callback then
			callback()
		end
		end)
end

--删除动画资源
function ArmatureManager:removeModelArmature(armatureName)
	ccs.ArmatureDataManager:getInstance():removeArmatureFileInfo("armature/".. armatureName .. ".xml")
end

--播放动画
function ArmatureManager:playArmature(armature, animationName , durationTo, loop)
	armature:getAnimation():play(animationName, durationTo or -1, loop or 1)
    --    armature:getAnimation():setSpeedScale(32/60)
end

return ArmatureManager
