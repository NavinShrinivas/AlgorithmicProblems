
#include<bits/stdc++.h>
#include<math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;
#define loop(i , n) for(i;i<n;i++);
#define maploop(m) for(auto it=m.begin();it!=m.end();it++);

// void swap(int a[],int i,int j)
// {
//     int temp=a[i];
//     a[i]=a[j];
//     a[j]=temp;
// }
int main()
{
    int t;
    cin>>t;
    while(t)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n,xor_v;
        cin>>n>>xor_v;
        ll nums[n];
        map<ll , ll> repeat;
        map<ll , ll> moves;
        for(int i=0 ; i<n ; i++){
            int c;
            cin>>c;
            nums[i]=c;
            repeat[c]++;
        }
        for(int i=0 ; i<n ; i++)
        {
            repeat[nums[i]^xor_v]++;
            moves[nums[i]^xor_v]++;
        }
        int mode = repeat[nums[0]];
        int repval=nums[0];
        for(auto it=repeat.begin() ; it!=repeat.end() ; it++)
        {
            if(mode < it->second)
            {
                mode=it->second;
                repval = it->first;
            }
            else if(mode == it->second && moves[mode] > moves[it->first])
            {
                repval = it->first;
            }
        }
        cout<<mode<<" "<<moves[repval]<<"\n";
        t--;
    }
}
