
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*
 *
 *void print_hello(int n)
 *{
 *    if(n==1)
 *    {
 *        printf("Hello \n");
 *        return;
 *    }
 *    printf("Hello \n");
 *    print_hello(n-1);
 *}
 */

int main(){
    int a[5]={10,20,30,40,50};
    int i=3;
    a[3]=i;
    for(int j=0;j<5;j++)
            printf("%d ",*(a+j));
}
