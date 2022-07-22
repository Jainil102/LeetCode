class StockSpanner {
public:
    stack<pair<int, int>> s;
    int ind = 0;
    
    int next(int price) {
        int ans;
        while(!s.empty()){
            if(s.top().first > price){
                ans = ind - s.top().second;
                break;
            }
            s.pop();
        }
        if(s.empty()){
            ans = ind+1;
        }   
        s.push({price, ind++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */