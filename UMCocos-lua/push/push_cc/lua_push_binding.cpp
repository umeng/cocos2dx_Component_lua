//
//  lua_binding.cpp

//
//  Created by zhouhouzhen on 17-9-20.
//  Copyright (c) 2015年 Umeng Inc. All rights reserved.
//


#include "lua_push_binding.h"
#include "CCUMPushSDK.h"
#include "LuaBasicConversions.h"
#include "tolua++.h"
extern "C" {
#include "lua.h"
}
#define UMENG_SUCCESS 0
#define UMENG_FAILED 1

static lua_State* ls = nullptr;
static string addtagFun;
static string deltagFun;
static string gettagFun;
static string addAliasFun;
static string setAliasFun;
static string remAliasFun;
static void addTagsCallback(int stCode,int remain){
    if (ls == NULL || addtagFun.empty()){
        return;
    }
    lua_getglobal(ls, addtagFun.c_str());
    lua_pushinteger(ls, stCode);
    lua_pushinteger(ls, remain);
    lua_call(ls, 2, 0);
}
static void delTagsCallback(int stCode,int remain){
    if (ls == NULL || deltagFun.empty()){
        return;
    }
    lua_getglobal(ls, deltagFun.c_str());
    lua_pushinteger(ls, stCode);
    lua_pushinteger(ls, remain);
    lua_call(ls, 2, 0);
}
static void tagsCallback(int stCode, list<string>& data){
    lua_getglobal(ls, gettagFun.c_str());
    lua_pushinteger(ls, stCode);
    lua_newtable(ls);
    lua_pushnumber(ls, -1); //push -1 into stack
    lua_rawseti(ls, -2, 0);
    int i = 0;
    for(auto tag:data){
        tolua_pushcppstring(ls, tag);
        lua_rawseti(ls, -2, i+1);
        i++;
    }
    lua_call(ls, 2, 0);
}
static void addAliasCallback(int stCode){
    if (ls == NULL || addAliasFun.empty()){
        return;
    }
    lua_getglobal(ls, addAliasFun.c_str());
    lua_pushinteger(ls, stCode);
    lua_call(ls, 1, 0);
}
static void delAliasCallback(int stCode){
    if (ls == NULL || remAliasFun.empty()){
        return;
    }
    lua_getglobal(ls, remAliasFun.c_str());
    lua_pushinteger(ls, stCode);
    lua_call(ls, 1, 0);
}
static void setAliasCallback(int stCode){
    if (ls == NULL || setAliasFun.empty()){
        return;
    }
    lua_getglobal(ls, setAliasFun.c_str());
    lua_pushinteger(ls, stCode);
    lua_call(ls, 1, 0);
}
int lua_umeng_push_addTags(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 2){
        std::string tags;
        if(!luaval_to_std_string(L, 1, &tags, "umeng_addTags")){
            return UMENG_FAILED;
        }
        addtagFun="";
        if(!luaval_to_std_string(L, 2, &addtagFun, "umeng_addTags")){
            return UMENG_FAILED;
        }
        umeng::CCUMPushSDK::addTags(tags.c_str(),addTagsCallback);
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}

int lua_umeng_push_deleteTags(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 2){
        std::string tags;
        if(!luaval_to_std_string(L, 1, &tags, "umeng_deleteTags")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 2, &deltagFun, "umeng_deleteTags")){
            return UMENG_FAILED;
        }
        umeng::CCUMPushSDK::deleteTags(tags.c_str(),delTagsCallback);
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}

int lua_umeng_push_getTags(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 1){
        if(!luaval_to_std_string(L, 1, &gettagFun, "umeng_getTags")){
            return UMENG_FAILED;
        }
        umeng::CCUMPushSDK::getTags(tagsCallback);
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}
int lua_umeng_push_addAlias(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 3){
        std::string name;
        if(!luaval_to_std_string(L, 1, &name, "umeng_addAlias")){
            return UMENG_FAILED;
        }
        std::string type;
        if(!luaval_to_std_string(L, 2, &type, "umeng_addAlias")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 3, &addAliasFun, "umeng_addAlias")){
            return UMENG_FAILED;
        }
        umeng::CCUMPushSDK::addAlias(name.c_str(),type.c_str(),addAliasCallback);
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}


int lua_umeng_push_setAlias(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 3){
        std::string name;
        if(!luaval_to_std_string(L, 1, &name, "umeng_setAlias")){
            return UMENG_FAILED;
        }
        std::string type;
        if(!luaval_to_std_string(L, 2, &type, "umeng_setAlias")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 3, &setAliasFun, "umeng_setAlias")){
            return UMENG_FAILED;
        }
        umeng::CCUMPushSDK::setAlias(name.c_str(),type.c_str(),setAliasCallback);
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}

int lua_umeng_push_removeAlias(lua_State* L)
{
    int paranum = 0;
    paranum = lua_gettop(L);
    if (paranum == 3){
        std::string name;
        if(!luaval_to_std_string(L, 1, &name, "umeng_removeAlias")){
            return UMENG_FAILED;
        }
        std::string type;
        if(!luaval_to_std_string(L, 2, &type, "umeng_removeAlias")){
            return UMENG_FAILED;
        }
        if(!luaval_to_std_string(L, 3, &remAliasFun, "umeng_removeAlias")){
            return UMENG_FAILED;
        }
        umeng::CCUMPushSDK::removeAlias(name.c_str(),type.c_str(),delAliasCallback);
        return UMENG_SUCCESS;
    }
    return UMENG_FAILED;
}

int lua_register_UmengPush(lua_State* L)
{
    ls = L;
    lua_register(L,"umeng_addTags",lua_umeng_push_addTags);
    lua_register(L,"umeng_deleteTags",lua_umeng_push_deleteTags);
    lua_register(L,"umeng_getTags",lua_umeng_push_getTags);
    lua_register(L,"umeng_addAlias",lua_umeng_push_addAlias);
    lua_register(L,"umeng_setAlias", lua_umeng_push_setAlias);
    lua_register(L,"umeng_removeAlias", lua_umeng_push_removeAlias);
    return 1;
}

int lua_register_umpush_module(lua_State* L)
{
    lua_getglobal(L, "_G");
    if (lua_istable(L,-1))//stack:...,_G,
    {
        lua_register_UmengPush(L);
    }
    lua_pop(L, 1);
    return 1;
}
//#endif
