//
//  DSEquation.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef __ims__DSEquation__
#define __ims__DSEquation__

#include <iostream>
#include "DSBlock.h"

// Blok ktery obsahuje jednu rovnici.
class DSEquation
{
    protected:
    DSBlock *result;
    
public:
    DSEquation(DSBlock *r): result(r){};
    double value (){ return result->value(); };
    // Funkce vraci dany vyraz.
    DSBlock *getResult();
};

#endif /* defined(__ims__DSEquation__) */
