#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
using std::cout;
using VEC=std::vector<int>;


int dp(const VEC &nums,int i,int s)
{
    if(i==0)
        return nums[i]*s;
    return nums[i]*s+std::max(0,dp(nums,i-1,s));
}

int maxSubarraySumCircular(const VEC &nums)
{
    int n=nums.size();
    int max_p=0,max_n=INT_MIN;
    for(int i=0;i<n;++i)
    {
        max_p=std::max(max_p,dp(nums,i,1));
        max_n=std::max(max_n,dp(nums,i,-1));
    }
    if(max_p<0)
        return max_p;
    return std::max(max_p,std::accumulate(nums.begin(),nums.end(),0)+max_n);
}

int main()
{
    VEC nums{1,-2,3,-2};
    cout<<maxSubarraySumCircular(nums);
}