//solution to "Luck Balance" problem in hackkerrank
//https://www.hackerrank.com/challenges/luck-balance/problem?h_l=llerview&playlist_slugs%5B%5D=llerview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,k;
    cin>>n>>k;
    ll count=0;
    ll L[n],t,temp;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        cin>>temp>>t;
        if(t==0)
        {
            ans=ans+temp;
        }
        else if(t==1)
        {
            L[count]=temp;
            count++;
        }
    }
    sort(L,L+count);
    if(k>count)
    {
        k=count;
    }
    ll d=count-k;
    for(ll i=0;i<k;i++)
    {            
        ans=ans+L[(count-1)-i];
    }
    for(ll i=0;i<d;i++)
        ans=ans-L[i];
    cout<<ans;
}
