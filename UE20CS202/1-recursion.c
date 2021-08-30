#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void print_hello(int n)
{
    if(n==1)
    {
        printf("Hello \n");
        return;
    }
    printf("Hello \n");
    print_hello(n-1);
}

int main(){
    printf("Enter number of hellos needed : ");
    int n;
    scanf("%i",&n); 
    print_hello(10);
}

