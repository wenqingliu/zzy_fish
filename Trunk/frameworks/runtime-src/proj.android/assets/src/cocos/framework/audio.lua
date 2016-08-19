--[[

Copyright (c) 2011-2014 chukong-inc.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

]]

local audio = {}

local engine = cc.SimpleAudioEngine:getInstance()

audio.SoundVolume = 1

function audio.getMusicVolume()
    local volume = engine:getMusicVolume()
    
    if DEBUG > 1 then
--        printf("[audio] getMusicVolume() - volume: %0.2f", volume)
    end
    return volume
end

function audio.setMusicVolume(volume)
    volume = checknumber(volume)
    if DEBUG > 1 then
        printf("[audio] setMusicVolume() - volume: %0.2f", volume)
    end
    engine:setMusicVolume(volume)
end

function audio.preloadMusic(filename)
--    if device.platform == "android" then
--        filename = filename .. ".ogg"
--    else device.platform == "ios"
--        filename = filename .. ".mp3"
--    end
    
    assert(filename, "audio.preloadMusic() - invalid filename")
    if DEBUG > 1 then
        printf("[audio] preloadMusic() - filename: %s", tostring(filename))
    end
    engine:preloadMusic(filename)
end

function audio.playMusic(filename, isLoop)
--    if device.platform == "android" then
--        filename = filename .. ".ogg"
--    elseif device.platform == "ios" then
--        filename = filename .. ".mp3"
--    end
    assert(filename, "audio.playMusic() - invalid filename")
    if type(isLoop) ~= "boolean" then isLoop = true end

    audio.stopMusic()
    if DEBUG > 1 then
        printf("[audio] playMusic() - filename: %s, isLoop: %s", tostring(filename), tostring(isLoop))
    end
    engine:playMusic(filename, isLoop)
    
    --待编辑
    --屏蔽声音
    if TEST ~= nil and TEST > 0 then
        if cc.Application:getInstance():getTargetPlatform() == cc.PLATFORM_OS_WINDOWS then
            audio:stopMusic()
        end
    end
end

function audio.stopMusic(isReleaseData)
    isReleaseData = checkbool(isReleaseData)
    if DEBUG > 1 then
        printf("[audio] stopMusic() - isReleaseData: %s", tostring(isReleaseData))
    end
    engine:stopMusic(isReleaseData)
end

function audio.pauseMusic()
    if DEBUG > 1 then
        printf("[audio] pauseMusic()")
    end
    engine:pauseMusic()
end

function audio.resumeMusic()
    if DEBUG > 1 then
        printf("[audio] resumeMusic()")
    end
    engine:resumeMusic()
end

function audio.rewindMusic()
    if DEBUG > 1 then
        printf("[audio] rewindMusic()")
    end
    engine:rewindMusic()
end

function audio.isMusicPlaying()
    local ret = engine:isMusicPlaying()
    if DEBUG > 1 then
        printf("[audio] isMusicPlaying() - ret: %s", tostring(ret))
    end
    return ret
end

function audio.getSoundsVolume()
    if device.platform == "ios" then
        audio.SoundVolume = engine:getEffectsVolume()
    end
    
    if DEBUG > 1 then
        printf("[audio] getSoundsVolume() - volume: %0.1f", audio.SoundVolume)
    end
    return audio.SoundVolume
end

function audio.setSoundsVolume(volume)
    audio.SoundVolume = checknumber(volume)
    if DEBUG > 1 then
        printf("[audio] setSoundsVolume() - volume: %0.1f", volume)
    end
    engine:setEffectsVolume(audio.SoundVolume)
end

function audio.playSound(filename, isLoop)
    if device.platform == "ios" then
        filename = filename .. ".mp3"
    else
        filename = filename .. ".ogg"
    end

    if not filename then
        printError("audio.playSound() - invalid filename")
        return
    end
    if type(isLoop) ~= "boolean" then isLoop = false end
    if DEBUG > 1 then
        printf("[audio] playSound() - filename: %s, isLoop: %s", tostring(filename), tostring(isLoop))
    end
    if device.platform == "ios" then
        return engine:playEffect(filename, isLoop)
    else
        return ccexp.AudioEngine:play2d(filename,isLoop,audio.getSoundsVolume())
    end
    
end

function audio.pauseSound(handle)
    if not handle then
        printError("audio.pauseSound() - invalid handle")
        return
    end
    if DEBUG > 1 then
        printf("[audio] pauseSound() - handle: %s", tostring(handle))
    end
    if device.platform == "ios" then
        engine:pauseEffect(handle)
    else
        ccexp.AudioEngine:pause(handle)
    end
    
end

function audio.pauseAllSounds()
    if DEBUG > 1 then
        printf("[audio] pauseAllSounds()")
    end
    if device.platform == "ios" then
        engine:pauseAllEffects()
    else
        ccexp.AudioEngine:pauseAll()
    end
    
end

function audio.resumeSound(handle)
    if not handle then
        printError("audio.resumeSound() - invalid handle")
        return
    end
    if DEBUG > 1 then
        printf("[audio] resumeSound() - handle: %s", tostring(handle))
    end
    if device.platform == "ios" then
        engine:resumeEffect(handle)
    else
        ccexp.AudioEngine:resume(handle)
    end
    
end

function audio.resumeAllSounds()
    if DEBUG > 1 then
        printf("[audio] resumeAllSounds()")
    end
    if device.platform == "ios" then
        engine:resumeAllEffects()
    else
        ccexp.AudioEngine:resumeAll()
    end
    
end

function audio.stopSound(handle)
    if not handle then
        printError("audio.stopSound() - invalid handle")
        return
    end
    if DEBUG > 1 then
        printf("[audio] stopSound() - handle: %s", tostring(handle))
    end
    if device.platform == "ios" then
        engine:stopEffect(handle)
    else
        ccexp.AudioEngine:stop(handle)
    end
    
end

function audio.stopAllSounds()
    if DEBUG > 1 then
        printf("[audio] stopAllSounds()")
    end
    if device.platform == "ios" then
        engine:stopAllEffects()
    else
        ccexp.AudioEngine:stopAll()
    end
end
audio.stopAllEffects = audio.stopAllSounds

function audio.preloadSound(filename)
    if device.platform == "ios" then
        filename = filename .. ".mp3"
    else
        filename = filename .. ".ogg"
    end
    
    if not filename then
        printError("audio.preloadSound() - invalid filename")
        return
    end
    if DEBUG > 1 then
        printf("[audio] preloadSound() - filename: %s", tostring(filename))
    end
    engine:preloadEffect(filename)
end

function audio.unloadSound(filename)
    if device.platform == "ios" then
        filename = filename .. ".mp3"
    else
        filename = filename .. ".ogg"
    end
    
    if not filename then
        printError("audio.unloadSound() - invalid filename")
        return
    end
    if DEBUG > 1 then
        printf("[audio] unloadSound() - filename: %s", tostring(filename))
    end
    
    if device.platform == "ios" then
        engine:unloadEffect(filename)
    else
        ccexp.AudioEngine:uncache()
    end
end

return audio
