//
//  DSMultiBlock.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSMultiBlock__
#define __ims__DSMultiBlock__

#include <iostream>
#include "DSOperator2Block.h"

// Trida krat. Jako hodnotu vraci nasobeni hodnot vyrazu.
class DSMultiBlock : public DSOperator2Block
{
public:
    explicit DSMultiBlock(DSBlock *opr1, DSBlock *opr2): DSOperator2Block(opr1, opr2){};
    virtual double value();
};

#endif /* defined(__ims__DSMultiBlock__) */
