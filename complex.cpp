#include "complex.h"

TComplex::TComplex()
{
    re = 0;
    im = 0;
}


TComplex::TComplex(int v)
{
    re = v;
    im = 0;
}

TComplex::TComplex(int r, int i)
{
    re = r;
    im = i;
}

TComplex TComplex::operator * (TComplex c) {
    TComplex temp;
    temp.re = re * c.re - im * c.im;
    temp.im = re * c.im + im * c.re;
    return temp;
}

TComplex TComplex::operator / (TComplex c) {
    TComplex temp;
    temp.re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
    temp.im = (im * c.re - re * c.im) / (c.re * c.re + c.im * c.im);
    return temp;
}

TComplex TComplex::operator + (TComplex c) {
    TComplex temp;
    temp.re = re + c.re;
    temp.im = im + c.im;
    return temp;
}

TComplex TComplex::operator - (TComplex c) {
    TComplex temp;
    temp.re = re - c.re;
    temp.im = im - c.im;
    return temp;
}

TComplex TComplex::operator * (int n) {
    return TComplex(re, im) * TComplex(n);
}

TComplex TComplex::operator + (int n) {
    return TComplex(re, im) + TComplex(n);
}

TComplex TComplex::operator - (int n) {
    return TComplex(re, im) - TComplex(n);
}

TComplex sqrt (TComplex& c) {
    double r = sqrt(pow(c.re, 2.) + pow(c.im, 2.));

    double fi = .0;

    if(c.re > 0) {
      fi = atan(c.im / c.re);
    } else if(c.re < 0 && c.im > 0) {
      fi = M_PI + atan(c.im / c.re);
    } else if(c.re < 0 && c.im < 0) {
      fi = -M_PI + atan(c.im / c.re);
    }

    TComplex temp;

    temp.re = cos((fi + 2 * M_PI) / 2);
    temp.im = sin((fi + 2 * M_PI) / 2);

    return temp * TComplex(sqrt(r));
}

std::istream& operator >> (std::istream& is, TComplex& complex) {
    is >> complex.re >> complex.im;
    return is;
}


std::ostream& operator << (std::ostream& os, TComplex& complex) {
    os << "(" << complex.re << " + (" << complex.im << "i))";
    return os;
}

QString& operator << (QString& qs, TComplex& complex) {
    qs += "(";
    qs += QString().setNum(complex.re);
    qs += " + (";
    qs += QString().setNum(complex.im);
    qs += "i))";

    return qs;
}
