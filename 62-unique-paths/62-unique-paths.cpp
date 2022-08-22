class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> arr(n,1);
        for(int i=1; i<m; i++){
            for(int i=1; i<n; i++){
                arr[i] = arr[i] + arr[i-1];
            }
        }
        return arr[n-1];
    }
};