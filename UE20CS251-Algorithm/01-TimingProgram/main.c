#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				   
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
	return t;
}
int main()
{

	long s = 0;
	struct timespec start;
	struct timespec end;
	clock_gettime(CLOCK_REALTIME, &start);	
	for(int i = 0; i < 1000; ++i)
	{
		for(int j = 0; j < 1000; ++j)
		{
			++s;
		}
	}
	clock_gettime(CLOCK_REALTIME, &end);	
	printf("time %lf \n",
			   time_elapsed(start, end));	printf("res : %ld\n", s);
}
