class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(umap.find(target-nums[i]) == umap.end()){
                umap[nums[i]] = i;
            }
            else{
                ans.emplace_back(umap[target-nums[i]]);
                ans.emplace_back(i);
                return ans;
            }
        }
        return ans;
    }
};