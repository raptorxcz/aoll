//
//  DSFunctions.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef ims_DSFunctions_h
#define ims_DSFunctions_h
#include "DSTime.h"
#include "DSIntegratorBlock.h"
#include <cstdio>
#include <iostream>
#include <cstdarg>
#include <fstream>
#include <cstdlib>

std::string output = "";

// Nastaveni typu integratoru.
void setMethod(intType it)
{
    integratorType = it;
}

// Inicializace casu vypoctu od do.
void init(double start, double stop)
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
        fprintf(stderr, "chyba, minimalni krok je vetsi nez krok vypisu\n");
        exit(1);
    }
    
    t.setBaseStep(step);
}

// Provedeni jednoho kroku simulace.
void runSimulation()
{
    for(std::vector<DSIntegratorBlock *>::iterator it = integrators.begin(); it != integrators.end(); ++it)
    {
        (*it)->run();
    }
}

// Provedeni simulace.
void run()
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
        }
        
        tempDSTime = t;
        t.incrementTime();
    }
    
    
}

// Nastaveni presnosti pouze relativni hodnotou.
void setAccuracy(double rel)
{
    eRel = rel;
    eAbs = 0;
}

// Nastaveni presnosti relativne i absolutne.
void setAccuracy(double abs, double rel)
{
    eAbs = abs;
    eRel = rel;
}

// Nastaveni minimalniho a maximalniho kroku vypoctu.
void setMinMaxStep(double min, double max)
{
    t.setMinMaxStep(min, max);
}

// Vytisknuti hodnot z bloku.
int print(const char *format, ...)
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
    
    return status;
}

// Nastaveni vystupu do souboru
void setOutput(std::string name)
{
    output = name;
}


#endif
