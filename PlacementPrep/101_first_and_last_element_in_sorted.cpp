#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int initial_index = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == x){
            initial_index = i;
            break;
        }
    }
    cout<<initial_index<<"\n";
    if(initial_index == -1){
        vector<int> new_res;
        new_res.push_back(-1);
        new_res.push_back(-1);
        return new_res;
    }
    int end_index = initial_index;
    for(int i=initial_index;i<n;i++){
        if(arr[i] == x)
            end_index = i;
        else
            break;
    }
    vector<int> new_res;
    new_res.push_back(initial_index);
    new_res.push_back(end_index);
    return new_res;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
