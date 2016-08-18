--是否测试版,0:非测试
TEST = 0

-- 0 - disable debug info, 1 - less debug info, 2 - verbose debug info
DEBUG = 0

-- use framework, will disable all deprecated API, false - use legacy API
CC_USE_FRAMEWORK = true

-- show FPS on screen
CC_SHOW_FPS = true --代码动态控制

-- disable create unexpected global variable
CC_DISABLE_GLOBAL = false

-- for module display
CC_DESIGN_RESOLUTION = {
    --默认值
    width = 1280,
    height = 720,
    autoscale = "FIXED_WIDTH",--NO_BORDER,FIXED_HEIGHT
    callback = function(framesize)
        local ratio = framesize.width / framesize.height
        if ratio <= 1.34 then
            -- iPad 768*1024(1536*2048) is 4:3 screen
            return {autoscale = CC_DESIGN_RESOLUTION.autoscale}
        end
    end,
    orientation = 0,--当前屏幕方向
    setRequestedOrientation = function(requestedOrientation) --设置屏幕方向
        if requestedOrientation == CC_DESIGN_RESOLUTION.orientation then
    	   return
        end
        local SDKControlHandler = import("app/handler/SDKControlHandler.lua")

		--设置平台屏幕方向
        local map = {}
        map.requestedOrientation = requestedOrientation
        SDKControlHandler:getInstance():sendMessage(SDKControlHandler.SendMsgList.CCSetRequestedOrientation,map)
        local glView = cc.Director:getInstance():getOpenGLView()
        if requestedOrientation == 0 then -- 横屏
            CC_DESIGN_RESOLUTION.orientation = 0
            CC_DESIGN_RESOLUTION.width = 1280
            CC_DESIGN_RESOLUTION.height = 720
            CC_DESIGN_RESOLUTION.autoscale = "FIXED_WIDTH"
        elseif requestedOrientation == 1 then --竖屏
            CC_DESIGN_RESOLUTION.orientation = 1
            CC_DESIGN_RESOLUTION.width = 720
            CC_DESIGN_RESOLUTION.height = 1280
            CC_DESIGN_RESOLUTION.autoscale = "FIXED_HEIGHT"
        end

        --重置坐标系
        local frameSize = glView:getFrameSize()
        glView:setFrameSize(frameSize.height,frameSize.width)
		glView:setDesignResolutionSize(CC_DESIGN_RESOLUTION.width,CC_DESIGN_RESOLUTION.height,cc.ResolutionPolicy.FIXED_HEIGHT)

        --重置display
		package.loaded["cocos.framework.display"] = nil
		display    = require("cocos.framework.display")
    end
}
