//
//  DSOperator2Block.cpp
//  ims
//
//  Created by Kryštof Matěj on 27.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSOperator2Block.h"

DSOperator2Block::~DSOperator2Block()
{
    delete operand1;
    delete operand2;
}
