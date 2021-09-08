//really ez problem
//just use hash maps like previous problem
//solution the the "Pairs" problem in hackerrank
//https://www.hackerrank.com/challenges/pairs/problem

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,t;
    cin>>n>>t;
    //t is target value
    int a[n],ans;
    ans=0;
    map <int , int> m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        int needed=a[i]+t;
        if(m.count(needed))
            ans++;
    }
    cout<<ans;
}