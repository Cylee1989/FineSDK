//
//  ProtocolFather.h
//  FineSDK
//
//  Created by Cylee on 2019/2/12.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#ifndef ProtocolFather_h
#define ProtocolFather_h

#include "ProtocolObject.h"
#include "CallBackListener.h"

class ProtocolFather :public ProtocolObject {

private:
    CallBackListener* _callBacklistener;

public:
    virtual void initProtocol();
    virtual void registerListener(CallBackListener* listener);
    virtual void receiveCallBack(const char* param);
    virtual void callFunctionWithParam(const char* funcName, const char* param);
    
};

#endif /* ProtocolFather_h */
