#include<bits/stdc++.h> 

using namespace std; 


void swap(int* arr,int a, int b){
    arr[a]+=arr[b];
    arr[b] = arr[a] - arr[b];
    arr[a] -= arr[b];
}

void reverse_array(int n,int arr[]){
    if(n%2 == 0){
        for(int i=0;i<=n/2;i++){
            int swap_index = n-i-1;
            swap(arr,i,swap_index);
        }
    }else{
        for(int i=0;i<n/2;i++){
            int swap_index = n-i-1;
            swap(arr,i,swap_index);
        }

    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse_array(n,arr);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
