class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = INT_MIN,b = INT_MIN,ca = 0,cb = 0;
        for(int i=0; i<nums.size(); i++){
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
        
        vector<int> ans;
        ca = 0;
        cb = 0;
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] == a) ca++;
            else if (nums[i] == b) cb++;
        }
        
        if (ca > nums.size()/3) ans.push_back(a);
        if (cb > nums.size()/3) ans.push_back(b);
        return ans;
    }
};