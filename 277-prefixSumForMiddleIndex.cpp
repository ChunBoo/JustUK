//前缀和算法求数组中间index,使得前后两部分的元素和相等

//前缀和算法求数组中间的下标值mIndex，可以实现sum(0,mIndex)=sum(mIndex+1,size-1)
#include<iostream>
#include<vector>
#include<numeric>  //std::accumulate

using DT=std::vector<int>;
int midIndex(const DT& nums)
{
    int sum=std::accumulate(nums.begin(),nums.end(),0);  //to get the sum of all array
    // int sum=std::accumulate(nums.begin(),nums.end(),0);
    int cur=0;
    for(int i=0;i<nums.size();++i)
    {
        if(sum-nums[i]-cur==cur)
            return i;
        cur+=nums[i];
    }
    return -1;
}

int main()
{
    DT nums{2,3,-1,8,-3};
    std::cout<<midIndex(nums);
    return 0;
}