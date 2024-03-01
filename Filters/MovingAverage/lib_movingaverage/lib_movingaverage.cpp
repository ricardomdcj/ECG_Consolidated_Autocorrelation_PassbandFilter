/*  This is a library to calculate a N sized window Moving Average filter. */

#include "lib_movingaverage.h"

libMovingaverage::libMovingaverage( double* inputData,
                                    double* outputData,
                                    int     sizeOfWindow,
                                    int     sizeOfData,
                                    int     print ) :
                                    inputData(inputData), outputData(outputData),
                                    sizeOfWindow(sizeOfWindow), sizeOfData(sizeOfData),
                                    print(print) {}

void libMovingaverage::movingAverageFilter()
{
    for (int i = 0; i < (sizeOfData - sizeOfWindow + 1); i += sizeOfWindow)
    {
        double sum = 0.0;

        for (int l = 0; l < sizeOfWindow; l++)
        {
            sum += inputData[i + l];
        }

        for (int k = i; k <= i + sizeOfWindow; k++)
        {
            outputData[k] = inputData[k] - sum;
        }
    }

    if (print == 1)
    {
        Serial.println("");
        Serial.println("Sinal de saída do filtro:");
        for (int i = 0; i < sizeOfData; i++)
        {
            Serial.print("MovAvgOutput[");
            Serial.print(i);
            Serial.print("] = ");
            Serial.println(outputData[i], 8);
        }
    }
}