//
//  DSFunctions.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef ims_DSFunctions_h
#define ims_DSFunctions_h
#include "DSTime.h"
#include "DSIntegratorBlock.h"

void setMethod(intType it)
{
    integratorType = it;
}

void Init(double start, double stop)
{
    t = DSTime(start, stop, runSampler.step);
}

void Run()
{
    while (t.isCurrentTimeValid())
    {
        runSampler.function();
        t.incrementTime();
    }
}



#endif
