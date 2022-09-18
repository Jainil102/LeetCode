class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        while(i>=0 && digits[i] == 9){
            digits[i--] = 0;
        }
        if(i < 0){
            digits.push_back(0);
            digits[0] = 1;
        }
        else{
            digits[i]++;
        }
        return digits;
    }
};