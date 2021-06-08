#include <omp.h>
#include <stdio.h>
int main (int argc, char *argv[]){ 
	int num_threads, id;
	
	/* Fork a team of threads giving them their own copies of variables */
	#pragma omp parallel private(num_threads, id)
	{
	 
	 /* Obtain and print thread id */
	 id = omp_get_thread_num();
	 printf("Hello World from thread = %d\n", id);
	 
	 /* Only master thread does this */
	 if (id == 0){
		 	 
		 num_threads = omp_get_num_threads();
		 printf("Number of threads = %d\n", num_threads);
	 }
	 } 
	 /* All threads join master thread and terminate */
}
