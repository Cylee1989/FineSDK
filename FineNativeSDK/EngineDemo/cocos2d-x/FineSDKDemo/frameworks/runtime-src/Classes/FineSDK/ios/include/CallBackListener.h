//
//  CallBackListener.h
//  FineSDK
//
//  Created by Cylee on 2019/2/18.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#ifndef CallBackListener_h
#define CallBackListener_h

#include <string>

using namespace std;

class CallBackListener {
    
public:
    virtual void onSDKCallBack(string params){};
    
};

#endif /* CallBackListener_h */
