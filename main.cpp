//
//  main.cpp
//  ims
//
//  Created by Kryštof Matěj on 15.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DS.h"

struct Lorenz {
    DSIntegratorBlock x1;
    DSParameterBlock p1, p2;
    Lorenz(double sigma, double lambda) :
    p1(sigma) , p2(lambda) ,
    x1(p1*(p2 - x1), 1){};           // dx1/dt = sigma * (x2 - x1)


};

Lorenz L(10, 2);

int main()
{
//    DSParameterBlock op1(5), op2(3), op3(1), op4(4);
//    DSEquation y = (-op1 + op2 * op3 ) / op4 - op1;
//    std::cout << y.value() << std::endl;
    std::cout << L.x1.value() << std::endl;
    return 0;
}

