#include"1_1.h"

void populate(int a[],int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
        a[i]=rand()%(2*n);
    }
}
int search(int a[], int n,int key){
    int found = 0;
    int i = -1;
    while(!found && i<n){
        ++i;
        found = a[i] == key;
    }
    return (i<n) ? i : -1;
}

int search_with_count(int a[],int n,int key,int* count){
    int found = 0;
    *count = 0;
    int i = -1;
    while(!found && i<n){
        ++i;
        found = a[i] == key;
        *count+=1;
    }
    return (i<n) ? i : -1;
}
