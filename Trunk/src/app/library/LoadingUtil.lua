local LoadingUtil = class("LoadingUtil")

function LoadingUtil:ctor()
    self.plistList = {};        --plist列表
    self.total_plist_num = 0    --plist总数
    self.load_plist_num = 0     --加载了几个plist
    self.picList = {}           --图片列表
    self.total_pic_num = 0      --图片总数
    self.musicList = {}         --音乐列表
    self.total_music_num = 0    --音乐总数
    self.soundList = {}         --声音列表
    self.total_sound_num = 0    --声音总数
    self.all_num = 0            --总共需要加载的数量
    self.load_num = 0           --已加载数量
end

function LoadingUtil:loadResource(plistList,picList,musicList,soundList,onCompleteCallBack)

    self.onCompleteCallBack = onCompleteCallBack

    self.plistList = plistList
    self.total_plist_num = #self.plistList

    self.picList = picList
    self.total_pic_num = #self.picList

    self.musicList = musicList
    self.total_music_num = #musicList

    self.soundList = soundList
    self.total_sound_num = #self.soundList

    --获得总下载数
    self.all_num = self.total_plist_num + self.total_pic_num + self.total_music_num + self.total_sound_num

    --plist
    for i = 1,#self.plistList do
        cc.Director:getInstance():getTextureCache():addImageAsync(self.plistList[i]..".png",handler(self,self.onLoadPlist))
    end

    --image
    for i = 1,#self.picList do
        cc.Director:getInstance():getTextureCache():addImageAsync(self.picList[i],handler(self,self.onLoadImage))
    end

    --music
    for i = 1,#self.musicList do
        audio.preloadMusic(self.musicList[i])
    end
    self.load_num = self.load_num + self.total_music_num

    --sound
    for i = 1,#self.soundList do
        local sound = ""
        if device.platform == "android" then
            audio.preloadSound(self.soundList[i] .. ".mp3")
        else
            audio.preloadSound(self.soundList[i] .. ".ogg")
        end
    end
    self.load_num = self.load_num + self.total_sound_num

    if self.load_num == self.all_num then
        self:onAllLoadComplete()
    end
end

--加载plist文件回调
function LoadingUtil:onLoadPlist(parameters)

    self.load_num = self.load_num + 1
    self.load_plist_num = self.load_plist_num + 1

    local plist = self.plistList[self.load_plist_num]..".plist"
    cc.SpriteFrameCache:getInstance():addSpriteFrames(plist)


    print("LoadingUtil:onLoadPist-",self.load_num,self.load_plist_num)

    if self.load_num == self.all_num then
        self:onAllLoadComplete()
    end
end

--加载普通图片回调
function LoadingUtil:onLoadImage(parameters)
    self.load_num = self.load_num + 1

    print("LoadingUtil:onLoadImage",self.load_num,self.all_num)

    if self.load_num == self.all_num then
        self:onAllLoadComplete()
    end
end

function LoadingUtil:onAllLoadComplete()
    print("LoadingUtil:onAllLoadComplete()",self.load_num)
    if self.onCompleteCallBack ~= nil then
        self.onCompleteCallBack()
    end
end

function LoadingUtil:removeAllLoad()
    --plist
    cc.Director:getInstance():getTextureCache():unbindAllImageAsync()
    self.onCompleteCallBack = nil
end

return LoadingUtil
