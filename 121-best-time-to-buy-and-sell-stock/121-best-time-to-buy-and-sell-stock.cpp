class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minB = prices[0];
        for(int i=1; i<prices.size(); i++){
            ans = max(ans, prices[i]-minB);
            minB = min(minB, prices[i]);
        }
        return ans;
    }
};