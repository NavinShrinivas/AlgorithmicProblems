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
    int t;
    cin>>t;
    while(t)
    {
        int n,m_count,t_count;
        cin>>n;
        char a[n];
        for(int i=0;i<n;i++)
        {
            char c;
            cin>>c;
            a[i]=c;
        }
        t_count=0;
        m_count=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='T' && m_count==0)
                t_count++;
            else if(a[i]=='T' && m_count!=0)
            {
                if(t_count>0)
                {
                    t_count--;
                    m_count--;
                }
                else
                    continue;
            }
            else if(a[i]=='M')
                m_count++;
        }
        if(t_count==0 && m_count==0)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
        t--;
    }
}
