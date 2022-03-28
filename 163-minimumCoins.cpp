//given a fixed coins,likes [1,5,10,25],and target sum value,to return the minimum counts of coins for this targeted value

#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
//dp methods
//bottoms2Top
float DPForMinCountOfCoins(const std::vector<int>& coins,int value)
{
    if(value<=0)
        return 0;

    std::vector<float> dp(value+1,INFINITY);
    dp[0]=1;

    for(int i=1;i<value+1;++i)
    {
        for(auto c:coins)
        {
            if(value>=c && dp[i-c]!=INFINITY)
            {
                dp[i]=std::min(dp[i-c]+1,dp[i]);
            }
        }
    }
    return dp[value];
}


int countOfCoins(std::vector<int>& coins, std::vector<int>& res, int Value)  //greedy algorithm
{
    if(coins.empty())
        return 0;

    if(Value<=0)
        return 0;
    
    std::sort(coins.begin(),coins.end(),std::greater<int>());  //sorted the coins list from bigger to smaller
    int ans=0;
    for(auto c:coins)
    {
        int cnt=Value/c;
        if(cnt)
            res.push_back(c);
        ans+=cnt;
        Value-=cnt*c;
        if(Value==0)
            break;
    }
    return ans;  
}


int main()
{
    std::vector<int> coins{1,5,10,25};
    std::vector<int> res;
    int value=12;
    // std::cout<<countOfCoins(coins,res,value)<<'\n';
    std::cout<<DPForMinCountOfCoins(coins,12)<<'\n';
    for(auto c:res)
        std::cout<<c<<',';
    return 0;
}