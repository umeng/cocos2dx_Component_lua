#!/bin/bash
myPath="UMCocosLua"
version="5.0.0"

sharename="upload/share/share_cocos2dxlua_$version.zip"
pushname="upload/push/push_cocos2dxlua_$version.zip"
analyticsname="upload/analytics/analytics_cocos2dxlua_$version.zip"
commonname="upload/common/common_cocos2dxlua_$version.zip"

common_android="UMCocosLua/common_java/java/com/umeng/common"
common_ios="UMCocosLua/common_cc/"
analytics_android="UMCocos/analytics_java/java/com/umeng/analytics"
analytics_ios="UMCocos/analytics_cc/"
push_android="UMCocos/push_java/java/com/umeng/push"
push_android_lib="UMCocos/push_java/"
push_ios="UMCocos/push_cc/"
share_android="UMCocos/share_java/java/com/umeng/share"
share_ios="UMCocos/share_cc/"

upload="upload"
upload_share="upload/share/"
upload_push="upload/push/"
upload_analytics="upload/analytics/"
upload_common="upload/common/"

if [ ! -d "$upload" ]; then
	
 mkdir "$upload"

fi 
if [ ! -d "$upload_share" ]; then
	
 mkdir -p "$upload_share"
fi 
if [ ! -d "$upload_push" ]; then
	
 mkdir -p "$upload_push"
fi 
if [ ! -d "$upload_analytics" ]; then
	
 mkdir -p "$upload_analytics"
fi 
if [ ! -d "$upload_common" ]; then
	
 mkdir -p "$upload_common"
fi 



cp ./${myPath}1.0.zip "$sharename"
cp ./${myPath}1.0.zip "$pushname"
cp ./${myPath}1.0.zip "$analyticsname"
cp ./${myPath}1.0.zip "$commonname"


zip -r upload.zip ./upload/*