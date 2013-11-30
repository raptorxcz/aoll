//
//  main.cpp
//  ims
//
//  Created by Kryštof Matěj on 15.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DS.h"
#include <cstdio>

//struct Lorenz {
//    DSIntegratorBlock x1, x2, x3;
//    DSParameterBlock p1, p2, p3, p4;
//    Lorenz(double sigma, double lambda, double b) :
//    p1(sigma), p2(lambda), p3(b), p4(1),
//    x1(p1*(x2 - x1), 1),           // dx1/dt = sigma * (x2 - x1)
//    x2((p4 + p2 - x3)*x1 - x2, 1), // dx2/dt = (1 + lambda - x3) * x1 - x2
//    x3(x1*x2 - p3*x3, 1){}          // dx1/dt = sigma * (x2 - x1)
//};

//Lorenz L(10, 24, 2);

//struct Mtd {
//    DSIntegratorBlock y;
//    Mtd(): y(t + 2*y, 0){};
//};
//
//Mtd m;

struct prepre {
    DSIntegratorBlock x1, x2;
    prepre(): x1(x2, 2), x2(x1, 6){};
};

prepre L;

void Sample() {
    //    std::cout  <<  t.value() << " " << L.x1.value() << std::endl;
    //    printf("%6.2f\t %g\t %g\n", t.value(), L.x1.value(), L.x2.value());
    Print("%6.2f\t %g\t %g\n", t.value(), L.x1.value(), L.x2.value());
    //        printf("%6.2f\t %12.6f\n", t.value(), m.y.value());
    //    fprintf(stdout, "%6.2f %g\n", t.value(), L.x1.value());
}

DSSampler S(Sample, 1);

int main()
{
    setMethod(EULER);
//    DSParameterBlock op1(5), op2(3), op3(1), op4(4);
//    DSEquation y = (-op1 + op2 * op3 ) / op4 - op1;
//    std::cout << y.value() << std::endl;
    Init(0, 2);
    Run();
    return 0;
}

