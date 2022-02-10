#include "1_1.h"

void towerofhanoi(int n,int from,int use,int to){
    if( n == 0 ){
        return;
    }else{
        towerofhanoi(n-1,from,to,use);
        printf("move disk %d  from %d to %d \n",n,from,to);
        towerofhanoi(n-1,use,from,to);
    }
}



void towerofhanoi_with_count(int n,int from,int use,int to,int* ptr_count){
    if( n == 0 ){
        *ptr_count+=1;
        return;
    }else{
        towerofhanoi_with_count(n-1,from,to,use,ptr_count);
        printf("move disk %d  from %d to %d \n",n,from,to);
        towerofhanoi_with_count(n-1,use,from,to,ptr_count);
        *ptr_count+=2;
    }
}
