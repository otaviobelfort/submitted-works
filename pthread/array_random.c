#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define    LENGTH 100
#define NUM_THREAD 4

int A[LENGTH];


int aux = 0;
int input = 0;

void *seachRandomArray(void *arg)
{
   

    for (int i = 0; i < LENGTH; i++)
    {
        if( input == A[i])
        {
            aux+=1;
            printf("\n Numero [%d] encontrado na posição %d\n! ",input, i);
        }
        else if(i == (LENGTH-1) && aux > 1)
        {
            printf("\n Numero [%d] se repetiu %d vezes! ",input, aux);
        }
        else
        {
            //printf("");
            //printf("\n Numero [%d] encontrado na posição %d\n! ",input, i);
        }
    }
}

int main()
{
    printf("Pesquisar numero inteiro no vetor: \n");
    scanf("%d",&input);

    printf("\nBuscando ... %d \n",input);

  // populando vetor, 100 valores aleatorios
  printf("populando vetor A: \n");
  for (int i = 0; i < LENGTH; i++)
  {
      A[i] = random() % 100;
  }

  pthread_t threads[NUM_THREAD];

  for (int i = 0; i < NUM_THREAD; i++)
  {
    int *p;
    pthread_create(&threads[i], NULL, seachRandomArray, (void *)(p));
  }

  printf("\n Vetor A:\n\n");
  for (int i = 0; i < LENGTH; i++)
  {
    
       printf("%d ", A[i]);
      //printf("A[%d][%d](%d)* B[%d][%d](%d) = C[%d][%d] = %d\n", i, j,A[i][j], i,j, B[i][j], i,j, C[i][j]);
  }

}