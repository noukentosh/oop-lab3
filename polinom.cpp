#include "polinom.h"

TPolinom::TPolinom (number x, number y, number z) {
    a = x;
    b = y;
    c = z;
}

std::ostream& operator << (std::ostream& os, TPolinom& polinom) {
    os << polinom.a
       << "x^2 + ("
       << polinom.b
       << ")x + ("
       << polinom.c
       << ")";

    return os;
}

number TPolinom::value (number x) {
    return (a * x * x) + (b * x) + c;
}

unsigned int TPolinom::roots (number* result) {
    number discriminant = b * b - a * c * 4;

    number sqrt_discriminant = sqrt(discriminant);

    result[0] = ((b * (-1)) - sqrt_discriminant) / (a * 2);
    result[1] = ((b * (-1)) + sqrt_discriminant) / (a * 2);

    return 2;
}

QString& operator << (QString& qs, TPolinom& polinom) {
    qs = "";
    qs << polinom.a;
    qs += "x^2 + ";
    qs << polinom.b;
    qs += "x + ";
    qs << polinom.c;

    return qs;
}
