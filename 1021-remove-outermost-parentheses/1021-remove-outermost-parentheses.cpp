class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string ans = "";
        for(int i=1; i<s.length(); i++){
            if(s[i] == ')'){
                if(open != 0){
                    open--;
                    ans.push_back(s[i]);
                }
                else{
                    i++;
                }
            }
            else{
                open++;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};