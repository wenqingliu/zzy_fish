local CMDBase = class("CMDBase")
CMDBase.size = 0
function CMDBase:createWithNotify(notify)
    local cmd = self:create()
    local ba = jt.ByteArray:createWithNotify(notify)
    self:readFormByteArray(ba)
    self:checkBytesAvailable(ba,notify)
    return cmd
end

--检查ByteArray有效值
function CMDBase:checkBytesAvailable(ba,notify)
    local available = ba:getPosition() - notify:getSize()
    if available == 0 then
        --正常状态
    elseif available > 0 then
        assert(false,"CMDBase:checkBytesAvailable访问越界".."MainType:"..notify:getMainType()..
            ",SubType:"..notify:getSubType()..",position:"..ba:getPosition()..",size:"..notify:getSize())
    elseif available < 0 and self:getSize() == 0 then
        print(false,"CMDBase:checkBytesAvailable数据未全部写入","MainType:",notify:getMainType(),",SubType:",notify:getSubType(),"position:",ba:getPosition(),",size:",notify:getSize())
    else
        print("CMDBase:checkBytesAvailable正在写入数组:","MainType:",notify:getMainType(),",SubType:",notify:getSubType(),"position:",ba:getPosition(),",size:",notify:getSize(),"self:getSize()",self:getSize())
    end
    return available
end

function CMDBase:getSize()
    return 0
end

function CMDBase:readFormByteArray(ba)
    assert(false,"CMDBase:readFormByteArray子类未重写")
end

function CMDBase:writeToByteArray(ba)
    assert(false,"CMDBase:writeToByteArray子类未重写")
end

return CMDBase