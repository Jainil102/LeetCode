class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0.0){
            return 1.0;
        }
        
        int isNeg = 0;
        long m = n;
        if(n < 0){
            isNeg = 1;
            m = abs(n);
        }
        double ans = 1.0;
        
        while(m > 1){
            if(m%2 == 0){
                x = x*x;
                m = m/2;
            }
            else{
                ans = ans*x;
                m--;
            }
        }
        
        ans = ans*x;
        if(isNeg)
            ans = 1/ans;
        return ans;
    }
};