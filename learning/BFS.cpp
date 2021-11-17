//implementing BFS for learning sake
#include<bits/stdc++.h>
using namespace std;

int main()
{

    //little queue stuff
    int queue[QUEUESIZE];
    int top=-1,front=-1;
    //------------------
    int m;
    cout<<"enter number of vertices"<<"\n";
    cin>>m;
    list<int>a[m];
    cout<<"enter the values of the two nodes joint by the vertices"<<"\n";
    for(int i=0;i<m;i++)
    {
        int c,b;
        cin>>b>>c;
        a[b].push_back(c);
    }
    queue<int>q;
    bool visited[m];
    int distance[m];
    int x;
    cout<<"enter node value from where search is to be done"<<"\n";
    cin>>x;
    visited[x]=true;
    distance[x]=0;
    q.push(x);
    while(q.empty()!=true)
    {
        int s=q.front();
        q.pop();
        cout<<s<<"distance="<<distance[s]<<"\n";
            for(auto i=a[s].begin();i!=a[s].end();i++)
            {
                if(visited[*i]==true)
                {
                    continue;
                }
                else
                {
                    q.push(*i);
                    visited[*i]=true;
                    distance[*i]=distance[s]+1;
                }
            }
    }
}
