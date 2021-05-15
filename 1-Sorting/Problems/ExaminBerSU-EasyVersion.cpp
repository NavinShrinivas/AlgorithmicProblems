#include<bits/stdc++.h>
#include<math.h>

#define long long int ll
using namespace std;

// void swap(int a[],int i,int j)
// {
//     int temp=a[i];
//     a[i]=a[j];
//     a[j]=temp;
// }
void comparedmerge(int a[],int l,int m,int r)
{
    int l_n=(m-l+1);
    int r_n=r-m;
    int L[l_n],R[r_n];
    for(int i=0;i<l_n;i++)
        L[i]=a[l+i];
    for(int i=0;i<r_n;i++)
        R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<l_n && j<r_n)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<l_n)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<r_n)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}



void mergesort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int m=(l+r-1)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    comparedmerge(a,l,m,r);
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    int ans[n];
    for(int i=0 ; i<n ; i++){
        int c;
        cin>>c;
        a[i]=c;
    }
    // mergesort(a,0,n);
    for(int i=0;i<n;i++)
    {
        int sum=0;
        sum+=a[i];
        int count=0;
        sort(a,a+i+1);
        for(int j=0;j<i;j++)
        {
            sum+=a[j];
            if(sum>m)
            {
                sum-=a[j];
                count++;
            }
        }
        ans[i]=count;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
