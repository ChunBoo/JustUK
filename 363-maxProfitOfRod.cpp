#include<vector>
#include<iostream>
//used one vector(dp) to save the intermediate values
using VEC=std::vector<int>;
int maxProfit(const VEC& prices,int n)
{
    VEC dp(n+1,0);
    for(int i=0;i<n+1;++i)
    {
        for(int j=0;j<i;++j)
        {
            dp[i]=std::max(dp[i],dp[i-j-1]+prices[j]);
        }
    }
    return dp[n];  
}

int main()
{
    VEC prices{1, 3, 5, 7, 7, 7};
    std::cout<<maxProfit(prices,6);
}