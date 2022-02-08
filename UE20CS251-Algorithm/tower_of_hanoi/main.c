#include "1_1.h"

int main(){
    int n;
    int count = 0;
    printf("Enter number of disks : ");
    scanf("%d",&n);
    towerofhanoi_with_count(n,1,2,3,&count);
    printf("Number of recursion : %d",count);
}
