class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int currA, li, maxA = 0;
        stack<int> s;
        int n = heights.size();
        for(int i=0; i<=n; i++){            
            while(!s.empty() && (i==n || heights[s.top()] > heights[i])){
                int currH = heights[s.top()];
                s.pop();
                li = s.empty() ? -1 : s.top();
                currA = currH * (i - li - 1);
                maxA = max(maxA, currA);
            }
            s.push(i);
        }
        return maxA;
    }
};