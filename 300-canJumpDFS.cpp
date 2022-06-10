#include<iostream>
#include<vector>

using DT=std::vector<int>;
bool dfs(const DT& nums,int cur)
{
    int len=nums.size()-1;
    if(cur>=len)
        return true;
    for(int i=1;i<nums[cur]+1;++i)
    {
        if((i+cur>=len)||(dfs(nums,i+cur)))
            return true;
        // if(dfs(nums,i+cur))
        //     return true;
    }
    return false;
}
bool canJump(const DT& nums)
{
    return dfs(nums,0);
}

int main()
{
    DT nums{1,1,8,2};
    std::cout<<canJump(nums);
    return 0;
}