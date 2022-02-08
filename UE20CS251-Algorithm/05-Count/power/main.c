#include"1_1.h"

int main(){
    printf("Enter base and power : ");
    int b,p;
    scanf("%d %d",&b,&p);
    int count = 0;
    int ans = power_with_count(b,p,&count);
    printf("Answer : %d ,  comparisons : %d\n",ans,count);
}
