//
//  DSMultiBlock.cpp
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#include "DSMultiBlock.h"

double DSMultiBlock::value()
{
    return operand1->value() * operand2->value();
}
