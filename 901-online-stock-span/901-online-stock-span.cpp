class StockSpanner {
public:
    stack<pair<int, int>> s;
    
    int next(int price) {
        int ans = 1;
        while(!s.empty()){
            if(s.top().first <= price){
                ans += s.top().second;
                s.pop();
            }
            else{
                break;
            }
        }
        s.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */