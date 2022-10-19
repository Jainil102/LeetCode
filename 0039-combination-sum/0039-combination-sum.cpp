class Solution {
public:
    void solve(vector<int> arr, int i, int sum, int target, vector<int> temp, vector<vector<int>> &ans){
        if(sum > target) return;
        
        if(i == arr.size()){
            if(sum == target) ans.push_back(temp);
            return;
        }
        
        temp.push_back(arr[i]);
        solve(arr, i, sum+arr[i], target, temp, ans);
        temp.pop_back();
        solve(arr, i+1, sum, target, temp, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, 0, 0, target, temp, ans);
        return ans;
    }
};