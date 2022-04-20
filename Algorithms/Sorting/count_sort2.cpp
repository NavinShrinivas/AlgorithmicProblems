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
    int smallest = intlimit;
    int largest = 0;
    int n;
    cin>>n;
    int a[n];
    map<int,int> freq_map;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        a[i]=c;
        if(c<smallest)
            smallest = c;
        if(c>largest)
            largest = c;
        freq_map[c]++;
    }
    for(int i=smallest;i<=largest;i++){
        int freq = freq_map[i];
        for(int j=0;j<freq;j++)
            cout<<i<<" ";
    }
}
