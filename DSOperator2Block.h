//
//  DSOperator2Block.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSOperator2Block__
#define __ims__DSOperator2Block__

#include "DSBlock.h"

// Abstraktni trida pro bloky ktery maji dva parametr.
class DSOperator2Block : public DSBlock
{
    protected:
    DSBlock *operand1, *operand2;
    
    public:
    explicit DSOperator2Block(DSBlock *opr1, DSBlock *opr2): operand1(opr1), operand2(opr2){};
    
};

#endif /* defined(__ims__DSOperator2Block__) */
