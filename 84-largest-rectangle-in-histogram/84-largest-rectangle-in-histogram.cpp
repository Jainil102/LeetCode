class Solution {
public:
    
    vector<int> NSR(vector<int> arr){
        vector<int> ans;
        stack<int> s;
        int n = arr.size();
        for(int i=n-1; i>=0; i--){
            while(!s.empty()){
                if(arr[s.top()] < arr[i]){
                    ans.push_back(s.top());
                    break;
                }
                s.pop();
            }
            if(s.empty()){
                ans.push_back(n);
            }   
            s.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> NSL(vector<int> arr){
        vector<int> ans;
        stack<int> s;
        for(int i=0; i<arr.size(); i++){
            while(!s.empty()){
                if(arr[s.top()] < arr[i]){
                    ans.push_back(s.top());
                    break;
                }
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }   
            s.push(i);
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl;
        vector<int> nsr;
        nsl = NSL(heights);
        nsr = NSR(heights);
        
        int ans = INT_MIN;
        for(int i=0; i<nsr.size(); i++){
            ans = max(ans, (nsr[i] - nsl[i] - 1)*heights[i]);
        }
        return ans;
    }
};