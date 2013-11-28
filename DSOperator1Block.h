//
//  DSOperator1Block.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSOperator1Block__
#define __ims__DSOperator1Block__

#include <iostream>
#include "DSBlock.h"

class DSOperator1Block: public DSBlock
{
    protected:
    DSBlock *operand1;
    
    public:
    explicit DSOperator1Block(DSBlock *opr1): operand1(opr1){};
};

#endif /* defined(__ims__DSOperator1Block__) */
