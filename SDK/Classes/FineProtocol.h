//
//  FineProtocol.h
//  FineSDK
//
//  Created by Cylee on 2019/2/13.
//  Copyright © 2019年 Cylee. All rights reserved.
//

#ifndef FineProtocol_h
#define FineProtocol_h

#include "ProtocolFather.h"

class FineProtocol {
    
public:
    static FineProtocol* getInstance();
    ProtocolFather* loadProtocol();
    
private:
    ProtocolFather* _protocolFather;

};

#endif /* FineProtocol_h */
