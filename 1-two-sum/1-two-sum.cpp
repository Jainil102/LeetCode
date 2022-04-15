class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num = nums;
        sort(nums.begin(), nums.end());
        int p = 0;
        int q = nums.size()-1;
        while(nums[p] + nums[q] != target){
            if(nums[p]+nums[q] > target){
                q--;
            }
            else{
                p++;
            }
        }
        vector<int> ans;
        for(int i=0; i<num.size(); i++){
            if(num[i] == nums[p] || num[i] == nums[q]){
                ans.push_back(i);
            }
            if(ans.size() == 2){
                break;
            }
        }
        return ans;
    }
};