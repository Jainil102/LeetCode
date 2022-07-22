class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int temp;
        for(int i=prices.size()-1; i>=0; i--){
            temp = prices[i];
            while(!s.empty()){
                if(s.top() <= prices[i]){
                    prices[i] -= s.top();
                    break;
                }
                s.pop();
            }
            s.push(temp);
        }
        return prices;
    }
};