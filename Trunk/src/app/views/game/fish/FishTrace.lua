local FishTrace = FishTrace or {}
local logger = zzy.Logger.new("FishTrace")

local sinf = math.sin
local cosf = math.cos
local acosf = math.acos
local tanf = math.tan
local pi = math.pi
local pi2 = pi/2

function FishTrace.BuildSceneKind1Trace(screenWidth, screenHeight)
    logger:log("BuildSceneKind1Trace")
    local sceneKind1Trace = {}
    for i = 1,210 do sceneKind1Trace[i] = {} end --100 + 17 + 17 + 30 + 30 + 15 + 1

  local fishCount = 0
  local kVScale = nf.heightScale
  local kHScale = nf.widthScale
  local kRadius = (screenHeight - (240 * kVScale)) / 2
  local kSpeed = 3 * kHScale
  local fishPos = {}
  for i = 1, 100 do fishPos[i] = {} end
  local center = {}
  center.x = screenWidth + kRadius
  center.y = kRadius + 120 * kVScale
  fishPos = MathAide.BuildCircle(center.x, center.y, kRadius, 100)
  local initX = {}
  local initY = {}
  for i = 1,  100 do
      initX[1] = fishPos[i].x
      initY[1] = fishPos[i].y
      initX[2] = -2* kRadius
      initY[2] = initY[1]
      sceneKind1Trace[i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
  end

  fishCount = fishCount + 100

  local kRotateRadian1 = 45 * math.pi / 180
  local kRotateRadian2 = 135 * math.pi / 180
  local kRadiusSmall = kRadius / 2
  local kRadiusSmall1 = kRadius / 3
  local centerSmall = {}
  for i = 1, 4 do centerSmall[i] = {} end
  centerSmall[1].x = center.x + kRadiusSmall * math.rad(math.cos(-kRotateRadian2))
  centerSmall[1].y = center.y + kRadiusSmall * math.rad(math.sin(-kRotateRadian2))
  centerSmall[2].x = center.x + kRadiusSmall * math.rad(math.cos(-kRotateRadian1))
  centerSmall[2].y = center.y + kRadiusSmall * math.rad(math.sin(-kRotateRadian1))
  centerSmall[3].x = center.x + kRadiusSmall * math.rad(math.cos(kRotateRadian2))
  centerSmall[3].y = center.y + kRadiusSmall * math.rad(math.sin(kRotateRadian2))
  centerSmall[4].x = center.x + kRadiusSmall * math.rad(math.cos(kRotateRadian1))
  centerSmall[4].y = center.y + kRadiusSmall * math.rad(math.sin(kRotateRadian1))

  fishPos = MathAide.BuildCircle(centerSmall[1].x, centerSmall[1].y, kRadiusSmall1,17)
  for i = 1, 17 do
      initX[1] = fishPos[i].x
      initY[1] = fishPos[i].y
      initX[2] = -2* kRadius
      initY[2] = initY[1]
      sceneKind1Trace[fishCount + i]= MathAide.BuildLinear(initX, initY, 2, kSpeed)
  end
  fishCount = fishCount + 17

  fishPos = MathAide.BuildCircle(centerSmall[2].x, centerSmall[2].y, kRadiusSmall1, 17)
  for i = 1, 17 do
      initX[1] = fishPos[i].x
      initY[1] = fishPos[i].y
      initX[2] = -2* kRadius
      initY[2] = initY[1]
      sceneKind1Trace[fishCount + i]= MathAide.BuildLinear(initX, initY, 2, kSpeed)
  end
  fishCount = fishCount + 17

  fishPos = MathAide.BuildCircle(centerSmall[3].x, centerSmall[3].y, kRadiusSmall1, 30)
  for i = 1, 30 do
      initX[1] = fishPos[i].x
      initY[1] = fishPos[i].y
      initX[2] = -2* kRadius
      initY[2] = initY[1]
      sceneKind1Trace[fishCount + i]= MathAide.BuildLinear(initX, initY, 2,  kSpeed)
  end
  fishCount = fishCount + 30

  fishPos = MathAide.BuildCircle(centerSmall[4].x, centerSmall[4].y, kRadiusSmall1, 30)
  for i = 1, 30 do
      initX[1] = fishPos[i].x
      initY[1] = fishPos[i].y
      initX[2] = -2* kRadius
      initY[2] = initY[1]
      sceneKind1Trace[fishCount + i]= MathAide.BuildLinear(initX, initY, 2,  kSpeed)
  end
  fishCount = fishCount + 30


  fishPos = MathAide.BuildCircle(center.x, center.y, kRadiusSmall / 2, 15)
  for i = 1, 15 do
      initX[1] = fishPos[i].x
      initY[1] = fishPos[i].y
      initX[2] = -2* kRadius
      initY[2] = initY[1]
      sceneKind1Trace[fishCount + i]= MathAide.BuildLinear(initX, initY, 2,kSpeed)
  end
  fishCount = fishCount + 15

  initX[1] = center.x
  initY[1] = center.y
  initX[2] = -2 * kRadius
  initY[2] = initY[1]
  sceneKind1Trace[fishCount] = MathAide.BuildLinear(initX, initY, 2, kSpeed)

  for i = 1 , #sceneKind1Trace[fishCount + 1] do
      sceneKind1Trace[fishCount + 1][i].angle = 0
  end

  fishCount = fishCount + 1

  logger:log("BuildSceneKind1Trace return sceneKind1Trace num = "..#sceneKind1Trace)
  return sceneKind1Trace
end

function FishTrace.BuildSceneKind2Trace(screenWidth, screenHeight)
    local sceneKind2Trace = {}
    for i = 1,214 do sceneKind2Trace[i] = {} end

    local kVScale = nf.heightScale
    local kHScale = nf.widthScale
    local kSpeed = 3 * kHScale
    local kStopExcursion = 180*kVScale
    local kHExcursion = 27*kHScale/2
    local kSmallFishInterval = (display.width - kHExcursion*2)/100
    local kSmallFishHeight = 65*kVScale

    local fishCount = 0

    local initX = {}
    local initY = {}

    local smallHeight = kSmallFishHeight * 3

    for i = 1,200 do
        initX[1] = kHExcursion + ((i-1)%100) * kSmallFishInterval
        initX[2] = initX[1]
        local excursion = math.random(0,smallHeight)
        if i <= 100 then
            initY[1] = -65 -excursion
            initY[2] = screenHeight + 65
        else
            initY[1] = screenHeight + 65 + excursion
            initY[2] = -65
        end
        sceneKind2Trace[i]= MathAide.BuildLinear(initX, initY, 2,  kSpeed)
    end
    fishCount = fishCount + 200

    local bigFishWidth = { 270 * kHScale, 226 * kHScale, 375 * kHScale, 420 * kHScale, 540 * kHScale, 454 * kHScale, 600 * kHScale }
    local bigFishExcursion = {}

    for i = 1, 7 do
        bigFishExcursion[i] = bigFishWidth[i]
        for j = 1,i do
            bigFishExcursion[i] = bigFishExcursion[i] + bigFishWidth[j]
        end
    end
    local yExcursoin = 250 * kVScale / 2

    for i = 1, 14 do
        if i <= 7 then
            initY[2] = screenHeight / 2 - yExcursoin
            initY[1] = -bigFishExcursion[i%7 + 1]
            initX[2] = screenWidth + bigFishWidth[i % 7 + 1]
            sceneKind2Trace[fishCount + i]= MathAide.BuildLinear(initX, initY, 2,  kSpeed)
        else
            initY[2] = screenHeight / 2 + yExcursoin
            initY[1] = screenWidth + bigFishWidth[i % 7 +1]
            initX[2] = -bigFishExcursion[i % 7 + 1]
            sceneKind2Trace[fishCount + i]= MathAide.BuildLinear(initX, initY, 2,  kSpeed)
        end
    end

    local smallFishTrace = {}
    initY[1] = -2 * kSmallFishHeight
    initY[2] = kStopExcursion
    smallFishTrace= MathAide.BuildLinear(initX, initY, 2,  kSpeed)

    local bigFishTrace = {}
    initX[1] = -bigFishExcursion[7]
    initX[2] = screenWidth + bigFishWidth[7]
    bigFishTrace= MathAide.BuildLinear(initX, initY, 2,  kSpeed)

    local bigStopCount = 0

    local sceneKind2SmallFishStopIndex = {}
    for i = 1,200 do sceneKind2SmallFishStopIndex[i] = {} end
    for i = 1, 200 do
        for  j = 1, #sceneKind2Trace do
            local pos = sceneKind2Trace[i][j]
            if  i <= 100 then
                if pos.y >= kStopExcursion then
                    sceneKind2SmallFishStopIndex[i] = j
                    if bigStopCount == 0 then
                        bigStopCount = j
                    elseif bigStopCount < j then
                        bigStopCount = j
                    end
                    break
                end
            else
                if pos.y < screenHeight - kStopExcursion then
                    sceneKind2SmallFishStopIndex[i] = j
                    if bigStopCount == 0 then
                        bigStopCount = j
                    elseif bigStopCount < j then
                        bigStopCount = j
                    end
                    break
                end
            end
        end
    end

  local sceneKind2SmallFishStopCount = #bigFishTrace
  local sceneKind2BigFishStopIndex = 0
  local sceneKind2BigFishStopCount = bigStopCount + 1

  logger:log("BuildSceneKind2Trace return sceneKind1Trace num = "..#sceneKind2Trace)
  return sceneKind2Trace
end

function FishTrace.BuildSceneKind3Trace(screenWidth, screenHeight)
    local sceneKind3Trace = {}
    for i = 1,242 do sceneKind3Trace[i] = {} end

    local fishCount = 0

    local kVScale = nf.heightScale
    local kRadius = (screenHeight - (240 * kVScale)) / 2
    local kSpeed = 1.5 * nf.widthScale
    local fishPos = {}
    local center = {}
    center.x = screenWidth + kRadius
    center.y = kRadius + 120 * kVScale

    fishPos = MathAide.BuildCircle(center.x, center.y, kRadius, 50)

    local initX = {}
    local initY = {}

    for i = 1, 50 do
        initX[1] = fishPos[i].x
        initY[1] = fishPos[i].y
        initX[2] = -2 * kRadius
        initY[2] = initY[1]
        sceneKind3Trace[i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
    end
    fishCount = fishCount + 50

    fishPos = MathAide.BuildCircle(center.x, center.y, kRadius * 40 / 50, 40)

    for i = 1, 40 do
        initX[1] = fishPos[i].x
        initY[1] = fishPos[i].y
        initX[2] = -2 * kRadius
        initY[2] = initY[1]
        sceneKind3Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
    end
    fishCount = fishCount + 40

    fishPos = MathAide.BuildCircle(center.x, center.y, kRadius * 30 / 50, 30)

    for i = 1, 30 do
        initX[1] = fishPos[i].x
        initY[1] = fishPos[i].y
        initX[2] = -2 * kRadius
        initY[2] = initY[1]
        sceneKind3Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
    end
    fishCount = fishCount + 30

    initX[1] = center.x
    initY[1] = center.y
    initX[2] = -2 * kRadius
    initY[2] = initY[1]
    sceneKind3Trace[fishCount] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
    fishCount = fishCount + 1;

    center.x = -kRadius;
    fishPos = MathAide.BuildCircle(center.x, center.y, kRadius, 50)

    for i = 1, 50 do
        initX[1] = fishPos[i].x
        initY[1] = fishPos[i].y
        initX[2] = screenWidth + 2 * kRadius
        initY[2] = initY[1]
        sceneKind3Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
    end
    fishCount = fishCount + 50

    fishPos = MathAide.BuildCircle(center.x, center.y, kRadius * 40 / 50, 40)

    for i = 1, 40 do
        initX[1] = fishPos[i].x
        initY[1] = fishPos[i].y
        initX[2] = screenWidth + 2 * kRadius
        initY[2] = initY[1]
        sceneKind3Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
    end
    fishCount = fishCount + 40

    fishPos = MathAide.BuildCircle(center.x, center.y, kRadius * 30 / 50, 30)

    for i = 1, 30 do
        initX[1] = fishPos[i].x
        initY[1] = fishPos[i].y
        initX[2] = screenWidth + 2 * kRadius
        initY[2] = initY[1]
         sceneKind3Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
    end
    fishCount = fishCount + 30

    initX[1] = center.x
    initY[1] = center.y
    initX[2] = screenWidth + 2 * kRadius
    initY[2] = initY[1]
    sceneKind3Trace[fishCount] = MathAide.BuildLinear(initX, initY, 2,  kSpeed)
    fishCount = fishCount + 1

    return sceneKind3Trace
end

function FishTrace.BuildSceneKind4Trace(screenWidth, screenHeight)
    local sceneKind4Trace = {}
    for i = 1,64 do sceneKind4Trace[i] = {} end

    local kHScale = nf.widthScale
    local kVScale = nf.heightScale
    local kSpeed = 3 * kHScale
    local kFishWidth = 512 * kHScale
    local kFishHeight = 304 * kVScale

    local fishCount = 0
    local initX = {}
    local initY = {}

    -- 左下
    local startPos = { x=0, y=screenHeight - kFishHeight / 2 }
    local targetPos = { x = screenWidth - kFishHeight / 2,y= 0 }
    local angle = acosf((targetPos.x - startPos.x) / MathAide.CalcDistance(targetPos.x, targetPos.y, startPos.x, startPos.y))
    local radius = kFishWidth * 4
    local length = radius + kFishWidth / 2
    local centerPos = {}
    centerPos.x = -length * cosf(angle)
    centerPos.y = startPos.y + length * sinf(angle)
    initX[2] = targetPos.x + kFishWidth
    initY[2] = targetPos.y - kFishHeight

    for i = 1, 8 do
        if radius < 0 then
          initX[1] = centerPos.x + radius * cosf(angle)
          initY[1] = centerPos.y - radius * sinf(angle)
        else
          initX[1] = centerPos.x - radius * cosf(angle + pi)
          initY[1] = centerPos.y + radius * sinf(angle + pi)
        end
        sceneKind4Trace[i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
        radius = radius - kFishWidth
    end
    fishCount = fishCount + 8

    startPos.x = kFishHeight / 2
    startPos.y = screenHeight
    targetPos.x = screenWidth
    targetPos.y = kFishHeight / 2
    angle = acosf((targetPos.x - startPos.x) / MathAide.CalcDistance(targetPos.x, targetPos.y, startPos.x, startPos.y))
    radius = kFishWidth * 4
    length = radius + kFishWidth / 2
    centerPos.x = startPos.x - length * cosf(angle)
    centerPos.y = startPos.y + length * sinf(angle)
    initX[2] = targetPos.x + kFishWidth
    initY[2] = targetPos.y - kFishHeight

    for i = 1, 8 do
        if radius < 0 then
          initX[1] = centerPos.x + radius * cosf(angle)
          initY[1] = centerPos.y - radius * sinf(angle)
        else
          initX[1] = centerPos.x - radius * cosf(angle + pi)
          initY[1] = centerPos.y + radius * sinf(angle + pi)
        end
        sceneKind4Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
        radius = radius - kFishWidth
    end
    fishCount = fishCount + 8

    -- 右下
    startPos.x = screenWidth - kFishHeight / 2
    startPos.y = screenHeight
    targetPos.x = 0
    targetPos.y = kFishHeight / 2
    angle = acosf((startPos.x - targetPos.x) / MathAide.CalcDistance(targetPos.x, targetPos.y, startPos.x, startPos.y))
    radius = kFishWidth * 4
    length = radius + kFishWidth / 2
    centerPos.x = startPos.x + length * cosf(angle)
    centerPos.y = startPos.y + length * sinf(angle)
    initX[2] = targetPos.x - kFishWidth
    initY[2] = targetPos.y - kFishHeight

    for i = 1, 8 do
        if radius < 0 then
          initX[1] = centerPos.x - radius * cosf(angle + pi)
          initY[1] = centerPos.y - radius * sinf(angle + pi)
        else
          initX[1] = centerPos.x - radius * cosf(angle)
          initY[1] = centerPos.y - radius * sinf(angle)
        end
        sceneKind4Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
        radius = radius - kFishWidth
    end
    fishCount = fishCount + 8

    startPos.x = screenWidth
    startPos.y = screenHeight - kFishHeight / 2
    targetPos.x = kFishHeight / 2
    targetPos.y = 0
    angle = acosf((startPos.x - targetPos.x) / MathAide.CalcDistance(targetPos.x, targetPos.y, startPos.x, startPos.y))
    radius = kFishWidth * 4
    length = radius + kFishWidth / 2
    centerPos.x = startPos.x + length * cosf(angle)
    centerPos.y = startPos.y + length * sinf(angle)
    initX[2] = targetPos.x - kFishWidth
    initY[2] = targetPos.y - kFishHeight

    for i = 1, 8 do
        if radius < 0 then
          initX[1] = centerPos.x - radius * cosf(angle + pi)
          initY[1] = centerPos.y - radius * sinf(angle + pi)
        else
          initX[1] = centerPos.x - radius * cosf(angle)
          initY[1] = centerPos.y - radius * sinf(angle)
        end
        sceneKind4Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
        radius = radius - kFishWidth
    end
    fishCount = fishCount + 8

    -- 右上
    startPos.x = screenWidth
    startPos.y = kFishHeight / 2
    targetPos.x = kFishHeight / 2
    targetPos.y = screenHeight
    angle = acosf((startPos.x - targetPos.x) / MathAide.CalcDistance(targetPos.x, targetPos.y, startPos.x, startPos.y))
    radius = kFishWidth * 4
    length = radius + kFishWidth / 2
    centerPos.x = startPos.x + length * cosf(angle)
    centerPos.y = startPos.y - length * sinf(angle)
    initX[2] = targetPos.x - kFishWidth
    initY[2] = targetPos.y + kFishHeight

    for i = 1, 8 do
        if radius < 0 then
          initX[1] = centerPos.x - radius * cosf(-angle - pi)
          initY[1] = centerPos.y - radius * sinf(-angle - pi)
        else
          initX[1] = centerPos.x - radius * cosf(-angle)
          initY[1] = centerPos.y - radius * sinf(-angle)
        end
        sceneKind4Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
        radius = radius - kFishWidth
    end
    fishCount = fishCount + 8

    startPos.x = screenWidth - kFishHeight / 2
    startPos.y = 0
    targetPos.x = 0
    targetPos.y = screenHeight - kFishHeight / 2
    angle = acosf((startPos.x - targetPos.x) / MathAide.CalcDistance(targetPos.x, targetPos.y, startPos.x, startPos.y))
    radius = kFishWidth * 4
    length = radius + kFishWidth / 2
    centerPos.x = startPos.x + length * cosf(angle)
    centerPos.y = startPos.y - length * sinf(angle)
    initX[2] = targetPos.x - kFishWidth
    initY[2] = targetPos.y + kFishHeight

    for i = 1 ,8 do
        if radius < 0 then
          initX[1] = centerPos.x - radius * cosf(-angle - pi)
          initY[1] = centerPos.y - radius * sinf(-angle - pi)
        else
          initX[1] = centerPos.x - radius * cosf(-angle)
          initY[1] = centerPos.y - radius * sinf(-angle)
        end
        sceneKind4Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
        radius = radius - kFishWidth
    end
    fishCount = fishCount + 8

    -- 左上
    startPos.x = kFishHeight / 2
    startPos.y = 0
    targetPos.x = screenWidth
    targetPos.y = screenHeight - kFishHeight / 2
    angle = acosf((targetPos.x - startPos.x) / MathAide.CalcDistance(targetPos.x, targetPos.y, startPos.x, startPos.y))
    radius = kFishWidth * 4
    length = radius + kFishWidth / 2
    centerPos.x = startPos.x - length * cosf(angle)
    centerPos.y = startPos.y - length * sinf(angle)
    initX[2] = targetPos.x + kFishWidth
    initY[2] = targetPos.y + kFishHeight

    for i = 1, 8 do
        if radius < 0 then
          initX[1] = centerPos.x + radius * cosf(angle + pi)
          initY[1] = centerPos.y + radius * sinf(angle + pi)
        else
          initX[1] = centerPos.x + radius * cosf(angle)
          initY[1] = centerPos.y + radius * sinf(angle)
        end
        sceneKind4Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
        radius = radius - kFishWidth
    end
    fishCount = fishCount + 8

    startPos.x = 0
    startPos.y = kFishHeight / 2
    targetPos.x = screenWidth - kFishHeight / 2
    targetPos.y = screenHeight
    angle = acosf((targetPos.x - startPos.x) / MathAide.CalcDistance(targetPos.x, targetPos.y, startPos.x, startPos.y))
    radius = kFishWidth * 4
    length = radius + kFishWidth / 2
    centerPos.x = startPos.x - length * cosf(angle)
    centerPos.y = startPos.y - length * sinf(angle)
    initX[2] = targetPos.x + kFishWidth
    initY[2] = targetPos.y + kFishHeight

    for  i = 1, 8 do
    if radius < 0 then
      initX[1] = centerPos.x + radius * cosf(angle + pi)
      initY[1] = centerPos.y + radius * sinf(angle + pi)
    else
      initX[1] = centerPos.x + radius * cosf(angle)
      initY[1] = centerPos.y + radius * sinf(angle)
    end
    sceneKind4Trace[fishCount + i] = MathAide.BuildLinear(initX, initY, 2, kSpeed)
    radius = radius - kFishWidth
    end
    fishCount = fishCount + 8

    return sceneKind4Trace
end

function FishTrace.BuildSceneKind5Trace(screenWidth, screenHeight)
    local sceneKind5Trace = {}
    for i = 1,236 do sceneKind5Trace[i] = {} end

    local fishCount    = 0
    local kVScale      = nf.heightScale
    local kRadius      = (screenHeight - (200 * kVScale)) / 2
    local kRotateSpeed = 1.5 * pi / 180
    local kSpeed       = 5 * nf.widthScale
    local fishPos      = {}
    local center       = {{},{}}
    center[1].x        = screenWidth / 4
    center[1].y        = kRadius + 100 * kVScale
    center[2].x        = screenWidth - screenWidth / 4
    center[2].y        = kRadius + 100 * kVScale
    local kLFish1Rotate = 720 * pi / 180
    local kRFish2Rotate = (720 + 90) * (pi / 180)
    local kRFish5Rotate = (720 + 180) * (pi / 180)
    local kLFish3Rotate = (720 + 180 + 45) * (pi / 180)
    local kLFish4Rotate = (720 + 180 + 90) * (pi / 180)
    local kRFish6Rotate = (720 + 180 + 90 + 30) * (pi / 180)
    local kRFish7Rotate = (720 + 180 + 90 + 60) * (pi / 180)
    local kLFish6Rotate = (720 + 180 + 90 + 60 + 30) * (pi / 180)
    local kLFish18Rotate = (720 + 180 + 90 + 60 + 60) * (pi / 180)
    local kRFish17Rotate = (720 + 180 + 90 + 60 + 60 + 30) * (pi / 180)

    for rotate = 0, kLFish1Rotate,kRotateSpeed do
        fishPos = MathAide.BuildCircle2(center[1].x, center[1].y, kRadius, 40, rotate, kRotateSpeed)
        for j = 1, 40 do
           table.insert(sceneKind5Trace[j],fishPos[j])
        end
    end
    fishCount = fishCount + 40 --40

    for rotate = 0, kRFish2Rotate,kRotateSpeed do
        fishPos = MathAide.BuildCircle2(center[2].x, center[2].y, kRadius, 40, rotate, kRotateSpeed)
        for j = 1, 40 do
            table.insert(sceneKind5Trace[fishCount + j],fishPos[j])
        end
    end
    fishCount = fishCount + 40 --80

    for rotate = 0, kRFish5Rotate, kRotateSpeed do
        fishPos = MathAide.BuildCircle2(center[2].x, center[2].y, kRadius - 34.5 * kVScale, 40, rotate, kRotateSpeed)
        for j = 1, 40 do
            table.insert(sceneKind5Trace[fishCount + j],fishPos[j])
        end
    end
    fishCount = fishCount + 40  --120

    for rotate = 0, kLFish3Rotate, kRotateSpeed do
        fishPos = MathAide.BuildCircle2(center[1].x, center[1].y, kRadius - 36 * kVScale, 40, rotate, kRotateSpeed)
        for j = 1, 40 do
            table.insert(sceneKind5Trace[fishCount + j],fishPos[j])
        end
    end
    fishCount = fishCount + 40 --160

    for rotate = 0, kLFish4Rotate, kRotateSpeed do
        fishPos = MathAide.BuildCircle2(center[1].x, center[1].y, kRadius - 36 * kVScale - 56 * kVScale,  24, rotate, kRotateSpeed)
        for j = 1, 24 do
            table.insert(sceneKind5Trace[fishCount + j],fishPos[j])
        end
    end
    fishCount = fishCount + 24 --184

    for rotate = 0, kRFish6Rotate, kRotateSpeed do
        fishPos = MathAide.BuildCircle2(center[2].x, center[2].y, kRadius - 34.5 * kVScale - 58.5 * kVScale, 24, rotate, kRotateSpeed)
        for j = 1, 24 do
            table.insert(sceneKind5Trace[fishCount + j],fishPos[j])
        end
    end
    fishCount = fishCount + 24 --208

    for rotate = 0, kRFish7Rotate, kRotateSpeed do
        fishPos = MathAide.BuildCircle2(center[2].x, center[2].y, kRadius - 34.5 * kVScale - 58.5 * kVScale - 65 * kVScale, 13, rotate, kRotateSpeed)
        for j = 1, 13 do
            table.insert(sceneKind5Trace[fishCount + j],fishPos[j])
        end
    end
    fishCount = fishCount + 13 -- 221

    for rotate = 0, kLFish6Rotate, kRotateSpeed do
        fishPos = MathAide.BuildCircle2(center[1].x, center[1].y, kRadius - 36 * kVScale - 56 * kVScale - 68 * kVScale, 13, rotate, kRotateSpeed)
        for j = 1, 13 do
            table.insert(sceneKind5Trace[fishCount + j],fishPos[j])
        end
    end
    fishCount = fishCount + 13 --234

    for rotate = 0, kLFish18Rotate, kRotateSpeed do
        fishPos[1].x = center[1].x
        fishPos[1].y = center[1].y
        fishPos[1].angle = -pi2 + rotate
        table.insert(sceneKind5Trace[fishCount+1],fishPos[1])
    end
    fishCount = fishCount + 1 --235

    for rotate = 0, kRFish17Rotate, kRotateSpeed do
        fishPos[1].x = center[2].x
        fishPos[1].y = center[2].y
        fishPos[1].angle = -pi2 + rotate
        table.insert(sceneKind5Trace[fishCount+1],fishPos[1])
    end
    fishCount = fishCount + 1 --236

    local initX = {}
    local initY = {}

    for i = 1, #sceneKind5Trace do
        local pos = sceneKind5Trace[i][#sceneKind5Trace[i]]
        local tempVector = {}
        initX[1] = pos.x
        initY[1] = pos.y
        initX[2], initY[2],pos.angle = FishTrace.GetTargetPoint(screenWidth, screenHeight, pos.angle,pos.x, pos.y)
        tempVector = MathAide.BuildLinear(initX, initY, 2, kSpeed)
        tempVector[1].angle = pos.angle
        tempVector[2].angle = pos.angle
        -- logger:log("i = "..i..",angle = "..pos.angle)
        -- table.merge(targetTrace[i],sceneKind5Trace[i])

        for k,v in ipairs(tempVector) do
            -- sceneKind5Trace[i][#sceneKind5Trace[i] + k] = v
            table.insert(sceneKind5Trace[i],v)
        end
    end
    return sceneKind5Trace
end

function FishTrace.GetTargetPoint(screenWidth, screenHeight, angle,srcPosX, srcPosY)
    --300 160
    local angle = FishTrace.angle_range(angle)

    local targetPosX, targetPosY
    if (angle > 0 and angle < pi2) then
        targetPosX = screenWidth + 300
        targetPosY = srcPosY + (screenWidth - srcPosX + 300) * tanf(angle)
    elseif (angle >= pi2 and angle < pi) then
        targetPosX = -300
        targetPosY = srcPosY - (srcPosX + 300) * tanf(angle)
    elseif (angle >= pi and angle < 3 * pi / 2) then
        targetPosX = -300
        targetPosY = srcPosY - (srcPosX + 300) * tanf(angle)
    else
        targetPosX = screenWidth + 300
        targetPosY = srcPosY + (screenWidth - srcPosX + 300) * tanf(angle)
    end
    return targetPosX,targetPosY,angle
end

function FishTrace.angle_range(angle)
    while (angle <= -pi * 2)
    do
        angle = angle + (pi * 2)
    end
    if (angle < 0) then
      angle = angle + (pi * 2)
    end
    while (angle >= pi * 2)
    do
        angle = angle - (pi * 2)
    end
    return angle
end

function FishTrace.BuildTrace(screenWidth, screenHeight)
    local trace = {}
    local kVScale = nf.heightScale
    local kHScale = nf.widthScale

    local initX = {}
    local initY = {}
    for i = 1, 3 do
        initX[i] = math.random(0, display.width)
        initY[i] = math.random(0, display.height)
    end
    trace = MathAide.BuildBezier(initX,initY,3,1)

    return trace
end

function FishTrace:buildTestTrace()
    local dir = math.random(0,3)
    local initPos = {{},{},{}}
    local kResolutionWidth = nf.resolutionWidth
    local kResolutionHeight = nf.resolutionHeight
    local centerX = kResolutionWidth/2
    local centerY = kResolutionHeight/2

    local fishKind = 1
    local fishBoundingBoxHeight = {200}
    local fishBoundingBoxWidth = {200}
    local factor = (math.random(0,32767) % 2 == 0 and 1 or -1)

    local initX = {}
    local initY = {}
    if dir == 0 then
        initX[1] = (centerX + factor * (math.random(0,32767) % centerX))
        initY[1] =  - (fishBoundingBoxHeight[fishKind]) * 2
        initX[2] = (centerX + factor * (math.random(0,32767) % centerX))
        initY[2] = (centerY + (math.random(0,32767) % centerY))
        initX[3] = (centerX - factor * (math.random(0,32767) % centerX))
        initY[3] = (kResolutionHeight + fishBoundingBoxHeight[fishKind] * 2)
    elseif dir == 1 then
        initX[1] =  - (fishBoundingBoxWidth[fishKind]) * 2
        initY[1] = (centerY + factor * (math.random(0,32767) % centerY))
        initX[2] = (centerX + (math.random(0,32767) % centerX))
        initY[2] = (centerY + factor * (math.random(0,32767) % centerY))
        initX[3] = (kResolutionWidth + fishBoundingBoxWidth[fishKind] * 2)
        initY[3] = (centerY - factor * (math.random(0,32767) % centerY))
    elseif dir == 2 then
        initX[1] = (centerX + factor * (math.random(0,32767) % centerX))
        initY[1] = kResolutionHeight + (fishBoundingBoxHeight[fishKind] * 2)
        initX[2] = (centerX + factor * (math.random(0,32767) % centerX))
        initY[2] = (centerY - (math.random(0,32767) % centerY))
        initX[3] = (centerX - factor * (math.random(0,32767) % centerX))
        initY[3] = (-fishBoundingBoxHeight[fishKind] * 2)
    elseif dir == 3 then
        initX[1] = kResolutionWidth + (fishBoundingBoxWidth[fishKind] * 2)
        initY[1] = (centerY + factor * (math.random(0,32767) % centerY))
        initX[2] = (centerX - (math.random(0,32767) % centerX))
        initY[2] = (centerY + factor * (math.random(0,32767) % centerY))
        initX[3] = (-fishBoundingBoxWidth[fishKind] * 2)
        initY[3] = (centerY - factor * (math.random(0,32767) % centerY))
    end

    -- dump(initX)
    local fixInitX = {}
    local fixInitY = {}
    for j = 1,3  do
            local offsetPos = FishGameManager:getOffsetPos()
            if initX[j] < 0 then
                fixInitX[j] = initX[j] - offsetPos.x
             else
                fixInitX[j] = initX[j] + offsetPos.x
            end
            if initY[j] < 0 then
                fixInitY[j] = initY[j] - offsetPos.y
             else

                fixInitY[j] = initY[j] + offsetPos.y
            end
    end

    -- logger:log("fixInitX[1] = "..fixInitX[1]..",fixInitY[1] = "..fixInitY[1])
    local trace = MathAide.BuildBezier(fixInitX,fixInitY,3,1)

    return trace
end


return FishTrace
