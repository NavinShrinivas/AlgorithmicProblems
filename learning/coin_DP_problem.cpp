//learning dynamic programming iwth help of the ever infamous
//coin problem 
#include<bits/stdc++.h>
#include<math.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
using namespace std;

int main()
{
    //optional for codeforces and harckerrank
    // int t;
    // int tc=0;
    // cin>>t;
    // IOS;
    // while(t)
    // {
    //     tc++;
    //     cout<<"Case #"<<tc<<": "<<count<<"\n";
    //     t--;
    // }
    int n;
    cout<<"enter number of coins:"<<"\n";
    cin>>n;
    vector<int> c(n);
    cout<<"enter values of each coin:"<<"\n";
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    int v;
    cout<<"enter the value to be obatined with least coins:"<<"\n";
    cin>>v;
    int value[v+1];
    value[0]=0;
    for(int i=1;i<=v;i++)
    {
        value[i]=2147483647;
        for(auto u:c){
            if(i-u>=0)
                value[i]=min(value[i],value[i-u]+1);
        }
    }
    if(value[v]>v || value[v]<0)
        cout<<"not possible to form this denomination with given coins"<<"\n";
    else
        cout<<"minimum number of coins needed to make "<<v<<" is: "<<value[v]<<"\n";
}