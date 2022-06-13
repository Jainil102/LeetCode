class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0];
        int ele_count = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == ele){
                ele_count++;
            }
            else{
                ele_count--;
                if(ele_count == 0){
                    ele = nums[i];
                    ele_count = 1;
                }
            }
        }
        return ele;
    }
};