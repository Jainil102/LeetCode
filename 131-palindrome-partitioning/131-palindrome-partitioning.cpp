class Solution {
public:
    
    bool isPal(string str, int s, int t){
        while(s < t){
            if(str[s++] != str[t--]){
                return false;
            }
        }
        return true;
    }
    
    void solve(string s, int ind, vector<string> ds, vector<vector<string>> &ans){
        if(ind == s.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind; i<s.length(); i++){
            if(isPal(s, ind, i)){
                ds.push_back(s.substr(ind, i-ind+1));
                solve(s, i+1, ds, ans);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        solve(s, 0, ds, ans);
        return ans;
    }
};