#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
  int n;
  scanf("%i", &n);
  printf("%i\n", n);
  int sum;
  for (int i = 0; i < n; i++)
    {
       // if(i%2 == 0){
        //sum += (pow((-1),i)/((2*i) + 1));
       sum += (pow(-1,i)/((2*i) + 1));
    }
  printf("Soma = %i\n", sum);
  return 0;
}
