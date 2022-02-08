#include"1_1.h"

int main(){
    int count=0;
    int n;
    printf("Enter nm=umber to find fibbonacci of : ");
    scanf("%d",&n);
    int ans = fib_with_count(n,&count);
    printf(" \n%d fib number : %d Number of recursive calls : %d \n",n,ans,count);
}
