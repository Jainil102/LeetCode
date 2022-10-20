class Solution {
public:
    void solve(vector<int> arr, int i, int target, vector<int> temp, vector<vector<int>> &ans){
        if(target < 0) return;
        
        if(i == arr.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }
        
        temp.push_back(arr[i]);
        solve(arr, i+1, target-arr[i], temp, ans);   
        temp.pop_back();
        while(i<arr.size()-1 && arr[i] == arr[i+1]) i++;
        solve(arr, i+1, target, temp, ans);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, 0, target, temp, ans);
        return ans;
    }
};