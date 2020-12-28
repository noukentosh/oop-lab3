#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <iostream>
#include <tgmath.h>
#include <QString>

class TComplex
{
    double re, im;
public:
    TComplex();
    TComplex(int v);
    TComplex(int r, int i);

    TComplex operator * (TComplex);
    TComplex operator / (TComplex);
    TComplex operator + (TComplex);
    TComplex operator - (TComplex);

    TComplex operator * (int);
    TComplex operator + (int);
    TComplex operator - (int);

    friend TComplex sqrt (TComplex&);

    friend std::istream& operator >> (std::istream&, TComplex&);
    friend std::ostream& operator << (std::ostream&, TComplex&);
    friend QString& operator << (QString&, TComplex&);
};

#endif // TCOMPLEX_H
