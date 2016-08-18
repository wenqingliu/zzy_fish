zzy = zzy or {}

zzy.ui = import(".ui.init")

zzy.Logger = import(".utils.Logger")
zzy.Scheduler = import(".utils.SchedulerFactory").new()

return zzy
