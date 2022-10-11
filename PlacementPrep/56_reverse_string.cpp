#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void reverseString(vector<char>& s){
      int len = s.size();
      for(int i=0;i<=ceil(len/2)-1;i++){
        char temp = s[len-i-1];
        s[len-i-1] = s[i];
        s[i] = temp;
      }
    }
};


