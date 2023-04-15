class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(4,0));
        dp[0][0]=-prices[0];
        for(int i=1;i<n;++i)
        {
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][1]-prices[i],dp[i-1][3]-prices[i]));  //buy stock
            dp[i][1]=max(dp[i-1][1],dp[i-1][3]);    //keep state of saled
            dp[i][2]=dp[i-1][0]+prices[i];                             //sale the stock
            dp[i][3]=dp[i-1][2];
        }
        return max(dp[n-1][1],max(dp[i-1][2],dp[i-1][3]));
    }
};