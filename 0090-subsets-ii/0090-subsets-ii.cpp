class Solution {
public:
    void solve(vector<int> arr, int i, vector<int> temp, vector<vector<int>> &ans){
        if(i == arr.size()){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(arr[i]);
        solve(arr, i+1, temp, ans);
        temp.pop_back();
        while(i<arr.size()-1 && arr[i] == arr[i+1]) i++;
        solve(arr, i+1, temp, ans);
        

        
        // solve(arr, i+1, temp, ans);
        // temp.push_back(arr[i]);
        // solve(arr, i+1, temp, ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums, 0, temp, ans);
        return ans;
    }
};