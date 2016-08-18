local Logger = class("Logger")

function Logger:ctor(name)
	self.name_ = name
end

local function printLog(tag, fmt, ...)
    local t = {
        "[",
            tostring(tag),
        "] ",
        string.format(tostring(fmt), ...)
    }
    print(table.concat(t))
end

function Logger:log_(fmt, ...)
    if DEBUG > 0 then
        local tag = self.name_ .."# " ..(debug.getinfo(3).name or "func").." #"
        printLog(tag, fmt, ...)
    end
end

function Logger:log(...)
	self:log_("%s", ...)
end

function Logger:logf(fmt, ...)
	self:log_(fmt, ...)
end

function Logger:info_(fmt, ...)
    if DEBUG > 0 then
        local tag = self.name_ .."# " ..(debug.getinfo(3).name or "func") .." #INFO"
        printLog(tag, fmt, ...)
    end
end

function Logger:info(...)
	self:info_("%s", ...)
end

function Logger:infof(fmt, ...)
	self:info_(fmt, ...)
end

function Logger:error_(fmt, ...)
    if DEBUG > 0 then
        local tag = self.name_ .."# " ..(debug.getinfo(3).name or "func") .." #ERR"
        printLog(tag, fmt, ...)
        print(debug.traceback("", 3))
    end
end

function Logger:error(...)
	self:error_("%s", ...)
end

function Logger:errorf(fmt, ...)
	self:error_(fmt, ...)
end

return Logger
