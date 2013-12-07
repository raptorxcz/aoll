#include "DS.h"

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

    Print("%6.2f\t %g\t %g\n", t.value(), e.x1.value(), e.x2.value());
}

DSSampler S(Sample, 0.01);

int main()
{
    setMinMaxStep(1e-8,1e-3);
    setMethod(ADAMB);
    setOutput("Shilnikov_adamb.dat");
    setAccuracy(1e-8,1e-3);
    Init(0, 250);
    Run();
    return 0;
}

