#include"1_1.h"

int fib(int n){
    int ans;
    if(n == 0){
        ans = 0;
    }else if ( n == 1 ){
        ans = 1;
    }else{
        ans = fib(n-1) + fib(n-2);
    }
    return ans;
}


int fib_with_count(int n,int* ptr_count){
    int ans;
    if(n == 0){
        *ptr_count += 1;
        ans = 0;
    }else if ( n == 1 ){
        *ptr_count += 1;
        ans = 1;
    }else{
        *ptr_count += 2;
        ans = fib_with_count(n-1 , ptr_count) + fib_with_count(n-2,ptr_count);
    }
    return ans;
}
