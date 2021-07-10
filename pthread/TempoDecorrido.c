#include <time.h>

int frequency_of_primes (int n) {
    int i,j;
    int freq=n-1;
    for (i=2; i<=n; ++i)
        for (j=sqrt(i);j>1;--j)
            if (i%j==0) {
                --freq;
                break;
            }
    return freq;
}

void main() {
    clock_t tInicio, tFim, t;
    int f;

    /* clock() - Retorna o número de ticks que o processo que chama a função já gastou no processador. */
    /* Cada CLOCKS_PER_SEC ciclos correspondem aproximadamente a 1 segundo. */
    /* Os tiques do relógio são unidades de tempo de duração constante, mas específica do sistema. */
    /* Dividir uma contagem de tiques do relógio por essa expressão gera o número de segundos. */

    tInicio = clock();

    f = frequency_of_primes (99999);

    tFim = clock();

    t = tFim-tInicio;

    printf ("Numero de primos menores que 100000 eh: %d\n",f);
    printf("Ticks gastos: %d. Tempo gasto: %lf s\n", t, (double)t/CLOCKS_PER_SEC);

}
