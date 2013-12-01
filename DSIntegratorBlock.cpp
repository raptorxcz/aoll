//
//  DSIntegratorBlock.cpp
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSIntegratorBlock.h"

intType integratorType = EULER;
double eAbs = 0.1;
double eRel = 0.1;
bool flagDecrementStep = false;
bool flagReset = false;

double DSIntegratorBlock::value()
{
    if(flagReset)
    {
        currTime = resetCurrentTime;
        parametr = resetParameter;
        //pri zaplneni
        if(integratorType == ADAMB)
        {
            if(ABSteps[0] != INFINITY && ABSteps[1] != INFINITY && ABSteps[2] != INFINITY && ABSteps[3] != INFINITY)
            {
                ABSteps[3] = ABSteps[2];
                ABSteps[2] = ABSteps[1];
                ABSteps[1] = ABSteps[0];
                ABSteps[0] = resetLastABStep;
            }
            else
            {
                for (int i = 3; i <= 0; i--)
                {
                    if(ABSteps[i] != INFINITY)
                    {
                        ABSteps[i] = resetLastABStep;
                        break;
                    }
                }
            }
        }
    }
    
    if(t.value() <= currTime || lock)
//        return parametr;
        return resetParameter;
    else
    {
        run();
        
        if(!flagDecrementStep)
        {
            resetCurrentTime = currTime;
            resetParameter = parametr;
            resetLastABStep = ABSteps[0];
        }
        
        return parametr;
    }
}

DSIntegratorBlock::DSIntegratorBlock(DSBlock &block, double value)
{
    lock = false;
    ABSteps[0] = INFINITY;
    ABSteps[1] = INFINITY;
    ABSteps[2] = INFINITY;
    ABSteps[3] = INFINITY;
    equation = &block;
    parametr = value;
    currTime = t.value();
    resetCurrentTime = currTime;
    resetParameter = parametr;
    resetLastABStep = INFINITY;
};

DSIntegratorBlock::DSIntegratorBlock(DSEquation block, double value)
{
    lock = false;
    ABSteps[0] = INFINITY;
    ABSteps[1] = INFINITY;
    ABSteps[2] = INFINITY;
    ABSteps[3] = INFINITY;
    equation = block.getResult();
    parametr = value;
    currTime = t.value();
    resetCurrentTime = currTime;
    resetParameter = parametr;
    resetLastABStep = INFINITY;
}

void DSIntegratorBlock::run()
{
    lock = true;
    
    switch(integratorType)
    {
    case EULER:
        eulerMethod();
        break;
    case RUNGEKUTT:
        rungeKuttMethod();
        break;
    case ADAMB:
        adamBMethod();
        break;
    }
    
    lock = false;
}

void DSIntegratorBlock::eulerMethod()
{
    double increment = t.getStep()*equation->value();
    
    if(!(fabs(increment) <= eAbs || parametr*eRel >= fabs(increment)))
        flagDecrementStep = true;
    
    parametr += increment;
    currTime = t.value();
}

void DSIntegratorBlock::rungeKuttMethod()
{
    double increment;
    double assist = parametr;
    double backupResetPar = resetParameter;
    currTime = t.value() - t.getStep();
    t.setTime(currTime);
    double k1 = t.getStep()*equation->value();

    currTime = t.value() + t.getStep() / 2;
    t.setTime(currTime);
    resetParameter = assist + k1/2;
    double k2 = t.getStep() *equation->value();

    resetParameter = assist + k2/2;
    double k3 = t.getStep() *equation->value();

    t.setTime(currTime + t.getStep()/2);
    currTime =t.value();
    resetParameter = assist + k3;
    double k4 = t.getStep() *equation->value();

    increment = (k1 + 2*k2 + 2*k3 + k4) / 6;
    
//    if(!(fabs(increment) <= eAbs || 1-eRel < fabs(parametr)/fabs(parametr+increment)))
//        flagDecrementStep = true;
    
    parametr += increment;
    currTime = t.value();
    resetParameter = backupResetPar;
}

void DSIntegratorBlock::adamBMethod()
{
    int initFlag = 0;

    for(int i = 0; i < 4;i++)
    {
        if(ABSteps[i] == INFINITY)
        {
            double assist = parametr;
            eulerMethod();
            ABSteps[i] = parametr - assist;
            currTime = t.value();
            initFlag = 1;
            break;
        }
    }

    if(!initFlag)
    {
        
        ABSteps[0] = ABSteps[1];
        ABSteps[1] = ABSteps[2];
        ABSteps[2] = ABSteps[3];
        ABSteps[3] = equation->value();
        parametr += (t.getStep() / 24)* (55*ABSteps[3] - 59 * ABSteps[2]  + 37 * ABSteps[1]  - 9 * ABSteps[0]);
        currTime = t.value();
    }
}


