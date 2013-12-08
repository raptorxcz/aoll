//
//  main.cpp
//  ims
//
//  Created by xkaisl00, xmatej42.
//
#include "DS.h"

// vypocet Lorenze
struct Lorenz {
    DSIntegratorBlock x1, x2, x3;
    DSParameterBlock p1, p2, p3, p4;
    Lorenz(double sigma, double lambda, double b) :
    p1(sigma), p2(lambda), p3(b), p4(1),
    x1(p1*(x2 - x1), 1),           // dx1/dt = sigma * (x2 - x1)
    x2((p4 + p2 - x3)*x1 - x2, 1), // dx2/dt = (1 + lambda - x3) * x1 - x2
    x3(x1*x2 - p3*x3, 1){}          // dx1/dt = sigma * (x2 - x1)
};

Lorenz L(10, 24, 2);

void Sample() {
    print("%6.2f\t %g\t %g\n", t.value(), L.x1.value(), L.x2.value());
}

DSSampler S(Sample, 0.01);

int main()
{
    setMinMaxStep(1e-8,1e-3);
    setMethod(ADAMB);
    setOutput("pokus.dat");
    setAccuracy(1e-8,1e-3);
    init(0, 250);
    run();
    return 0;
}

