--任务
local BaseLayer       = import("app/views/layer/BaseLayer.lua")
local TaskLayer       = class("TaskLayer",BaseLayer)
local PersonInfoLayer = import("app/views/layer/PersonInfoLayer")
local CMD_Server_Task = import("app/cmd/loginSever/CMD_Server_Task.lua")

function TaskLayer:ctor()
    self.super.ctor(self)
    display.addSpriteFrames("hall/task.plist","hall/task.png")
    display.addSpriteFrames("common.plist","common.png")
    self:setupView()
    self:show()
end

function TaskLayer:showCallBack()
    self:setupTab()
    self:setTab(1)

    CFrameDataHandler:getInstance():addNotifyListener(self)
    CFrameDataHandler:getInstance():getDailyTaskList()
end

function TaskLayer:OnTCPWithDataRoom(notify)
    if notify:getMainType() == CMD_Server_Task.MDM_GR_QUERY then --查询命令
        local sub = notify:getSubType()
        if sub == CMD_Server_Task.SUB_GF_GAME_DAY_TASK_LIST then
            return self:onTaskListEvent(notify)
        elseif sub == CMD_Server_Task.SUB_GF_GAME_DAY_TASK then
            return self:onGetRewardBack(notify)
        elseif sub == CMD_Server_Task.SUB_GF_QUERY_WEEKTASK_RET then
            return self:onWeekTaskListEvent(notify)
        elseif sub == CMD_Server_Task.SUB_GF_DRAW_WEEKTASK_RET then
            return self:onGetWeekRewardBack(notify)
        end
    end
    return false
end

function TaskLayer:setupView()
    self.panel = display.newSprite("#common_layer_bg.png"):addTo(self):setPosition(display.cx,display.cy - 10)
    self:setRootBg(self.panel)
    local size = self.panel:getContentSize()
    self.btnClose = ccui.Button:create("btn_close.png","btn_close.png","btn_close.png",1):addTo(self.panel,1):setPosition(size.width - 20,size.height - 20)
    self.btnClose:addTouchEventListener(function(ref,type)
                                            if type == 0 then --begin
                                                 transition.scaleTo(ref, {time = 0.05, scale = 0.9})
                                            elseif type == 1 then --moved
                                            elseif type == 2 then --release
                                                audio.playSound("music/click")
                                                transition.scaleTo(ref, {time = 0.05, scale = 1})
                                                self:hide()
                                            elseif type == 3 then --cancle
                                                transition.scaleTo(ref, {time = 0.05, scale = 1})
                                            end
                                        end)

    self.node = {}
    self.node[1] = display.newNode():addTo(self.panel):setPosition(0,0):setVisible(false)
    self.node[2] = display.newNode():addTo(self.panel):setPosition(0,0):setVisible(false)

    -- init node 1
    self.dailyListView = ccui.ListView:create():addTo(self.node[1])
    self.dailyListView:setDirection(1)
    self.dailyListView:setTouchEnabled(true)
    self.dailyListView:setBounceEnabled(true)
    self.dailyListView:setPosition(35,35)
    self.dailyListView:setContentSize(cc.size(1150,502))
    self.tips1 = cc.Label:create():setPosition(590,320):setSystemFontSize(42):addTo(self.node[1]):setVisible(true):setString("暂时没有任务可领取")

    -- init node 2
    self.tips2 = cc.Label:create():setPosition(590,320):setSystemFontSize(42):addTo(self.node[2]):setVisible(true):setString("暂未开放,敬请期待")
end

local tabPosX = {308,880}
local tabPosY = 600
function TaskLayer:setupTab()
    self.tabs = {{},{}}
    local tabFrontRes = {"tab_task1_front.png","tab_task2_front.png"}
    local tabBackRes = {"tab_task1_back.png","tab_task2_back.png"}

    for i = 1, #self.tabs do
        self.tabs[i] = ccui.Button:create(tabBackRes[i],tabFrontRes[i],tabFrontRes[i],1):addTo(self.panel):setPosition(tabPosX[i],tabPosY)
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[1]:setTouchEnabled(false)
    self.tabs[1]:setBright(false)

    self.particle = cc.ParticleSystemQuad:create("particle/diandian.plist")
    self.particle:setPosition(tabPosX[1],tabPosY-15)
    self.particle:setScale(0.6)
    self.particle:addTo(self.panel)

    self.tabIdx = 1
end

