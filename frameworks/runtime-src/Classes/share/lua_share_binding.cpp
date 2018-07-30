//
//  lua_binding.cpp

//
//  Created by zhouhouzhen on 17-9-20.
//  Copyright (c) 2015年 Umeng Inc. All rights reserved.
//


#include "lua_share_binding.h"
#include "CCUMSocialSDK.h"
#include "LuaBasicConversions.h"
#include "tolua++.h"
extern "C" {
#include "lua.h"
}
#define UMENG_SUCCESS 0
#define UMENG_FAILED 1

static lua_State* ls = nullptr;
static string authorizeFun;
static string delAuthorizeFun;
static string directFun;
static string boardFun;
static string boardCustomFun;
static string getInfoFun;

static void authorizeCallback(int platform, int stCode,map<string, string>& data){
    if (ls == NULL || authorizeFun.empty()){
        return;
    }
    lua_getglobal(ls, authorizeFun.c_str());
    lua_pushinteger(ls, platform);
    lua_pushinteger(ls, stCode);
    lua_newtable(ls);
    for(auto tag:data){
        tolua_pushcppstring(ls, tag.first);
        tolua_pushcppstring(ls, tag.second);
        lua_settable(ls,-3);//弹出key,value，并设置到table里面去
    }
    lua_call(ls, 3, 0);
}
static void delAuthorizeCallBack(int platform, int stCode,map<string, string>& data){
    if (ls == NULL || delAuthorizeFun.empty()){
        return;
    }
    lua_getglobal(ls, delAuthorizeFun.c_str());
    lua_pushinteger(ls, platform);
    lua_pushinteger(ls, stCode);
    lua_newtable(ls);
    for(auto tag:data){
        tolua_pushcppstring(ls, tag.first);
        tolua_pushcppstring(ls, tag.second);
        lua_settable(ls,-3);//弹出key,value，并设置到table里面去
    }
    lua_call(ls, 3, 0);
}
static void directCallback(int platform, int stCode, string& errorMsg){
    if (ls == NULL || directFun.empty()){
        return;
    }
    lua_getglobal(ls, directFun.c_str());
    lua_pushinteger(ls, platform);
    lua_pushinteger(ls, stCode);
    tolua_pushcppstring(ls, errorMsg);
    lua_call(ls, 3, 0);
}
static void boardCallBack(){
    if (ls == NULL || boardFun.empty()){
        return;
    }
    lua_getglobal(ls, boardFun.c_str());
    lua_call(ls, 0, 0);
}

static void boardCustomCallBack(int platform){
    if (ls == NULL || boardCustomFun.empty()){
        return;
    }
    lua_getglobal(ls, boardCustomFun.c_str());
    lua_pushinteger(ls, platform);
    lua_call(ls, 1, 0);
}
static void getInfoCallback(int platform, int stCode, map<string, string>& data){
    if (ls == NULL || getInfoFun.empty()){
        return;
    }
    lua_getglobal(ls, getInfoFun.c_str());
    lua_pushinteger(ls, platform);
    lua_pushinteger(ls, stCode);
    lua_newtable(ls);
    for(auto tag:data){
        tolua_pushcppstring(ls, tag.first);
        tolua_pushcppstring(ls, tag.second);
        lua_settable(ls,-3);//弹出key,value，并设置到table里面去
    }
    lua_call(ls, 3, 0);
}

int lua_umeng_share_authorize(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 2){
        int tags;
        if(!luaval_to_int32(L, 1, &tags, "umeng_authorize")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 2, &authorizeFun, "umeng_authorize")){
            return UMENG_FAILED;
        }
        umeng::CCUMSocialSDK::authorize(tags,auth_selector(authorizeCallback));
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}

int lua_umeng_share_del_authorize(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 2){
        int tags;
        if(!luaval_to_int32(L, 1, &tags, "umeng_del_authorize")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 2, &delAuthorizeFun, "umeng_del_authorize")){
            return UMENG_FAILED;
        }
        umeng::CCUMSocialSDK::deleteAuthorization(tags,auth_selector(delAuthorizeCallBack));
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}

