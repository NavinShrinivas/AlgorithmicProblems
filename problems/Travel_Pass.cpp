#include<bits/stdc++.h>
#include<math.h>
#include<string>
#include <cstdlib>

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
    int t;cin>>t;
    while(t)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int ans=0;
        string c;
        cin>>c;
        for(int i=0;i<n;i++)
        {
            if((int)c[i]==48)
                ans+=a;
            else
                ans+=b;
        }
        cout<<ans<<"\n";
        t--;
    }
}
