#include<iostream>
#include<vector>

using DT=std::vector<int>;

bool canJump(const DT& nums)
{
    int len=nums.size();
    DT dp(len,0);
    dp[len-1]=1;
    for(int i=len-2;i>=0;--i)
    {
        int reach=std::min(nums[i]+i,len-1);
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
    DT nums{0,1,0,2};
    std::cout<<canJump(nums);
    return 0;
}