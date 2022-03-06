//given a list of coins and one target,return the minimum changes

#include<iostream>
#include<vector>
#include<cmath>




int dpTop2Down(const std::vector<int>& coins, int target)
{
    if(target==0)
        return 0;
    int ans=100;
    for(auto c:coins)
    {
        int x=100;
        if(c<=target)
        {
            x=dpTop2Down(coins,target-c);
            if(x!=100)
                ans=std::min(ans,x+1);

        }
    }
    return ans;
}



// int dp()
int dpBottom2Top(const std::vector<int>& coins,int target)
{
    std::vector<int> dp(target+1,100);
    dp[0]=0;
    for(int i=1;i<target+1;++i)
    {
        for(auto c:coins)
        {
            if(i>=c&&dp[i-c]!=-1)
            {
                dp[i]=std::min(dp[i-c]+1,dp[i]);
            }

        }
    }
    return dp[target];
}


int main()
{
    std::vector<int> coins{1,5,20,25};
    std::cout<<dpTop2Down(coins,60)<<'\n';
    return 0;
}