//
//  DSTime.h
//  ims
//
//  Created by Kryštof Matěj on 29.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSTime__
#define __ims__DSTime__

#include <iostream>
#include "DSBlock.h"

class DSTime : public DSBlock
{
    double currentTime;
    double baseTime;
    double startTime;
    double endTime;
    double step;
    double running;
    
public:
    DSTime(double aStartTime, double anEndTime, double aStep):
    startTime(aStartTime), endTime(anEndTime), step(aStep)
    {
        running = true;
        currentTime = startTime;
        baseTime = startTime;
    }
    bool incrementTime();
    bool isCurrentTimeValid();
    virtual double value();
    double getStep();
    void setTime(double time);
};

extern DSTime t;

#endif /* defined(__ims__DSTime__) */
