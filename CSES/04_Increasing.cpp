#include<bits/stdc++.h> 

using namespace std;
typedef long long int ll;

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];

    ll ans = 0;
    for(ll i=1;i<n;i++){
        if(arr[i] < arr[i-1]){
            ans+= abs(arr[i]-arr[i-1]);
            arr[i]+=abs(arr[i]-arr[i-1]);

        }
    }
    cout<<ans;
}
