#include "1_1.h"

int main(){
    int n;
    printf("Enter value for n : ");
    scanf("%d",&n);
    int a[n];
    populate(a,n);
    int sum=0;
    for(int i=0;i<10;i++){
        int key = rand()%(2*n);
        int count;
        int res = search_with_count(a,n,key,&count);
        sum+=count;
        if(res >= 0){
            printf("%d found in the array at : %d\n",key,res);
            printf("Number of comparisons : %d\n",count);
        }else{
            printf("Number not found!\n");
        }
    }
    printf("Average number of comparisions : %d \n",sum/10);
}
