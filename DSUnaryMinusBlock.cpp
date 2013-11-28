//
//  DSUnaryMinusBlock.cpp
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSUnaryMinusBlock.h"

double DSUnaryMinusBlock::value()
{
    return -operand1->value();
}
