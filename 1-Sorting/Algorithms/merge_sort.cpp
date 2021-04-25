//merge sort comes under divide and conquer paradigm
//merge sort uses recursion ofc
//O(nlogn) time complexity

#include<bits/stdc++.h>
#include<math.h>

#define long long int ll
using namespace std;

//void swap(int a[],int i,int j)
//{
    //int temp=a[i];
    //a[i]=a[j];
    //a[j]=temp;
//}

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
            i++; //I forgot add these in notes for merge sort...sowwie!
        }
        else
        {
            a[k]=R[j];
            j++; //forgot to add this too
        }
        k++;
    }
    //left out elements if any
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
    if(l>=r) //base case
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
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        int c;
        cin>>c;
        a[i]=c;
    }
    mergesort(a,0,n);
    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
}

