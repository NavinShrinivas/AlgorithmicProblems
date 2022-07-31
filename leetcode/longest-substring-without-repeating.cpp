
//Note : Most longest substring without repeasting can be solved in O(n) using maps


class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        // During initlia problem analysis, ive considered overlaping strings also to be valid 
        //O(n) solution using maps 
        int ans=0;
        map<char,int>m;
        //few corner cases : 
        if(s.length() == 1)
            return 1;
        if(s.length() == 0)
            return 0;

        int left_ptr = 0;
        int right_ptr = 1;
        m[s[left_ptr]]++;
        while(right_ptr != s.length()){
            if(m[s[right_ptr]] == 1){
                //second occurence between two ptrs still exists
                m[s[left_ptr]]--;
                left_ptr++;
                continue;
                //hence no counting distance between two ptrs
            }
            m[s[right_ptr]]++;
            if(right_ptr-left_ptr > ans){
                ans = right_ptr-left_ptr;
            }
            right_ptr++;
        }
       return ans+1; 
    }
};
