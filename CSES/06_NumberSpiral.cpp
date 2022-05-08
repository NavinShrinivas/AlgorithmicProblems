#include<bits/stdc++.h> 

using namespace std;
typedef long long int ll;


//This is some myth ive come up all xy myself with 0 help from llernet, so pardon me if it doesnt make sense.


int main(){
    ll t;
    cin>>t;
    while(t){
        ll y,x;
        cin>>y>>x;
        ll myx = (y<x)?x:y;
        ll min = (y>=x)?x:y;
        /*
         *ll scope =  0+(myx-1)*2;
         *ll sum_scoope = (myx/2)*(0+scope);
         *ll scope_myx = sum_scoope + max+1;
         *cout<<scope_myx-(x+y-max)<<"\n";
         */
        //A lightbulb moment lyter :
        if (y>x){
            if (y%2==0) cout<<y*y -x+1;
            else cout<<(y-1)*(y-1) +x;
        }
        else{
            if (x%2==0) cout<<(x-1)*(x-1) +y;
            else cout<<x*x - y+1;
        }
        cout<<"\n";

        t--;
    }

}
