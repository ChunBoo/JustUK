#include<iostream>
#include<vector>
using VEC=std::vector<int>;  
int dfs(int n,VEC& prices)  //top2bottom DP method
{
    if(n<=0)
        return 0;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans=std::max(ans,dfs(n-i-1,prices)+prices[i]);
    }
    return ans;
}

int maxProfitBottom2Top(int n,VEC& prices) //Bottom2Top
{
    if(n<=0)
        return 0;

    VEC dp(n,0);
    dp[0]
    for(int i=0;i<n;++i)
    {
        dp[i]
    }
}


int maxProfit(int n,VEC& prices)
{
    return dfs(n,prices);
}

int main()
{
    VEC prices{1, 3, 5, 7, 7, 7};
    std::cout<<maxProfit(6,prices);
}