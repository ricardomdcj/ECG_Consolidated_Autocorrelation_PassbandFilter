/* This is a library created to execute a 3rd order passband filtering
calculus through a N sized vector of data */

#ifndef PASSBAND_FILTER_H
#define PASSBAND_FILTER_H

#include <cmath>
#include "Arduino.h"

class libPassband
{
public:
    libPassband(double* input, double* output, int sizeOfData, int print);

    void auxiliaryParameters();
    void passbandFilter();

private:
    double* input;
    double* output;
    double x0, x1, x2, x3;
    double y0, y1, y2, y3;
    int sizeOfData;
    int print;
};

#endif