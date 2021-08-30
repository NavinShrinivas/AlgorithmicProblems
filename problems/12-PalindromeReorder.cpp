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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string raw;
    string rh="";
    string lh="";
    cin>>raw;
    map<char,int> supermap;
    for(int i=0;i<raw.length();i++)
    {   
        char c=raw[i];
        if(supermap[c]+1==2)
        {
            supermap[c]=0;
            lh+=c;
            rh+=c;
        }
        else
            supermap[c]++;
    }
    char center;int sum=0;

    for(auto i=supermap.begin();i!=supermap.end();i++)
    {
        sum+=i->second;
        if(i->second!=0)
            center=i->first;
    }
    reverse(rh.begin(),rh.end());
    if(raw.length()%2!=0 && sum==1)
    {
        cout<<lh<<center<<rh;
    }
    else if(raw.length()%2==0 && sum==0)
    {
        cout<<lh<<rh;
    }
    else
        cout<<"NO SOLUTION";
}