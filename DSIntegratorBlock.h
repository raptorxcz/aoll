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
#include <vector>
#include "DSOperations.h"

typedef enum intType
{
    EULER,
    RUNGEKUTT,
    ADAMB
}IntegratorType;


class DSIntegratorBlock : public DSBlock
{
public:
    DSIntegratorBlock(DSEquation block, double value = 0);
    DSIntegratorBlock(DSBlock &block, double value = 0);
    ~DSIntegratorBlock();
    virtual double value();
    void run();
    void reset();
protected:
    DSBlock *equation;
    double parametr;
    double currTime;
    double ABSteps[4];
    double resetParameter;
    double resetCurrentTime;
    double resetLastABStep;
    
private:
    
    double eulerMethod();
    double rungeKuttMethod();
    double adamBMethod();
    void registerIntegrator();
};

extern intType integratorType;
extern double eAbs;
extern double eRel;
extern bool flagDecrementStep;
extern bool flagReset;
extern std::vector<DSIntegratorBlock *> integrators;
#endif /* defined(__ims__DSIntegratorBlock__) */
