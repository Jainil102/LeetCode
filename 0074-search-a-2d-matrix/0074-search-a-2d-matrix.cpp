class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(target > matrix[n-1][m-1] || target < matrix[0][0]){
            return false;
        }
        
        int low = 0;
        int high = n*m - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int i = mid/m;
            int j = mid%m;
            if(matrix[i][j] == target){
                return true;
            }
            else if (matrix[i][j] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
        
    }
};