int lua_umeng_share_directShare(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 6){
        int tags;
        if(!luaval_to_int32(L, 1, &tags, "umeng_directShare")){
            return UMENG_FAILED;
        }
        string text;
        if(!luaval_to_std_string(L, 2, &text, "umeng_directShare")){
            return UMENG_FAILED;
        }
        string title;
        if(!luaval_to_std_string(L, 3, &title, "umeng_directShare")){
            return UMENG_FAILED;
        }
        string url;
        if(!luaval_to_std_string(L, 4, &url, "umeng_directShare")){
            return UMENG_FAILED;
        }
        string image;
        if(!luaval_to_std_string(L, 5, &image, "umeng_directShare")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 6, &directFun, "umeng_directShare")){
            return UMENG_FAILED;
        }
        umeng::CCUMSocialSDK::directShare(tags,text.c_str(),title.c_str(),url.c_str(),image.c_str(),share_selector(directCallback));
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}
int lua_umeng_share_openShare(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 7){
        tolua_Error tolua_err;
        vector<int> platforms;
        if (tolua_istable(L, 1, 0, &tolua_err)){
            lua_pushnil(L);
            while ( 0 != lua_next(L, 1 ) )
            {
                int plat;
                if(luaval_to_int32(L, -1, &plat))
                {
                    platforms.push_back(plat);
                }
                lua_pop(L, 1);
            }
        }
        string text;
        if(!luaval_to_std_string(L, 2, &text, "umeng_openShare")){
            return UMENG_FAILED;
        }
        string title;
        if(!luaval_to_std_string(L, 3, &title, "umeng_openShare")){
            return UMENG_FAILED;
        }
        string url;
        if(!luaval_to_std_string(L, 4, &url, "umeng_openShare")){
            return UMENG_FAILED;
        }
        string image;
        if(!luaval_to_std_string(L, 5, &image, "umeng_openShare")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 6, &boardFun, "umeng_openShare")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 7, &directFun, "umeng_openShare")){
            return UMENG_FAILED;
        }
       umeng::CCUMSocialSDK::setBoardDismissCallback(boarddismiss_selector(boardCallBack));
        umeng::CCUMSocialSDK::openShare(&platforms,text.c_str(),title.c_str(),url.c_str(),image.c_str(),share_selector(directCallback));
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}


int lua_umeng_share_customShare(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 3){
        tolua_Error tolua_err;
        vector<int> platforms;
        if (tolua_istable(L, 1, 0, &tolua_err)){
            lua_pushnil(L);
            while ( 0 != lua_next(L, 1 ) )
            {
                int plat;
                if(luaval_to_int32(L, -1, &plat))
                {
                    
                    platforms.push_back(plat);
                }
                lua_pop(L, 1);
            }
        }
        std::string type;
        if(!luaval_to_std_string(L, 2, &boardFun, "umeng_customShare")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 3, &boardCustomFun, "umeng_customShare")){
            return UMENG_FAILED;
        }
        umeng::CCUMSocialSDK::setBoardDismissCallback(boarddismiss_selector(boardCallBack));
        umeng::CCUMSocialSDK::openCustomShare(&platforms,boardCustomCallBack);
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}

int lua_umeng_share_getInfo(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 2){
        int tags;
        if(!luaval_to_int32(L, 1, &tags, "umeng_getInfo")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 2, &getInfoFun, "umeng_getInfo")){
            return UMENG_FAILED;
        }
        umeng::CCUMSocialSDK::getPlatformInfo(tags,AuthEventHandler(getInfoCallback));
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}

int lua_register_UmengShare(lua_State* L)
{
    ls = L;
    lua_register(L,"umeng_authorize",lua_umeng_share_authorize);
    lua_register(L,"umeng_del_authorize",lua_umeng_share_del_authorize);
    lua_register(L,"umeng_directShare",lua_umeng_share_directShare);
    lua_register(L,"umeng_openShare",lua_umeng_share_openShare);
    lua_register(L,"umeng_customShare", lua_umeng_share_customShare);
    lua_register(L,"umeng_getInfo", lua_umeng_share_getInfo);
    return 1;
}

int lua_register_umshare_module(lua_State* L)
{
    lua_getglobal(L, "_G");
    if (lua_istable(L,-1))//stack:...,_G,
    {
        lua_register_UmengShare(L);
    }
    lua_pop(L, 1);
    return 1;
}
//#endif
