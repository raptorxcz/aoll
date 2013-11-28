//
//  DSParameterBlock.cpp
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
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
