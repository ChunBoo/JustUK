class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n=prices.size();
        vector<int> min_prices(n);
        vector<int> max_profit(n);
        if(n<1)
            return 0;
        min_prices[0]=prices[0];
        max_profit[0]=0;

        for(int i=1;i<n;++i)
        {
            min_prices[i]=min(min_prices[i-1],prices[i]);
            max_profit[i]=max(max_profit[i-1],prices[i]-min_prices[i]);
        }
        return max_profit[n-1];
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n=prices.size();
        vector<int> gain(n-1,0);
        if(n<2) return 0;
        // gain[0]=0;
        for(int i=1;i<n;++i)
            gain[i-1]=prices[i]-prices[i-1];
        return max(0,maxSubArray(gain));
    }
private:
    int maxSubArray(vector<int>& nums)
    {
        vector<int> f(nums.size());
        f[0]=nums[0];
        for(int i=1;i<nums.size();++i )
        {
            f[i]=max(f[i-1]+nums[i],nums[i]);
        }
        return *max_element(begin(f),end(f));
    }
};