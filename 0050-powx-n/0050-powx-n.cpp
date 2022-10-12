class Solution {
public:
    double myPow(double x, int m) {
        int isNeg = 0;
        long long n = m;
        if(m<0){
            isNeg = 1;
            n = -1*(long long)m;
        }
        double ans = 1;
        while(n > 0){
            if(n%2 == 0){
                x = x*x;
                n = n/2;
            }
            else{
                ans = ans*x;
                n = n-1;
            }
        }
        if(isNeg){
            ans = 1/ans;   
        }
        return ans;
    }
};