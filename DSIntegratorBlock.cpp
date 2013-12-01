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
std::vector<DSIntegratorBlock *> integrators;

void DSIntegratorBlock::reset()
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
            for (int i = 3; i >= 0; i--)
            {
                if(ABSteps[i] != INFINITY)
                {
                    ABSteps[i] = INFINITY;
                    break;
                }
            }
        }
    }
}

double DSIntegratorBlock::value()
{
    return parametr;
}

void DSIntegratorBlock::registerIntegrator()
{
    bool add = true;
    
    for(std::vector<DSIntegratorBlock *>::iterator it = integrators.begin(); it != integrators.end(); ++it)
    {
        if((*it)->equation == this->equation && (*it)->parametr == this->parametr)
            add = false;
    }
    
    if(add)
        integrators.push_back(this);
}

DSIntegratorBlock::DSIntegratorBlock(DSBlock &block, double value)
{
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
    registerIntegrator();
};

DSIntegratorBlock::DSIntegratorBlock(DSEquation block, double value)
{
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
    registerIntegrator();
}

void DSIntegratorBlock::run()
{
    double r = 0;
    
    switch(integratorType)
    {
    case EULER:
        r = eulerMethod();
        break;
    case RUNGEKUTT:
        r = rungeKuttMethod();
        break;
    case ADAMB:
        r = adamBMethod();
        break;
    }
    
    if(!flagDecrementStep)
    {
        resetCurrentTime = currTime;
        resetParameter = parametr;
        resetLastABStep = ABSteps[0];
    }
}

double DSIntegratorBlock::eulerMethod()
{
    double increment = t.getStep()*equation->value();
    
    if(!(fabs(increment) <= eAbs || parametr*eRel >= fabs(increment)))
        flagDecrementStep = true;
    
    parametr += increment;
    currTime += t.getStep();
    return parametr;
}

double DSIntegratorBlock::rungeKuttMethod()
{
// !!!!!!!!!!!!!!!!!!!
// BLBOST NUTNOST ZAVOLAT runSimulator po zmene kroku !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//    NEBO SU UPLNE MIMO A FUNGUJE TO NECHAPU
//    OTAZKA ZDA SE MAJI ZMENIT I OSTATNI INTEGRATORY DO STAVU T+H/2 POKUD NE TAK JE TO OK
//    !!!!!!!!!!!!!!!!!!!!!!!!z
    
    double assist = parametr;
    double k1 = t.getStep()*equation->value();

    currTime += t.getStep()/2;
    t.setTime(currTime);
    parametr = assist + k1 /2;
    double k2 = t.getStep()*equation->value();

    parametr = assist + k2 /2;
    double k3 = t.getStep()*equation->value();

    currTime += t.getStep()/2;
    t.setTime(currTime);

    parametr = assist + k3;
    double k4 = t.getStep()*equation->value();

    double increment = (k1 + 2*k2 + 2*k3 + k4) / 6;

    if(!(fabs(increment) <= eAbs || parametr*eRel >= fabs(increment)))
        flagDecrementStep = true;

    parametr = assist;
    parametr += increment;
    return parametr;
}

double DSIntegratorBlock::adamBMethod()
{
    double increment;
    int initFlag = 0;
    
    if(ABSteps[3] == INFINITY)
        for(int i = 0; i < 4;i++)
        {
            if(ABSteps[i] == INFINITY)
            {
                double assist = parametr;
                parametr = rungeKuttMethod();
                ABSteps[i] = parametr - assist;
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
        increment = (t.getStep() / 24)* (55*ABSteps[3] - 59 * ABSteps[2]  + 37 * ABSteps[1]  - 9 * ABSteps[0]);
        
        if(!(fabs(increment) <= eAbs || 1-eRel < fabs(parametr)/fabs(parametr+increment)))
            flagDecrementStep = true;
        
        currTime += t.getStep();
        parametr += increment;
    }
    
    return parametr;
}


