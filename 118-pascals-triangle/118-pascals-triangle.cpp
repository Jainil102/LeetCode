class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=1; i<=numRows; i++){
            for(int j=i-2; j>0; j--){
                temp[j] += temp[j-1];
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};