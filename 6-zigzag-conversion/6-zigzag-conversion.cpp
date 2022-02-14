class Solution {
public:
    string convert(string s, int numRows) {
        int row = numRows;
        int n = s.length();
        if(n<=row || n<=2 || row==1){
            return s;
        }
        string ans;
        int iterator = 2*row-2;
        for(int i=0; i<row; i++){
            int j = i;
            ans.push_back(s[i]);
            while((j+iterator-(2*i))<n){
                j += iterator;
                if(i>0 && i<(row-1)){
                    ans.push_back(s[j-(2*i)]);
                }
                if(j<n)
                    ans.push_back(s[j]);
            }
        }
        return ans;
    }
};