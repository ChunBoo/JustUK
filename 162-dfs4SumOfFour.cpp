//given a vector and a target number, return true if can find sum of four unique numbers is target,or return false

#include<iostream>
#include<vector>

bool sumOfFour(const std::vector<int>& nums,int left,int count,int target)
{
    if(nums.empty())
        return false;

    if(count==4)
        return target==0;
    if(left>nums.size()-1)
        return false;
    

    bool pick=sumOfFour(nums,left+1,count+1,target-nums[left]);
    bool notPick=sumOfFour(nums,left+1,count,target);

    return pick||notPick;
}

int main()
{
    std::vector<int> nums{1,2,3,4,5,6};
    bool res=sumOfFour(nums,0,0,21);
    std::cout<<res<<'\n';
    return 0;
}