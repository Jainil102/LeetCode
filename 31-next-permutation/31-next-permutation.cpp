class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int isPermuted = 0;
        int n = nums.size();
        for(int i=n-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                int max = INT_MAX;
                int max_id = -1;
                for(int j=i; j<n; j++){
                    if(nums[j] > nums[i-1] && nums[j] < max){
                        max = nums[j];
                        max_id = j;
                    }
                }
                swap(nums[i-1], nums[max_id]);
                sort(nums.begin()+i, nums.end());
                isPermuted = 1;
                break;
            }
        }
        if(isPermuted == 0){
            sort(nums.begin(), nums.end());
        }
    }
};