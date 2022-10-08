class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int flag = 1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                flag = 0;
                for(int j=i+1; j<=(n+i)/2; j++){
                    swap(nums[j], nums[n+i-j]);
                }
                
                for(int j=i+1; j<n; j++){
                    if(nums[j] > nums[i]){
                        swap(nums[j], nums[i]);
                        break;
                    }
                }
                break;
            }
        }
        if(flag){
            for(int i=0; i<n/2; i++){
                swap(nums[i], nums[n-1-i]);
            }               
        }
    }
};