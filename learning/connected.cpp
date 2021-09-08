//implementing connectivity check using graph traversal for learning sake

#include <bits/stdc++.h>

using namespace std;

void dfs(int j,bool visited[],list<int>a[],int h,int &connected)
{
    if(j==h)
        connected=1;
    if(visited[j]==true)
        return;
    else
    {
        visited[j]=true;
        for(auto i=a[j].begin();i!=a[j].end();i++)
            dfs(*i,visited,a,h,connected);
    }
}

int main()
{
    int m;
    int connected=0;
    cout<<"enter number of vertices"<<"\n";
    cin>>m;
    list<int>a[m];
    cout<<"enter a and b values for each vertices"<<"\n";
    for(int i=0;i<m;i++)
    {
        int c,b;
        cin>>c>>b;
        a[c].push_back(b);
    }
    cout<<"enter the two numebrs who's connectedness is to be checked"<<"\n";
    int g,h;
    cin>>g>>h;
    bool visited[m];
    for (int i = 0; i < m; i++)
        visited[i]=false;
    dfs(g,visited,a,h,connected);
    if(connected==1)
        cout<<"YES!they are of same component"<<"\n";
    else
        cout<<"NO!they are of diffrent components"<<"\n";
}

