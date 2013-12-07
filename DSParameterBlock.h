//
//  DSParameterBlock.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSParameterBlock__
#define __ims__DSParameterBlock__

#include <iostream>
#include "DSBlock.h"

// Blok ktery vraci jako hodnotu velikost jeho parametru.
class DSParameterBlock : public DSBlock
{
    protected:
    double parameter;
    
    public:
    DSParameterBlock(double value):parameter(value){};
    DSParameterBlock & operator=(const double &);
    void set(double val);
    virtual double value();
};

#endif /* defined(__ims__DSParameterBlock__) */
