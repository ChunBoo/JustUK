#include<vector>
#include<iostream>

bool isMaxHeap(std::vector<int>& nums)
{
    int sz=nums.size();

    for(int i=0;i<sz/2;++i)
    {
        if(((i*2+1)<sz)&& (nums[i]<nums[i*2+1]))
            return false;
        if(((i*2+2)<sz)&& (nums[i]<nums[i*2+2]))
            return false;
    }
    return true;
}

int main()
{
    std::vector<int> nums{100,9,98,97,97,95,94};
    std::cout<<isMaxHeap(nums);
    return 0;
}