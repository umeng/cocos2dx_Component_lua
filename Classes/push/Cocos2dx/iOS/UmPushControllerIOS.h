

#ifndef __UmengGame__UmPushControllerIOS__
#define __UmengGame__UmPushControllerIOS__

#include "CCUMTypeDef.h"
#include <string>
#include <vector>
#import "CCUMPushSDK.h"


using namespace std;
using namespace umeng::social;

class UmPushControllerIOS {
public:
    
   
    
    //初始化sdk @石乐
    
    static void initCocos2dxSDK(const char *sdkType, const char *version);
    static void setAlias(const char *name, const char *type, PushCallBack callback);
      
private:
    static string m_appKey;
};

#endif /* defined(__UmengGame__UmPushControllerIOS__) */