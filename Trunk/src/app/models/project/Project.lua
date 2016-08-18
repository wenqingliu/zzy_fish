local Project = class("Project")

Project.ProudctVersions = 6 -- 产品版本号
Project.AppVersions = "3.10.0" -- 程序版本号
Project.Versions = "3.10.20" -- 热更新版本号

Project.addressList = {
    --主IP
    {
        -- LoginAddress = "120.24.70.142",
        LoginAddress = "192.168.0.189",
    },
    -- {
    --     LoginAddress = "119.63.37.230",
    -- },
    -- {
    --     LoginAddress = "119.63.37.245",
    -- },
    -- --副IP
    -- {
    --     LoginAddress = "183.60.233.222",
    -- },
    -- {
    --     LoginAddress = "119.63.37.222",
    -- },
    -- {
    --     LoginAddress = "183.60.233.4",
    -- },
    -- {
    --     LoginAddress = "119.63.37.4",
    -- }
}

--Project.addressList = {
--    {
--        LoginAddress = "61.147.113.53"
--    },
--    {
--        LoginAddress = "61.147.113.16"
--    },
--    --副IP
--    {
--        LoginAddress = "61.147.113.16"
--    },
--    {
--        LoginAddress = "183.60.233.230"
--    }
--}

Project.LoginAddress = Project.addressList[1].LoginAddress
Project.LoginPort = 8300
Project.URLPort = ":2020"

--Project.LoginAddress = "120.24.70.142"
--Project.URLPort = ":80"

--Project.LoginAddress = "192.168.0.110"
--Project.URLPort = ":80"

--Project.LoginAddress = "183.60.233.230"
--Project.URLPort = ":2020"

--Project.LoginAddress = "61.147.113.53"
--Project.URLPort = ":8931"

--Project.LoginAddress = "61.147.113.16"

--下载、头像服务器域名
Project.domainURL = "http://www.zzy1314.com"

Project.LogonValidateKey = "937A4673-5B26-4AB8-857E-46153403FBD3"
Project.AppId = 27
Project.RoomNameList = {"新百人", "摇摇乐", "二人", "百变", "无王百人牛", "水果机", "对战牛牛",
    "德州扑克","公婆大战","看牌抢庄","飞禽走兽","李逵劈鱼"}

--登录类型
Project.LogonType_Enum = {
    LogonType_Tourist=0,
    LogonType_QQ=1,
    LogonType_Sina=2,
    LogonType_Email=3,
    LogonType_NineOne=4,
    LogonType_WeChat=5,
    LogonType_360=6,
    LogonType_Fetion=7,
    LogonType_XiaoMi=8,
    LogonType_UC=9,
}

--可登录按钮列表可见性,与LogonType_Enum对应
Project.LogonBtn_List = {
    true,   --LogonType_Tourist
--    true,   --LogonType_QQ
}

function Project:getDeviceType()
    if device.platform == "windows" then
        return 0x10 --共用安卓类型
    elseif device.platform == "android" then
        return 0x10
    elseif device.platform == "ios" then
        return 0x20
    end
end

function Project:getVersionClient()
    local cbMainVer,cbSubVer,cbBuildVer = Project:getVersionList(self.AppVersions)
    local ver = bit.blshift(self.ProudctVersions, 24) + bit.blshift(cbMainVer,16) + bit.blshift(cbSubVer,8) + cbBuildVer
    return ver
end

function Project:getVersionList(versions)
    local ver = string.split(versions,".")
    local cbMainVer,cbSubVer,cbBuildVer = tonumber(ver[1]),tonumber(ver[2]),tonumber(ver[3])
    cbMainVer = cbMainVer or 0
    cbSubVer = cbSubVer or 0
    cbBuildVer = cbBuildVer or 0
    return cbMainVer,cbSubVer,cbBuildVer
end

--获取玩家信息
function Project:getUserInfoURL(gameid)
    return self:getActionURL() .. "/getUserInfo.aspx?gameid=" .. gameid
end

--判断好友关系
--返回结果 0 无任何关系 1 待对方通过好友验证 2 已是好友 3对方在我的黑名单列表
function Project:getFriendShipURL()
    return self:getActionURL() .. "/getFriendShip.aspx?myid=%d&gameid=%d"
end

--商品列表
function Project:getProductURL()
    local storetype = device.platform == "ios" and 1 or 0
    local devicetype = device.platform == "ios" and 0 or 1
    return self:getActionURL().."/getProduct.aspx?appid=27&storetype="..storetype.."&devicetype="..devicetype
--    return "http://61.147.113.16:2020/getProduct.aspx?appid=27&storetype=1&devicetype=0"
end

--获取订单号
function Project:getOrderNo(gameid,productid)
    return self:getActionURL() .. "/GetOrderNo.aspx?gameid="..gameid.."&productid="..productid
end

--购买支付结果通知
function Project:getNotifyURL(type)
    if type == 0 then --appstore
        return self:getActionURL() .. "/VailPay.aspx"
    elseif type == 1 then --支付宝
        return self:getActionURL() .. "/alipay.aspx"
--        return "http://" .. "120.24.70.142" .. ":1080" .. "/alipay.aspx"
    end
    return ""
end

--添加消费记录
function Project:getAddExpenseURL(userid,productid)
    return self:getActionURL() ..  "/AddExpense.aspx?appid=" .. self.AppId .. "&userid=" .. userid .. "&productid=" .. productid .."&count=1"
end

--获取排行榜
function Project:getRankUrl(which)
    if which == 1 then
        return self:getActionURL() .."/getScoreRank.aspx"
    else
        return self:getActionURL() .."/getScoreRank.aspx?type=gift"
    end
end

--获取活动列表
function Project:getActivityUrl()
    return self:getActionURL() .."/getTrophy.aspx"
end

--获取控制
function Project:getTransfer(storetype,devicetype,markettype,version)
    return self:getActionURL()
        .."/getTransfer.aspx?appid=27&storetype="..storetype.."&devicetype="..devicetype.."&markettype="..markettype.."&version="..version
end

--获取公告栏网站地址
function Project:getBulletinURL(platform)
    return "http://app.qq.com/#id=detail&appid=1104499581"
end

--App下载地址
function Project:getAppURL()
    return "http://www.zzy1314.com/niuniu.html"
end

function Project:getOrginal(gameid,type)
    return self:getActionURL() .. "/getOrginal.aspx?gameid="..gameid.."&type="..type
end

function Project:getGameWebSite()
    return self.domainURL
end

function Project:getActionURL()
    return "http://" .. self.LoginAddress .. Project.URLPort
--    return self.actionURL
end

return Project
