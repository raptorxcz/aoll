//
//  DSUnaryMinusBlock.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSUnaryMinusBlock__
#define __ims__DSUnaryMinusBlock__

#include <iostream>
#include "DSOperator1Block.h"

class DSUnaryMinusBlock: public DSOperator1Block
{
    
    public:
    explicit DSUnaryMinusBlock(DSBlock *opr1): DSOperator1Block(opr1){};
    virtual double value();
};

#endif /* defined(__ims__DSUnaryMinusBlock__) */
