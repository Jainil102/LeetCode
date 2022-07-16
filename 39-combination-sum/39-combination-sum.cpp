class Solution {
public:
    void solve(vector<int> arr, int i, vector<int> temp, int target, vector<vector<int>> &ans){
        if(target < 0 || i >= arr.size()){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        solve(arr, i+1, temp, target, ans);
        temp.push_back(arr[i]);
        solve(arr, i, temp, target-arr[i], ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, temp, target, ans);
        return ans;
    }
};