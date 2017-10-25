//
//  MobClickCpp.m
//  MobClickCpp
//
//  Created by 周厚振 on 16-5-24.
//  Copyright (c) 2016年 zhouhouzhen. All rights reserved.
//

#include "UMCCCommon.h"
#include <platform/CCCommon.h>
#include <jni/JniHelper.h>
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
//#include <stdio.h>
//#include "cocos2d.h"

#include <map>
#include <string>
#include <utility>
#include <vector>
#include <stddef.h>





USING_NS_CC;
using namespace std;


extern "C"
    {
         static bool getCCommonMethod(JniMethodInfo &mi, const char *methodName,const char *signature) {

            return JniHelper::getStaticMethodInfo(mi,
            "com/umeng/common/UMCocosConfigure", methodName, signature);
        }

        static void releaseCommonMethod(JniMethodInfo &mi) {
        mi.env->DeleteLocalRef(mi.classID);
        }
       
JNIEXPORT void JNICALL Java_com_umeng_common_UMCocosConfigure_InitCC (
        JNIEnv *env, jclass clz) {
       jclass strClass = env->FindClass("com/umeng/common/UMCocosConfigure");
    if(strClass==0){

        return;
    }
     jmethodID mid = env->GetStaticMethodID(strClass, "initCocos", "(Ljava/lang/String;Ljava/lang/String;)V");
  
     if(mid==0){
        return;
    }

     jstring version = env->NewStringUTF(VERSION);
    jstring type = env->NewStringUTF(WRAP_TYPE);

    env->CallStaticVoidMethod(strClass, mid,type,version);
}

    }

    void UMCCCommon::setLogEnabled(bool value){
         JniMethodInfo mi;
        bool isHave = getCCommonMethod(mi, "setLog",  "(Z)V");
        if (isHave) {
        mi.env->CallStaticVoidMethod(mi.classID, mi.methodID, value);
        releaseCommonMethod(mi);
        } 
    }
    void UMCCCommon::init(const char *appkey, const char *channel){
       
    }
   

