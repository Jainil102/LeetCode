class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int S_len = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                S_len++;
            }
            else if(s[i] == ')'){
                ans = max(ans, S_len);
                S_len--;
            }
        }
        return ans;
    }
};