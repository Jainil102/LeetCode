class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        while(i>=0 || j>=0){
            int p = (i>=0) ? a[i--]-'0' : 0;
            int q = (j>=0) ? b[j--]-'0' : 0;
            p = p + q + carry;
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