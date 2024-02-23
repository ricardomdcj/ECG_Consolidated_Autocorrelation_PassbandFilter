#include <stdio.h>
#include <math.h>

// Define os coeficientes do filtro
#define A0 1
#define A1 -1.463561442496923
#define A2 0.914051209844413
#define A3 -0.198874182451286
#define B0 0.031451948112026
#define B1 0.094355844336077
#define B2 0.094355844336077
#define B3 0.031451948112026

// Define o tamanho do buffer de entrada e saída
#define N 100

// Função que aplica o filtro passa baixas a um sinal de entrada
void filtro_passa_baixas(double entrada[], double saida[])
{
    // Inicializa as variáveis auxiliares
    double x0, x1, x2, x3; // Amostras de entrada
    double y0, y1, y2, y3; // Amostras de saída
    x0 = x1 = x2 = x3 = 0;
    y0 = y1 = y2 = y3 = 0;

    // Percorre o buffer de entrada
    for (int i = 0; i < N; i++)
    {
        // Atualiza as amostras de entrada
        x3 = x2;
        x2 = x1;
        x1 = x0;
        x0 = entrada[i];

        // Calcula a amostra de saída usando a equação de diferenças
        y0 = B0 * x0 + B1 * x1 + B2 * x2 + B3 * x3 - A1 * y1 - A2 * y2 - A3 * y3;

        // Atualiza as amostras de saída
        y3 = y2;
        y2 = y1;
        y1 = y0;

        // Armazena a amostra de saída no buffer de saída
        saida[i] = y0;
    }
}

// Função principal que testa o filtro com um sinal de entrada
int main()
{
    // Cria um buffer de entrada com um sinal senoidal de 60 Hz
    double entrada[N];
    double freq = 60; // Frequência do sinal em Hz
    double fs = 500; // Frequência de amostragem em Hz
    double dt = 1 / fs; // Intervalo de tempo entre as amostras em segundos
    for (int i = 0; i < N; i++)
    {
        entrada[i] = sin(2 * 3.14159265358979323846 * freq * i * dt); // Calcula a amostra i do sinal
    }

    // Cria um buffer de saída vazio
    double saida[N];

    // Aplica o filtro ao sinal de entrada
    filtro_passa_baixas(entrada, saida);

    // Imprime o sinal de entrada e o sinal de saída
/*     printf("Entrada\t\tSaida\n");
    for (int i = 0; i < N; i++)
    {
        printf("%.8f\t%.8f\n", entrada[i], saida[i]);
    } */

    printf("Vetor inteiro de entrada:\n{");
    for (int i = 0; i < N; i++)
    {
        printf("%.8f", entrada[i]);
        if(i != 99)
        {
            printf(", ");
        }
        else if (i == 99)
        {
        printf("}\n");
        }
    }

    printf("Vetor inteiro de saída:\n{");
    for (int i = 0; i < N; i++)
    {
        printf("%.8f", saida[i]);
        if(i != 99)
        {
            printf(", ");
        }
        else if (i == 99)
        {
        printf("}\n");
        }
    }

    return 0;
}