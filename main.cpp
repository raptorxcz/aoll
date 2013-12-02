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
//
//Lorenz L(10, 24, 2);

//struct Mtd {
//    DSIntegratorBlock y;
//    Mtd(): y(t + 2*y, 0){};
//};
//
//Mtd m;

//struct prepre {
//    DSIntegratorBlock x1, x2, x3;
//    prepre(): x1(x2, 2), x2(x3, 6), x3(x1, 0){};
//};
//
//prepre Z;

class Silnikov {
public:
    DSParameterBlock a,b,c,d;
    DSIntegratorBlock x1, x2, x3;
    Silnikov(double _a, double _b, double _c, double _d) :
    a(_a), b(_b), c(_c), d(_d),
    x1(x2, 0.1234),
    x2(x3, 0.2),
    x3(-a*x3 - x2 + b*x1*(1 - c*x1 - d*x1*x1), 0.1) {}
};

Silnikov e(0.4, 0.65, 0, 1);

void Sample() {
    //    std::cout  <<  t.value() << " " << L.x1.value() << std::endl;
//    Print("%6.2f\t %g\t %g\n", t.value(), L.x1.value(), L.x2.value());
    Print("%6.2f\t %g\t %g\n", t.value(), e.x1.value(), e.x2.value());
//    Print("%6.2f\t %g\t %g\n", t.value(), Z.x1.value(), Z.x2.value());
//        Print("%6.2f\t %12.6f\n", t.value(), m.y.value());
//        Print("%18.6f\n", m.y.value());
    //    fprintf(stdout, "%6.2f %g\n", t.value(), L.x1.value());
}

DSSampler S(Sample, 0.05);

int main()
{
    setMinMaxStep(1e-8,1e-3);
    setMethod(ADAMB);
    setOutput("output.txt");
    setAccuracy(1, 1e-1);
    Init(0, 250);
    Run();
    return 0;
}

