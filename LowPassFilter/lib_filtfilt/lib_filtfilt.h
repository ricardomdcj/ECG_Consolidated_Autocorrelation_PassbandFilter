/* This is a library created to execute a 3rd order passband filtering
calculus through a N sized vector of data */

#ifndef PASSBAND_FILTER_H
#define PASSBAND_FILTER_H

#include <cmath>
#include <Arduino.h>

class libFiltfilt
{
public:
    libFiltfilt(double *x,
                double *y,
                int sizeOfData,
                int print);

    ~libFiltfilt();

    void filtfilt();

private:
    double *tmp1;
    double *tmp2;
    double *b;
    double *a;
    double *x;
    double *y;
    int filtOrder;
    int sizeOfData;
    int print;
};

#endif