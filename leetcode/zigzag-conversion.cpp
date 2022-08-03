class Solution {
    public:
    string convert(string s, int numRows) {
        int sviwel = 0;
        bool down = true;
        string ans_arr[numRows];
        for(int i=0;i<numRows;i++){
            ans_arr[i] = "";
        }
        
        if(numRows == 1){
            return s;
        }
        for(int i=0;i<s.length();i++){
            ans_arr[sviwel] += s[i];
            if(down && sviwel!=numRows-1){
                sviwel++;
            }else if(!down && sviwel!=0){
                sviwel--;
            }else if(down && sviwel==numRows-1){
                down = false;
                sviwel--;
            }else{
                down = true;
                sviwel++;
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            ans+=ans_arr[i];
        }
        return ans;
    }
};
