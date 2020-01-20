//
//  ProtocolFather.cpp
//  FineSDK
//
//  Created by Cylee on 2019/2/12.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#include "ProtocolFather.h"

void ProtocolFather::initProtocol(){}

void ProtocolFather::callFunctionWithParams(const char* funcName, const char* params){}

void ProtocolFather::registerListener(CallBackListener* listener){
    _callBacklistener = listener;
}

void ProtocolFather::receiveCallBack(const char* param){
    if (_callBacklistener) {
        _callBacklistener -> onSDKCallBack(param);
    }
}
