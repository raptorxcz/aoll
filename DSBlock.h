//
//  SDBlock.h
//  ims
//
//  Created by Kryštof Matěj on 27.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__SDBlock__
#define __ims__SDBlock__

#include <iostream>
class DSParameterBlock;

class DSBlock
{
    public:
//    virtual void operator () (double x);
    virtual double value();
};

#include "DSParameterBlock.h"

#endif /* defined(__ims__SDBlock__) */
