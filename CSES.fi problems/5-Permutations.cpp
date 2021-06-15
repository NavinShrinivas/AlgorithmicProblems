#include<bits/stdc++.h>
#include<math.h>
//UNSOLVED  :((
typedef long long int ll;
#define intlimit 2147483647;
using namespace std;

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
    ll n;
    cin>>n;
    int a[n];
    vector<int>q;
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    else if(n<=3)
    {
        cout<<"NO SOLUTION";
    }
    else{
        int out=0;
        int pos=1;
        while(out!=n)
        {
            if(q.size()==0)
            {
                q.push(pos);
                pos+=2;
                out++;
            }
            else{
                if(q[])
            }
        }
    }
}