//
//  DSTime.cpp
//  ims
//
//  Created by Kryštof Matěj on 29.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSTime.h"

double DSTime::value()
{
    return currentTime;
}

double DSTime::getStep()
{
    return step;
}

DSTime t(0, 1, 0.01);