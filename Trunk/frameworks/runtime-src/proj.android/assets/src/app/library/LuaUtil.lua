local LuaUtil = {}

-----------
-- 创建一维数组
-- @param self
-- @param len 一维数组长度
-- @param value 初始化值，默认为0
-- @return #table table
function LuaUtil:createArray(len,value)
    value = value == nil and 0 or value
    local arr = {}
    for i=1,len do
        arr[i] = value
    end
    return arr
end

-----------
--创建二维数组
-- @param self
-- @param len1 一维数组长度
-- @param len2 二维数组长度
-- @param value 初始化值，默认为0
-- @return #table 二维数组
function LuaUtil:createArray2(len1,len2,value)
    value = value == nil and 0 or value
    local arr2 = {}
    for i=1,len1 do
      arr2[i] = {}
      for j=1,len2 do
         arr2[i][j] = 0
	  end
    end
    return arr2
end

-----------
-- @param self
-- @param srcTable 源table
-- @param destTable 复制到目标table
function LuaUtil:copyTable(srcTable,destTable)
    if type(srcTable) ~= "table" then
        return
    end
    for k,v in pairs(srcTable) do
        local vtype = type(v)
        if vtype == "table" then
            destTable[k] = self:copyTable(v)
        else
            destTable[k] = v
        end
    end
    return destTable
end

function LuaUtil:arraycopy(srcTable,srcPos,destTable,length)
    if type(srcTable) ~= "table" then
        return
    end
    for i=srcPos,length do
        destTable[i] = srcTable[i]
    end
    return destTable
end

function LuaUtil:deepCopy(object)
    local lookup_table = {}
    local function _copy(object)
        if type(object) ~= "table" then
            return object
        elseif lookup_table[object] then
            return lookup_table[object]
        end

        local new_table = {}
        lookup_table[object] = new_table
        for index, value in pairs(object) do
            new_table[_copy(index)] = _copy(value)
        end
        return setmetatable(new_table, getmetatable(object))
    end
    return _copy(object)
end

function LuaUtil:tableFind(table,item)
    for i=1,#table do
        if table[i] == item then
    	   return i
    	end
    end
    return -1
end

function LuaUtil:filterChar(str)
    --[[
    local function utf8len(input,limitCharByteCount)
        local len = string.len(input)
        local left = len
        local cnt = 0
        local bl_out_limit = false
        local arr = {0,0xc0,0xe0,0xf0,0xf8,0xfc} --utf8可变字节特性
        while left ~= 0 do
            local tmp = string.byte(input,-left)
            local i = #arr
            while arr[i] do
                if tmp >= arr[i] then
                    left = left - 1
                    break
                end
                i = i - 1
            end
            if i > (limitCharByteCount or 3) then --大部分需要的字符都集中在3字节内,包括中文,超过3字节就直接过滤
                bl_out_limit = true
            end
            cnt = cnt + 1
            left = left - 1
        end
        return cnt,bl_out_limit
    end
    
    local utf8_len,bl_out_limit = utf8len(str,3)
    if bl_out_limit then
        return str
    end
    ]]--
    
    local newstr,newlen = "",0
    for unchar,v in string.gfind(str,"[%z\48-\57\64-\126\226-\233][\128-\191]*") do    
        newstr = newstr .. unchar
        newlen = newlen + 1
    end
    if newlen == 0 then
        return str
    end
    return newstr
end

-----------
-- @param self
-- @param socre
function LuaUtil:parseScore(score)
    if(score>=100000000) then
        local v = (score / 100000000)
        if v - math.floor(v) > 0 then--有小数点
            return  string.format("%.2f亿",v) 
        else
            return  v.."亿"
        end
    elseif(score>=10000) then
        local v = (score / 10000)
        if v - math.floor(v) > 0 then--有小数点
            return  string.format("%.2f万",v) 
        else
            return  v.."万"
        end
    end
    return score..""
end

-----------
-- @param self
-- @param socre
function LuaUtil:parseLong(score)
    if(score>=100000000) then
        return math.floor(score / 100000000).."亿"
    elseif(score>=10000) then
        return math.floor(score / 10000).."万"
    end
    return score..""
end

-----------
-- @param self
-- @param socre
function LuaUtil:splitScore(score)
    local formatted = tostring(checknumber(score))
    local k
    while true do
        formatted, k = string.gsub(formatted, "^(-?%d+)(%d%d%d)", '%1,%2')
        if k == 0 then break end
    end
    return formatted
end



-----------
-- @param self
-- @param socre
function LuaUtil:parseJetton(score)
    if(math.abs(score)>=100000000) then
        return math.floor(score / 100000000).."E"
    elseif(math.abs(score)>=10000) then
        return math.floor(score / 10000).."W"
    end
    return score..""
end

return LuaUtil