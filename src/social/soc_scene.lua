cc.exports.socscene = {}

local lab_tag = 456
local function back(sender)
    -- body
    cc.Director:getInstance():popScene()
end
local function qq_share(sender)
    -- body
    cc.Director:getInstance():popScene()
end
local function sina_share(sender)
    -- body
    cc.Director:getInstance():popScene()
end

local function wx_share(sender)
    -- body
    cc.Director:getInstance():popScene()
end

local function facebook_share(sender)
    -- body
    cc.Director:getInstance():popScene()
end

local function twitter_share(sender)
    -- body
    cc.Director:getInstance():popScene()
end

function socscene.create()
	local scene = cc.Scene:create()
    local size = cc.Director:getInstance():getWinSize()
	local  item1 = cc.MenuItemFont:create("qq"):setPosition(cc.p(300,490))
    item1:registerScriptTapHandler(qq_share)
    local  item2 = cc.MenuItemFont:create("新浪"):setPosition(cc.p(300,420))
    item2:registerScriptTapHandler(sina_share)
    local  item3 = cc.MenuItemFont:create("微信"):setPosition(cc.p(300,350))
    item3:registerScriptTapHandler(wx_share)
    local  item4 = cc.MenuItemFont:create("打开分享面板"):setPosition(cc.p(300,280))
    item4:registerScriptTapHandler(facebook_share)
    local  item5 = cc.MenuItemFont:create("打开分享不同内容分享面板"):setPosition(cc.p(300,210))
    item5:registerScriptTapHandler(twitter_share)
    local label = cc.Label:createWithSystemFont("分享回调结果","Arial", 50)
    label:setPosition(cc.p(size.width/2,50))
    local  item6 = cc.MenuItemFont:create("返回"):setPosition(cc.p(cc.Director:getInstance():getWinSize().width-100,100))
	item6:registerScriptTapHandler(back)
    local  menu = cc.Menu:create()
	menu:addChild(item1)
    menu:addChild(item2)
    menu:addChild(item3)
    menu:addChild(item4)
    menu:addChild(item5)
    menu:addChild(item6)
    menu:setPosition(cc.p(0,0))
    local layer = cc.Layer:create()
    layer:addChild(menu)
    layer:addChild(label,lab_tag)
    scene:addChild(layer)
	return scene
end


return cc.exports.socscene
