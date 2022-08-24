class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                count++;
                if(count > 1) 
                    return false;
            }
        }
        if(count==1 && nums[0]<nums[n-1]){
            return false;
        }
        return true;
    }
};