class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        string temp = "";
        for(int i=0; i<num.length(); i++){
            if(num[i]%2 != 0){                
                temp.push_back(num[i]);
                ans += temp;
                temp = "";
            } 
            else{
                temp.push_back(num[i]);
            }
        }
        return ans;
    }
};