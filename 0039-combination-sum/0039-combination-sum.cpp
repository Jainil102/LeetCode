class Solution {
public:
    void solve(vector<int> arr, int i, int target, vector<int> temp, vector<vector<int>> &ans){
        if(target < 0) return;
        
        if(i == arr.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }
        
        solve(arr, i+1, target, temp, ans);
        temp.push_back(arr[i]);
        solve(arr, i, target-arr[i], temp, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, 0, target, temp, ans);
        return ans;
    }
};