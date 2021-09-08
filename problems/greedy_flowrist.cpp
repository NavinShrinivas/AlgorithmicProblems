//solution to the "Greedy Flowrist" problem from hackerrank
//greedy algorithm 
//https://www.hackerrank.com/challenges/greedy-florist/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 int main()
 {
     int t,p;
     cin>>t>>p;
     int a[t];
    for(int i=0;i<t;i++)
        cin>>a[i];
    sort(a,a+t);
     int demi=0;
     int pur=0;
     int count=t-1;
     int ans=0;
     for(int i=0;i<t;i++)
     {
         ans=ans+((pur+1)*a[count]);
         count--;
         demi++;
         if(demi%p==0)
            pur++;
    }
    cout<<ans;
 }