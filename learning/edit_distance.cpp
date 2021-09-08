//edit distance problem
//using dynamic programming

#include<bits/stdc++.h>

using namespace std;
int main(){
    string str1,str2;
    cout<<"enter starting string"<<"\n";
    cin>>str1;
    cout<<"enter ending string"<<"\n";
    cin>>str2;
    int n=str1.length();
    int m=str2.length();
    int distance[n+1][m+1];//this array always contains editdistance from [1] to [2]
    distance[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            char s1=str1[i-1];
            char s2=str2[j-1];
            if(i==0)
                distance[i][j]=j;
            else if(j==0)
                distance[i][j]=i;
            else if(s1==s2)
                distance[i][j]=distance[i-1][j-1];
            else{
                distance[i][j]=1+min({distance[i][j-1],distance[i-1][j],distance[i-1][j-1]});
            }
        }
    }
    cout<<"EDIT DISTANCE = "<<distance[n][m]<<"\n";
}