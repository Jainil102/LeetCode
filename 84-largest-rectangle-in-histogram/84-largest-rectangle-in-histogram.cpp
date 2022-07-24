class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxA = 0;
        stack<int> s;
        int n = heights.size();
        for(int i=0; i<n; i++){
            if(s.empty() || heights[i] > heights[s.top()]){
                s.push(i);
                continue;
            }
            
            int currA;
            while(!s.empty() && heights[s.top()] > heights[i]){
                int currH = heights[s.top()];
                s.pop();
                int li = s.empty() ? -1 : s.top();
                currA = currH * (i - li - 1);
                maxA = max(maxA, currA);
            }
            s.push(i);
        }
        int currA;
        while(!s.empty()){
            int currH = heights[s.top()];
            s.pop();
            int li = s.empty() ? -1 : s.top();
            currA = currH * (n - li - 1);
            maxA = max(maxA, currA);
        }
        return maxA;
    }
};