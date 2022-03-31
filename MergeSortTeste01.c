#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

void merge(int vetor[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1; // Define o tamanho do primeiro vetor e l+1 pois m é acrescido de 1
  int n2 = r - m;     // Define o tamanho do segundo vetor. m não é acrescido de 1 pois ja vem assim
  int L[n1];          // Cria o primeiro vetor
  int R[n2];          // Cria o segundo vetor

  for (i = 0; i < n1; i++)
  {
    L[i] = vetor[l + i];
  }

  for (j = 0; j < n2; j++)
  {
    R[j] = vetor[m + 1 + j];
  }

  i = 0; // Indices do primeiro subvetor
  j = 0; // Indices do segundo subvetor
  k = l; // Indices do vetor ja combinado

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      vetor[k] = L[i];
      i++;
    }
    else
    {
      vetor[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    vetor[k] = L[i];
    i++;
    k++;
  } // Outro while para copiar quem sobrou em R
}

void mergeSort(int vetor[], int l, int r)
{
  // Roda enquanto o r for maior do que o l
  if (l < r)
  {
    int m = l + (r - l) / 2; // Calcula o valor da metade do vetor
    // Divide o vetor em dois
    mergeSort(vetor, l, m);
    mergeSort(vetor, m + 1, r);

    merge(vetor, l, m, r);
  }
}

int main(void)
{
  srand(time(NULL));
  int vetor[SIZE];

  // Coloca números aleatórios no vetor
  for (int i = 0; i < SIZE; i++)
  {
    vetor[i] = rand() % 10;
  }

  mergeSort(vetor, 0, SIZE - 1);

  for (int i = 0; i < SIZE; i++)
  {
    printf("Vetor[%d] = %d\n", i, vetor[i]);
  }

  return 0;
}
