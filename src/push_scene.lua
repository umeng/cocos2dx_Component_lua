cc.exports.pushscene = {}

local function back(sender)
    -- body
    cc.Director:getInstance():popScene()
end

function pushscene.create()
	local scene = cc.Scene:create()
	local  item1 = cc.MenuItemFont:create("addtags"):setPosition(cc.p(300,490))
    local  item2 = cc.MenuItemFont:create("deltags"):setPosition(cc.p(300,420))
    local  item3 = cc.MenuItemFont:create("addalias"):setPosition(cc.p(300,350))
    local  item4 = cc.MenuItemFont:create("delalias"):setPosition(cc.p(300,280))
    local  item5 = cc.MenuItemFont:create("alias type"):setPosition(cc.p(300,210))
    local  item6 = cc.MenuItemFont:create("serialnet"):setPosition(cc.p(300,140))
    local  item7 = cc.MenuItemFont:create("listtags"):setPosition(cc.p(300,70))
    local  item8 = cc.MenuItemFont:create("add exclisive alias"):setPosition(cc.p(800,490))
    local  item9 = cc.MenuItemFont:create("appinfo"):setPosition(cc.p(800,420))
    local  item15 = cc.MenuItemFont:create("返回"):setPosition(cc.p(cc.Director:getInstance():getWinSize().width-100,100))
	item15:registerScriptTapHandler(back)
    local  menu = cc.Menu:create()
	menu:addChild(item1)
    menu:addChild(item2)
    menu:addChild(item3)
    menu:addChild(item4)
    menu:addChild(item5)
    menu:addChild(item6)
    menu:addChild(item7)
    menu:addChild(item8)
    menu:addChild(item9)
    menu:setPosition(cc.p(0,0))
    scene:addChild(cc.Layer:create():addChild(menu))
	return scene
end


return cc.exports.pushscene