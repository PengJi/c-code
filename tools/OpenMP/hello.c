#include <stdio.h>
#include <omp.h>
  
int main()  
{  
	int i;
#pragma omp task
	{
		printf("task\n");
		printf("Thread ID: %d\n",omp_get_thread_num());
	}

#pragma omp task
	{
		printf("task\n");
		printf("Thread ID: %d\n",omp_get_thread_num());
	}

#pragma omp parallel
	printf("parallel\n");

#pragma omp parallel num_threads(2)
	{
		printf("num_threads\n");
		printf("Thread ID: %d\n",omp_get_thread_num());
	}

	return 0;
}
/*
 * 编译
 * gcc -fopenmp hello.c
 * ./a.out
 *
 */
