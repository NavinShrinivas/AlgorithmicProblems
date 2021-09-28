
#include<bits/stdc++.h>
#include <cstdio>
#include<math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;
#define loop(n) for(int i=0;i<n;i++);
#define maploop(m) for(auto it=m.begin();it!=m.end();it++);

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
    int n,m;
    cin>>n>>m;
    map<int,int>team1;
    map<int,int>team2;
    for(int i=0;i<m;i++)
    {
        int c,d;
        cin>>c>>d;
        if(team1[c]!=0)
        {
            team1[c]++;
            team2[d]++;
        }
        else if(team1[d]!=0)
        {
            team1[d]++;
            team2[c]++;    
        }       
        else if(team2[c]!=0)
        {
            team2[c]++;
            team1[d]++;    
        }
        else if(team2[d]!=0)
        {
            team1[c]++;
            team2[d]++;    
        }
        else{
            team1[c]++;
            team2[d]++;
        }
    }
    for(auto it=team1.begin();it!=team1.end();it++)
    {
        if(team2[it->first]!=0)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(team1[i]!=0)
            cout<<"1 ";
        else
            cout<<"2 ";
    }
}
