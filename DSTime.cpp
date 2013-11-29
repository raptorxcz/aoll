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

bool DSTime::isCurrentTimeValid()
{
    return currentTime <= endTime;
}

bool DSTime::incrementTime()
{
    currentTime += step;
    return currentTime <= endTime;
}

DSTime t(0, 1, 0.01);