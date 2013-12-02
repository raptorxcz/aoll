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
#include <cstdio>
#include <iostream>
#include <cstdarg>
#include <fstream>

int count = 1;
std::string output = "";


void setMethod(intType it)
{
    integratorType = it;
}

void Init(double start, double stop)
{
    DSTime oldTime = t;
    t = DSTime(start, stop, fmin(runSampler.step, t.getMaxStep()));
    t.setMinMaxStep(oldTime.getMinStep(), oldTime.getMaxStep());
    runSampler.setStartTime(start);
    
    double step;

    if(runSampler.step <= t.getMaxStep() && runSampler.step >= t.getMinStep())
        step = runSampler.step;
    else if(runSampler.step >= t.getMinStep())
    {
        int steps = runSampler.step / t.getMaxStep() + 1;
        step = runSampler.step / steps;
    }
    else
    {
        fprintf(stderr, "chyba, minimalni krok je vetsi jak krok vypisu\n");
        exit(1);
    }
    
    t.setBaseStep(step);
}

void runSimulation()
{
    for(std::vector<DSIntegratorBlock *>::iterator it = integrators.begin(); it != integrators.end(); ++it)
    {
        (*it)->run();
    }
}

void Run()
{
    std::ofstream ofs;
    ofs.open(output.c_str(), std::ofstream::out);
    ofs.close();
    double newStep;
    double tempTime;
    DSTime tempDSTime = t;
    
    while (t.isCurrentTimeValid())
    {
        if(flagReset)
        {
            for(std::vector<DSIntegratorBlock *>::iterator it = integrators.begin(); it != integrators.end(); ++it)
                (*it)->reset();
        }
        
        runSimulation();
        flagReset = false;
        
        if(t.value() >= runSampler.value())
        {
            tempTime = t.value();
            t.setTime(runSampler.value());
            runSampler.function();
            t.setTime(tempTime);
            runSampler.incrementTime();
        }
        
        if(flagDecrementStep)
        {
            flagDecrementStep = false;
            flagReset = true;
            t = tempDSTime;
            
            if((newStep = t.getStep()/2) < t.getMinStep())
                newStep = t.getMinStep();
                
            t.setStep(newStep);
            count *= 2;
        }
        
        tempDSTime = t;
        t.incrementTime();
    }
    
    
}

void setAccuracy(double rel)
{
    eRel = rel;
    eAbs = 0;
}

void setAccuracy(double abs, double rel)
{
    eAbs = abs;
    eRel = rel;
}

void setMinMaxStep(double min, double max)
{
    t.setMinMaxStep(min, max);
}

int Print(const char *format, ...)
{
    va_list arg;
    int status;
    char string[256];
    
    va_start(arg, format);
    status = vsprintf (string, format, arg);
    va_end(arg);
    
    if(!flagDecrementStep)
    {
        if(!output.empty())
        {
            std::ofstream ofs;
            ofs.open(output.c_str(), std::ofstream::app);
            ofs << string;
            ofs.close();
        }
        else
            std::cout << string;
        
        t.clearStep();
    }
//    else if(!flagDecrementStep)
//        count--;
    
    return status;
}

void setOutput(std::string name)
{
    output = name;
}


#endif
