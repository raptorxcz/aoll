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

    #include "DSOperator2Block.h"
        #include "DSPlusBlock.h"


DSExpressionBlock operator+(DSBlock &v1, DSBlock &v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = &v2;
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    return DSExpressionBlock(p);
}

#endif
