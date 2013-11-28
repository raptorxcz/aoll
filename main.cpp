//
//  main.cpp
//  ims
//
//  Created by Kryštof Matěj on 15.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#include "DS.h"
/*
const double F = 1.0;

class Integrator;
class Graph;
class Input;
class Kolo {
  //  Graph G;              // výstup polohy kola
    //Integrator v,y;       // stav systému kola
public:
    Kolo(Input F, double M, double D, double k);//:
//    G("Výchylka", y, 0.01){}//,
    //v((F-D*v-k*y)/M),
    //y(v) {}
};

Kolo k1(F, 2, 5.656, 400);

int main() {                  // popis experimentu
    Print(" Model tlumení kola automobilu v C++ \n");
    OpenOutputFile("kolo.out");
    Init(0,1.5);                // inicializace parametrů experimentu
    SetStep(1e-3,0.1);          // krok integrace
    SetAccuracy(0.001);         // max. povolená rel. chyba integrace
    Run();                      // simulace
    Print(" Konec simulace \n");
    return 0;
}
*/

int main()
{
    DSParameterBlock op1(5), op2(3);
    DSExpressionBlock x = op1 + op2;
    std::cout << x.value() << std::endl;
    
    return 0;
}
/*
#include <iostream>

class A {
public:
    virtual void print_me(void) {
        std::cout << "I'm A" << std::endl;
    }
    
    virtual ~A() {}
};

class B : public A {
public:
    virtual void print_me(void) {
        std::cout << "I'm B" << std::endl;
    }
};

class C : public A {
};

int main() {
    
    A a;
    B b;
    C c;
    
    A p = a+b;
    p.print_me();
    
    p = b;
    p.print_me();
    
    p = c;
    p.print_me();
    
    return 0;
}

*/
