class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = INT_MIN;
        int ca = 0;
        int b = INT_MIN;
        int cb = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == a) ca++;
            else if(nums[i] == b) cb++;
            else if(ca == 0){
                a = nums[i];
                ca = 1;
            }
            else if(cb == 0){
                b = nums[i];
                cb = 1;
            }
            else{
                ca--;
                cb--;
            }
        }
        ca = cb = 0;
        for(auto i : nums){
            if(i == a) ca++;
            else if(i == b) cb++;
        }
        vector<int> ans;
        if(ca > n/3) ans.push_back(a);
        if(cb > n/3) ans.push_back(b);
        return ans;
    }
};