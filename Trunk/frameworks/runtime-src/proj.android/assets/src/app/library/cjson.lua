local json = nil
if device.platform == "windows" then
    json = require "cocos.cocos2d.json"
else
    json = require "cjson"
end
return json