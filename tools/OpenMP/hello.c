#include <stdio.h>
#include <omp.h>
  
int main()  
{  
	int i;
#pragma omp task
	printf("task\n");

#pragma omp task
	printf("task\n");

#pragma omp parallel
	printf("parallel\n");

	return 0;
}

/*
 * 编译
 * gcc -fopenmp hello.c
 * ./a.out
 *
 */
