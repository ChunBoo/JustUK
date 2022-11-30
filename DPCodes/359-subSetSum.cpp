#include<iostream>
#include<vector>
#include <numeric>

#include<map>
#include<algorithm>
using MAP=std::map<int,bool>;
using VEC=std::vector<int>;

bool dfs(const VEC& nums,int left,int sum)
{
    if(left==nums.size())
        return sum==0;
    if(sum<0)
        return false;
    return dfs(nums,left+1,sum-nums[left]) || dfs(nums,left+1,sum);
}
bool isCanPartitionSum(const VEC& nums)
{
    int n=nums.size();
    auto sum=std::accumulate(nums.begin(),nums.end(),0);
    if(sum&1)
        return 0;
    
    return dfs(nums,0,sum/2);
}

int main()
{
    VEC nums{1,6,6,11};
    std::cout<<isCanPartitionSum(nums);
    return 0;
}