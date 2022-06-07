class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(target < matrix[0][0] || target > matrix[n-1][m-1]){
            return false;
        }
        
        int l = 0;
        int h = n-1;
        int m1;
        while(true){
            m1 = l + (h-l)/2;
            if(target == matrix[m1][0]){
                return true;
            }
            else if(target > matrix[m1][0]){
                if(m1 == n-1){
                    break;
                }
                if(target < matrix[m1+1][0]){
                    break;
                }         
                l = m1 + 1;
            }
            else{
                if(m1 == 0){
                    break;
                }
                if(target > matrix[m1-1][0]){
                    m1--;
                    break;
                }
                h = m1 - 1;
            }
        }
        
        int l2 = 0;
        int h2 = m-1;
        int m2;
        while(l2 <= h2){
            m2 = l2 + (h2-l2)/2;
            if(matrix[m1][m2] == target)
                return true;
            else if(matrix[m1][m2] > target)
                h2 = m2 - 1;
            else
                l2 = m2 + 1;
        }
        
        return false;
    }
};