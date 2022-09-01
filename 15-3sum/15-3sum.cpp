class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp(3);
        for(int i=0; i<n; i++){
            int target = -1*nums[i];
            int p = i+1;
            int q = n-1;
            while(p<q){
                int sum = nums[p] + nums[q];
                if(sum > target) q--;
                else if(sum < target) p++;
                else{
                    temp[0] = nums[i];
                    temp[1] = nums[p];
                    temp[2] = nums[q];
                    ans.push_back(temp);
                    while(p<q && nums[p]==temp[1]) p++;
                    while(p<q && nums[q]==temp[2]) q--;
                }
            }
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};