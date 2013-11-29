//
//  DSIntegratorBlock.cpp
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSIntegratorBlock.h"



DSIntegratorBlock::DSIntegratorBlock(DSEquation *block, double value)
{
    theBlock = block;
    initialValue = value;
}

void DSIntegratorBlock::run()
{
    switch(type)
    {
    case EULER:
        void eulerMethod();
        break;
    case RUNGEKUTT:
        void rungeKuttMethoud();
        break;
    case ADAMB:
        void adamBMethoud();
        break;
    }
}

void DSIntegratorBlock::eulerMethod()
{
    (initialValue == INFINITY) ? (finalValue = initialValue) : (initialValue = initialValue);

    finalValue += step*theBlock(t,finalValue);
}

void DSIntegratorBlock::rungeKuttMethoud()
{
    (initialValue == INFINITY) ? (finalValue = initialValue) : (initialValue = initialValue);

    theBlock->value();
    double k1 = step*theBlock(t,finalValue);
    double k2 = step*theBlock(t + step/2,finalValue + k1 / 2);
    double k3 = step*theBlock(t + step/2,finalValue + k2 / 2);
    double k4 = step*theBlock(t + h, finalValue + k3);

    finalValue += 1/6 *(k1 + 2*k2 + 2*k3 + k4);
}

void DSIntegratorBlock::adamBMethoud()
{
    (initialValue == INFINITY) ? (finalValue = initialValue) : (initialValue = initialValue);

    int initFlag = 0;

    for(int i = 0; i < 3;i++)
    {
        if(ABSteps[i] == INFINITY)
        {
            ABSteps[i] = initABMethod();
            initFlag = 1;
            break;
        }
    }

    if(!initFlag)
    {
        ABSteps[3] = theBlock(t,finalValue);
        finalValue += (step / 24)* (55*ABSteps[3] - 59 * ABSteps[2]  + 37 * ABSteps[1]  - 9 * ABSteps[0]);
        ABSteps[0] = ABSteps[1];
        ABSteps[1] = ABSteps[2];
        ABSteps[2] = ABSteps[3];
    }
}


