BtnGroup = BtnGroup or {}

BtnGroup.COLOR_NORMAL = cc.c3b(255,255,255)
BtnGroup.COLOR_DOWN = cc.c3b(166,166,166)

function BtnGroup:getHandler()
    return handler(BtnGroup,BtnGroup.onTouch)
end

function BtnGroup:onTouch(target,type)
    if type == cc.EventCode.BEGAN then
        target:setColor(BtnGroup.COLOR_DOWN)
        audio.playSound("music/click")
    elseif type == cc.EventCode.ENDED or type == cc.EventCode.CANCELLED then
        target:setColor(BtnGroup.COLOR_NORMAL)
    end
end

----------------------
-- Layer点击按钮列表效果
-- @return 
function BtnGroup:onTouchLayer(event,btnList,isNotPlaySound)
    if btnList then
        for i=1,#btnList do
            local btn = btnList[i]
            if btn ~= nil then
                if event.name == "began" and btn:isVisible() then
                    local point =  btn:convertToNodeSpace(event)
                    local size = btn:getContentSize()
                    local rect = cc.rect(0,0,size.width,size.height)
                    if cc.rectContainsPoint(rect,point) then
                        btn:setColor(BtnGroup.COLOR_DOWN)
                        if not isNotPlaySound then
                            audio.playSound("music/click")
                        end
                        return true
                    end 
                else 
                if event.name == "ended" then
                    btn:setColor(BtnGroup.COLOR_NORMAL)
                end
                end
            else
                print("BtnGroup:onTouchLayer,error-nil:",i)
            end
        end
    end
end

function BtnGroup:onTouchButton(button,eventType,isNotPlaySound)
    if eventType == 0 then
        button:setColor(BtnGroup.COLOR_DOWN)
        if not isNotPlaySound then
            audio.playSound("music/click")
        end
    elseif eventType == 2 or eventType == 3 then
        button:setColor(BtnGroup.COLOR_NORMAL)
    end
end

function BtnGroup:onTouchNode(event,node)
    if event.name == "began" then
        local point =  node:convertToNodeSpace(event)
        local size = node:getContentSize()
        local rect = cc.rect(0,0,size.width,size.height)
        if cc.rectContainsPoint(rect,point) then
            node:setColor(BtnGroup.COLOR_DOWN)
            return true
        end 
    else 
        if event.name == "ended" then
            node:setColor(BtnGroup.COLOR_NORMAL)
        end
    end
end

return BtnGroup