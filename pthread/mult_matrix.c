#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define    LENGTH 50
#define NUM_THREAD 16

int A[LENGTH][LENGTH];
int B[LENGTH][LENGTH];
int C[LENGTH][LENGTH];

int sum = 0;
int aux = 0;

void *multiMatrix(void *arg)
{

  for (int i = 0; i < LENGTH; i++)
  {
    for (int j = 0; j < LENGTH; j++)
    {
      for (int k = 0; k < LENGTH; k++)
      {
        sum += A[i][k] * B[k][j];
      }

      C[i][j] = sum;
      sum = 0;
    }
  }
}

int main()
{

  for (int i = 0; i < LENGTH; i++)
  {
    for (int j = 0; j < LENGTH; j++)
    {
      A[i][j] = 2;
      B[i][j] = 3;
      //A[i][j] = rand() % 20;
      //B[i][j] = rand() % 20;
    }
  }

  printf("Matrix A: \n");
  char ai[LENGTH+4];
  char aj;
  for (int i = 0; i < LENGTH; i++)
  {
    for (int j = 0; j < LENGTH; j++)
    {
       // strcat(ai, A[i][j]);
        printf("A[%d][%d] = %d\n", i, j, A[i][j]);
    }
  }

  printf("\n Matriz B: \n");
  for (int i = 0; i < LENGTH; i++)
  {
    for (int j = 0; j < LENGTH; j++)
    {
       printf("B[%d][%d] = %d\n", i, j, B[i][j]);
      //printf("%c \n",aj);
    }
  }

  pthread_t threads[NUM_THREAD];

  for (int i = 0; i < NUM_THREAD; i++)
  {
    int *p;
    pthread_create(&threads[i], NULL, multiMatrix, (void *)(p));
  }

  printf("\n Multiplicacao de A*B:\n\n");
  for (int i = 0; i < LENGTH; i++)
  {
    for (int j = 0; j < LENGTH; j++)
    {
        printf("C[%d][%d] = %d\n", i, j, C[i][j]);
      //printf("A[%d][%d](%d)* B[%d][%d](%d) = C[%d][%d] = %d\n", i, j,A[i][j], i,j, B[i][j], i,j, C[i][j]);
     
    }
  }
}