class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(auto coin:coins)
        {
            for(int i=coin;i<=amount;++i)
                dp[i]=min(dp[i],dp[i-coin]+1);
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};

/**
 * You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

 * 
*/

// // class Solution {
// // public:
// //     int coinChange(vector<int>& coins, int amount) {
// //         std::sort(coins.rbegin(),coins.rend()); //sort coins in descending order
// //         int ans =INT_MAX;
// //         dfs(coins,0,amount,0,ans);
// //         return ans==INT_MAX?-1:ans;

// //     }
// // private:
// //     void dfs(const vector<int>& coins,int s,int amount,int count, int& ans)
// //     {
// //         const int coin=coins[s];
// //         if(s==coins.size()-1)
// //         {
// //             if(amount%coin==0)
// //                 ans=min(ans,count+amount/coin);
// //         }
// //         else
// //         {
// //             for(int k=amount/coin;k>=00&&count+k<ans;--k)
// //                 dfs(coins,s+1,amount-k*coin,count+k,ans);
// //         }
// //     }
// // };

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         // Sort coins in desending order
//         std::sort(coins.rbegin(), coins.rend());
//         int ans = INT_MAX;
//         coinChange(coins, 0, amount, 0, ans);
//         return ans == INT_MAX ? -1 : ans;
//     }
// private:
//     void coinChange(const vector<int>& coins, 
//                     int s, int amount, int count, int& ans) {
//         if (amount == 0) {
//             ans = min(ans, count);
//             return;
//         }
        
//         if (s == coins.size()) return;
        
//         const int coin = coins[s];                
//         for (int k = amount / coin; k > 0 && count + k < ans; k--)
//             coinChange(coins, s + 1, amount - k * coin, count + k, ans);
//     }    
// };


class Solution{
    public:
        int coinChange(vector<int>& coins, int amount){
            vector<int> dp(amount+1,INT_MAX); //min coins to make up to amount i
            dp[0]=0;
            for(int coin:coins){
                for(int i=coin;i<=amount;++i)
                    if(dp[i-coin]!=INT_MAX)
                        dp[i]=min(dp[i],dp[i-coin]+1);
            }
            return dp[amount]==INT_MAX?-1:dp[amount];
        }
};