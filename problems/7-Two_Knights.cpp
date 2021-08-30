#include<bits/stdc++.h>
#include<math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;

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
    ll k;cin>>k;
    ll m=1;
    while(m<=k)
    {
        ll ans=(((m*m)-1)*(m*m)/2)-(4*(m-1)*(m-2));
        cout<<ans<<"\n";
        m++;    
    }
}
