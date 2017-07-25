#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>
 
int main()
{
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
	sleep(10);
	gettimeofday(&end,NULL);
	diff = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
	printf("thedifference is %ld\n",diff);
	return 0;
}
