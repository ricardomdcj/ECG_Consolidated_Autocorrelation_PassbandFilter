/*  This is a library to calculate a N sized window Moving Average filter. */

#ifndef MOVINGAVERAGE_FILTER_H
#define MOVINGAVERAGE_FILTER_H

#include "Arduino.h"

class libMovingaverage
{
public:
    libMovingaverage( double* inputData,
                      double* outputData,
                      int     sizeOfData,
                      int     sizeOfWindow,
                      int     print );

    void convolve();

private:
    double* inputData;
    double* outputData;
    int sizeOfData;
    int sizeOfWindow;
    int print;
    int ones_vector;
};

#endif
