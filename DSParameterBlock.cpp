//
//  DSParameterBlock.cpp
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#include "DSParameterBlock.h"

void DSParameterBlock::set(double value)
{
    parameter = value;
}

double DSParameterBlock::value()
{
    return parameter;
}


DSParameterBlock & DSParameterBlock::operator=(const double &x)
{
    set(x);
    return *this;
}

