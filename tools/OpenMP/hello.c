#include <stdio.h>
#include <omp.h>
  
int main()  
{  
#pragma omp parallel  
    {  
		printf("test\n");
    }  
	
	return 0;
}
