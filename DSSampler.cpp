//
//  DSSampler.cpp
//  ims
//
//  Created by Kryštof Matěj on 29.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSSampler.h"
#include <iostream>
#include <cstdlib>

void rnPrint()
{
    std::cout << "doplnte sampler" << std::endl;
    exit(1);
}

DSSampler::DSSampler(void(*f)(), double aStep)
{
    step = aStep;
    time = 0;
    function = f;
    runSampler = *this;
};

double DSSampler::value()
{
    return time;
}

void DSSampler::incrementTime()
{
    time += step;
}

void DSSampler::setStartTime(double aTime)
{
    time = aTime;
}

DSSampler runSampler(rnPrint, 0.01);
