class Solution {
public:
    
    void solve(string s, int i, string temp, vector<string> ds, vector<vector<string>> &ans){
        if(i == s.length()-1){
            temp += s[i];
            ds.push_back(temp);
            int flag = 0;
            for(int j=0; j<ds.size(); j++){
                int n = ds[j].size();
                for(int k=0; k<n/2; k++){
                    if(ds[j][k] != ds[j][n-k-1]){
                        flag = 1;
                        break;
                    }
                }
            }     
            if(flag == 0) ans.push_back(ds);
            return;
        }
        
        temp += s[i];
        solve(s, i+1, temp, ds, ans);
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