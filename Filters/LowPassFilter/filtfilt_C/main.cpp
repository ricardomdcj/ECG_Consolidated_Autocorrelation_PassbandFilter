#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define sizeOfData 100     // Tamanho do sinal de entrada

void filtfilt(const double *b, const double *a, int order, const double *x, int N, double *y) {
    int i, j;
    double *tmp1 = (double *)malloc(N * sizeof(double));
    double *tmp2 = (double *)malloc(N * sizeof(double));

    // Forward filter
    for (i = 0; i < N; ++i) {
        tmp1[i] = 0.0;
        for (j = 0; j <= order; ++j) {
            if (i - j >= 0) {
                tmp1[i] += b[j] * x[i - j];
            }
        }
        for (j = 1; j <= order; ++j) {
            if (i - j >= 0) {
                tmp1[i] -= a[j] * tmp1[i - j];
            }
        }
    }

    // Backward filter
    for (i = N - 1; i >= 0; --i) {
        tmp2[i] = 0.0;
        for (j = 0; j <= order; ++j) {
            if (i + j < N) {
                tmp2[i] += b[j] * tmp1[i + j];
            }
        }
        for (j = 1; j <= order; ++j) {
            if (i + j < N) {
                tmp2[i] -= a[j] * tmp2[i + j];
            }
        }
    }

    // Scaling
    for (i = 0; i < N; ++i) {
        y[i] = tmp2[i] / a[0];
    }

    free(tmp1);
    free(tmp2);
}

int main() {
    // Coeficientes do filtro de terceira ordem
    double az[] = {1.000000000000000, -1.463561442496923, 0.914051209844413, -0.198874182451286};
    double bz[] = {0.031451948112026, 0.094355844336077, 0.094355844336077, 0.031451948112026};

    int order = 3;  // Ordem do filtro
    double x[sizeOfData];
    for (int i = 0; i < sizeOfData; i++)
    {
        x[i] = sin(0.7540*i);  // Sinal de entrada
    }

    double y[sizeOfData];    // Sinal de saída

    filtfilt(bz, az, order, x, sizeOfData, y);

    // Imprimir resultado
    printf("Sinal de entrada:\n");
    for (int i = 0; i < sizeOfData; ++i) {
        printf("%f ", x[i]);
    }

    printf("\nSinal de saída:\n");
    for (int i = 0; i < sizeOfData; ++i) {
        printf("%f ", y[i]);
    }

    return 0;
}
