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
    t = DSTime(start, stop, runSampler.step);
}

void Run()
{
    std::ofstream ofs;
    ofs.open(output.c_str(), std::ofstream::out);
    ofs.close();
    double newStep;
    
    while (t.isCurrentTimeValid())
    {
        runSampler.function();
        flagReset = false;
        
        if(flagDecrementStep)
        {
            flagDecrementStep = false;
            flagReset = true;
            t.stepBack();
            
            if((newStep = t.getStep()/2) < t.getMinStep())
                newStep = t.getMinStep();
                
            t.setStep(newStep);
            count *= 2;
        }
    
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
    
    if(!flagDecrementStep && count == 1)
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
    else if(!flagDecrementStep)
        count--;
    
    return status;
}

void setOutput(std::string name)
{
    output = name;
}


#endif
