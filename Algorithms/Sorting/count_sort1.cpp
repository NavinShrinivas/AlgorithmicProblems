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
    int n;
    cin>>n;
    int a[n];
    int count[n]={0};
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        a[i]=c;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j] < a[i])
                count[i]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(count[j] == i)
                cout<<a[j]<<" ";
        }
    }

}
