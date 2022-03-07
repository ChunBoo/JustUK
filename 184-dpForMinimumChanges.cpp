//given a list of coins and one target,return the minimum changes
//DP have two methods: top2Down and bottom2top
//bottom2top will calculate each value from 0,so should create one vector to record each elements
//top2Down will use recursion method 
#include<iostream>
#include<vector>
#include<cmath>

double  dpTop2Down(const std::vector<int>& coins, int target)
{
   if(target==0)
    return 0;

   double ans=INFINITY;
   for(auto c:coins)
   {
       double x = INFINITY;
       if(target>=c)
       {
           x=dpTop2Down(coins,target-c);
           if(x!=INFINITY)
             ans=std::min(x+1,ans);   //if used std::min, then the initialized value should be the maximum values
       }
   }
    return ans;
}




int dpBottom2Top(const std::vector<int>& coins,int target)
{
    if(target==0)
        return 0;
    
    std::vector<float> dp(target+1,INFINITY);
    dp[0]=0;
    for(int i=1;i<target+1;++i)
    {
        for(auto c:coins)
        {
            if(i>=c && dp[i-c]!=INFINITY)
            {
                dp[i]=std::min(dp[i-c]+1,dp[i]);
            }
        }
    }
    return static_cast<int>(dp[target]);
}


int main()
{
    std::vector<int> coins{1,5,20,25};
    std::cout<<dpTop2Down(coins,60)<<'\n';
    // std::cout<<"Result is:"<<dpBottom2Top(coins,60)<<'\n';
    return 0;
}