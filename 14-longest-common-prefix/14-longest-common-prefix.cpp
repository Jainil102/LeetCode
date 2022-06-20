class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        string ans = "";
        for(int i=0; i<strs[0].size(); i++){
            char c = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(strs[j].size() < i || c != strs[j][i]){
                    return ans;
                }
            }
            ans += c;
        }
        return ans;
    }
};