//solution to the minimum absolute diffrence in an
//array problem from hackerrank
//https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    ll least=1000000000;
    for(int i=1;i<(n-1);i++)
    {
        int ll=abs(a[i]-a[i-1]);
        int rl=abs(a[i]-a[i+1]);
        if(ll < rl && ll < least)
            least=ll;
        else if(rl < ll && rl < least)
            least=rl;
    }
    cout<<least;
}