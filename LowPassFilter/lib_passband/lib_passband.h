/* This is a library created to execute a 4th order passband filtering
calculus through a N sized vector of data */

#ifndef PASSBAND_FILTER_H
#define PASSBAND_FILTER_H

#include <cmath>

class libPassband
{
public:
    libPassband(double* input, double* output, int sizeOfData);

    auxiliaryParameters();
    void passbandFilter();

private:
    double* input;
    double* output;
    double x0, x1, x2, x3;
    double y0, y1, y2, y3;
    int sizeOfData;
};

#endif