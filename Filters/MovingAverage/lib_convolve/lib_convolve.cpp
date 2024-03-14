/*  This is a library to calculate a N sized window Moving Average filter. */

#include "lib_convolve.h"

libMovingaverage::libMovingAverage(double *inputData, double *outputData, int sizeOfData, int sizeOfWindow, int print) : inputData(inputData), outputData(outputData), sizeOfData(sizeOfData), sizeOfWindow(sizeOfWindow), print(print) {}

void libMovingaverage::convolve()
{
    int ones_vector[sizeOfWindow];
    for (int i = 0; i < sizeOfWindow; i++)
    {
        ones_vector[i] = 1;
    }

    for (int i = 0; i < sizeOfData; i++)
    {
        for (int j = 0; j < sizeOfWindow; j++)
        {
            int k = i - sizeOfWindow / 2 + j;
            if (k >= 0 && k < sizeOfData)
            {
                outputData[i] += ones_vector[j] * inputData[k] ;
            }
        }
    }

    // Normalizando o vetor resultante
    for (int i = 0; i < sizeOfData; i++)
    {
        outputData[i] /= sizeOfWindow;
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