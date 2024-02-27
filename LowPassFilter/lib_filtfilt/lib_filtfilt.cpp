/*  This is a library created to execute a 4th order passband filtering
    calculus through a N sized vector of data.
    It was created with the purpose of being implemented on microcontollers. */

#include "lib_filtfilt.h"

#define filtOrder 3

/*  These filter coefficients were previously calculated by using
    the Matlab software */
double az[] = {1.0, -1.463561442496923, 0.914051209844413, -0.198874182451286};
double bz[] = {0.031451948112026, 0.094355844336077, 0.094355844336077, 0.031451948112026};

libFiltfilt::libFiltfilt(double *x,
                         double *y,
                         int sizeOfData,
                         int print) :
                         x(x), y(y), sizeOfData(sizeOfData), print(print) {}

libFiltfilt::~libFiltfilt()
{
    delete[] tmp1;
    delete[] tmp2;
    delete[] b;
    delete[] a;
}

void libFiltfilt::filtfilt()
{
    const double *b = bz;
    const double *a = az;
    double tmp1[sizeOfData] = {0.0};
    double tmp2[sizeOfData] = {0.0};

    // Forward filter
    for (int i = 0; i < sizeOfData; ++i)
    {
        for (int j = 0; j <= filtOrder; ++j)
        {
            if (i - j >= 0)
            {
                tmp1[i] += b[j] * x[i - j];
            }
        }
        for (int j = 1; j <= filtOrder; ++j)
        {
            if (i - j >= 0)
            {
                tmp1[i] -= a[j] * tmp1[i - j];
            }
        }
    }

    // Backward filter
    for (int i = sizeOfData - 1; i >= 0; --i)
    {
        for (int j = 0; j <= filtOrder; ++j)
        {
            if (i + j < sizeOfData)
            {
                tmp2[i] += b[j] * tmp1[i + j];
            }
        }
        for (int j = 1; j <= filtOrder; ++j)
        {
            if (i + j < sizeOfData)
            {
                tmp2[i] -= a[j] * tmp2[i + j];
            }
        }
    }

    // Scaling
    for (int i = 0; i < sizeOfData; ++i)
    {
        y[i] = tmp2[i] / a[0];
    }

    if (print == 1)
    {
        Serial.println("");
        Serial.println("Sinal de saída do filtro:");
        for (int i = 0; i < sizeOfData; i++)
        {
            Serial.print("filterOutput[");
            Serial.print(i);
            Serial.print("] = ");
            Serial.println(y[i], 8);
        }
    }
}
