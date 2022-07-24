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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxR = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> currBuilding;
        for(int j=0; j<m; j++){
            currBuilding.push_back(matrix[0][j]-'0');
        }
        maxR = largestRectangleArea(currBuilding);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(currBuilding[j] == 0){
                    currBuilding[j] = matrix[i][j] - '0';
                }    
                else{
                    if(matrix[i][j] == '1'){
                        currBuilding[j]++;
                    }
                    else{
                        currBuilding[j] = 0;
                    }
                }
            }
            maxR = max(maxR, largestRectangleArea(currBuilding));
        }
        return maxR;
    }
};