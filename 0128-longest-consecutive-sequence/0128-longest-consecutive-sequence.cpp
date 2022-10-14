class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i=0; i<nums.size(); i++){
            set.insert(nums[i]);
        }
        
        int ans = 0;
        int count;
        unordered_set<int> :: iterator it;
        for(it = set.begin(); it != set.end(); it++){
            int a = *it;
            if(set.find(a-1) == set.end()){
                count = 1;
                while(set.find(++a) != set.end()){
                    count++;
                }
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};