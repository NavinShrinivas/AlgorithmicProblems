#include<bits/stdc++.h>
#include<math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;

// void swap(ll a[],ll i,ll j)
// {
//     ll temp=a[i];
//     a[i]=a[j];
//     a[j]=temp;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        ll c;
        cin>>c;
        a[i]=c;
    }
    ll count=0;
    for(ll i=0;i<n;i++)
    {
        if(i==0)
            continue;
        else{
            if(a[i]<a[i-1])
            {
                count+=a[i-1]-a[i];
                a[i]=a[i-1];
            }
        }
    }
    cout<<count;
}