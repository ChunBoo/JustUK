#include<iostream>
#include<vector>


using DT=std::vector<int>;
bool canJump(const DT& nums)
{
    int reach=0;
    int sz=nums.size();
    for(int i=0;i<sz&&i<=reach;++i)
    {
        reach=std::max(reach,i+nums[i]);
    }
    return reach>=sz-1;
}

int main()
{
    DT nums{1,2,0,2};
    std::cout<<canJump(nums);
    return 0;
}