#include "1_1.h"

double time_elapsed(struct timespec start, struct timespec end)
{
	double t;
	t = (end.tv_sec - start.tv_sec);				   
	t += (end.tv_nsec - start.tv_nsec) * 0.000000001;  
	return t;
}


int main(){
    printf("Enter size of matrix : ");
    int n;
    scanf("%d",&n);
    int a[n][n],b[n][n];
    fill_matrix(n,a);
    fill_matrix(n,b);

    struct timespec start;
    struct timespec end;

    clock_gettime(CLOCK_REALTIME,&start);
    int c[n][n];
    add_matrix(n,a,b,c);
    clock_gettime(CLOCK_REALTIME,&end);
    printf("time for add :  %lf \n",time_elapsed(start, end));

    struct timespec start1;
    struct timespec end1;

    clock_gettime(CLOCK_REALTIME,&start);
    int mul[n][n];
    init_matrix(n,mul);
    mul_matrix(n,a,b,mul);
    clock_gettime(CLOCK_REALTIME,&end1);
    printf("time for mul : %lf \n",time_elapsed(start1, end1));
}
