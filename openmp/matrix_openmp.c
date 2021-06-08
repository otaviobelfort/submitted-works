#include <stdio.h>
#include <omp.h>
#include <time.h>
int main (int argc, char *argv[]){

   int TAM = 1000;
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

   
   #pragma omp parallel private(i,j)
   {
   	int id = omp_get_thread_num();
   	int nt = omp_get_num_threads();
   	int size = (int) TAM/nt;
   	int ini = id*size;
   	int fim = ini + size - 1;
   	
   	//int i, j;
   	
   	for (i = ini; i <= fim; i++)
   	{
   		for (j = 0; j < TAM; j++)
   		{
   			C[i][j] = A[i][j] + B[i][j];
   		}
   	}
   }
 
   for (i = 0; i < TAM; i++)
   {
   	for (j = 0; j < TAM; j++)
   	{
   		//printf("C[%d][%d] = %f\n", i, j, C[i][j]);
   	}
   }
   
   return 0;
 }
 
 
   			
   
