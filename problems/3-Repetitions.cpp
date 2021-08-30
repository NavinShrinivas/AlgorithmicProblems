#include<bits/stdc++.h>
#include<math.h>

typedef long long int ll;
#define intlimit 2147483647;
using namespace std;

// void swap(int a[],int i,int j)
// {
//     int temp=a[i];
//     a[i]=a[j];
//     a[j]=temp;
// }
int main()
{
    map<char,ll>m;
    map<char,ll>longest;
    string s;
    cin>>s;
    for(ll i=0;i<s.length();i++)
    {
        if(i==0)
            m[s[i]]++;
        else{
            if(s[i-1]!=s[i])
            {
                m[s[i]]=0;
                m[s[i]]++;
            }
            else
                m[s[i]]++;
        }
        if(longest[s[i]]<m[s[i]])
        {
            longest[s[i]]=m[s[i]];
        }
    }
    ll largest=-intlimit;
    for(auto i=longest.begin();i!=longest.end();i++)
    {
        if(i->second > largest)
            largest=i->second;
    }
    cout<<largest;
    //ok so this is a test lol
}
