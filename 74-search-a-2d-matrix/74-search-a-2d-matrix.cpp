class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0;
        int h = m*n - 1;
        int m1,i,j;
        while(l <= h){
            m1 = l + (h-l)/2;
            i = m1/m;
            j = m1%m;
            
            if(target == matrix[i][j]){
                return true;
            }
            else if(target > matrix[i][j]){         
                l = m1 + 1;
            }
            else{
                h = m1 - 1;
            }
        }
        return false;
    }
};