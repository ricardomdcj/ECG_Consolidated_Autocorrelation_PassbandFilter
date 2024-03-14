#include <stdio.h>
#include <stdlib.h>

const int sizeOfData = 100;
const int sizeOfWindow = 25;

void convolution(double *input, int input_length, double *output)
{
    int ones_vector[sizeOfWindow];
    for (int i = 0; i < sizeOfWindow; i++)
    {
        ones_vector[i] = 1;
    }

    for (int i = 0; i < input_length; i++)
    {
        for (int j = 0; j < sizeOfWindow; j++)
        {
            int k = i - sizeOfWindow / 2 + j;
            if (k >= 0 && k < input_length)
            {
                output[i] += ones_vector[j] * input[k] ;
            }
        }
    }

    // Normalizando o vetor resultante
    for (int i = 0; i < sizeOfData; i++)
    {
        output[i] /= sizeOfWindow;
    }
}

int main() {

    double crescent_vector[sizeOfData] = {
       0.00806596, 0.00804456, 0.00802316, 0.00800178, 0.0079804 ,
       0.00795904, 0.00793769, 0.00791636, 0.00789503, 0.00787372,
       0.00785242, 0.00783113, 0.00780986, 0.00778859, 0.00776734,
       0.00774611, 0.00772488, 0.00770367, 0.00768246, 0.00766128,
       0.0076401 , 0.00761894, 0.00759779, 0.00757665, 0.00755552,
       0.00753441, 0.00751331, 0.00749222, 0.00747115, 0.00745008,
       0.00742903, 0.007408  , 0.00738697, 0.00736596, 0.00734497,
       0.00732398, 0.00730301, 0.00728205, 0.0072611 , 0.00724017,
       0.00721925, 0.00719835, 0.00717745, 0.00715657, 0.00713571,
       0.00711485, 0.00709401, 0.00707319, 0.00705237, 0.00703158,
       0.00701079, 0.00699002, 0.00696926, 0.00694851, 0.00692778,
       0.00690706, 0.00688636, 0.00686567, 0.00684499, 0.00682433,
       0.00680368, 0.00678305, 0.00676242, 0.00674182, 0.00672122,
       0.00670064, 0.00668008, 0.00665953, 0.00663899, 0.00661847,
       0.00659796, 0.00657746, 0.00655698, 0.00653652, 0.00651606,
       0.00649563, 0.0064752 , 0.00645479, 0.0064344 , 0.00641402,
       0.00639365, 0.0063733 , 0.00635296, 0.00633264, 0.00631233,
       0.00629204, 0.00627176, 0.00625149, 0.00623124, 0.00621101,
       0.00619079, 0.00617058, 0.00615039, 0.00613021, 0.00611005,
       0.00608991, 0.00606978, 0.00604966, 0.00602956, 0.00600948};

    // Inicializando o vetor resultante com zeros
    double conv_result[sizeOfData] = {0.0};

    // Calculando a convolução
    convolution(crescent_vector, sizeOfData, conv_result);

    // Imprimindo o resultado
    printf("Resultado da convolução:\n");
    for (int i = 0; i < sizeOfData; i+=6)
    {
        printf("%.8f ", conv_result[i]);
        printf("%.8f ", conv_result[i+1]);
        printf("%.8f ", conv_result[i+2]);
        printf("%.8f ", conv_result[i+3]);
        printf("%.8f ", conv_result[i+4]);
        printf("%.8f ", conv_result[i+5]);
        printf("\n");
    }

    return 0;
}