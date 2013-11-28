//
//  DSExpressionBlock.cpp
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSExpressionBlock.h"

double DSExpressionBlock::value()
{
    return operand1->value();
}
