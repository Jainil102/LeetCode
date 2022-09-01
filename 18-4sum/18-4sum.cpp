class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();        
        vector<vector<int>> ans;
        vector<int> arr(4);
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int temp = nums[i];
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
                        while(p<n && nums[p] == arr[2]) p++;
                        while(q>=0 && nums[q] == arr[3]) q--;
                    }
                    else if(nums[p] + nums[q] < newTarget) p++;
                    else q--;
                }
                while(j<n && nums[j] == arr[1]) j++;
                j--;
            }
            while(i<n && nums[i] == temp) i++;
            i--;
        }
        return ans;
    }
};