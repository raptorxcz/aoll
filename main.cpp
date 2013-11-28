//
//  main.cpp
//  ims
//
//  Created by Kryštof Matěj on 15.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DS.h"

//#include "simlib/src/simlib.h"
//
//const double F = 1.0;
//
//class Kolo {
////    Graph G;              // výstup polohy kola
//    Integrator v,y;       // stav systému kola
//public:
//    Kolo(Input F, double M, double D, double k):
////    G("Výchylka", y, 0.01){},
//    v((F-D*v-k*y)/M),
//    y(v) {}
//};
//
//Kolo k1(F, 2, 5.656, 400);
//
//int main() {                  // popis experimentu
//    Print(" Model tlumení kola automobilu v C++ \n");
////    OpenOutputFile("kolo.out");
//    Init(0,1.5);                // inicializace parametrů experimentu
//    SetStep(1e-3,0.1);          // krok integrace
//    SetAccuracy(0.001);         // max. povolená rel. chyba integrace
//    Run();                      // simulace
//    Print(" Konec simulace \n");
//    return 0;
//}


int main()
{
    DSParameterBlock op1(5), op2(3), op3(1);
    DSEquation y = -op1 + op2 * op3;
    std::cout << y.value() << std::endl;
    return 0;
}

