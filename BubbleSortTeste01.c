#include <stdio.h>
#define SIZE 10

int main()
{
    int N[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, temp;

    // De forma raiz, ineficiente
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            if (N[j - 1] > N[j])
            {
                temp = N[j];
                N[j] = N[j - 1];
                N[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("N[%d] = %d\n", i, N[i]);
    }
    return 0;
}