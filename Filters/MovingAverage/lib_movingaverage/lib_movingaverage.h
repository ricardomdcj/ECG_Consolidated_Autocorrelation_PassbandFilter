/*  This is a library to calculate a N sized window Moving Average filter. */

#ifndef MOVINGAVERAGE_FILTER_H
#define MOVINGAVERAGE_FILTER_H

#include "Arduino.h"

class libMovingaverage
{
public:
    libMovingaverage( double* inputData,
                      double* outputData,
                      int     sizeOfWindow,
                      int     sizeOfData,
                      int     print );

    void movingAverageFilter();

private:
    double* inputData;
    double* outputData;
    int sizeOfData;
    int sizeOfWindow;
    int print;
    double sum;
};

#endif