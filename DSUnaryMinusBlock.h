//
//  DSUnaryMinusBlock.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSUnaryMinusBlock__
#define __ims__DSUnaryMinusBlock__

#include <iostream>
#include "DSOperator1Block.h"

// Trida unarniho minus. Jako hodnotu vraci negovanou hodnotu vyrazu.
class DSUnaryMinusBlock: public DSOperator1Block
{
    
    public:
    explicit DSUnaryMinusBlock(DSBlock *opr1): DSOperator1Block(opr1){};
    virtual double value();
};

#endif /* defined(__ims__DSUnaryMinusBlock__) */
