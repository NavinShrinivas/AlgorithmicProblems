
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
int recursive_sum(int n , int b)
{
    if(n/b==1)
    {
        return n%b;
    }
    return (n%b)+recursive_sum(n/b,b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cout<<t;
    while(t)
    {
        int end_flag=0;
        int n,l,r;
        cin>>n>>l>>r;
        cout<<"HALO";
        for(int i=l;i<=r;i++)
        {
            cout<<"HALO";
            int sum=recursive_sum(n,i);
            if(sum==1) //1 is minimum anyhow
            {
                cout<<i<<"\n";
                end_flag=1;
                break;
            }
            if(end_flag==1)
                break;
        }
        t--;
    }
}
