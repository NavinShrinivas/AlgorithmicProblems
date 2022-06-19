#include<bits/stdc++.h> 

using namespace std; 

typedef struct pair{
    int x;
    int y;
}pair_t;

void swap(int* arr,int a, int b){
    arr[a]+=arr[b];
    arr[b] = arr[a] - arr[b];
    arr[a] -= arr[b];
}

pair_t* minmax_array(int n,int arr[]){
    pair_t* pair_struct = (pair_t*)malloc(sizeof(pair_t));
    pair_struct->x = arr[0];
    pair_struct->y = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > pair_struct->x)
            pair_struct->x = arr[i];
        if(arr[i] < pair_struct->y)
            pair_struct->y = arr[i];
    }
    return pair_struct;
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    pair_t* minmax = minmax_array(n,arr);
    cout<<"Max : "<<minmax->x<<" "<<"Min : "<<minmax->y<<" ";
    cout<<"\n";
    return 0;
}
