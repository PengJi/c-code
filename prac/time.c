#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
 
int main()
{
	//第一种方法，linux环境下
	struct  timeval    tv;
	struct  timezone   tz;
	gettimeofday(&tv,&tz);
	struct  timeval start;
	struct  timeval end;
 
	printf("tv_sec:%d\n",tv.tv_sec);
	printf("tv_usec:%d\n",tv.tv_usec);
	printf("tz_minuteswest:%d\n",tz.tz_minuteswest);
	printf("tz_dsttime:%d\n",tz.tz_dsttime);

	unsigned  long diff;
	gettimeofday(&start,NULL);
	printf("test interval\n");
	sleep(5);
	gettimeofday(&end,NULL);
	diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	printf("the distance is %ld us\n",diff);
	printf("the distance is %ld ms\n",diff/1000);
	printf("the distance is %d s\n",diff/1000000);

	//第二种方法(linux下失效)
	clock_t startTime, endTime;
	startTime = clock();
	printf("%ld\n",startTime);
	sleep(5);
	endTime = clock();
	printf("%ld\n",endTime);
	printf("total time: %f s\n",(double)(endTime-startTime)/CLOCKS_PER_SEC);

	return 0;
}
