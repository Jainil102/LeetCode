class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        for(int i=1; i<=numRows; i++){
            vector<int> row;
            for(int j=1; j<=i; j++){
                if(j==1 || j==i){
                    row.push_back(1);
                }
                else{
                    row.push_back(pt[i-2][j-1] + pt[i-2][j-2]);
                }
            }
            pt.push_back(row);
        }
        return pt;
    }
};