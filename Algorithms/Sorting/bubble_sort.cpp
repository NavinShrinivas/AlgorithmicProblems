#include<bits/stdc++.h>
#include<math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;
#define loop(n) for(int i=0;i<n;i++);
#define maploop(m) for(auto it=m.begin();it!=m.end();it++);

void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //This is better impl of bubble sort
    bool is_swapped = true;
    int i=0;
    while(is_swapped && i<n-1){ //loop till n-2 is enuf
        is_swapped = false;//assuming array is sorted every iteration
        int j=0;
        while(j<n-i-1){
            if(a[j]>a[j+1]){
                is_swapped = true;
                swap(a,j,j+1);
            }
            j++;
        }
        i++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
