//
//  DSPlusBlock.cpp
//  ims
//
//  Created by Kryštof Matěj on 27.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSPlusBlock.h"

double DSPlusBlock::value()
{
    return operand1->value() + operand2->value();
}
