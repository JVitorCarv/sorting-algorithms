#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
    int vetor[SIZE], temp, pos_min;

    // Coloca valores aleatorios de 0 a 9 no vetor para ordenar
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        vetor[i] = rand() % 10;
    }

    // Itera pelo vetor até a penúltima posição para evitar que compare consigo mesmo
    for (int i = 0; i < SIZE - 1; i++)
    {
        pos_min = i; // Define a posicao do menor, uma vez que guardar o menor numero em si nao e necessario

        // Itera para cada i um numero j de vezes para comparar
        for (int j = i + 1; j < SIZE; j++)
        {
            // Se o valor na posicao j sendo comparado for menor que o atual menor...
            if (vetor[j] < vetor[pos_min])
            {
                pos_min = j; // ...a posicao do menor valor passa a ser a posicao j
            }
        }

        // Troca de posicoes entre a posicao do menor e a posicao i
        temp = vetor[i];
        vetor[i] = vetor[pos_min];
        vetor[pos_min] = temp;
    }

    // Printa o vetor ordenado
    for (int i = 0; i < SIZE; i++)
    {
        printf("N[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}
