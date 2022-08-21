class Solution {
public:
    
    double myPow(double x, int n) {
        long m = n;
        if(m < 0){
            m = -m;
        }
        double ans = 1.0;
        while(m > 0){
            if(m%2 == 0){
                x = x*x;
                m = m/2;
            }
            else{
                ans = ans*x;
                m--;
            }
        }

        if(n<0){
            ans = 1/ans;
        }
        
        return ans;
    }
};