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
    int t;
    cin>>t;
    while(t){
        ll k,l;
        cin>>k>>l;
        if(k>l){
            vector<int>kn(k,1);
            for(int i=1;i<=t-1;i++)
                kn.push_back(0);
            if(kn.size()/2 > t)
                cout<<kn[kn.size()/2]<<"\n";
            else{
                if(kn[kn.size()/2] == 9)
                    cout<<0<<"\n";
                else
                    cout<<kn[kn.size()/2]+1<<"\n";
            }
        }else{
            vector<int>kn(t,1);
            for(int i=1;i<=k-1;i++)
                kn.push_back(0);
            if(kn.size()/2 > k)
                cout<<kn[kn.size()/2]<<"\n";
            else{
                if(kn[kn.size()/2] == 9)
                    cout<<0<<"\n";
                else
                    cout<<kn[kn.size()/2]+1<<"\n";
            }

        }
t--;
    }
}
