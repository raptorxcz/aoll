//
//  DSIntegratorBlock.cpp
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSIntegratorBlock.h"



DSIntegratorBlock::DSIntegratorBlock(DSEquation *block)
{
    theBlock = block;
}

double DSIntegratorBlock::value()
{
    return 1;
}


void DSIntegratorBlock::method(IntegratorType inType)
{
    type = inType;
}
