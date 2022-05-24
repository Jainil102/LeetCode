class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;
        for(int i=0; i<nums.size(); i++){
            currSum += nums[i];
            if(currSum > maxSum){
                maxSum = currSum;
            }
            if(currSum <= 0){
                // if(nums[i] > maxSum){
                //     maxSum = nums[i];
                //     currSum = nums[i];
                // }
                // else{
                //     currSum = 0;
                // }
                currSum = max(0, nums[i]);
                maxSum = max(maxSum, nums[i]);
            }
        }
        return maxSum;
    }
};