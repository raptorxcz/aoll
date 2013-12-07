//
//  DSMinusBlock.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSMinusBlock__
#define __ims__DSMinusBlock__

#include <iostream>
#include "DSOperator2Block.h"

// Trida minus. Jako hodnotu vraci rozdil hodnot vyrazu.
class DSMinusBlock : public DSOperator2Block
{
public:
    explicit DSMinusBlock(DSBlock *opr1, DSBlock *opr2): DSOperator2Block(opr1, opr2){};
    virtual double value();
};

#endif /* defined(__ims__DSMinusBlock__) */
