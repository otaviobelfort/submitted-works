#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUMTHREADS  4
#define VETSIZE	    5000
//gcc -pthread -o SomaThreadsSemaforo SomaThreadsSemaforo.c 
typedef struct {
	int idx, length;
} thread_arg, *ptr_thread_arg;

pthread_t   threads[NUMTHREADS];  // Threads do programa
thread_arg  arguments[NUMTHREADS];  // Argumentos do programa

sem_t S;

int sum; // Soma geral dos dados

void *thread_func(void *arg) {
	ptr_thread_arg  argument = (ptr_thread_arg)arg;
	int i, localsum = 0, endidx;

	endidx = argument->idx + argument->length;  // Posi��o do ultimo+1
	printf("Somando de %d ate %d\n", argument->idx,endidx);
	for(i = argument->idx; i < endidx; i++) {
		localsum += i;  // localsum = localsum+i
	}
	printf("Soma local %d\n",localsum);
	sem_wait(&S);
	sum += localsum; // Acumula a soma da thread na soma geral (sum = sum+localsum)
	sem_post(&S);
}

int main(int argc, char **argv) {
	int i, length, remainder;  // remainder = resto

	sem_init(&S,0,1);
	sum = 0;
    length = VETSIZE / NUMTHREADS; // Tamanho dos dados de cada thread (divis�o inteira)
	remainder = VETSIZE % NUMTHREADS; // Resto da divis�o inteira
	// Criar todas as threads
	for(i = 0; i < NUMTHREADS; i++) {
		arguments[i].idx = i * length;
		arguments[i].length = length;
		if(i == (NUMTHREADS - 1)) // Testa se � ultima thread
			arguments[i].length += remainder; // A �ltima recebe o resto, al�m dos dados
		pthread_create(&threads[i], NULL, thread_func, &arguments[i]);
	}
	// Aguardar todas as threads terminarem
	for(i=0; i<NUMTHREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	sem_destroy(&S);
	printf("A soma dos numeros de 0 a 4999 eh %d\n", sum);

}


