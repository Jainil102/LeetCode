class Solution {
public:
    
    void solve(vector<int> nums, int i, vector<int> ds, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(nums[i]);
        solve(nums, i+1, ds, ans);
        
        ds.pop_back();
        int j;
        for(j=i; j<nums.size(); j++){
            if(nums[i] != nums[j]){
                break;
            }
        }
        solve(nums, j, ds, ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(nums, 0, ds, ans);
        return ans;
    }
};