local loadingWord = {
    "为了维护健康的娱乐环境，请勿私下进行游戏买卖!",
    "金币输光了不要紧，每天都可在大厅领取复活金哦!",
    "下注手要快哦，买定离手!",
    "游戏中有小按钮可以查看十局输赢走势哦!",
    "据说打出五花牛的概率是万分之三哟!",
    "牌型相同取最大的一张牌决出输赢，K最大A最小，记住哦!",
    "注意账户安全，不要随意透露自己的账户密码哦!",
    "五张牌中取三张加起来为十或二十就会牛的哟!",
    "新手教程中有倍数表可以查的哟!",
    "亲~游戏娱乐时记得注意休息哟!",
    "游戏中注意小红包的出现，可以抢哦!",
    "游戏闪退或者掉线，请检查网络环境或者游戏版本是否最新哟!"
}

function loadingWord:getLoadingTime()
	return "26"
end
function loadingWord:getWordByIndex(index)
    if self[index] ~= nil then
        return self[index]
	end
	return nil
end

function loadingWord:getWordByRandom()
	math.randomseed(os.time())
--	local count = 0
--	for i, v in ipairs(self) do
--		count = count + 1
--	end
    print("count :"..#self)
    local rand_ = math.random(1,#self)
	return self[rand_]
end
return loadingWord