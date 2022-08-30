

#include<iostream>
#include<vector>
#include<numeric>  //for std::accumulate()
using VEC=std::vector<int>;
using TVEC=std::vector<VEC>;

bool canPartitionAsTwoSubSet(VEC& nums)
{
    int total=std::accumulate(nums.begin(),nums.end(),0);
    if(total&1)
        return false;

    int half=total/2,n=nums.size();

    TVEC dp(n,VEC(half,false));  // row is the index, column is the left subset's sum

    for(int i=0;i<n;++i)
        dp[i][0]=true;

    for(int i=n-2;i>-1;--i)
    {
        for(int j=half;j>-1;--j)
        {
            if(j<nums[i])
                dp[i][j]=dp[i+1][j];
            else
            {
                dp[i][j]=dp[i+1][j]||dp[i+1][j-nums[i]];
            }
        }
    }
    return dp[0][half];
}

int main()
{
    VEC nums{1,5,5,11};
    std::cout<<canPartitionAsTwoSubSet(nums);
}