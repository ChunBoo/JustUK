#include<iostream>
#include<vector>


using DT=std::vector<int>;
bool canJump(const DT& nums)
{
    int reach=0;
    for(int i=0;i<nums.size()&&i<=reach;++i)
        reach=std::max(reach,i+nums[i]);
    return reach>=nums.size()-1;
}

int main()
{
    DT nums{2,0,0};
    std::cout<<canJump(nums);
    return 0;
}