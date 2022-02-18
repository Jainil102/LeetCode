class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                S.push(s[i]);
            }
            else{
                if(S.empty()){
                    return false;
                }
                char c = S.top();
                S.pop();
                if(s[i] - c != 1 && s[i] - c != 2){
                    return false;
                }
            }
        }
        return S.empty();
    }
};