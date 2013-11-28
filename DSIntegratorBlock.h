//
//  DSIntegratorBlock.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSIntegratorBlock__
#define __ims__DSIntegratorBlock__

#include <iostream>
#include "DSBlock.h"
#include "DSEquation.h"

typedef enum intType
{
    EULER,
    RUNGEKUTT,
    ADAMB
}IntegratorType;

class DSIntegratorBlock: public DSBlock
{
protected:
    IntegratorType type = EULER;
    DSBlock *theBlock;

    public:
    BSIntegratorBlock();
    ~BSIntegratorBlock();
    virtual double value();
    void method(IntegratorType inType);
};

#endif /* defined(__ims__DSIntegratorBlock__) */
