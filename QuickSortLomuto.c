#include <stdio.h>

int partition(int A[], int l, int r)
{
    int pivot = A[l];
    int i = l;
    for (int j = l + 1; j <= r; j++)
    {
        // Checa se a posicao j e menor do que o pivot ou igual a ele
        if (A[j] <= pivot)
        {
            // Incrementa a posicao i para que troque a posicao verificada com o j
            // e nao o pivot
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    // Coloca o pivot na posicao i achada
    int temp = A[i];
    A[i] = A[l];
    A[l] = temp;

    return i;
}

void quicksort(int A[], int l, int r)
{
    if (l < r)
    {
        int pivot_index = partition(A, l, r);
        quicksort(A, l, pivot_index - 1);
        quicksort(A, pivot_index + 1, r);
    }
}

int main()
{
    int vetor[] = {4, 1, 2, 5, 3};

    quicksort(vetor, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }
    return 0;
}