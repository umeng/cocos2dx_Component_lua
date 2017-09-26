cc.exports.umSocialForLua = {}


cc.exports.umSharePlatform = {
    --新浪微博
    SINA = 0,
    --微信
    WEIXIN = 1,
    --微信朋友圈
    WEIXIN_CIRCLE = 2,
    -- QQ
    QQ = 3,
    -- QQ空间
    QZONE = 4,
    -- 人人网
    RENREN = 5,
    -- 豆瓣
    DOUBAN = 6,
    -- 来往
    LAIWANG = 7,
    --- 来往动态
    LAIWANG_CIRCLE = 8,
    -- 易信
    sYIXIN = 9,
    -- 易信朋友圈
    YIXIN_CIRCLE = 10,
    -- facebook
    FACEBOOK = 11,
    -- twitter
    TWITTER = 12,
    -- instagram
    INSTAGRAM = 13,
    -- 短信
    SMS = 14,
    -- 邮件
    EMAIL = 15,
    -- 腾讯微博
    TENCENT_WEIBO = 16
};
--[[ qq授权
     @callback 回调接口
     @return .
 ]]
function umSocialForLua.QQ_authorize(callback_str)
    umeng_authorize(umSharePlatform["QQ"],callback_str)
end
--[[ qq取消授权
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.QQ_del_authorize(callback_str)
    umeng_del_authorize(umSharePlatform["QQ"],callback_str)
end
--[[ sina授权
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.sina_authorize(callback_str)
    umeng_authorize(umSharePlatform["SINA"],callback_str)
end

--[[ qq取消授权
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.sina_del_authorize(callback_str)
    umeng_del_authorize(umSharePlatform["SINA"],callback_str)
end
--[[ wx授权
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.wx_authorize(callback_str)
    umeng_authorize(umSharePlatform["WEIXIN"],callback_str)
end

--[[ wx取消授权
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.wx_del_authorize(callback_str)
    umeng_del_authorize(umSharePlatform["WEIXIN"],callback_str)
end

--[[ facebook授权
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.facebook_authorize(callback_str)
    umeng_authorize(umSharePlatform["FACEBOOK"],callback_str)
end

--[[ facebook取消授权
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.facebook_del_authorize(callback_str)
    umeng_del_authorize(umSharePlatform["FACEBOOK"],callback_str)
end

--[[ twitter授权
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.twitter_authorize(callback_str)
    umeng_authorize(umSharePlatform["TWITTER"],callback_str)
end

--[[ twitter取消授权
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.twitter_del_authorize(callback_str)
    umeng_del_authorize(umSharePlatform["TWITTER"],callback_str)
end

--[[ qq分享
     @text 文本
     @title 标题
     @targeturl 目标url
     @imgName   图片名称
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.qq_share(text,title,targeturl,imgName,callback_str)
    umeng_directShare(umSharePlatform["QQ"],text,title,targeturl,imgName,callback_str)
end

--[[ sina分享
     @text 文本
     @title 标题
     @targeturl 目标url
     @imgName   图片名称
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.sina_share(text,title,targeturl,imgName,callback_str)
    umeng_directShare(umSharePlatform["SINA"],text,title,targeturl,imgName,callback_str)
end

--[[ 微信分享
     @text 文本
     @title 标题
     @targeturl 目标url
     @imgName   图片名称
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.wx_share(text,title,targeturl,imgName,callback_str)
    umeng_directShare(umSharePlatform["WEIXIN"],text,title,targeturl,imgName,callback_str)
end

--[[ 打开分享界面
     @platforms 要分享的平台数组
     @text 文本
     @title 标题
     @targeturl 目标url
     @imgName   图片名称
     @boardDismissCallback 平台消失时的回调
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.open_share(platforms,text,title,targeturl,imgName,boardDismissCallback,callback_str)
    umeng_openShare(platforms,text,title,targeturl,imgName,boardDismissCallback,callback_str)
end

--[[ 自定义分享
     @platforms 要分享的平台数组
     @boardDismissCallback 平台消失时的回调
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.curtom_share(platforms,boardDismissCallback,callback_str)
    umeng_customShare(platforms,boardDismissCallback,callback_str)
end


--[[ 获取用户qq信息
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.qq_getInfo(callback_str)
    umeng_getInfo(umSharePlatform["QQ"],callback_str)
end

--[[ 获取用户sina信息
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.sina_getInfo(callback_str)
    umeng_getInfo(umSharePlatform["SINA"],callback_str)
end

--[[ 获取用户wx信息
     @callback 回调接口
     @return .
 ]]

function umSocialForLua.wx_getInfo(callback_str)
    umeng_getInfo(umSharePlatform["WEIXIN"],callback_str)
end

return cc.exports.umSocialForLua
