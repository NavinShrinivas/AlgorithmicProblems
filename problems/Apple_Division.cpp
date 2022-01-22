#include<bits/stdc++.h>
#include<math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;
#define loop(n) for(int i=0;i<n;i++);
#define maploop(m) for(auto it=m.begin();it!=m.end();it++);

// void swap(int a[],int i,int j)
// {
//     int temp=a[i];
//     a[i]=a[j];
//     a[j]=temp;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll arr [n];
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        arr[i]=c;
    }
    sort(arr,arr+n);
    //this leds to O(n) solution
    if(n==1){
        cout<<arr[0];
    }else if(n==2){
        cout<<arr[1]-arr[0];
    }else{
        int l=0,r=0;
        for(int i=n-1;i>=0;i--){
            if(l<=r)
                l+=arr[i];
            else
                r+=arr[i];
        }
        cout<<abs(l-r);
    }
}


//Using greedy approach with sorting, sorting handled by stl library.
