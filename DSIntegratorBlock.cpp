//
//  DSIntegratorBlock.cpp
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSIntegratorBlock.h"


double DSIntegratorBlock::value()
{
    if(t.value() == currTime)
    {
        return parametr;
    }
    else
    {
        run();
        return parametr;
    }
}



DSIntegratorBlock::DSIntegratorBlock(DSEquation block, double value)
{
    equation = block.getResult();
    parametr = value;
    currTime = t.value();
}

void DSIntegratorBlock::run()
{
    switch(type)
    {
    case EULER:
        eulerMethod();
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
    parametr += t.getStep()*equation->value();
    currTime = t.value();
}

void DSIntegratorBlock::rungeKuttMethoud()
{
    double assist = parametr;
    double k1 = t.getStep()*equation->value();

    currTime = t.value() - t.getStep() / 2;
    t.setTime(currTime);
    parametr = assist + k1/2;
    double k2 = t.getStep() *equation->value();

    parametr = assist + k2/2;
    double k3 = t.getStep() *equation->value();

    t.setTime(currTime + t.getStep()/2);
    currTime =t.value();
    parametr = assist + k3;
    double k4 = t.getStep() *equation->value();

    parametr += 1/6 *(k1 + 2*k2 + 2*k3 + k4);
}


//void DSIntegratorBlock::adamBMethoud()
//{
//    (initialValue == INFINITY) ? (finalValue = initialValue) : (initialValue = initialValue);
//
//    int initFlag = 0;
//
//    for(int i = 0; i < 3;i++)
//    {
//        if(ABSteps[i] == INFINITY)
//        {
//            ABSteps[i] = initABMethod();
//            initFlag = 1;
//            break;
//        }
//    }
//
//    if(!initFlag)
//    {
//        ABSteps[3] = theBlock(t,finalValue);
//        finalValue += (step / 24)* (55*ABSteps[3] - 59 * ABSteps[2]  + 37 * ABSteps[1]  - 9 * ABSteps[0]);
//        ABSteps[0] = ABSteps[1];
//        ABSteps[1] = ABSteps[2];
//        ABSteps[2] = ABSteps[3];
//    }
//}
//

