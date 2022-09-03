class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int ind = -1;
        for(int i=0; i<num.length(); i++){
            if(num[i]%2 != 0){                
                ind = i;
            } 
        }
        return num.substr(0,ind+1);
    }
};