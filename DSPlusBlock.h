//
//  DSPlusBlock.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSPlusBlock__
#define __ims__DSPlusBlock__

#include <iostream>
#include "DSOperator2Block.h"

// Trida plus. Jako hodnotu vraci soucet hodnot vyrazu.
class DSPlusBlock : public DSOperator2Block
{
    public:
    explicit DSPlusBlock(DSBlock *opr1, DSBlock *opr2): DSOperator2Block(opr1, opr2){};
    virtual double value();
};

#endif /* defined(__ims__DSPlusBlock__) */
