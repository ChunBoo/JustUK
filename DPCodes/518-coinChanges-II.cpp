// class Solution {
// public:
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         int ans=0;
//         dfs(n-1,amount,coins,ans);
//         return ans;
//     }
// private:
//     void dfs(int i, int c, const vector<int>& coins,int& ans)
//     {
//         if(i<0)
//         {
//             if(c==0)
//                 ans+=1;
//         }
//         if(c<coins[i])
//              dfs(i-1,c,coins,ans);
//         else 
//          dfs(i-1,c,coins,ans)+dfs(i,c-coins[i],coins,ans);
//     }
// };

class Solution{
    public:
        int change(int amount,vector<int>& coins){
            vector<int> dp(amount+1,0);
            dp[0]=1;
            for(const int coin:coins){
                for(int i=0;i<=amount-coin;++i)
                    dp[i+coin]+=dp[i];
            }
            return dp[amount];

        }
};

/**
 * @brief 
 * ，给定总金额 amount\textit{amount}amount 和数组 coins\textit{coins}coins，要求计算金额之和等于 amount\textit{amount}amount 的硬币组合数。其中，coins\textit{coins}coins 的每个元素可以选取多次，且不考虑选取元素的顺序，因此这道题需要计算的是选取硬币的组合数。

可以通过动态规划的方法计算可能的组合数。用 dp[x]\textit{dp}[x]dp[x] 表示金额之和等于 xxx 的硬币组合数，目标是求 dp[amount]\textit{dp}[\textit{amount}]dp[amount]。

动态规划的边界是 dp[0]=1\textit{dp}[0]=1dp[0]=1。只有当不选取任何硬币时，金额之和才为 000，因此只有 111 种硬币组合。

对于面额为 coin\textit{coin}coin 的硬币，当 coin≤i≤amount\textit{coin} \le i \le \textit{amount}coin≤i≤amount 时，如果存在一种硬币组合的金额之和等于 i−coini - \textit{coin}i−coin，则在该硬币组合中增加一个面额为 coin\textit{coin}coin 的硬币，即可得到一种金额之和等于 iii 的硬币组合。因此需要遍历 coins\textit{coins}coins，对于其中的每一种面额的硬币，更新数组 dp\textit{dp}dp 中的每个大于或等于该面额的元素的值。

由此可以得到动态规划的做法：

初始化 dp[0]=1\textit{dp}[0]=1dp[0]=1；

遍历 coins\textit{coins}coins，对于其中的每个元素 coin\textit{coin}coin，进行如下操作：

遍历 iii 从 coin\textit{coin}coin 到 amount\textit{amount}amount，将 dp[i−coin]\textit{dp}[i - \textit{coin}]dp[i−coin] 的值加到 dp[i]\textit{dp}[i]dp[i]。
最终得到 dp[amount]\textit{dp}[\textit{amount}]dp[amount] 的值即为答案。

上述做法不会重复计算不同的排列。因为外层循环是遍历数组 coins\textit{coins}coins 的值，内层循环是遍历不同的金额之和，在计算 dp[i]\textit{dp}[i]dp[i] 的值时，可以确保金额之和等于 iii 的硬币面额的顺序，由于顺序确定，因此不会重复计算不同的排列。

例如，coins=[1,2]\textit{coins}=[1,2]coins=[1,2]，对于 dp[3]\textit{dp}[3]dp[3] 的计算，一定是先遍历硬币面额 111 后遍历硬币面额 222，只会出现以下 222 种组合：

3=1+1+13=1+2\begin{aligned} 3 &= 1+1+1 \\ 3 &= 1+2 \end{aligned}
3
3
​
  
=1+1+1
=1+2
​
 
硬币面额 222 不可能出现在硬币面额 111 之前，即不会重复计算 3=2+13=2+13=2+1 的情况。


 * 
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int& coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

