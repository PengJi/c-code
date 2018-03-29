#include <stdio.h>
#include <mpi.h>

/*
 * https://www.felix021.com/blog/read.php?2123
 */

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv); //初始化MPI环境
	
	    printf("Hello world!\n");
		
		    MPI_Finalize(); //结束MPI环境
			    return 0;
}
/*
mpicc -o hello hello.c
mpiexec -n 4 ./hello
*/
