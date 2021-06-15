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
    ll t;
    cin>>t;
    while(t)
    {
        ll n,m;
        cin>>n>>m;
        ll diag;
        if(n>m)
        {
            diag=(n*n)-(n-1);
            if(n%2==0)
                cout<<diag+(n-m)<<"\n";
            else
                cout<<diag-(n-m)<<"\n";
        }
        else{
            diag=(m*m)-(m-1);
            if(m%2==0)
                cout<<diag-(m-n)<<"\n";
            else
                cout<<diag+(m-n)<<"\n";
        }
        t--;
    }
}