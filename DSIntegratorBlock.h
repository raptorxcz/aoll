//
//  DSIntegratorBlock.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSIntegratorBlock__
#define __ims__DSIntegratorBlock__

#include <iostream>
#include <cmath>
#include "DSBlock.h"
#include "DSEquation.h"
#include "DSTime.h"
#include <vector>

// Vycet typu integracnich metod.
typedef enum intType
{
    EULER,
    RUNGEKUTT,
    ADAMB
}IntegratorType;

// Objekt integratoru
class DSIntegratorBlock : public DSBlock
{
public:
    DSIntegratorBlock(DSEquation block, double value = 0);
    DSIntegratorBlock(DSBlock &block, double value = 0);
    ~DSIntegratorBlock();
    
    // Vraci posledni vypoctenou hodnotu.
    virtual double value();
    
    // Vyhodnoti integrator
    void run();
    
    // Vraci integrator do predchoziho stavu.
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
    // Vypocet eulera.
    double eulerMethod();
    // Vypocet RungeKutta.
    double rungeKuttMethod();
    // Vypocet AdamB.
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
