//
//  DSEquation.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSEquation__
#define __ims__DSEquation__

#include <iostream>
#include "DSBlock.h"

class DSEquation
{
    protected:
    DSBlock *result;
    
public:
    DSEquation(DSBlock *r): result(r){};
    double value (){ return result->value(); };
    DSBlock *getResult();
};

#endif /* defined(__ims__DSEquation__) */
