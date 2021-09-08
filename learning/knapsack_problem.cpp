//knapsack problem solution
//using dynamic programming
//the problem given in the book and gfg is diffrent but same logic can
//be used for both
//the current implementation of knapsack here gives a sementation fault
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout<<"enter number of weights"<<"\n";
    cin>>n;
    int w[n];
    cout<<"enter value of weights"<<"\n";
    int total=0;
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
        total=total+w[i];
    }
    bool possible[total+1][n+1];
    possible[0][0]=true;
    // int single[total+1];
    // single[0]==0;
    // int count=1;
    for(int k=1;k<=n;k++)
    {
        for(int x=0;x<=total;x++)
        {
            if(x-w[k]>0)
                possible[x][k]|=possible[x-w[k]][k-1];
            possible[x][k]|=possible[x][k-1];

            // if(possible[x][k])
            // {
            //     single[count]==x;
            //     count++;
            // }
        }

    }
//     cout<<"cin weight with number of weights to be used to check viability"<<"\n";
//     int m,z;
//     cin>>m>>z;
//     if(possible[m][z])
//         cout<<"yes"<<"\n";
//     else
//         cout<<"NO"<<"\n";
for(int k=1;k<=n;k++)
{
    for(int x=0;x<=total;x++)
    {
        if(possible[x][k]==true)
            cout<<"YES"<<" ";
        else
            cout<<"NO"<<" ";    
    }    
    cout<<"\n";   
}
}