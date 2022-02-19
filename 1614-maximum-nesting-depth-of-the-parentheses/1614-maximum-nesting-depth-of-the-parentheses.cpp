class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int S_len = 0;
        stack<char> S;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                S.push(s[i]);
                S_len++;
            }
            else if(s[i] == ')'){
                ans = max(ans, S_len);
                S.pop();
                S_len--;
            }
        }
        return ans;
    }
};