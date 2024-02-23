/*  This is a library created to execute a 4th order passband filtering
    calculus through a N sized vector of data.
    It was created with the purpose of being implemented on microcontollers. */

#include "lib_passband.h"

/*  These filter coefficients were previously calculated by using
    the Matlab software */
#define A0 1.000000000000000
#define A1 -1.463561442496923
#define A2 0.914051209844413
#define A3 -0.198874182451286
#define B0 0.031451948112026
#define B1 0.094355844336077
#define B2 0.094355844336077
#define B3 0.031451948112026

libPassband::libPassband(double* input, double* output, int sizeOfData, int print) :
input(input), output(output), sizeOfData(sizeOfData), print(print) {}

/* The print parameter is only for debbuging purposes*/

libPassband::auxiliaryParameters()
{
    x0 = x1 = x2 = x3 = 0;
    y0 = y1 = y2 = y3 = 0;
}

void libPassband::passbandFilter()
{
    // Run through the whole input buffer
    for (int i = 0; i < sizeOfData; i++)
    {
        // Update the input variables
        x3 = x2;
        x2 = x1;
        x1 = x0;
        x0 = input[i];

        // Calculate through the difference equation
        y0 = B0 * x0 + B1 * x1 + B2 * x2 + B3 * x3 - A1 * y1 - A2 * y2 - A3 * y3;

        // Update the output variables
        y3 = y2;
        y2 = y1;
        y1 = y0;

        output[i] = y0;
    }

    if (print == 1)
    {
        for (int i = 0; i < sizeOfData; i++)
        {
            Serial.print("filterOutput[");
            Serial.print(i);
            Serial.print("] = ");
            Serial.println(output[i], 8);
        }
    }
}