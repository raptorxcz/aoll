//
//  DSOperator2Block.h
//  ims
//
//  Created by Kryštof Matěj on 27.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSOperator2Block__
#define __ims__DSOperator2Block__

#include "DSBlock.h"

class DSOperator2Block : public DSBlock
{
    protected:
    DSBlock *operand1, *operand2;
    
    public:
    explicit DSOperator2Block(DSBlock *opr1, DSBlock *opr2): operand1(opr1), operand2(opr2){};
    ~DSOperator2Block();
    
};

#endif /* defined(__ims__DSOperator2Block__) */
