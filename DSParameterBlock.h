//
//  DSParameterBlock.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSParameterBlock__
#define __ims__DSParameterBlock__

#include <iostream>
#include "DSBlock.h"

class DSParameterBlock : public DSBlock
{
    protected:
    double parameter;
    
    public:
    DSParameterBlock(double value):parameter(value){};
    void set(double val);
    virtual double value();
};

#endif /* defined(__ims__DSParameterBlock__) */
