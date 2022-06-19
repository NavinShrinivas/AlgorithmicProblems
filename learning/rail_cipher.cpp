
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter text to encrypt : ";
    string S;
    getline(cin,S);
    
    cout<<"Enter value for key : ";
    int key;
    cin>>key;
    string answer_lines[key];
    S.erase(remove_if(S.begin(), S.end(), ::isspace),S.end());
    int mod_value = (2*key) - 2;
    int switcher = 0;
    
    for(int i=0;i<S.length();i++){
        int res = i%mod_value;
        if(res >= key){
            int diff = res-(key-1);
            res = (key-1)-diff;
        }
        answer_lines[res]+=S[i];
        for(int j=0;j<key;j++){
            if(j!=res){
                answer_lines[j]+=".";
            }
        }
    }
    for(int j=0;j<key;j++){
        cout<<answer_lines[j]<<"\n";   
    }
    return 0;
    
}
