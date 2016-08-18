MotionUtil = {}--MotionUtil or {}

----------------------
--延迟执行回调方法
-- @param self
-- @param time int
-- @param callback function
-- @param parament table
function MotionUtil:delayCallFunc(time,callback,parament)
    parament = parament or {}
    local delay = cc.DelayTime:create(time)
    local func = cc.CallFunc:create(callback,parament)
    local seq = cc.Sequence:create({delay,func})
    return seq
end

----------------------
--注册最顶层,屏蔽底层事件
function MotionUtil:addEventListenerWithSceneGraphPriorityTop(node)
    local listener = cc.EventListenerTouchOneByOne:create()
    listener:setSwallowTouches(true);
    local function onTouch()
        return true
    end
    listener:registerScriptHandler(onTouch,cc.Handler.EVENT_TOUCH_BEGAN)
    cc.Director:getInstance():getEventDispatcher():
        addEventListenerWithSceneGraphPriority(listener,node)
    return listener
end

--根据触摸点坐标获取指定grid索引
function MotionUtil:touchPointToCell(rect,col,row)
    local cellX = math.modf((rect.x) / rect.width)
    local cellY = math.modf((rect.y) / rect.height)
    local cell = {}
    cell.x = cellX + 1
    cell.y = cellY + 1
    if cell.x > col or rect.x < -rect.width/2 or
        cell.y > row or rect.y < -rect.height/2 then
        cell = nil
    end
    return cell
end

----------------------
--获取触屏node对象
---- @param #touch
---- @param #event
---- @return bool(是否目标触屏对象);node(当前触屏对象)
function MotionUtil:checkTouchPointToNode(touch,event)
    local node = event:getCurrentTarget()
    if not node:getVisible() then return false end
    local size = node:getContentSize()
    local rect = cc.rect(0,0,size.width,size.height)
    local point = node:convertTouchToNodeSpace(touch)
    if cc.rectContainsPoint(rect,point) then
        return true,node
    end
    return false,node
end

----------------------
---- @param #node
---- @param #event
---- @return bool(是否目标触屏对象)
function MotionUtil:checkPointToNode(node,event)
    if not node:isVisible() then return false end
    local point =  node:convertToNodeSpace(event)
    local size = node:getContentSize()
    local rect = cc.rect(0,0,size.width,size.height)
    if cc.rectContainsPoint(rect,point) then
        return true
    end
    return false
end

function MotionUtil:checkOnClick(node,event)
    if event.name == "moved" then return end
    local point =  node:convertToNodeSpace(event)
    local size = node:getContentSize()
    local rect = cc.rect(0,0,size.width,size.height)
    if cc.rectContainsPoint(rect,point) then
        if event.name == "began" then
            MotionUtil._beganTarget = node
        elseif event.name == "ended" then
            if MotionUtil._beganTarget == node then
                MotionUtil._beganTarget = nil
                return true
            end
        end
    else
        MotionUtil._beganTarget = nil
    end
    return false

end

----------------------
--  替换为网络图片为头像
---- @return jt.SpriteURL
function MotionUtil:RepleaceWithURLPic(node,user,size,defaultPic,isNoMask,isLight)

    local pos_mask = cc.p(node:getPositionX(),node:getPositionY())
    local parentNode = node:getParent()
    local order = node:getLocalZOrder()
    node:retain()

    --移除遮罩对象
    if node.mask ~= nil then
        pos_mask = cc.p(parentNode:getPositionX(),parentNode:getPositionY())
        parentNode = node:getParent():getParent()
        node:getParent():removeFromParent()
        node.mask = nil
    end
    if node.kuang then
    	node.kuang:removeFromParent()
    	node.kuang = nil
    end
    node:removeFromParent()
    node:release()

    if user ~= nil then
        if defaultPic ~= nil and user:getFaceURL() ~= "" and user:getGameID() then
            node = jt.SpriteURL:create(user:getFaceURL(),defaultPic,tostring(user:getGameID())):addTo(parentNode,order)
        else
            print("MotionUtil:RepleaceWithURLPic",user:getGameID(),user:getFaceURL())
            node = jt.SpriteURL:create(user:getFaceURL(),GameManager:getUserManager():getDefaultFace(user:getGender()),tostring(user:getGameID())):addTo(parentNode,order)
        end
    else
        node = jt.SpriteURL:create("",defaultPic,"1000"):addTo(parentNode,order)
    end

    local contentSize_ = node:getContentSize()
    node:setScaleX(size.width/contentSize_.width)
    node:setScaleY(size.height/contentSize_.height)
    node:setPosition(pos_mask)
    node:getHttpPic(size)

    if not isNoMask and user then
        -- node = self:addCircleHead(node,user:getMemberOrder(),size,isLight)
    end

    return node
