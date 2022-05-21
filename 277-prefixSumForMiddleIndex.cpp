//前缀和算法 的
#include<iostream>
#include<vector>
#include<numeric>

using DT=std::vector<int>;

int midIndex(const DT& nums)
{
    int sum=std::accumulate(nums.begin(),nums.end(),0);
    int c=0;
    for(int i=0;i<nums.size();++i)
    {
        if((sum-c-nums[i])==c)
            return i;
        c+=nums[i];
    }
    return -1;
}

int main()
{
    DT nums{2,3,-1,8,4};
    std::cout<<midIndex(nums);
    return 0;
}