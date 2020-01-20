//
//  FineSDK.h
//  FineSDK
//
//  Created by Cylee on 2019/2/12.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#ifndef FineSDK_h
#define FineSDK_h

#define return_if_fails(cond) if (!(cond)) return;

#import "ProtocolFather.h"
#import "FineSDKInterface.h"

class FineSDK : public ProtocolFather {
    
public:
    static FineSDK* getInstance();
    static const char* convertToChar(NSMutableDictionary* dict);
    static id <FineSDKInterface> getInterface();

    void callFunctionWithParams(const char* funcName, const char* params);
    
};

#endif /* FineSDK_h */
