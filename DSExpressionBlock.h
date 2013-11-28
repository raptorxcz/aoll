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
#include "DSOperator1Block.h"

class DSExpressionBlock : public DSOperator1Block
{
public:
    DSExpressionBlock(DSBlock *exp): DSOperator1Block(exp){};
    virtual double value();
};

#endif /* defined(__ims__DSExpressionBlock__) */
