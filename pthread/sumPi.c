#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <math.h>

#define    LENGTH
#define NUM_THREAD 4



double sum = 0;
int n0,n;

void *sumPi(void *arg)
{
    
    for (int i = 0; i < n; i++)
    {
       // if(i%2 == 0){
        //sum += (pow((-1),i)/((2*i) + 1));
       sum += (pow(-1,i)/((2*i) + 1));
    }
    
}

int main()
{

   
    printf("Valor (n): ");
    scanf("%d",&n);

  // populando vetor, 100 valores aleatorios
  

  pthread_t threads[NUM_THREAD];

  for (int i = 0; i < NUM_THREAD; i++)
  {
    int *p;
    pthread_create(&threads[i], NULL, sumPi, (void *)(p));
  }

  printf("\n A soma é A: %f ",sum);
  

}