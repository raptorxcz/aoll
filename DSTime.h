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
    double baseStep;
    double running;
    double minStep;
    double maxStep;
    
public:
    DSTime(double aStartTime, double anEndTime, double aStep):
    startTime(aStartTime), endTime(anEndTime), step(aStep), baseStep(step)
    {
        if(anEndTime <= aStartTime)
            running = false;
        else
            running = true;
        
        currentTime = startTime;
        baseTime = startTime;
    }
    bool incrementTime();
    void clear();
    bool isCurrentTimeValid();
    virtual double value();
    double getStep();
    void setTime(double time);
    void setStep(double aStep);
    void clearStep();
    double getMinStep(){ return minStep; }
    double getMaxStep(){ return maxStep; }
    void setMinMaxStep(double min, double max){
        minStep = min;
        maxStep = max;
    }
};

extern DSTime t;

#endif /* defined(__ims__DSTime__) */
