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
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    string s2,s3;
    cin>>s;
    int goodness=0;
    int work=0;
    if(n%2==0){
        for(int i=0;i<(n/2);i++)
            s2+=s[i];
        for(int i=n/2;i<n;i++)
            s3=+=s[i];
    }
    else{
        for(int i=0;i<(n/2);i++)
            s2+=s[i];
        for(int i=(n/2)+1;i<n;i++)
            s3=+=s[i];
        
    }
    // for(int i=1;i<(n/2);i++)
    // {
    //     if(s[i-1]==s[n-i] && goodness<k)
    //     {
    //         goodness++;
    //     }
    //     else if (s[i-1]!=s[n-i] && goodness<k){
    //         work++;
    //     }
    // }
    cout<<"Case #1:"<<work;
}
