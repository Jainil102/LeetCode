class Solution {
public:
    vector<vector<int>> ans;
    
    void powerset(vector<int> arr, int i, vector<int> temp){
        if(i >= arr.size()){
            ans.push_back(temp);
            return;
        }
        powerset(arr, i+1, temp);
        temp.push_back(arr[i]);
        powerset(arr, i+1, temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        powerset(nums, 0, temp);
        return ans;
    }
};