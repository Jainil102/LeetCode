class Solution {
public:
    
    vector<int> NSR(vector<int> arr){
        vector<int> ans;
        stack<pair<int,int>> s;
        int n = arr.size();
        for(int i=n-1; i>=0; i--){
            while(!s.empty()){
                if(s.top().first < arr[i]){
                    ans.push_back(s.top().second);
                    break;
                }
                s.pop();
            }
            if(s.empty()){
                ans.push_back(n);
            }   
            s.push({arr[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> NSL(vector<int> arr){
        vector<int> ans;
        stack<pair<int,int>> s;
        for(int i=0; i<arr.size(); i++){
            while(!s.empty()){
                if(s.top().first < arr[i]){
                    ans.push_back(s.top().second);
                    break;
                }
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }   
            s.push({arr[i], i});
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl;
        vector<int> nsr;
        nsl = NSL(heights);
        nsr = NSR(heights);
        for(int i=0; i<nsr.size(); i++){
            nsr[i] = nsr[i] - nsl[i] - 1;
            nsr[i] *= heights[i];
        }
        int ans = nsr[0];
        for(int i=1; i<nsr.size(); i++){
            ans = max(ans, nsr[i]);
        }
        return ans;
    }
};