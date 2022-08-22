class Solution {
public:
    int uniquePaths(int m, int n) {
        int k = n+m-2;
        int r = m - 1;
        double ans = 1.0;
        for(int i=1; i<=r; i++){
            ans = ans * (k-r+i) / i;
        }
        return (int)ans;
    }
};