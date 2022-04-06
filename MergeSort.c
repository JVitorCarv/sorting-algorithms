#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10

void merge(int vetor[], int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;
  int left[n1], right[n2];

  // Preenche os subvetores
  for (int i = 0; i < n1; i++)
  {
    left[i] = vetor[i + l]; // +l porque o indice pode ser diferente de zero
  }
  for (int i = 0; i < n2; i++)
  {
    right[i] = vetor[i + m + 1]; // +m+1 pq e a partir da segunda metade
  }

  int i = 0, j = 0;
  int k = l; // Ele precisa considerar tambem os casos dos subvetores

  // Executa enquanto os indices de cada subvetor forem menores que o indice de sua ultima posicao
  while (i < n1 && j < n2)
  {
    if (left[i] <= right[j]) // o <= é para garantir estabilidade, os da esquerda sempre ficarao a esquerda. o Inverso seria apenas > para garantir o mesmo
    {
      vetor[k] = left[i];
      i++;
    }
    else
    {
      vetor[k] = right[j];
      j++;
    }
    k++;
  }

  // No caso de sobrar em cada subvetor
  while (i < n1)
  {
    vetor[k] = left[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    vetor[k] = right[j];
    j++;
    k++;
  }
}

void mergeSort(int vetor[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeSort(vetor, l, m);
    mergeSort(vetor, m + 1, r);
    merge(vetor, l, m, r);
  }
}

int main()
{
  int vetor[SIZE];

  srand(time(NULL));
  for (int i = 0; i < SIZE; i++)
  {
    vetor[i] = rand() % 10;
  }

  mergeSort(vetor, 0, 9);

  // Exibir
  for (int i = 0; i < SIZE; i++)
  {
    printf("Vetor[%d] = %d\n", i, vetor[i]);
  }
  return 0;
}
