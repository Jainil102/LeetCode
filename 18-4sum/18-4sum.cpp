class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();        
        vector<vector<int>> ans;
        vector<int> arr(4);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long newTarget = (long)target - nums[i] - nums[j];
                arr[0] = nums[i];
                arr[1] = nums[j];
                int p = j+1;
                int q = n-1;
                while(p<q){
                    if((long)nums[p] + nums[q] == newTarget){
                        arr[2] = nums[p];
                        arr[3] = nums[q];
                        ans.push_back(arr);
                        while(p<q && nums[p] == arr[2]) p++;
                        while(p<q && nums[q] == arr[3]) q--;
                    }
                    else if(nums[p] + nums[q] < newTarget) p++;
                    else q--;
                }
                while(j<n-1 && nums[j] == nums[j+1]) j++;
            }
            while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};