#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define NUMTHREADS  20
#define VETSIZE	    5000000

typedef struct {
	int fromidx, length;
} thread_arg, *ptr_thread_arg;

pthread_t   threads[NUMTHREADS];
thread_arg  arguments[NUMTHREADS];

int sum;

void *thread_func(void *arg) {
	ptr_thread_arg argument = (ptr_thread_arg)arg;
	int i, localsum = 0, endidx;

	endidx = argument->fromidx + argument->length;
	for(i = argument->fromidx; i < endidx; i++) {
		localsum += i*i*i;
	}
	sum += localsum;
}

int main(int argc, char **argv) {
	int i, length, remainder;
	clock_t tInicio, tFim, t;

	sum = 0;
    length = VETSIZE / NUMTHREADS;
	remainder = VETSIZE % NUMTHREADS;
	tInicio = clock();
	for(i = 0; i < NUMTHREADS; i++) {
		arguments[i].fromidx = i * length;
		arguments[i].length = length;
		if(i == (NUMTHREADS - 1)) /* Testa se é ultima thread */
			arguments[i].length += remainder; // 1665  1665  1670
		pthread_create(&(threads[i]), NULL, thread_func, &(arguments[i]));
	}
	for(i=0; i<NUMTHREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	tFim = clock();
    t = tFim-tInicio;
	printf("A soma dos numeros de 0 a 5000 eh %d\n", sum);
	printf("Ticks gastos: %d. Tempo gasto: %lf s\n", t, (double)t/CLOCKS_PER_SEC);
}