function TaskLayer:onTabClick(ref, type)
    if type == 2 then --release
        audio.playSound("music/click")
        for i = 1,#self.tabs do
            if ref == self.tabs[i] then
                self:setTab(i)
            end
        end
    end
end

function TaskLayer:setTab(tabIdx)
    print("tabIdx = "..tabIdx)
    for i = 1, #self.tabs do
        self.node[i]:setVisible(tabIdx == i)
        self.tabs[i]:setTouchEnabled(true)
        self.tabs[i]:setBright(true)
        self.tabs[i]:addTouchEventListener(handler(self,self.onTabClick))
    end

    self.tabs[tabIdx]:setTouchEnabled(false)
    self.tabs[tabIdx]:setBright(false)

    self.particle:setPosition(tabPosX[tabIdx],tabPosY - 15)

    self.tabIdx = tabIdx

    if tabIdx == 1 then
        if self.taskList1 == nil then
            CFrameDataHandler:getInstance():getDailyTaskList()
        -- else
        --     self:addTaskList(self.taskList1)
        end
    elseif tabIdx == 2 then
        -- if self.taskList2 == nil then
        --     CFrameDataHandler:getInstance():getWeekTaskList()
        -- else
        --     if #self.taskList2 ~= 0 then
        --         self.dailyListView:setVisible(true)
        --         self.tips:setVisible(false)
        --     end
        --     self:addWeekTaskList(self.taskList2)
        -- end
    end
end

function TaskLayer:onTouch(event)
    self.super.onTouch(self,event)
    return true
end

--获取任务列表返回
function TaskLayer:onTaskListEvent(notify)
    if notify:getSize() == 0 then
        self.tips1:setString("暂没有任务可领取")
        self.tips1:setVisible(true)
    else
        self.tips1:setVisible(false)
        local cmd = CMD_Server_Task.CMD_GR_S_GameDayTaskList:createWithNotify(notify)


        self.dailyListView:removeAllItems()
        self:addTaskList(cmd.allTask)
        self.taskList1 = cmd.allTask
    end
    return true
end

--领取奖励返回
function TaskLayer:onGetRewardBack(notify)
    if self.tabIdx == 1 then
        if notify:getSize() ~= 0 then
            local cmd = CMD_Server_Task.CMD_GR_S_GameDayTaskRet:createWithNotify(notify)
            local index = self:findTaskIndexByID(self.taskList1,cmd.dwTaskID)
            if index ~= 0 then
                local layout = self.dailyListView:getItem(index - 1)
                print(tolua.type(layout))

                local node = layout:getChildByTag(1)
                print(tolua.type(node))

                local bg = node:getChildByTag(1)
                print(tolua.type(bg))

                local btn = bg:getChildByTag(1)
                print(tolua.type(btn))

                btn:setTouchEnabled(false)
                btn:setBright(false)
                GameManager:showAlertSystem(self,"领取成功")
            end
            GameManager:getUserSelf():setScore(GameManager:getUserSelf():getScore() + cmd.lScore)
            if GameManager:getGameDelegate() ~= nil then
                GameManager:getGameDelegate():updateGameView()
            end
        end
    end
    -- self.taskList1 = nil
    -- CFrameDataHandler:getInstance():getDailyTaskList()
    return true
end

--领取周奖励返回
function TaskLayer:onGetWeekRewardBack(notify)
    if self.tabIdx == 2 then
        if notify:getSize() ~= 0 then
            local cmd = CMD_Server_Task.CM_GR_S_Draw_WeekTask:createWithNotify(notify)
            local index = self:findTaskIndexByID(self.taskList2,cmd.dwTaskID)
            if index ~= 0 then
                local item = self.dailyListView:getItem(index - 1)
                local layout = item:getChildByTag(1)
                local bg = layout:getChildByTag(1)
                local btn = bg:getChildByTag(1)
                btn:setTouchEnabled(false)
                btn:setBright(false)
                GameManager:showAlertSystem(self,"领取成功")
            end

            GameManager:getUserSelf():setScore(GameManager:getUserSelf():getScore() + cmd.lAwardScore)
            if GameManager:getGameDelegate() ~= nil then
                GameManager:getGameDelegate():updateGameView()
            end
        end
    end

    self.taskList2 = nil
    CFrameDataHandler:getInstance():getWeekTaskList()
    return true
end

