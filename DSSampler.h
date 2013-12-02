//
//  DSSampler.h
//  ims
//
//  Created by Kryštof Matěj on 29.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSSampler__
#define __ims__DSSampler__

#include <iostream>

class DSSampler
{
public:
    void (*function)();
    double step;
    double time;
    DSSampler(void(*f)(), double aStep = 0.01);
    double value();
    void incrementTime();
    void setStartTime(double aTime);
};

extern DSSampler runSampler;
    
#endif /* defined(__ims__DSSampler__) */
