//unbounded knapsack issue,used dp
//无限背包问题，DP解决
// given  a list of each weights and the target for the object, return how many methods can be implemented

#include<iostream>
#include<vector>

int getMethod2(const std::vector<int>& nums,int Target)   //bottom2top
{
    if(Target==0)
        return 1;

    std::vector<int> dp(Target+1,0);
    dp[0]=1;
    for(int i=1;i<Target+1;++i)
    {
        for(auto v:nums)
        {
            if(i>=v)
            {
                dp[i]+=dp[i-v];
            }
        }
    }
    return dp[Target];
}


int getMethods(const std::vector<int>& nums,int target)  //top2bottom
{
    int ans=0;
    if(target==0)
        ans+=1;
    
    for(auto v:nums)
    {
        if(target>=v)
        {
            ans+=getMethods(nums,target-v);
        }
    }
    return ans;
}



int main()
{
    std::vector<int> nums{1,2,3};
    std::vector<int> rVector{};
    int target=4;
    
    int res=0;
    // res=getMethods(nums,target);
    res=getMethod2(nums,target);
    std::cout<<res<<'\n';
    for(auto i:rVector)
    {
        if(9==i)
            std::cout<<'\n';
        else
            std::cout<<(i);
    }
        
    return 0;
}

