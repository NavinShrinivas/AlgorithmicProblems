#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long int ll;

//Backtraking solution 

ll n;
int check_fn(vector<int>* a){
    for(int i=1;i<a->size();i++){
        if(abs(a->at(i)-a->at(i-1)) == 1)
            return 0;

    }
    return 1;
}

int recurse_backtrack(int* visisted,int* visisted_so_far,vector<int>* order,int new_e){
    visisted[new_e] = 1;
    *visisted_so_far = *visisted_so_far+1;
    order->push_back(new_e);
    int check = check_fn(order);
    if(*visisted_so_far == n && check){
        return 1;
    }else if(*visisted_so_far == n){ //If is one end point but no valid
        order->pop_back();
        visisted[new_e] = 0;
        *visisted_so_far = *visisted_so_far-1;
        return 0;
    }
    else if(check){ //If not end point and is valid
        for(int i=0;i<n;i++){
            int res = 0 ;
            if(visisted[i]!= 1 && i!=new_e){
                res = recurse_backtrack(visisted,visisted_so_far,order,i);
                if(res == 1){
                    return res; //escape sequence
                }
            }
        }
    }
    //Not end point and not valid
    order->pop_back();
    visisted[new_e] = 0;
    *visisted_so_far = *visisted_so_far-1;
    return 0;
}


int main()
{
    cin>>n;


    for(int i=0;i<n;i++){
        vector<int> order;
        int visisted[n];
        for(int i=0;i<n;i++)
            visisted[i] = 0;
        int visisted_so_far = 0;
        int res = recurse_backtrack(visisted,&visisted_so_far,&order,i);
        if(res == 0){
            continue;
        }
        if(res == 1){
            for(int i=0;i<order.size();i++){
                cout<<order[i]+1<<" ";
            }
            return 0;

        }
    }
    cout<<"NO SOLUTION";
    return 0;
}

