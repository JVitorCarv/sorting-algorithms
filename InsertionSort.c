#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
    int vetor[SIZE];
    int i, j, temp;

    // Coloca valores aleatorios de 0 a 9 no vetor para ordenar
    srand(time(NULL));
    for (i = 0; i < SIZE; i++)
    {
        vetor[i] = rand() % 10;
    }

    // InsertionSort
    // Itera o vetor inteiro a partir do indice 1, ja isolando o indice 0
    for (i = 1; i < SIZE; i++)
    {
        j = i; // Define j como i para sempre comparar a partir da primeira posicao nao isolada

        // Vai trocar a posicao dos vetores enquanto a posicao atual nao for 0 e o elemento anterior for maior
        while (j > 0 && vetor[j] < vetor[j - 1])
        {
            temp = vetor[j - 1];
            vetor[j - 1] = vetor[j];
            vetor[j] = temp;
            j--; // Redefine o j uma vez que ele desceu uma posicao
        }
    }

    // Print de checagem
    for (i = 0; i < SIZE; i++)
    {
        printf("N[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}
