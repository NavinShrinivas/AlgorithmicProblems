//O(n^2) time complexity

#include<bits/stdc++.h>
#include<math.h>

#define long long int ll
using namespace std;

void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void insertionsort(int a[],int n)
{
    int c,p;
    c=1;
    while(c<n)
    {
        for(p=c;p>0;p--)
        {
            if(a[p]<a[p-1])
                swap(a,p,p-1);
        }
        c++;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        int c;
        cin>>c;
        a[i]=c;
    }
    insertionsort(a,n);
    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
}
