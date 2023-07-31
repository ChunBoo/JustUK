/**
未来7天价格是 [100, 80, 60, 70, 60, 75, 85]，
跨度将是 [1, 1, 1, 2, 1, 4, 6]。
*/

class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        if(i==0||price<prices.back()){
            dp.push_back(1);
        }
        else{
            int j=i-1;
            while(j>=0&&price>=prices[j]){
                j-=dp[j];
            }
            dp.push_back(i-j);
        }
        ++i;
        prices.push_back(price);
        return dp.back();
    }
private:
    vector<int> dp;
    vector<int> prices;
    int i=0;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */