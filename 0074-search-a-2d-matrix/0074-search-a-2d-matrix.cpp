class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n*m - 1;
        int mid,i,j;
        
        while(low <= high){
            mid = low + (high-low)/2;
            i = mid/m;
            j = mid%m;
            
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