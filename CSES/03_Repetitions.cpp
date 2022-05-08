#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ll n;
    string s;
    cin>>s;
    n = s.length();
    int global_max = 0;
    int local_max = 1;

    int i=1;
    while(i<n){
        if(s[i] == s[i-1]){
            local_max++;
        }else{
            if(local_max > global_max)
                global_max = local_max;
            local_max = 1;
        }
        i++;
    }
    if(local_max > global_max)
        global_max = local_max;
    cout<<global_max;
    return 0;
}

