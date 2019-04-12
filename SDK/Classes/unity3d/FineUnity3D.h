//
//  FineUnity3D.h
//  FineSDK
//
//  Created by Cylee on 2019/4/11.
//  Copyright © 2019年 cylee. All rights reserved.
//

#ifndef FineUnity3D_h
#define FineUnity3D_h

typedef void (*CallBack)(const char*);

#include "Platform.h"
#include <string>

extern "C" {
    
    void initSDK(char* jsonString, CallBack callBack);
    void callUniversalFunction(char* functionName, char* jsonString);

}

#endif /* FineUnity3D_h */
