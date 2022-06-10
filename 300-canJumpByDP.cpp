#include<iostream>
#include<vector>

using DT=std::vector<int>;

bool canJump(const DT& nums)
{
    int n=nums.size();
    DT dp(n,0);
    dp[n-1]=1;
    for(int i=n-2;i>=0;--i)
    {
        int reach=std::min(n-1,i+nums[i]);
        for(int j=i;j<=reach;++j)
        {
            if(dp[j])
                dp[i]=1;
        }
    }
    return dp[0];
}

int main()
{
    DT nums{1,1,0};
    std::cout<<canJump(nums);
    return 0;
}