--获取周任务列表返回
function TaskLayer:onWeekTaskListEvent(notify)
    if notify:getSize() == 0 then
        self.tips2:setString("暂没有任务可领取")
        self.tips2:setVisible(true)
    else
        local cmd = CMD_Server_Task.CM_GR_S_Query_WeekTask:createWithNotify(notify)
        self.dailyListView:removeAllItems()
        self:addWeekTaskList(cmd.allTask)
        self.taskList2 = cmd.allTask
    end
    return true
end

function TaskLayer:addTaskList(taskList)
    dump(taskList)
     for k,taskInfo in ipairs(taskList) do
        local item = display.newNode():setTag(1)
        local bg = display.newSprite("#item_task.png"):addTo(item):setPosition(1143/2,66):setTag(1)
        display.newSprite("#icon_task_reward.png"):addTo(item):setPosition(88,66)
        local labelDes = cc.Label:create():addTo(bg):setPosition(190,96):setString(taskInfo.szDescribe):setSystemFontSize(36):setTextColor(cc.c4b(255,255,255,255)):setAnchorPoint(0,0.5)
        labelDes:enableOutline(cc.c4b(11,62,102,255),3)

        display.newScale9Sprite("common_conten_bg.png",1,cc.size(476,50),cc.rect(183/2,47/2,2,2)):addTo(bg):setPosition(425,42)
        local labelReward = cc.Label:create():addTo(bg):setPosition(190,42):setString("奖励 : "..taskInfo.lScore.."金币"):setSystemFontSize(36):setTextColor(cc.c4b(255,255,65,255)):setAnchorPoint(0,0.5)
        labelReward:enableOutline(cc.c4b(11,62,102,255),3)

        local curCount,totalCount = taskInfo.dwFTaskCount,taskInfo.dwTaskLimit
        if curCount >= totalCount then  --finished
                local btn = ccui.Button:create("btn_getreward.png","btn_getreward.png","btn_getreward_disabled.png",1):addTo(bg):setPosition(1015,66):setTag(1)
                btn:addTouchEventListener(handler(self,self.onBtnClick))
                btn.progress = 100
                btn.taskID = taskInfo.dwTaskID
                if taskInfo.cbTaskStatus == 1 then --haven't got reward
                elseif taskInfo.cbTaskStatus == 2 then --have got reward
                    btn:setTouchEnabled(false)
                    btn:setBright(false)
                end
        else    --not finished
            cc.Label:create():addTo(bg):setPosition(690,45):setString("(进度"..curCount.."/"..totalCount..")"):setSystemFontSize(32):setTextColor(cc.c4b(20,59,88,255)):setAnchorPoint(0,0.5)
            local btn = ccui.Button:create("btn_gofinish.png","btn_gofinish.png","btn_gofinish.png",1):addTo(bg):setPosition(1015,66)
            btn:addTouchEventListener(handler(self,self.onBtnClick))
            btn.taskID = taskInfo.dwTaskID
            btn.szDescribe = taskInfo.szDescribe
        end

        local layout = ccui.Layout:create()
        layout:setContentSize(cc.size(1140,133))
        layout:setTag(1)
        layout:addChild(item)
        self.dailyListView:pushBackCustomItem(layout)
    end
end

