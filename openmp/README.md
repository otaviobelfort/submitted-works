# submitted-works

# OpenMP

**comando de compilação**
```
gcc matrix_openmp.c -fopenmp -o matrix_openmp
```

**comando de execução**

```
./matrix_openmp
```

**comando de tempo execução**

```
time ./matrix_openmp
```

```
#include <stdio.h>
#include <omp.h>
#include <time.h>
int main (int argc, char *argv[]){

   int TAM = 3;
   float A[TAM][TAM];
   float B[TAM][TAM];
   float C[TAM][TAM];
   
   int i, j;
   
   
   
   for (i = 0; i < TAM; i++)
   {
   	for (j = 0; j < TAM; j++)
   	{
   	 	A[i][j] = 2;
   	 	B[i][j] = 3;
   	}
   }
   
   float x = clock();
   float y = 0;
   float z = 0;

   
  // #pragma omp parallel private(i,j)
   //{
   	// int id = omp_get_thread_num();
   	// int nt = omp_get_num_threads();
   	// int size = (int) TAM/nt;
   	// int ini = id*size;
   	// int fim = ini + size - 1;
   	
   	//int i, j;
   	float cont = 0;
   	for (i = 0; i <= TAM; i++)
   	{
		 for (int k= 0; k<TAM;k++){  
			for (j = 0; j < TAM; j++)
			{
				cont += (A[i][j] * B[j][i]);
			}
			C[i][k] = cont;
			printf("CC[%d][%d] = %f\n", i, k, C[i][k]);
			cont = 0;
		 }
   	}
  // }
 
   for ( i = 0; i < TAM; i++)
   {
   	for ( j = 0; j < TAM; j++)
   	{
   		printf("C[%d][%d] = %f\n", i, j, C[i][j]);
   	}
   }
   
   return 0;
 }
 

```
https://www.cenapad.unicamp.br/servicos/treinamentos/apostilas/apostila_openmp.pdf