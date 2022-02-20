class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int n = x;
        long long temp = 0;
        while(n){
            temp = temp*10 + (n%10);
            n = n/10;
        }
        if(x==temp){
            return true;
        }
        else{
            return false;
        }
    }
};