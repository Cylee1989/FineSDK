//
//  FineProtocol.cpp
//  FineSDK
//
//  Created by Cylee on 2019/2/13.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#include "FineSDK.h"
#include "FineProtocol.h"

static FineProtocol* _instance = NULL;
FineProtocol* FineProtocol::getInstance() {
    if (_instance == NULL) {
        _instance = new FineProtocol();
    }
    return _instance;
}

ProtocolFather* FineProtocol::loadProtocol() {
    if (_protocolFather != NULL) {
        return _protocolFather;
    }
    
    ProtocolFather* pRet = FineSDK::getInstance();
    if (pRet != NULL) {
        pRet -> initProtocol();
    }
    _protocolFather = pRet;
    return pRet;
}
