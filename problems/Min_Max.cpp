//solution to the "Min Max"problem in hakerrrank
//greedy algorithm
//https://www.hackerrank.com/challenges/angry-children/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int smallest=1000000000;
    for(int i=0;i<=(n-x);i++)
    {
        int diff=a[i+x-1]-a[i];
        if(diff<smallest)
            smallest=diff;
    }
    cout<<smallest;
}