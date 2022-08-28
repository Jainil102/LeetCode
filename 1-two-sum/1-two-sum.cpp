class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            unordered_map<int, int>:: iterator itr = m.find(target - nums[i]);
            if(itr != m.end()){
                ans.push_back(i);
                ans.push_back(itr->second);
                break;
            }
            else{
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};