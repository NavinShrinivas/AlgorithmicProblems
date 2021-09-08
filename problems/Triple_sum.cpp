//sorting problem
//solutions the the problem "Triple Sum" from hackerrank
//https://www.hackerrank.com/challenges/triple-sum/problem
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,l;
    cin>>m>>n>>l;
    int ans=0;
    int a[m],b[n],c[l];
    int count_l[m],count_r[l];//these act a cumulative frequencies(to find number of elements less than a mid ele)
    set<int> s;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
        count_l[i]=s.size();
    }
    s.clear();
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<l;i++)
    {
        cin>>c[i];
        s.insert(c[i]);
        count_r[i]=s.size();
    }
    sort(a,a+m);
    sort(b,b+n);
    sort(c,c+l);
    //for initial case as checking 0 is skipped in for loop...cus of the need of distinct triplets
    int x,y;;
    x=upper_bound(a,a+n,b[0])-a;//-a and -b is not altering the value its just to maintian the pointer variable type
    y=upper_bound(c,c+l,b[0])-b;
    x--;
    y--;
    if(x>=0 && y>=0)
    {
        ans=ans+(count_l[x]*count_r[y]);
    }
    //actual for loop
    for(int i=1;i<n;i++)
    {
        if(b[i]!=b[i-1])
        {
            x=upper_bound(a,a+m,b[i])-a;      
            y=upper_bound(c,c+l,b[i])-b;
            x--;
            y--;
            if(x>=0 && y>=0)
            {
                ans=ans+(count_l[x]*count_r[y]);
            }
        }
    }
    cout<<ans;
}