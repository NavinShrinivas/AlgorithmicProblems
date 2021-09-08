//solution to  "problem j" "Multicoloured cycles" from http://hcmus-icpc.ml/public/problems
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int ans=1;
    vector<int> a[n];
    int v,u;
    map<int,int>p;
    for(int i=0;i<m;i++)
    {
        cin>>v>>u;
        a[v].push_back(u);
        p[v]++;
    }
    for(auto i=p.begin();i!=p.end();i++)
    {
        if((a[i->first].size())%2 != 0)
        {
            ans=0 ;
            break;
        }
    }
    if(ans==1)
        cout<<"YES";
    else
        cout<<"NO";
}