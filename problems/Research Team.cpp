//solution to "problem A" in http://hcmus-icpc.ml/public/problems
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll n=(((a+1)*(b+1))/(c+1))-1;
    cout<<n;
}