//
//  DSOperator1Block.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSOperator1Block__
#define __ims__DSOperator1Block__

#include <iostream>
#include "DSBlock.h"

// Abstraktni trida pro bloky ktery maji jeden parametr.
class DSOperator1Block: public DSBlock
{
    protected:
    DSBlock *operand1;
    
    public:
    explicit DSOperator1Block(DSBlock *opr1): operand1(opr1){};
};

#endif /* defined(__ims__DSOperator1Block__) */
