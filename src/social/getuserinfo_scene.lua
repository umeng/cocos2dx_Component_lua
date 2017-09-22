cc.exports.userinfoscene = {}


local function back(sender)
    -- body
    cc.Director:getInstance():popScene()
end

local function qq(sender)
    
end

local function sina(sender)
    
end

local function wx(sender)
    
end


function userinfoscene.create()
	local scene = cc.Scene:create()
    local size = cc.Director:getInstance():getWinSize()
	local  item1 = cc.MenuItemFont:create("qq"):setPosition(cc.p(size.width/2,size.height/2+100))
    item1:registerScriptTapHandler(qq)
    local  item2 = cc.MenuItemFont:create("新浪"):setPosition(cc.p(size.width/2,size.height/2))
    item2:registerScriptTapHandler(sina)
    local  item3 = cc.MenuItemFont:create("微信"):setPosition(cc.p(size.width/2,size.height/2-100))
    item3:registerScriptTapHandler(wx)
    local  item4 = cc.MenuItemFont:create("返回"):setPosition(cc.p(cc.Director:getInstance():getWinSize().width-100,100))
	item4:registerScriptTapHandler(back)
    local  menu = cc.Menu:create()
	menu:addChild(item1)
    menu:addChild(item2)
    menu:addChild(item3)
    menu:addChild(item4)
    menu:setPosition(cc.p(0,0))
    scene:addChild(cc.Layer:create():addChild(menu))
	return scene
end


return cc.exports.userinfoscene
