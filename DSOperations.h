//
//  DSOperations.h
//  ims
//
//  Created by Kryštof Matěj on 28.11.13.
//  Copyright (c) 2013 Kryštof Matěj. All rights reserved.
//

#ifndef ims_DSOperations_h
#define ims_DSOperations_h
#include <vector>
#include "DSBlock.h"
#include "DSPlusBlock.h"
#include "DSMinusBlock.h"
#include "DSMultiBlock.h"
#include "DSDivideBlock.h"
#include "DSParameterBlock.h"
#include "DSUnaryMinusBlock.h"

std::vector<DSBlock *> toDelete;

//! Scitani
DSEquation operator+(DSBlock &v1, DSBlock &v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = &v2;
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator+(DSEquation v1, DSBlock &v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = &v2;
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator+(DSBlock &v1, DSEquation v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = v2.getResult();
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator+(DSEquation v1, DSEquation v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = v2.getResult();
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator+(double v1, DSBlock &v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = &v2;
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator+(DSEquation v1, double v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = new DSParameterBlock(v2);
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator+(double v1, DSEquation v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = v2.getResult();
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator+(DSBlock &v1, double v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = new DSParameterBlock(v2);
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    return DSEquation(p);
}

//! odcitani
DSEquation operator-(DSBlock &v1, DSBlock &v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = &v2;
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator-(DSEquation v1, DSBlock &v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = &v2;
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator-(DSBlock &v1, DSEquation v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = v2.getResult();
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator-(DSEquation v1, DSEquation v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = v2.getResult();
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator-(double v1, DSBlock &v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = &v2;
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator-(DSEquation v1, double v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = new DSParameterBlock(v2);
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator-(double v1, DSEquation v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = v2.getResult();
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator-(DSBlock &v1, double v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = new DSParameterBlock(v2);
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    return DSEquation(p);
}

//! nasobeni
DSEquation operator*(DSBlock &v1, DSBlock &v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = &v2;
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator*(DSBlock &v1, DSEquation v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = v2.getResult();
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator*(DSEquation v1, DSBlock &v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = &v2;
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator*(DSEquation v1, DSEquation v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = v2.getResult();
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator*(double v1, DSBlock &v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = &v2;
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator*(DSEquation v1, double v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = new DSParameterBlock(v2);
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator*(double v1, DSEquation v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = v2.getResult();
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator*(DSBlock &v1, double v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = new DSParameterBlock(v2);
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    return DSEquation(p);
}

//! deleni
DSEquation operator/(DSBlock &v1, DSBlock &v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = &v2;
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator/(DSBlock &v1, DSEquation v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = v2.getResult();
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator/(DSEquation v1, DSBlock &v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = &v2;
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator/(DSEquation v1, DSEquation v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = v2.getResult();
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator/(double v1, DSBlock &v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = &v2;
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator/(DSEquation v1, double v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = new DSParameterBlock(v2);
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator/(double v1, DSEquation v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = v2.getResult();
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    return DSEquation(p);
}

DSEquation operator/(DSBlock &v1, double v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = new DSParameterBlock(v2);
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    return DSEquation(p);
}

//! unarni minus
DSEquation operator-(DSBlock &v1)
{
    DSBlock *p1 = &v1;
    DSUnaryMinusBlock *p = new DSUnaryMinusBlock(p1);
    return DSEquation(p);
}

DSEquation operator-(DSEquation v1)
{
    DSBlock *p1 = v1.getResult();
    DSUnaryMinusBlock *p = new DSUnaryMinusBlock(p1);
    return DSEquation(p);
}

void deleteAllocs()
{
    for(std::vector<DSBlock *>::iterator it = toDelete.end(); it != toDelete.begin(); ++it)
    {
        delete (*it);
        toDelete.pop_back();
    }
}

#endif
