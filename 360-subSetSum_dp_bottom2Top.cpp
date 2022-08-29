

#include<iostream>
#include<vector>
#include<numeric>
using VEC=std::vector<int>;
using TVEC=std::vector<VEC>;

bool canPartitionAsTwoSubSet(VEC& nums)
{
    int total=std::accumulate(nums.begin(),nums.end(),0);
    if(total&1)
        return false;

    int half=total/2,len=nums.size();

    TVEC dp(len,VEC(half,false));

    for(int i=0;i<len;++i)
        dp[i][0]=false;

    for(int i=len-2;i>-1;--i)
    {
        for(int j=half;j>-1;--j)
        {
            if(j<nums[i])
                dp[i][j]=dp[i+1][j];
            else
                dp[i][j]=dp[i+1][j]|| dp[i+1][j-nums[i]];
        }
    }
    return dp[0][half];
}

int main()
{
    VEC nums{1,5,6,11};
    std::cout<<canPartitionAsTwoSubSet(nums);
}