//
//  DS.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef ims_DS_h
#define ims_DS_h

#include "DSBlock.h"
    #include "DSExpressionBlock.h"
    #include "DSParameterBlock.h"
    #include "DSIntegratorBlock.h"
    #include "DSConstantBlock.h"

    #include "DSOperator1Block.h"
        #include "DSUnaryMinusBlock.h"

    #include "DSOperator2Block.h"
        #include "DSPlusBlock.h"
        #include "DSMinusBlock.h"
        #include "DSMultiBlock.h"
        #include "DSDivideBlock.h"

DSExpressionBlock operator+(DSBlock &v1, DSBlock &v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = &v2;
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    return DSExpressionBlock(p);
}

DSExpressionBlock operator+(DSExpressionBlock &v1, DSBlock &v2)
{
    return DSExpressionBlock(v1);
}

DSExpressionBlock operator-(DSBlock &v1)
{
    DSBlock *p1 = &v1;
    DSUnaryMinusBlock *p = new DSUnaryMinusBlock(p1);
    return DSExpressionBlock(p);
}

#endif
