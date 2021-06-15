#include<bits/stdc++.h>
#include<math.h>

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
    map <int,int> m;
    int n;
    cin>>n;
    int largest=-intlimit;
    for(int i=0;i<n-1;i++)
    {
        int c;
        cin>>c;
        m[c]++;
        if(c>largest)
            largest=c;

    }
    for(int i=1;i<=n;i++)
    {
        if(m[i]==0)
        {
            cout<<i;
            break;
        }

    }
}
