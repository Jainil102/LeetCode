class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int n = a.length();
        int m = b.length();
        int diff = abs(n-m);
        if(n < m){
            for(int i=1; i<=diff; i++){
                a.insert(0, "0");
            }
            n = m;
        }
        else{
            for(int i=1; i<=diff; i++){
                b.insert(0, "0");
            }
        }
        
        int carry = 0;
        for(int i=n-1; i>=0; i--){
            int p = a[i] - '0' + b[i] - '0' + carry;
            if(p == 2){
                carry = 1;
                p = 0;
            }         
            else if(p == 3){
                carry = 1;
                p = 1; 
            }
            else{
                carry = 0;
            }
            ans.insert(0, 1, p+'0');
        }
        if(carry > 0){
            ans.insert(0, 1, carry+'0');            
        }
        return ans;
    }
};