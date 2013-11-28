//
//  DSPlusBlock.h
//  ims
//
//  Created by Kryštof Matěj on 27.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSPlusBlock__
#define __ims__DSPlusBlock__

#include <iostream>
#include "DSOperator2Block.h"

class DSPlusBlock : public DSOperator2Block
{
    public:
    explicit DSPlusBlock(DSBlock *opr1, DSBlock *opr2): DSOperator2Block(opr1, opr2){};
    virtual double value();
};

#endif /* defined(__ims__DSPlusBlock__) */
