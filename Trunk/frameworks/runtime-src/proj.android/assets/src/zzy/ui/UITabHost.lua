
local UITabHost = class("UITabHost", function()
    return display.newNode()
end)

function UITabHost:ctor(parameters)
    self.curIndex_ = 1

    self.num_ = parameters.num

    self.tabFrontSrc_ = parameters.tabFrontSrc
    self.tabBackSrc_ = parameters.tabBackSrc
    self.padding_ = parameters.padding

    if parameters.tabWidth then
        self.tabWidth_ = parameters.tabWidth
    else
        self.tabWidth_ = 0
    end

    if parameters.tabHeight then
        self.tabHeight_ = parameters.tabHeight
    else
        self.tabHeight_ = 0
    end

    self.offsetY_ = 0
    if parameters.offsetY then
        self.offsetY_ = parameters.offsetY
    end

    self.buttonOffSetX_ = self.labelOffsetX_ or 0
    if parameters.buttonOffSetX then
        self.buttonOffSetX_ = parameters.buttonOffSetX
    end

    self.isVertical_ = false
    if parameters.isVertical then
        self.isVertical_ = true
    end

    self.tabs_ = {}

    if self.isVertical_ then
        for i = 1 , self.num_ do
            self.tabs_[i] = ccui.Button:create(self.tabBackSrc_,self.tabBackSrc_,self.tabFrontSrc_,1)
            self.tabs_[i]:addTouchEventListener(handler(self,self.onTabClick))
            :onButtonClicked(handler(self,self.onTabClick))
            :addTo(self)

            self.tabs_[i]:setPosition(-self.buttonOffSetX_,-(self.tabHeight_ + self.padding_)*(i - 1))
        end
    else
        for i = 1 , self.num_ do
            self.tabs_[i] = ccui.Button:create(self.tabBackSrc_,self.tabBackSrc_,self.tabFrontSrc_,1)
            self.tabs_[i]:addTouchEventListener(handler(self,self.onTabClick))
            :onButtonClicked(handler(self,self.onTabClick))
            :addTo(self)

            self.tabs_[i]:setPosition((self.tabWidth_ + self.padding_)*(i - 1),-self.offsetY_)
        end
    end
    --当前设为第一个tab
    self.tabs_[1]:setButtonEnabled(false)
    self.tabs_[1]:setPosition(0,0)
--    self:onTabClick({target == self.tabs_[1]})
end

function UITabHost:setCallback(callback)
    self.callback_ = callback
    return self
end

function UITabHost:onTabClick(ref, type)
    if type == 2 then --release
        local index = 1
        if self.isVertical_ then
            for i = 1 , self.num_ do
                if self.tabs_[i] == ref then
                    index = i
                    self.tabs_[i]:setButtonEnabled(false)
                    self.tabs_[i]:setPosition(0,-(self.tabHeight_ + self.padding_)*(i - 1))
                else
                    self.tabs_[i]:setButtonEnabled(true)
                    self.tabs_[i]:setPosition(-self.buttonOffSetX_,-(self.tabHeight_ + self.padding_)*(i - 1))
                end
            end
        else
            for i = 1 , self.num_ do
                if self.tabs_[i] == ref then
                    index = i
                    self.tabs_[i]:setButtonEnabled(false)
                    self.tabs_[i]:setPosition((self.tabWidth_ + self.padding_)*(i - 1),0)
                else
                    self.tabs_[i]:setButtonEnabled(true)
                    self.tabs_[i]:setPosition((self.tabWidth_ + self.padding_)*(i - 1),-self.offsetY_)
                end
            end
        end
        if  self.callback_ then
           self.callback_(index)
        end
        self.curIndex_ = index
    end
end

function UITabHost:setCurTabIndex(i)
    --rp.SoundManager:playSounds(rp.SoundManager.btn_click)
    if self.curIndex_ == i then return end
    local index = i

    if self.isVertical_ then
        for i = 1 , self.num_ do
            if i == index then

                self.tabs_[i]:setButtonEnabled(false)
                self.tabs_[i]:setPosition(0,-(self.tabHeight_ + self.padding_)*(i - 1))
            else
                self.tabs_[i]:setButtonEnabled(true)
                self.tabs_[i]:setPosition(-self.buttonOffSetX_,-(self.tabHeight_ + self.padding_)*(i - 1))
            end
        end
    else
        for i = 1 , self.num_ do
            if i == index  then

                self.tabs_[i]:setButtonEnabled(false)
                self.tabs_[i]:setPosition((self.tabWidth_ + self.padding_)*(i - 1),0)
            else
                self.tabs_[i]:setButtonEnabled(true)
                self.tabs_[i]:setPosition((self.tabWidth_ + self.padding_)*(i - 1),-self.offsetY_)
            end
        end
    end

    self.curIndex_ = index
end

function UITabHost:getTabs()
    return self.tabs_
end
return UITabHost