function TaskLayer:addWeekTaskList(taskList)

    for k,taskInfo in ipairs(taskList) do
        local item = display.newNode():setTag(1)
        local bg = display.newSprite("#item_task.png"):addTo(item):setPosition(1143/2,66):setTag(1)
        display.newSprite("#icon_task_reward.png"):addTo(item):setPosition(88,66)
        local labelDes = cc.Label:create():addTo(bg):setPosition(190,96):setString(taskInfo.szDescribe):setSystemFontSize(36):setTextColor(cc.c4b(255,255,255,255)):setAnchorPoint(0,0.5)
        labelDes:enableOutline(cc.c4b(11,62,102,255),3)

        display.newScale9Sprite("common_conten_bg.png",1,cc.size(476,50),cc.rect(183/2,47/2,2,2)):addTo(bg):setPosition(425,42)
        local labelReward = cc.Label:create():addTo(bg):setPosition(190,42):setString("奖励 : "..taskInfo.lScore.."金币"):setSystemFontSize(36):setTextColor(cc.c4b(255,255,65,255)):setAnchorPoint(0,0.5)
        labelReward:enableOutline(cc.c4b(11,62,102,255),3)

        local curCount,totalCount = taskInfo.nCurCount,taskInfo.nMaxCount
        if curCount >= totalCount then  --finished
                local btn = ccui.Button:create("btn_getreward.png","btn_getreward.png","btn_getreward_disabled.png",1):addTo(bg):setPosition(1015,66):setTag(1)
                btn:addTouchEventListener(handler(self,self.onBtnClick))
                btn.progress = 100
                btn.taskID = taskInfo.dwTaskID
                if taskInfo.wFlag == 1 then --haven't got reward
                elseif taskInfo.wFlag == 2 then --have got reward
                    btn:setTouchEnabled(false)
                    btn:setBright(false)
                end
        else    --not finished
            cc.Label:create():addTo(bg):setPosition(690,66):setString("(进度"..curCount.."/"..totalCount..")"):setSystemFontSize(32):setTextColor(cc.c4b(20,59,88,255)):setAnchorPoint(0,0.5)
            local btn = ccui.Button:create("btn_gofinish.png","btn_gofinish.png","btn_gofinish.png",1):addTo(bg):setPosition(1015,66)
            btn:addTouchEventListener(handler(self,self.onBtnClick))
            btn.kindID = taskInfo.wKindID
            btn.taskID = taskInfo.dwTaskID
            btn.szDescribe = taskInfo.szDescribe
        end

        local layout = ccui.Layout:create()
        layout:setContentSize(cc.size(1140,133))
        layout:addChild(item)
        self.dailyListView:pushBackCustomItem(layout)
    end
end

function TaskLayer:onBtnClick(sender,type)
    if type == 0 then --begin
         transition.scaleTo(sender, {time = 0.05, scale = 0.9})
    elseif type == 1 then --moved
    elseif type == 2 then --release
        audio.playSound("music/click")
        transition.scaleTo(sender, {time = 0.05, scale = 1})
        if sender.progress == 100 then
            if self.tabIdx == 1 then
                CFrameDataHandler:getInstance():getTaskReward(sender.taskID)
            elseif self.tabIdx == 2 then
                CFrameDataHandler:getInstance():giveWeekTaskReward(sender.taskID)
            end
        else
            local roomList = GameManager:getRoomServer():getRoomList()
            local item =  GameManager:getRoomServer():getRoomByName(roomList[1]:szServerName())
            GameManager:getGameDelegate():loginRoom(item)
            -- local item = GameManager:getRoomServer():getRoomByKindID(sender.kindID)
            -- if GameManager:getKindID() == KIND_ID_MSG then
            --     if sender.kindID ~= KIND_ID_MSG then
            --         --进游戏房间
            --         GameManager:getGameDelegate():loginRoom(item)
            --     else
            --         if string.find(sender.szDescribe,"分享游戏") ~= nil then --每日分享
            --             local preson = PersonInfoLayer:create(GameManager:getUserSelf()):addTo(self:getParent())
            --             preson:share()
            --         elseif string.find(sender.szDescribe,"登录") ~= nil then --登录
            --             GameManager:showAlertSystem(self,"亲,保持每日登录就可以领奖啦~")
            --         end
            --     end
            -- end
        end
    elseif type == 3 then --cancle
        transition.scaleTo(sender, {time = 0.05, scale = 1})
    end

end

function TaskLayer:findTaskIndexByID(taskList,taskID)
    local index = 0
    for i = 1,#taskList do
        if taskList[i].dwTaskID == taskID then
            index = i
            return index
        end
    end
    return index
end

--获取游戏对应的图标
function TaskLayer:getIcon(kindID)
    local str = ""
    if kindID == KIND_ID_MSG then
        str = "layer_task/lihe.png"
    elseif kindID == KIND_ID_BR or kindID == KIND_ID_OXBR then
        str = "layer_task/jiangbei.png"
    elseif kindID == KIND_ID_Slot then
        str = "layer_task/77.png"
    elseif kindID == KIND_ID_VS or kindID == KIND_ID_KPQZ then
        str = "layer_task/kanpai.png"
    elseif kindID == KING_ID_FEIQIN then
        str = "layer_task/feiqin.png"
    elseif kindID == KIND_ID_Gongpo then
        str = "layer_task/gongfu.png"
    elseif kindID == KIND_ID_YY then
        str = "layer_task/yyl.png"
    else
        str = "layer_task/lihe.png"
    end

    return str
end

function TaskLayer:onCleanup()
    display.removeSpriteFramesWithFile("hall/task.plist","hall/task.png")
    CFrameDataHandler:getInstance():removeNotifyListener(self)
end

return TaskLayer
