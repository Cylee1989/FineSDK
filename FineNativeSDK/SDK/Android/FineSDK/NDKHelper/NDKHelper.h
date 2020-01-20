//
//  NDKHelper.h
//  FineSDK
//
//  Created by Cylee on 2019/2/21.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#ifndef NDKHelper_h
#define NDKHelper_h

#include <string>

using namespace std;

class NDKHelper {

};

extern "C" {
    void SendMessageWithParams(string methodName, string methodParams);
}

#endif /* NDKHelper_h */
