#include <bits/stdc++.h>
#include<math.h>

#define long long int ll
using namespace std;

void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void bubblesort(int a[],int n)
{
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            if(a[j]>a[j+1]){
                swap(a,j,j+1);
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        int c;
        cin>>c;
        a[i]=c;
    }
    bubblesort(a,n);
    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }
}
