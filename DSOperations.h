//
//  DSOperations.h
//  ims
//
//  Created by xkaisl00, xmatej42.
//

#ifndef ims_DSOperations_h
#define ims_DSOperations_h

// Soubor s pretizenymi operacemi mezi DSBlock, double a DSEquation

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
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator+(DSBlock &v1, DSEquation v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = v2.getResult();
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator+(DSEquation v1, DSEquation v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = v2.getResult();
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator+(double v1, DSBlock &v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = &v2;
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p1);
    return DSEquation(p);
}

DSEquation operator+(DSEquation v1, double v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = new DSParameterBlock(v2);
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p2);
    return DSEquation(p);
}

DSEquation operator+(double v1, DSEquation v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = v2.getResult();
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p1);
    return DSEquation(p);
}

DSEquation operator+(DSBlock &v1, double v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = new DSParameterBlock(v2);
    DSPlusBlock *p = new DSPlusBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p2);
    return DSEquation(p);
}

//! odcitani
DSEquation operator-(DSBlock &v1, DSBlock &v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = &v2;
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator-(DSEquation v1, DSBlock &v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = &v2;
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator-(DSBlock &v1, DSEquation v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = v2.getResult();
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator-(DSEquation v1, DSEquation v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = v2.getResult();
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator-(double v1, DSBlock &v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = &v2;
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p1);
    return DSEquation(p);
}

DSEquation operator-(DSEquation v1, double v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = new DSParameterBlock(v2);
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p2);
    return DSEquation(p);
}

DSEquation operator-(double v1, DSEquation v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = v2.getResult();
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p1);
    return DSEquation(p);
}

DSEquation operator-(DSBlock &v1, double v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = new DSParameterBlock(v2);
    DSMinusBlock *p = new DSMinusBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p2);
    return DSEquation(p);
}

//! nasobeni
DSEquation operator*(DSBlock &v1, DSBlock &v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = &v2;
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator*(DSBlock &v1, DSEquation v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = v2.getResult();
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator*(DSEquation v1, DSBlock &v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = &v2;
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator*(DSEquation v1, DSEquation v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = v2.getResult();
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator*(double v1, DSBlock &v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = &v2;
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p1);
    return DSEquation(p);
}

DSEquation operator*(DSEquation v1, double v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = new DSParameterBlock(v2);
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p2);
    return DSEquation(p);
}

DSEquation operator*(double v1, DSEquation v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = v2.getResult();
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p1);
    return DSEquation(p);
}

DSEquation operator*(DSBlock &v1, double v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = new DSParameterBlock(v2);
    DSMultiBlock *p = new DSMultiBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p2);
    return DSEquation(p);
}

//! deleni
DSEquation operator/(DSBlock &v1, DSBlock &v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = &v2;
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator/(DSBlock &v1, DSEquation v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = v2.getResult();
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator/(DSEquation v1, DSBlock &v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = &v2;
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator/(DSEquation v1, DSEquation v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = v2.getResult();
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator/(double v1, DSBlock &v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = &v2;
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    toDelete.push_back(p);
    toDelete.push_back(p1);
    return DSEquation(p);
}

DSEquation operator/(DSEquation v1, double v2)
{
    DSBlock *p1 = v1.getResult();
    DSBlock *p2 = new DSParameterBlock(v2);
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    toDelete.push_back(p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator/(double v1, DSEquation v2)
{
    DSBlock *p1 = new DSParameterBlock(v1);
    DSBlock *p2 = v2.getResult();
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    toDelete.push_back(p1);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator/(DSBlock &v1, double v2)
{
    DSBlock *p1 = &v1;
    DSBlock *p2 = new DSParameterBlock(v2);
    DSDivideBlock *p = new DSDivideBlock(p1, p2);
    toDelete.push_back(p2);
    toDelete.push_back(p);
    return DSEquation(p);
}

//! unarni minus
DSEquation operator-(DSBlock &v1)
{
    DSBlock *p1 = &v1;
    DSUnaryMinusBlock *p = new DSUnaryMinusBlock(p1);
    toDelete.push_back(p);
    return DSEquation(p);
}

DSEquation operator-(DSEquation v1)
{
    DSBlock *p1 = v1.getResult();
    DSUnaryMinusBlock *p = new DSUnaryMinusBlock(p1);
    toDelete.push_back(p);
    return DSEquation(p);
}

#endif
