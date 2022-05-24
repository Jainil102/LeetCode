class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int currMax = prices[prices.size()-1];
        // int maxProfit = 0;
        // for(int i=prices.size()-2; i>=0; i--){
        //     currMax = max(currMax, prices[i]);
        //     maxProfit = max(maxProfit, currMax-prices[i]);
        // }
        int currMin = prices[0];
        int maxProfit = 0;
        for(int i=1; i<prices.size(); i++){
            currMin = min(currMin, prices[i]);
            maxProfit = max(maxProfit, prices[i]-currMin);
        }
        return maxProfit;
    }
};