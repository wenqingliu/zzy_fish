--邮件
local CMD_Server_Task = {}

CMD_Server_Task.MDM_GR_QUERY                  = 8                           --查询命令
CMD_Server_Task.SUB_GF_GAME_DAY_TASK_LIST     = 23                          --每日任务表
CMD_Server_Task.SUB_GF_GAME_DAY_TASK          = 22                          --每日任务领取分数

CMD_Server_Task.SUB_GF_QUERY_WEEKTASK_REQ     = 33                  		--查询周任务请求
CMD_Server_Task.SUB_GF_QUERY_WEEKTASK_RET     = 34                  		--查询周任务返回
CMD_Server_Task.SUB_GF_DRAW_WEEKTASK_REQ      = 35                  		--领取周任务请求
CMD_Server_Task.SUB_GF_DRAW_WEEKTASK_RET      = 36                  		--领取周任务返回

CMD_Server_Task.SUB_GF_GAME_CHECK_DAYTASK_REQ = 47                          --查询每日任务
CMD_Server_Task.SUB_GF_GAME_DRAW_DAYTASK_REQ  = 49				            --领取每日任务
CMD_Server_Task.SUB_GF_GAME_CHECK_DAYTASK_RET = 50				            --查询每日任务返回
CMD_Server_Task.SUB_GF_GAME_DRAW_DAYTASK_RET  = 51				            --领取每日任务返回


--请求任务列表
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Task.CMD_GR_C_GameDayTaskList = class("CMD_GR_C_GameDayTaskList",CMDBase)

function CMD_Server_Task.CMD_GR_C_GameDayTaskList:writeToByteArray(ba)
    -- ba:writeDWORD(                              self.dwGameID);                   -- 玩家GameID
end

--返回 任务列表
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Task.CMD_GR_S_GameDayTaskList = class("CMD_GR_S_GameDayTaskList",CMDBase)
function CMD_Server_Task.CMD_GR_S_GameDayTaskList:readFormByteArray(ba)
    self.allTask = {}
    for i = 1,ba:getLength()/self:getSize() do
        local tanskinfo        = {}
        tanskinfo.dwTaskID     = ba:readDWORD();                 --任务ID
        tanskinfo.cbTaskStatus = ba:readBYTE();                  -- 1未领取  2 领取 0不可领取
        tanskinfo.dwFTaskCount = ba:readDWORD();                 -- 当前局数
        tanskinfo.dwTaskLimit  = ba:readDWORD();                 -- 任务规定局数
        tanskinfo.lScore       = ba:readLONGLONG();              -- 奖励分数
        tanskinfo.szTaskName   = ba:readTchar(32);               -- 任务名字
        tanskinfo.szDescribe   = ba:readTchar(127);              -- 任务描述
        table.insert(self.allTask,tanskinfo)
    end
end

function CMD_Server_Task.CMD_GR_S_GameDayTaskList:getSize()
    local size = 4+1+4+4+8+64+254             --340
    return size
end

--请求领取任务奖励
local CMDBase = import("app/cmd/CMDBase.lua")
CMD_Server_Task.CMD_GR_C_GameDayTaskReq = class("CMD_GR_C_GameDayTaskReq",CMDBase)
function CMD_Server_Task.CMD_GR_C_GameDayTaskReq:writeToByteArray(ba)
    ba:writeDWORD(self.dwTaskID); -- 任务ID
    ba:writeDWORD(self.dwGameID); -- 玩家GameID
end

CMD_Server_Task.CMD_GR_S_GameDayTaskRet = class("CMD_GR_S_GameDayTaskRet",CMDBase)
function CMD_Server_Task.CMD_GR_S_GameDayTaskRet:readFormByteArray(ba)
    self.dwTaskID   = ba:readDWORD()        --任务ID
    self.dwGameID   = ba:readDWORD()        --用户ID
    self.lScore     = ba:readLONGLONG()     --领取分数
    self.bSuccess   = ba:readInt()         --是否领取成功 0不成功 ，1成功
    self.szDescribe = ba:readTCHAR(127)
end

--查询周任务
CMD_Server_Task.CM_GR_C_Query_WeekTask  = class("CM_GR_C_Query_WeekTask",CMDBase)
function CMD_Server_Task.CM_GR_C_Query_WeekTask:writeToByteArray(ba)
    ba:writeDWORD(           self.dwUserID)                                   --用户ID
end
--查询周任务
CMD_Server_Task.CM_GR_S_Query_WeekTask  = class("CM_GR_S_Query_WeekTask",CMDBase)
function CMD_Server_Task.CM_GR_S_Query_WeekTask:readFormByteArray(ba)
    self.allTask = {}
    local len_ = ba:getLength()
    for i = 1,ba:getLength()/self:getSize() do
        local tanskinfo = {}
        tanskinfo.dwTaskID 		   =			ba:readBYTE()                                            --任务类型
        tanskinfo.wKindID           =           ba:readWORD()                                            --游戏ID
        tanskinfo.cbTaskFlag 		=			ba:readBYTE()                                            --任务标志 0，末完成 1，已完成 2，已领取
        tanskinfo.nCurCount  		=			ba:readInt()                                             --当前数据
        tanskinfo.nMaxCount  		=			ba:readInt()                                             --最大数据
        tanskinfo.lScore		    =			ba:readLONGLONG()                                        --奖金
        tanskinfo.szDescribe 		=			ba:readTCHAR(127)                            			 --描述
        self.allTask[i] = tanskinfo
    end
end

function CMD_Server_Task.CM_GR_S_Query_WeekTask:getSize()
    local size = 1+2+1+4+4+8+127*2
    return size
end

--领取周任务
CMD_Server_Task.CM_GR_C_Draw_WeekTask  = class("CM_GR_C_Draw_WeekTask",CMDBase)
function CMD_Server_Task.CM_GR_C_Draw_WeekTask:writeToByteArray(ba)
    ba:writeDWORD(           self.dwUserID)                                   --用户ID
    ba:writeBYTE(            self.cbTaskType)                                 --任务类型
end

--领取周任务
CMD_Server_Task.CM_GR_S_Draw_WeekTask  = class("CM_GR_S_Draw_WeekTask",CMDBase)
function CMD_Server_Task.CM_GR_S_Draw_WeekTask:readFormByteArray(ba)
    self.bSuccess 		= 				ba:readInt()                                   --是否领取成功
	self.dwTaskID		=				ba:readBYTE()									--任务类型
    self.lAwardScore 	= 				ba:readLONGLONG()                                --奖金
    self.szDescribe		=				ba:readTCHAR(127)                            --描述
end


return CMD_Server_Task
