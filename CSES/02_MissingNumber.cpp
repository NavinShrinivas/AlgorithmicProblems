#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    cin>>n;
    ll is_present[n+1];
    is_present[0] = 1; //can omit 0 always 
    for(ll i=0;i<n-1;i++){
        ll c;
        cin>>c;
        is_present[c] = 1;
    }
    for(ll i=0;i<n+1;i++){
        if(is_present[i] != 1){ //The array maybe filled with junk value but I dont mind it 
            cout<<i;
            return 0;
        }
    }
    return 0;
}
