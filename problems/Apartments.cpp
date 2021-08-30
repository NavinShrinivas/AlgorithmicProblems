#include<bits/stdc++.h>
#include<math.h>
#include<string.h>
#define loop(n) for(ll i=0;i<n;i++)
#define maploop(m) for(auto it=m.begin();it!=m.end();it++)
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
    ll n,m,k;
    cin>>n>>m>>k;
    ll req[n],apt[m];
    loop(n)
    {
        ll c;cin>>c;
        req[i]=c;
    }
    loop(m)
    {
        ll c;cin>>c;
        apt[i]=c;
    }
    sort(req,req+n,greater<ll>());sort(apt,apt+m,greater<ll>());
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(abs(apt[i]-req[j])>=k){
                ans++;
                apt[i]=-intlimit;
                break;
            }
           // else if (apt[i]>req[j])
            //{
                //i++;
            //}
        }
    }
    cout<<ans;
}
