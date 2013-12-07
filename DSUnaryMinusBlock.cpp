//
//  DSUnaryMinusBlock.cpp
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#include "DSUnaryMinusBlock.h"

double DSUnaryMinusBlock::value()
{
    return -operand1->value();
}
