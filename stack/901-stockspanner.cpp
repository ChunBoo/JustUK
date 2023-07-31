
/**
 in the following 7 days prices is [100, 80, 60, 70, 60, 75, 85]，
the span will be [1, 1, 1, 2, 1, 4, 6]。
*/
#include<vector>
#include<iostream>
#include<stack>

using namespace std;

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

int main()
{
  vector<int> prices { 100, 80, 60, 70, 60, 75, 85 };
  StockSpanner *obj = new StockSpanner();
  for(const int p:prices)
    cout<<obj->next(p)<<',';
}