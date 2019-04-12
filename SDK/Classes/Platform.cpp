//
//  Platform.cpp
//  FineSDK
//
//  Created by Cylee on 2019/2/13.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#include "Platform.h"
#include "FineProtocol.h"
#include "ProtocolFather.h"

Platform* _instance = NULL;
ProtocolFather* _protocol = NULL;
Platform* Platform::getInstance() {
    if (_instance == NULL) {
        _instance = new Platform();
        _protocol = FineProtocol::getInstance()->loadProtocol();
    }
    return _instance;
}

void Platform::initSDK(string jsonString, CallBack callBack) {
    this -> _callBack = callBack;
    _protocol -> registerListener(this);
    _protocol -> callFunctionWithParams("initSDK", jsonString.c_str());
}

void Platform::callUniversalFunction(string functionName, string jsonString) {
    _protocol -> callFunctionWithParams(functionName.c_str(), jsonString.c_str());
}

void Platform::onSDKCallBack(string params) {
    if(Platform::getInstance()->_callBack){
        Platform::getInstance()->_callBack(params.c_str());
    }
}


