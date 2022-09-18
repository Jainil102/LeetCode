class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] != 9){
            digits[n-1]++;
            return digits;
        }
        
        int i = n-1;
        while(i>=0 && digits[i] == 9){
            digits[i--] = 0;
        }
        if(i < 0){
            digits.insert(digits.begin(), 1);
        }
        else{
            digits[i]++;
        }
        return digits;
    }
};