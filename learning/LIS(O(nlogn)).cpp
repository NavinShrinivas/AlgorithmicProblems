//learning dp with LIS
//spent around 8 hrs to lean and understand this properly
#include<bits/stdc++.h>

using namespace std;

int LIS_function(vector<int>v)
{
    if(v.size()==0)
        return 0;
    
    vector<int>tail (v.size(),0);

    tail[0]=v[0];
    int length=1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<tail[0])
            tail[0]=v[i];
        else if(v[i]>tail[length-1])
            tail[length++]=v[i];
        else
        { 
            auto it=upper_bound(tail.begin(),tail.begin()+length,v[i]-1);
            *it=v[i];
        }
    }
    return length;
}

int main()
{
    cout<<"enter number of elements"<<"\n";
    int n;
    cin>>n;
    vector<int> v(n);
    cout<<"enter all the elements"<<"\n";
    for(int i=0;i<n;i++)cin>>v[i];
    int ans=LIS_function(v);
    cout<<"the LIS for given array is "<<ans;
}