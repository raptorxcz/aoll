//
//  DSPlusBlock.cpp
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#include "DSPlusBlock.h"

double DSPlusBlock::value()
{
    return operand1->value() + operand2->value();
}
