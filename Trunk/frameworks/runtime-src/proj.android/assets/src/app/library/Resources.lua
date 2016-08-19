Resources = {}
local map = nil

-----
--return string.plist文件String字段
function Resources:getString(key)
    if(map == nil) then
        local file = cc.FileUtils:getInstance():fullPathForFilename("string.plist")
        map = cc.FileUtils:getInstance():getValueMapFromFile(file)
    end
    return map[key]
end

---------------------------
-- cc.CSLoader:createNode加载文件并执行ccui.Helper:doLayout适配
-- @return Node#Node Node (return value: cc.Node)
function Resources:createNodeAndDoLayout(filename)
    local node = cc.CSLoader:createNode(filename)
    node:setContentSize(cc.Director:getInstance():getOpenGLView():getVisibleSize())
    ccui.Helper:doLayout(node)
    return node
end

---------------------------
-- 满屏显示
function Resources:setFullScaleY(node)
    local scaleH = (display.height / node:getContentSize().height)
    if scaleH > 1 then
        node:setScaleY(scaleH)
    end
    return node
end

---------------------------
-- 获取listview；注意:ListView在win32下显示可能不正确,如出现白底、无法裁切内容、超出显示区域等情况，在android或IOS上正常
-- @return Listview#Listview Listview (return value: ccui.Listview)
function Resources:getListView(panel,listviewName)
    local listview = panel:getChildByName(listviewName)
    --已废弃
--    if device.platform == "windows" then
--        listview:setClippingEnabled(false)--win32下关闭裁切
--    end
    return listview
end

function Resources:setClippingEnabled(widget)
    --已废弃
--    if device.platform == "windows" then
--        widget:setClippingEnabled(false)--win32下关闭裁切
--    end
    return widget
end

---------------------------
-- SpriteFrameCache类方法简写
--@return 
function Resources:addSpriteFrames(plist)
    cc.SpriteFrameCache:getInstance():addSpriteFrames(plist)
end

---------------------------
-- SpriteFrameCache类方法简写
--@return 
function Resources:removeSpriteFrameByName(plist)
    cc.SpriteFrameCache:getInstance():removeSpriteFrameByName(plist)
end

function Resources:removeUnusedAllRes()
    --按顺序释放资源
--    cc.AnimationCache:getInstance():destroyInstance()
--    cc.SpriteFrameCache:getInstance():removeUnusedSpriteFrames()

    --引擎BUG，引擎图片需避免释放
    local play_background = cc.Director:getInstance():getTextureCache():getTextureForKey("play_background")
    local play_enable = cc.Director:getInstance():getTextureCache():getTextureForKey("play_enable")
    local cc_2x2_white_image = cc.Director:getInstance():getTextureCache():getTextureForKey("cc_2x2_white_image")
    local shine = cc.Director:getInstance():getTextureCache():getTextureForKey("shine")
    if play_background ~= nil then
        play_background:retain()
        play_enable:retain()
--        cc_2x2_white_image:retain()
        shine:retain()
    else
        print("shine")
    end

--    cc.Director:getInstance():getTextureCache():removeUnusedTextures()
    cc.Director:getInstance():purgeCachedData()

    if play_background ~= nil then
        play_background:release()
        play_enable:release()
--        cc_2x2_white_image:release()
        shine:release()
    end

end

function Resources:unloadSoundByList(list)
    for i=1,#list do
        audio.unloadSound(list[i])
    end
end

return Resources