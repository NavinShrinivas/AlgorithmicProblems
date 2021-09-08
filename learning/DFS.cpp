//implementing DFS for the frist time (learning)

#include <bits/stdc++.h>

using namespace std;

void dfs(int j,bool visited[],list<int>a[])
{
    if(visited[j]==true)
        return;
    else
    {
        cout<<j<<" ";
        visited[j]=true;
        for(auto i=a[j].begin();i!=a[j].end();i++)
            dfs(*i,visited,a);
    }
}

int main()
{
    int m;
    cout<<"enter number of vertices"<<"\n";
    cin>>m;
    list<int>a[m];
    cout<<"enter a an b values for each vertices"<<"\n";
    for(int i=0;i<m;i++)
    {
        int c,b;
        cin>>c>>b;
        a[c].push_back(b);
    }
    cout<<"enter from where the search is to be started"<<"\n";
    int j;
    cin>>j;
    bool visited[m];
    for (int i = 0; i < m; i++)
        visited[i]=false;
    dfs(j,visited,a);
}

