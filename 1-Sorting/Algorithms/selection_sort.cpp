//Selection sort algorithm
//O(n^2) time complexity [not efficient]
//O(n) space complexity [Decent efficiency]

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


void selectionsort(int a[] , int n)
{
    for(int i=n-1 ; i>=0 ; i--)
    {
        int largest=a[0];
        int largest_pos=0;
        for(int j=0 ; j<=i ; j++)
        {
            if(largest<a[j])
            {
                largest_pos=j;
                largest=a[j];
            }
        }
        swap(a,i,largest_pos);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ;i++)
    {
        int c;
        cin>>c;
        a[i]=c;
    }
    selectionsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

