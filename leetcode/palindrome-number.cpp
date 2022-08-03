//DP solution
class Solution {
public:
    bool isPalindrome(int x) {
        //From solution : 
        //My first idea was to convert  to string and check if palindrome,
        
        
        if(x<0){
            return false;
        }if (x < 10){
            return true;
        }
        
        string s = to_string(x);
        int n=s.length();
        bool dp_arr[n][n];
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                dp_arr[i][j] = false;
            }
        } 
        int max_len = 1;
        
        //len 1 substring are always palindrome 
        for(int i=0;i<n;i++){
            dp_arr[i][i] = true;
            max_len = 1; 
        }

        //calculating palindrome for substring of 2 : 
        //Note : we dont use the lower half of the dp_arr
        for(int i=0;i<n-1;i++){
            if (s[i] == s[i+1]){
                dp_arr[i][i+1] = true;
                max_len = 2;
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
                    }
                }else{
                    dp_arr[i][j] = false;
                }
            } 
        }
        if (max_len == n){
            cout<<max_len;
            return true;
        }else{
            cout<<max_len;
            return false;
        }
        
        
        
    }
};
