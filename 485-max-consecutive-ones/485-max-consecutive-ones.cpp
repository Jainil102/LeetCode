class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx = 0;
        int currMax = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]){
                currMax++;
            }
            else{
                maxx = max(maxx,currMax);                
                currMax = 0;
            }
        }
        return max(maxx,currMax);
    }
};