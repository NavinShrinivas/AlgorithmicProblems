
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void mulmat(int** a , int** b ,int** c , int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)    
            {    
                c[i][j]+=a[i][k]*b[k][j];    
            }       
        }
    }
}

int main(){
    /*int** p = (int**) malloc(3*3*sizeof(int));*/
    int n;
    printf("Enter size fo matrix : ");
    scanf("%d",&n);
    int* a[n]; int* b[n]; int* c[n];
    for(int i =0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        b[i]=(int*)malloc(n*sizeof(int));   
        c[i]=(int*)malloc(n*sizeof(int));
    }
    printf("Enter the elements  of first matrix: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",(*(a+j)+i));
        }
    }
    printf("Enter the elements of next matrix : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",(*(a+i)+j));
        }
    }
    mulmat(a,b,c,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",*(*(c+i)+j));
        }
        printf("\n");
    }
}
