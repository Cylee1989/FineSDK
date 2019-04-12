//
//  Platform.h
//  FineSDK
//
//  Created by Cylee on 2019/2/13.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#ifndef Platform_h
#define Platform_h

#include "ProtocolObject.h"
#include "CallBackListener.h"

typedef void (*CallBack) (const char*);

class Platform :public ProtocolObject, CallBackListener {
    
public:
    static Platform* getInstance();
    void initSDK(string jsonString, CallBack callBack);
    void callUniversalFunction(string functionName, string jsonString);

private:
    CallBack _callBack;
    virtual void onSDKCallBack(string jsonString);

};

#endif /* Platform_h */
