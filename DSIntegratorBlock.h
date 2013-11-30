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
#include "DSTime.h"

typedef enum intType
{
    EULER,
    RUNGEKUTT,
    ADAMB
}IntegratorType;


class DSIntegratorBlock : public DSBlock
{
public:
    DSIntegratorBlock(DSEquation block, double value);
    virtual double value();
protected:
    DSBlock *equation;
    double parametr;
    double currTime;
    double ABSteps[4] = {INFINITY,INFINITY,INFINITY,INFINITY};
    
private:
    void run();
    void eulerMethod();
    void rungeKuttMethoud();
    void adamBMethoud();
};

extern intType integratorType;

#endif /* defined(__ims__DSIntegratorBlock__) */
