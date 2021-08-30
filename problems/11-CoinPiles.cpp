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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int a,b;
        cin>>a>>b;
        if((a+b)%3==0 && min(a,b)*2>=max(a,b))
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
        t--;
    }
}
