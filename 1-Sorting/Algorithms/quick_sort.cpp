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

int pivotplacer(int a[],int l,int r)
{
    int i=l;
    int pivot=a[r];
    //higly experimental code
    // for(int j=l;j<r;j++)
    // {
    //     if(a[j]>pivot && i==l-1)
    //     {
    //         i=j;
    //     }
    //     else if(a[j]<pivot && i!=l-1)
    //     {
    //         swap(a,i,j);
    //         i=j;
    //     }
    // }
    for (int j=l;j<r;j++)
    {
        if(a[j]<pivot)
        {
               swap(a,i,j);
               i++;
        }
    }
    swap(a,i,r);
    return i;
}

void quicksort(int a[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
    int pi=pivotplacer(a,l,r);
    quicksort(a,l,pi-1);
    quicksort(a,pi+1,r);
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
    quicksort(a,0,n);
    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
}

