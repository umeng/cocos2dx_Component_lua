/*
 * FileName : CCUMScoialSDK.h
 * Author   : hehonghui
 * Company  : umeng.com
 *
 */

#ifndef __CCUMLuaShare__
#define __CCUMLuaShare__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif


/**
 * Call this function can import the lua bindings for the mobclick module and start mobclick.
 * After registering, we could call the related mobclick code conveniently in the lua.
 */

int lua_register_umshare_module(lua_State* L);
#endif
