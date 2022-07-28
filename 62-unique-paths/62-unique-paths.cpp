class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m , vector<int> (n));
        for(int i=0; i<n; i++){
            grid[m-1][i] = 1;
        }
        for(int i=0; i<m; i++){
            grid[i][n-1] = 1;
        }
        
        m = m-2;
        n = n-2;
        
        while(n>=0){
            for(int i=m; i>=0; i--){
                grid[i][n] = grid[i+1][n] + grid[i][n+1];
            }
            n--;
        }
        return grid[0][0];        
    }
};