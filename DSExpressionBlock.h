//
//  DSExpressionBlock.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSExpressionBlock__
#define __ims__DSExpressionBlock__

#include <iostream>
#include "DSBlock.h"

class DSExpressionBlock : public DSBlock
{
    DSBlock *expression;
    
public:
    DSExpressionBlock(DSBlock *exp): expression(exp){};
    virtual double value();
};

#endif /* defined(__ims__DSExpressionBlock__) */
