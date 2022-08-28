class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> num;
        for(int i=0; i<nums.size(); i++){
            num.push_back({nums[i],i});
        }
        sort(num.begin(), num.end());
        int p = 0;
        int q = nums.size()-1;
        while(num[p].first + num[q].first != target){
            if(num[p].first + num[q].first > target) q--;
            else p++;
        }
        vector<int> ans;
        ans.push_back(num[p].second);
        ans.push_back(num[q].second);
        return ans;
    }
};