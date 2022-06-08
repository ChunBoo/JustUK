#include<iostream>
#include<vector>


using DT=std::vector<int>;
bool canJump(const DT& nums)
{
    int reach=0,i=0,len=nums.size();
    for(;i<len&&i<=reach;++i)
    {
        reach=std::max(reach,nums[i]+i);
    }
    return reach>=len-1;
}

int main()
{
    DT nums{1,1,1,2};
    std::cout<<canJump(nums);
    return 0;
}