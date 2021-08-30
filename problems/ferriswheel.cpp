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
    ll n,max;
    cin>>n>>max;
    int a[n],ans=0;
    for(ll i=0;i<n;i++)
    {
        ll c;
        cin>>c;
        a[i]=c;
    }
    sort(a,a+n,greater<int>());
    ll l=0;ll r=n-1;
    while(l<=r)
    {
        if(a[l]+a[r] <= max)
        {
            ans++;
            l++;
            r--;
        }
        else if(a[l]+a[r] > max)
        {
            ans++;
            l++;
        }
        else if(l==r){
            ans++;l++;r++;
        }
    }
    cout<<ans;
}
