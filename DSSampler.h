//
//  DSSampler.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSSampler__
#define __ims__DSSampler__

#include <iostream>

// Trida ktera vzorkuje vysledek a vypisuje je na vystup.
class DSSampler
{
public:
    void (*function)();
    double step;
    double time;
    DSSampler(void(*f)(), double aStep = 0.01);
    ~DSSampler();
    double value();
    // Zvisi cas Sampleru.
    void incrementTime();
    
    // Nastavi pocatecni cas.
    void setStartTime(double aTime);
};

extern DSSampler *runSampler;
    
#endif /* defined(__ims__DSSampler__) */
