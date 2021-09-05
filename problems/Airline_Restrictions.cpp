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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t)
    {
        int chk , carry;
        int a[3];
        cin>>a[0]>>a[1]>>a[2]>>chk>>carry;
        if(a[0]<=carry && a[1]+a[2]<=chk)
            cout<<"YES";
        else if(a[1]<=carry && a[0]+a[2]<=chk)
            cout<<"YES";
        else if(a[2]<=carry && a[0]+a[1]<=chk)
            cout<<"YES";
        else
            cout<<"NO";

        t--;
    }
}
