class Solution {
public:
    
    void solve(vector<int> arr, int ind, vector<int> ds, vector<vector<int>> &ans){
        if(ind == arr.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(arr[ind]);
        solve(arr, ind+1, ds, ans);
        
        ds.pop_back();
        int j;
        for(j=ind; j<arr.size(); j++){
            if(arr[j] != arr[ind]){
                break;
            }
        }
        solve(arr, j, ds, ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ds, ans);
        return ans;
    }
};