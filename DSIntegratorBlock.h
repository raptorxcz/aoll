//
//  DSIntegratorBlock.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSIntegratorBlock__
#define __ims__DSIntegratorBlock__

#include <iostream>
#include <cmath>
#include "DSBlock.h"
#include "DSEquation.h"

double step;

typedef enum intType
{
    EULER,
    RUNGEKUTT,
    ADAMB
}IntegratorType;

class DSIntegratorBlock: public DSBlock
{
protected:
    IntegratorType type = EULER;
    DSEquation *theBlock;
    double initialValue;
    double finalValue = INFINITY;
    double ABSteps[4] = {INFINITY,INFINITY,INFINITY,INFINITY};

public:
    DSIntegratorBlock(DSEquation *block, double value);
    ~DSIntegratorBlock();


    virtual double value(){return finalValue;}

    void method(IntegratorType inType){type = inType;}
    void Init(double value){initialValue = value;}
    void run();

private:
    void eulerMethod();
    void rungeKuttMethoud();
    void adamBMethoud();
    double initABMethod();
};

#endif /* defined(__ims__DSIntegratorBlock__) */
//komentar pro git
