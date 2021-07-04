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
    // ll a[n*20];
    // a[0]=1;
    // ll resv=1;
    // for(ll i=2;i<=n;i++)
    // {
    //     ll carry=0;
    //     for(ll j=0;j<resv;j++)
    //     {
    //         ll prod=(a[j]*i)+carry;
    //         a[j]=prod%10;
    //         carry=prod/10;
    //     }
    //     while(carry)
    //     {
    //         a[resv]=carry%10;
    //         carry/=10;
    //         resv++;
    //     }
    // }
    // for(ll i=0;i<n;i++)
    // {
    //     if(a[i]==0)
    //         zerocount++;
    //     else
    //         break;
    // }
    ll zerocount=0; 
    ll copy=n;
    for(int i=5;copy/i>=1;i=i*5)
    {
        zerocount+=copy/i;
    }
    cout<<zerocount;
}