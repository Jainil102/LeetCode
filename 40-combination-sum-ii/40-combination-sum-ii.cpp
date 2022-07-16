class Solution {
public:
    
    void solve(vector<int> arr, int i, vector<int> ds, int target, int sum, vector<vector<int>> &ans){
        if(sum > target){
            return;
        }
        
        if(i == arr.size()){
            if(sum == target){
                ans.push_back(ds);
            }
            return;
        }
        
        ds.push_back(arr[i]);
        solve(arr, i+1, ds, target, sum+arr[i], ans);
        
        ds.pop_back();
        int j;
        for(j=i; j<arr.size(); j++){
            if(arr[i] != arr[j]){
                break;
            }
        }
        solve(arr, j, ds, target, sum, ans);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates, 0, ds, target, 0, ans);
        return ans;
    }
};