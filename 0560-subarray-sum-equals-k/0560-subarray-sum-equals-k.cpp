class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long,int> umap;
        int total = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            total += nums[i];
            if(total == k) ans++;
            if(umap.find(total-k) != umap.end()) { 
                ans += umap[total-k];
            }
            umap[total]++;
        }
        return ans;
    }
};