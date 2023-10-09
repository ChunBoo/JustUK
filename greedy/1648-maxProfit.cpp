class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        constexpr int kMod=1e9+7;
        const int n=inventory.size();
        sort(rbegin(inventory),rend(inventory));
        long cur=inventory[0],ans=0,c=0;
        while(orders){
            while(c<n&&inventory[c]==cur) ++c;
            int nxt=c==n?0:inventory[c];
            int cnt=min(static_cast<long>(orders),c*(cur-nxt));
            int t=cur-nxt, r=0;
            if(orders<c*(cur-nxt)){
                t=orders/c;
                r=orders%c;
            }
            ans=(ans+(cur+cur-t+1)*t/2*c+(cur-t)*r)%kMod;
            orders-=cnt;
            cur=nxt;
        }
        return ans;
    }
};