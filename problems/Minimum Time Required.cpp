 //solution to the "Minimum Time Required" problem ojn hackerrank
//my solution odes not pass all cases
//time complexity is much higher:O(n) needed:O(nlog(n))

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,order;
    cin>>n>>order;
    int a[n],b[n];//b acts as a copy array to know the reccuring value
    int manufactured=0;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        a[i]=t;
        b[i]=t;
    }
    // sort(a,a+n);
    // sort(b,b+n);
    int counter;
    while(order!=manufactured)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]==counter)
            {
                manufactured++;
                a[i]=a[i]+b[i];
            }
            
        }
        counter++;
    }
    // int semi=0;
    // for(int i=1;i<=order;i++)
    // {
    //     if(semi>=n)
    //     {
    //         semi=0;
    //     }
    //     if(a[semi]==i)
    //     {
    //         manufactured++;
    //         a[semi]=a[semi]+b[semi];
    //         semi++;
    //         counter=i;
    //     }
    //     else if(manufactured==order)
    //     {
    //         break;
    //     }
    // }
    counter--;
    cout<<counter;
}