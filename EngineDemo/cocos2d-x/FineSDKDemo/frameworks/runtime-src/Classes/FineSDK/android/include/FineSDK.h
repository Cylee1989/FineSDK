//
//  FineSDK.h
//  FineSDK
//
//  Created by Cylee on 2019/2/19.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#ifndef FineSDK_h
#define FineSDK_h

#include "ProtocolFather.h"

class FineSDK : public ProtocolFather {
    
public:
    static FineSDK* getInstance();
    void registerListener(CallBackListener* listener);
    void receiveCallBack(const char* param);
    void callFunctionWithParam(const char* funcName, const char* param);
};

#endif /* FineSDK_h */
