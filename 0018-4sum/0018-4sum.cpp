class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n-3; i++){
            for(int j = i+1; j<n-2; j++){
                long newT = (long)target - nums[i] - nums[j];
                int p = j+1;
                int q = n-1;
                while(p < q){
                    if((long)nums[p]+nums[q] == newT){
                        ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                        while(p<q && nums[p] == nums[p+1]){
                            p++;
                        }
                        p++;
                        while(p<q && nums[q] == nums[q-1]){
                            q--;
                        }
                        q--;
                    }
                    else if (nums[p]+nums[q] > newT){
                        q--;
                    }
                    else{
                        p++;
                    }
                }
                while(j<n-2 && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i<n-3 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};