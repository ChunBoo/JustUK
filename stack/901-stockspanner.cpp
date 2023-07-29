class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        int span=1;
        while(!s.empty()&&price>=s.top().first){
            span+=s.top().second;
            s.pop();
        }
        s.emplace(price,span);
        return span;
    }
private:
    stack<pair<int,int>> s;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */