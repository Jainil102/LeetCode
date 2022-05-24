class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMax = prices[prices.size()-1];
        int maxProfit = 0;
        for(int i=prices.size()-2; i>=0; i--){
            currMax = max(currMax, prices[i]);
            maxProfit = max(maxProfit, currMax-prices[i]);
        }
        return maxProfit;
    }
};