
#ifndef _UMENG_LUABASICCONVERSIONS_H_
#define _UMENG_LUABASICCONVERSIONS_H_
#include <stdlib.h>
#include "tolua_fix.h"
#include <string>
#include <map>
#include <vector>
extern bool luaval_to_ushort(lua_State* L, int lo, unsigned short* outValue, const char* funcName="");


extern bool luaval_to_int32(lua_State* L,int lo,int* outValue, const char* funcName="");

extern bool luaval_to_uint32(lua_State* L, int lo, unsigned int* outValue, const char* funcName="");
extern bool luaval_to_uint16(lua_State* L,int lo,uint16_t* outValue, const char* funcName="");

extern bool luaval_to_boolean(lua_State* L,int lo,bool* outValue, const char* funcName="");

extern bool luaval_to_number(lua_State* L,int lo,double* outValue, const char* funcName="");


extern bool luaval_to_long_long(lua_State* L,int lo,long long* outValue, const char* funcName="");
extern bool luaval_to_std_string(lua_State* L, int lo, std::string* outValue, const char* funcName="");



extern bool luaval_to_long(lua_State* L,int lo, long* outValue, const char* funcName="");
extern bool luaval_to_ssize(lua_State* L,int lo, ssize_t* outValue, const char* funcName="");

extern bool luaval_to_ulong(lua_State* L,int lo, unsigned long* outValue, const char* funcName="");

extern bool luaval_to_stdmap(lua_State* L, int lo, std::map<std::string, std::string>* ret, const char* funcName="");

extern bool luaval_to_std_vector_string(lua_State* L, int lo, std::vector<std::string>* ret, const char* funcName="");

extern bool luaval_to_std_vector_int(lua_State* L, int lo, std::vector<int>* ret, const char* funcName="");

extern bool luaval_to_std_vector_float(lua_State* L, int lo, std::vector<float>* ret, const char* funcName="");


extern bool luaval_to_std_vector_ushort(lua_State* L, int lo, std::vector<unsigned short>* ret, const char* funcName="");


extern void ccvector_std_string_to_luaval(lua_State* L, const std::vector<std::string>& inValue);


extern void ccvector_int_to_luaval(lua_State* L, const std::vector<int>& inValue);

extern void ccvector_float_to_luaval(lua_State* L, const std::vector<float>& inValue);


extern void ccvector_ushort_to_luaval(lua_State* L, const std::vector<unsigned short>& inValue);
extern bool luaval_is_usertype(lua_State* L,int lo,const char* type, int def);
#endif