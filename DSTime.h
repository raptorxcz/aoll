//
//  DSTime.h
//  ims
//
//  Created by Kryštof Matěj on 29.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef __ims__DSTime__
#define __ims__DSTime__

#include <iostream>
#include "DSBlock.h"

class DSTime : public DSBlock
{
    double minStep;
    double maxStep;
    double currentTime;
    double minTime;
    double maxTime;
    
public:
    virtual double value();
};

#endif /* defined(__ims__DSTime__) */
