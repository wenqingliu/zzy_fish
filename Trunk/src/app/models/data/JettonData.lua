local JettonData = class("Jetton")

function JettonData:ctor()
	self.x = 0
    self.y = 0 
    self.type = 0;
    self.score = 0;
    self.area = 0;
end

return JettonData