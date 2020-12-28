#ifndef TPOLINOM_H
#define TPOLINOM_H

#include <iostream>
#include "number.h"
#include <math.h>
#include <QString>

class TPolinom {
    number a, b, c;
public:
    TPolinom (number, number, number);
    number value (number);
    unsigned int roots (number* result);

    friend std::ostream& operator << (std::ostream&, TPolinom&);
    friend QString& operator << (QString&, TPolinom&);
};

#endif // TPOLINOM_H
