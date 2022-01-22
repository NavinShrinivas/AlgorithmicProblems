#include<bits/stdc++.h>
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

void permute(string s,map<string,int>&m){
    for(int i=0;i<s.length();i++){
        string p = s;
        char t = p[0];
        p[0]=p[i];
        p[i]=t;
        if(m[p] != 0)
            continue;
        else{
            m[p]++;
            permute(p,m);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,int>m;
    string s;
    cin>>s;
    m[s]++;
    permute(s,m);
    int n=0;
    for(auto it=m.begin();it!=m.end();it++){
        n+=1;
    
    }
    cout<<n<<"\n";
    for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<"\n";
}

//using a recursive solution with maps for a little speed adavantage.
