#include <stdio.h>

#define sizeOfWindow 25  // Window size for the moving average filter
#define sizeOfData 100  // Number of samples in your dataset

double inputData[sizeOfData] = {0.00000000, 0.68454711, 0.99802673, 0.77051324, 0.12533323, -0.58778525, -0.98228725, -0.84432793, -0.24868989, 0.48175367, 0.95105652, 0.90482705, 0.36812455, -0.36812455, -0.90482705, -0.95105652, -0.48175367, 0.24868989, 0.84432793, 0.98228725, 0.58778525, -0.12533323, -0.77051324, -0.99802673, -0.68454711, -0.00000000, 0.68454711, 0.99802673, 0.77051324, 0.12533323, -0.58778525, -0.98228725, -0.84432793, -0.24868989, 0.48175367, 0.95105652, 0.90482705, 0.36812455, -0.36812455, -0.90482705, -0.95105652, -0.48175367, 0.24868989, 0.84432793, 0.98228725, 0.58778525, -0.12533323, -0.77051324, -0.99802673, -0.68454711, -0.00000000, 0.68454711, 0.99802673, 0.77051324, 0.12533323, -0.58778525, -0.98228725, -0.84432793, -0.24868989, 0.48175367, 0.95105652, 0.90482705, 0.36812455, -0.36812455, -0.90482705, -0.95105652, -0.48175367, 0.24868989, 0.84432793, 0.98228725, 0.58778525, -0.12533323, -0.77051324, -0.99802673, -0.68454711, -0.00000000, 0.68454711, 0.99802673, 0.77051324, 0.12533323, -0.58778525, -0.98228725, -0.84432793, -0.24868989, 0.48175367, 0.95105652, 0.90482705, 0.36812455, -0.36812455, -0.90482705, -0.95105652, -0.48175367, 0.24868989, 0.84432793, 0.98228725, 0.58778525, -0.12533323, -0.77051324, -0.99802673, -0.68454711};


double outputData[sizeOfData] = {0.0};


float moving_average(double* input_data, double* output_data, int window_size)
{
    double sum = 0.0;

    for (int i = 0; i < sizeOfData; i += window_size)
    {
        for (int l = 0; l <= window_size; l++)
        {
            sum += input_data[i];
        }
        printf("%f\n ", sum);

        for (int k = i; k <= i + window_size; k++)
        {
            outputData[k] = input_data[k] - sum;
        }
    }
}

int main(void)
{
    moving_average(inputData, outputData, sizeOfWindow);

    // Print the original filtered_data
    printf("Original Filtered Data:\n");
    for (int i = 0; i < sizeOfData; ++i)
    {
        printf("%f ", inputData[i]);
    }
    printf("\n");

    // Print the smoothed_data
    printf("Smoothed Data:\n");
    for (int i = 0; i < sizeOfData; ++i)
    {
        printf("%f ", outputData[i]);
    }
    printf("\n");
}