end

function MotionUtil:addCircleHead(headPic,vipLevel,size,isLight)
        local headSize = headPic:getContentSize()
        local kuang_str = "image/VIP_kuang/vip_0.png"
        if vipLevel == 1 or vipLevel == 2 then
            kuang_str = "image/VIP_kuang/vip1_2.png"
        elseif vipLevel == 3 or vipLevel == 4 then
            kuang_str = "image/VIP_kuang/vip3_4.png"
        elseif vipLevel == 5 or vipLevel == 6 then
            kuang_str = "image/VIP_kuang/vip5_6.png"
        elseif vipLevel == 7 then
            kuang_str = "image/VIP_kuang/vip7.png"
        elseif vipLevel == 8 then
            kuang_str = "image/VIP_kuang/vip8.png"
        elseif vipLevel == 9 then
            kuang_str = "image/VIP_kuang/vip9.png"
        end

        local order = headPic:getLocalZOrder()
        local kuang = cc.Sprite:create(kuang_str):addTo(headPic:getParent(),order)
        kuang:setLocalZOrder(headPic:getLocalZOrder())
        headPic.kuang = kuang
        if vipLevel < 0  or vipLevel > 9 then
        	vipLevel = 0
        end
        if vipLevel ~= 0 then
        local vip_flag_spr = cc.Sprite:create("image/VIP_flag/VIP_Flag_"..vipLevel..".png"):addTo(kuang,order):setScale(0.8)
            vip_flag_spr:setPosition(kuang:getContentSize().width - 55,45)
            if vipLevel == 9 and not isLight then
                local cilpNode_ = cc.ClippingNode:create(cc.Sprite:create("image/VIP_flag/VIP_Flag_9.png")):setScale(0.8)
                cilpNode_:setAnchorPoint(0.5,0.5)
                cilpNode_:setPosition(vip_flag_spr:getPosition())
                cilpNode_:setAlphaThreshold(0)
                kuang:addChild(cilpNode_)
                local img_1 = cc.Sprite:create("image/VIP_flag/vip_light.png"):addTo(cilpNode_):setPosition(-vip_flag_spr:getContentSize().width/2 - 20,0)
                img_1:runAction(cc.RepeatForever:create(cc.Sequence:create(cc.MoveBy:create(1,cc.p(200,0)),cc.DelayTime:create(2),cc.CallFunc:create(function()
                    img_1:setPosition(-vip_flag_spr:getContentSize().width/2 - 20,0)
                end))))
            end
        end
        local kuangSize = kuang:getContentSize()
        kuang:setPosition(headPic:getPosition())
        local x = size.width/kuangSize.width*1.28
        local y = size.height/kuangSize.height*1.28
        kuang:setScaleX(x)
        kuang:setScaleY(y)
        if vipLevel == 0 then
            kuang:setScale(kuang:getScale()*0.858)
        end
    return headPic
end

--限制label长度
function MotionUtil:cutLabel(label,width)
    if label:getContentSize().width <= width then
        return label
    end
    
    local str = label:getString()
	local function checkWidth()
        if label:getContentSize().width <= width then
            label:setString(label:getString().."...")
            return label
        end
        local char = string.byte(string.sub(str,-1))            --最后一个字符的ASCII
        if char >= 0 and char <= 127 then
            str = string.sub(str,1,string.len(str) - 1)         --非中文
        else
            str = string.sub(str,1,string.len(str) - 3)         --中文
        end

        label:setString(str)
        return checkWidth()
	end

	return checkWidth()
end

return MotionUtil;
