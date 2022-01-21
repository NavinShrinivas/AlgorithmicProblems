#include "1_1.h"

void fill_matrix(int n, int x[][n]){
	srand(time(0));
    for(int i = 0;i < n; i++){
        for(int j = 0; j <n ; j++){
            x[i][j] = rand() % 100;
        }
    }
}


void disp_matrix(int n, int x[][n]){
     for(int i = 0; i < n; i++) {
        for(int j = 0;j < n; j++) {
            printf("%d ",x [i][j]);
        }
        printf("\n");
    }
}

void add_matrix(int n,int a[][n],int b[][n],int c[][n]){
    for(int i = 0; i < n ; i++){
        for(int j=0 ; j < n ; j++){
            c[i][j]=a[i][j]+a[i][j];
        }
    }
}

void init_matrix(int n,int x[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            x[i][j]=0;
        }
    }
}

void mul_matrix(int n,int a[][n],int b[][n],int c[][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }
}

