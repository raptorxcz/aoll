//
//  DSDivideBlock.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSDivideBlock__
#define __ims__DSDivideBlock__

#include <iostream>
#include "DSOperator2Block.h"

// Trida deleno. Jako hodnotu podil soucet hodnot vyrazu.
class DSDivideBlock : public DSOperator2Block
{
public:
    explicit DSDivideBlock(DSBlock *opr1, DSBlock *opr2): DSOperator2Block(opr1, opr2){};
    virtual double value();
};
#endif /* defined(__ims__DSDivideBlock__) */
