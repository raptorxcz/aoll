//
//  SDBlock.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__SDBlock__
#define __ims__SDBlock__

#include <iostream>
#include <vector>

// Abstraktni trida pro bloky.
class DSBlock
{
    public:
    // Funkce ktera vraci hodnotu vyrazu.
    virtual double value();
};

extern std::vector<DSBlock *> toDelete;

#endif /* defined(__ims__SDBlock__) */
