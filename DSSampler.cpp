//
//  DSSampler.cpp
//  ims
//
//  Created by Kryštof Matěj on 29.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DSSampler.h"
#include <iostream>

void rnPrint()
{
    std::cout << "doplnte sampler" << std::endl;
}

DSSampler::DSSampler(void(*f)(), double aStep)
{
    step = aStep;
    function = f;
    runSampler = *this;
};

DSSampler runSampler(rnPrint, 0.01);
