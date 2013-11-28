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
#include "DSBlock.h"

class DSIntegratorBlock: public DSBlock
{
    
    
    public:
    virtual double value();
};

#endif /* defined(__ims__DSIntegratorBlock__) */
