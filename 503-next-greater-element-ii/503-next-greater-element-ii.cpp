class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        stack<int> s;
        int n = nums.size();
        for(int i=n-1; i>=0; i--){
            s.push(nums[i]);
        }
        
        for(int i=nums.size()-1; i>=0; i--){
            while(!s.empty()){
                if(s.top() > nums[i]){
                    ans.push_back(s.top());
                    s.push(nums[i]);
                    break;
                }
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
                s.push(nums[i]);
            }
        }
        
        for(int i=0; i<ans.size()/2; i++){
            swap(ans[i], ans[ans.size()-i-1]);
        }
        return ans;
    }
};