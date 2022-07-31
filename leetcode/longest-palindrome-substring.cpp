class Solution {
    public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp_arr[n][n];
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                dp_arr[i][j] = false;
            }
        } 
        
        int max_len = 0;
        int start_index = 0;
        
        //len 1 substring are always palindrome 
        for(int i=0;i<n;i++){
            dp_arr[i][i] = true;
            max_len = 1; 
            start_index = i;
        }

        //calculating palindrome for substring of 2 : 
        //Note : we dont use the lower half of the dp_arr
        for(int i=0;i<n-1;i++){
            if (s[i] == s[i+1]){
                dp_arr[i][i+1] = true;
                max_len = 2;
                start_index = i;
            }
        }

        //for substrings greater than 2 : 
        //k is the length of substring we are searching for
        for(int k = 3 ; k <=n; k++){
            //To have a substring of atleast length k we need i to be less than n-k-1
            for(int i = 0; i <= n-k; i++){
                int j = i+k-1; //k is not index, its len hence -1, i->j len should be k

                if(dp_arr[i+1][j-1] && s[i] == s[j]){
                    dp_arr[i][j] = true;
                    if(k>max_len)
                    {
                        max_len = k;
                        start_index = i;
                    }
                }else{
                    dp_arr[i][j] = false;
                }
            } 
        }
        string ans = s.substr(start_index,max_len);
        return ans;
    }
};
