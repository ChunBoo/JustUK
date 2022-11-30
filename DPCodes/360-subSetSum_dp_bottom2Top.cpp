

#include<iostream>
#include<vector>
#include<numeric>  //for std::accumulate()
using VEC=std::vector<int>;
using TVEC=std::vector<VEC>;

bool canPartitionAsTwoSubSet(VEC& nums)
{
    int sum=std::accumulate(nums.begin(),nums.end(),0);
    if(sum&1)
        return false;
    int n=nums.size();
    TVEC dp(n,VEC(sum/2,false));

    for(int i=n-2;i>-1;--i)
    {
        for(int s=sum/2;s>-1;--s)
        {
            if(s<nums[i])
                dp[i][s]=dp[i+1][s];
            else
                dp[i][s]=dp[i+1][s]||dp[i+1][s-nums[i]];
        }
    }
    return dp[0][sum/2];
}

int main()
{
    VEC nums{1,5,5,11};
    std::cout<<canPartitionAsTwoSubSet(nums);
    return 0;
}