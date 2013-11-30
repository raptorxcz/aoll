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
    return running;
}

bool DSTime::incrementTime()
{
    double newTime = 0;
    if(running)
    {
        if(baseTime < endTime && (newTime = baseTime + step) <= endTime)
        {
            baseTime = newTime;
            currentTime = baseTime;
        }
        else if(baseTime < endTime)
        {
            baseTime = endTime;
            currentTime = baseTime;
        }
        else
            running = false;
    }
    
    return running;
}

void DSTime::clear()
{
    currentTime = baseTime;
}

void DSTime::setTime(double time)
{
    currentTime = time;
}

DSTime t(0, 1, 0.01);