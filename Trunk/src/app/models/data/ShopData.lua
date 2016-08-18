local ShopData = {}

--钻石
if jt.SDKControl:getInstance():getSDKPlatform() == 1 then --应用宝
    ShopData.diamondNum = {60,300,600,1080,2080,6180}
    ShopData.diamondMoney = {6,30,60,108,208,618}
else
    ShopData.diamondNum = {60,390,800,1500,3000,9680}
    ShopData.diamondMoney = {6,30,60,108,208,618}
end

--金币
ShopData.MoneyNum = {50000,100000,500000,1000000,2000000,5000000}
ShopData.MoneyDiamond = {50,100,500,1000,2000,5000}

return ShopData
