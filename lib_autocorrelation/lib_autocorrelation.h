#ifndef lib_autocorrelation_h
#define lib_autocorrelation_h

#include <stdio.h>
#include <stdlib.h>
#include <Arduino.h>

class libAutocorrelation
{
public:
    libAutocorrelation(double* data, double* features, double* ndata, int lag, int sizeOfData, int print);

    void calcMean();
    void calcVar();
    void norm();
    void atc();

private:
    double* data;
    double* features;
    double* ndata;
    int lag;
    int sizeOfData;
    int print;
    float mean, var;
};

#endif