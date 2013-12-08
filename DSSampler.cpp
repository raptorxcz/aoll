//
//  DSSampler.cpp
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#include "DSSampler.h"
#include <iostream>
#include <cstdlib>

// Vychozi funkce tisku.
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
    runSampler = this;
//    delete assist;
}

DSSampler::~DSSampler()
{
    //delete runSampler;
}

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

DSSampler *runSampler = NULL;
