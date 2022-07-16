class Solution {
public:
    void powerset(vector<int> arr, int i, vector<int> temp, vector<vector<int>> &ans){
        if(i >= arr.size()){
            ans.push_back(temp);
            return;
        }
        powerset(arr, i+1, temp, ans);
        temp.push_back(arr[i]);
        powerset(arr, i+1, temp, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        powerset(nums, 0, temp, ans);
        return ans;
    }
};