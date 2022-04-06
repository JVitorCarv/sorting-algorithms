#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    int vetor[SIZE], temp;

    srand(time(NULL));
    // Atribui valores aleatorios ao vetor
    for (int i = 0; i < SIZE; i++)
    {
        vetor[i] = rand() % 10;
    }

    // Para cada elemento no vetor (-1, a última significaria apenas comparar consigo mesmo)
    for (int i = 0; i < SIZE - 1; i++)
    {
        // Itera e compara cada posição do vetor e esta posição + 1, por isso SIZE - 1, para evitar IOR.
        for (int j = 0; j < SIZE - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                // Armazena o vetor[j+1] em temp para que o valor possa ser passado para j depois
                temp = vetor[j + 1];
                vetor[j + 1] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    // Printa o vetor ordenado
    for (int i = 0; i < SIZE; i++)
    {
        printf("N[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}
