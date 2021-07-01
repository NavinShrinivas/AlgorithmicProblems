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
    ll n;cin>>n;
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        sum+=i;
    }
    if(sum%2!=0)
    {
        cout<<"NO";
        return 0;
    }
    else
    {
        cout<<"YES"<<"\n";
        ll half=sum/2;
        ll firsthalf[n+1]={0};
        ll halfsum=0;
        ll count=0;
        for(ll i=n;i>0;i--)
        {
            halfsum+=i;
            if(halfsum>half)
                halfsum-=i;
            else if(half==halfsum)
            {
                count++;
                firsthalf[i]=1;
                break;
            }
            else
            {
                count++;
                firsthalf[i]=1;
            }            
        }
        cout<<count<<"\n";
        for(ll i=1;i<=n;i++)
        {
            if(firsthalf[i]==1)
                cout<<i<<" ";
        }
        cout<<"\n"<<n-count<<"\n";   
        for(ll i=1;i<=n;i++)
        {
            if(firsthalf[i]==0)
                cout<<i<<" ";
        }
    }
}
