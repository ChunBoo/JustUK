#include<iostream>
#include<vector>

using DT=std::vector<int>;
bool dfs(const DT& nums,int cur)
{
    if(cur>=nums.size()-1)
        return true;

    for(int i=1;i<nums[cur]+1;++i)
    {
        if(cur+i>=nums.size())
            break;
        if(dfs(nums,i+cur))
            return true;
    }
    return false;
}
bool canJump(const DT& nums)
{
    return dfs(nums,0);
}

int main()
{
    DT nums{1,0,1,2};
    std::cout<<canJump(nums);
    return 0;
}