//
//  FineUnity3D.cpp
//  FineSDK
//
//  Created by Cylee on 2019/4/11.
//  Copyright © 2019年 cylee. All rights reserved.
//

#include "FineUnity3D.h"

void initSDK(char* jsonString, CallBack callBack) {
    Platform::getInstance()->initSDK(jsonString, callBack);
}

void callUniversalFunction(char* functionName, char* jsonString) {
    Platform::getInstance()->callUniversalFunction(functionName, jsonString);
}
