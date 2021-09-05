
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
        int n;
        cin>>n;
        int odd=0,even=0,ans=0;
        for(int i=0;i<n;i++)
        {
            int c;
            cin>>c;
            if(c%2==0)
                even++;
            else
                odd++;
        }
        if(n%2==0)
        {
            if(odd < n/2)//check for even number with indices , BIG BRAIN SOLN.
                ans+=odd;
            else
                ans+=n/2;

            if(even < n/2)
                ans+=even;
            else
                ans+=n/2;
        }
        else{
            if(odd < n/2)
                ans+=odd;
            else
                ans+=n/2;

            if(even < (n-(n/2)))
                ans+=even;
            else
                ans+=(n-(n/2));
        }
        cout<<ans<<"\n";
        
        t--;
    }
}

