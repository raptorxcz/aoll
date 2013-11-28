//
//  main.cpp
//  ims
//
//  Created by Kryštof Matěj on 15.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DS.h"

int main()
{
    DSParameterBlock op1(5), op2(3), op3(1), op4(4);
    DSEquation y = (-op1 + op2 * op3 ) / op4 - op1;
    std::cout << y.value() << std::endl;
    return 0;
}

