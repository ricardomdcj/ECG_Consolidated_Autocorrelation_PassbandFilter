#include "lib_autocorrelation.h"

libAutocorrelation::libAutocorrelation(double* data, double* features, double* ndata, int lag, int sizeOfData, int print)
    : data(data), features(features), ndata(ndata), lag(lag), sizeOfData(sizeOfData), print(print) {}

void libAutocorrelation::calcMean()
{
    mean = 0;

    for (int i = 0; i < sizeOfData; i++)
    {
        mean += data[i];
    }
    mean = mean / sizeOfData;

    if (print == 1)
    {
        Serial.print("mean = ");
        Serial.println(mean, 8);
    }
}

void libAutocorrelation::calcVar()
{
    var = 0;

    for (int i = 0; i < sizeOfData; i++)
    {
        var += ((data[i] - mean) * (data[i] - mean)) / sizeOfData;
    }

    if (print == 1)
    {
        Serial.print("var = ");
        Serial.println(var, 8);
    }
}

void libAutocorrelation::norm()
{
    for (int i = 0; i < sizeOfData; i++)
    {
        ndata[i] = data[i] - mean;
    }
}

void libAutocorrelation::atc()
{
    for (int l = 0; l < lag; l++)
    {
        double c = 1.0, sum = 0.0;
        double tmp = 0.0;

        if (l > 0)
        {
            for (int i = l; i < (sizeOfData - 1); i++)
            {
                tmp += (ndata[i] * ndata[i - l]);
            }
            c = tmp / sizeOfData / var;
        }

        features[l] = c;

        if (print == 1)
        {
            Serial.print("features[");
            Serial.print(l);
            Serial.print("] = ");
            Serial.println(features[l], 8);
        }
    }
}