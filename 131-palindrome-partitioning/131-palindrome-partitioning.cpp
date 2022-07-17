class Solution {
public:
    
    void solve(string s, int i, string temp, vector<string> ds, vector<vector<string>> &ans){
        if(i == s.length()-1){
            temp.push_back(s[i]);
            int n = temp.length();
            for(int j=0; j<n/2; j++){
                if(temp[j] != temp[n-j-1]){
                    return;
                }
            }
            ds.push_back(temp);
            ans.push_back(ds);
            return;
        }
        
        temp.push_back(s[i]);
        solve(s, i+1, temp, ds, ans);
        int n = temp.length();
        for(int j=0; j<n/2; j++){
            if(temp[j] != temp[n-j-1]){
                return;
            }
        }
        ds.push_back(temp);
        solve(s, i+1, "", ds, ans);
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(s, 0, "", ds, ans);
        return ans;
    }
};