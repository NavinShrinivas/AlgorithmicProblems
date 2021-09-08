//https://www.hackerrank.com/challenges/maximum-subarray-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t)
    {
    ll n,m;
    cin>>n>>m;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i]; 
    }
    ll sum=0,best=0;
    for(ll i=0;i<n;i++)
    {
        if((a[i]%m)>((a[i]+sum)%m))
        {
            sum=a[i]%m;
        }
        else
        {
            sum=(sum+a[i])%m;
        }
        if(sum>best)
            best=sum;
    }
    cout<<best;
    t--;
    }
}
