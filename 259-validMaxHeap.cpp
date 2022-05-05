#include<vector>
#include<iostream>
//given a vector of integers,return if those numbers can be a max heap(root is larger than it's children)
bool isMaxHeap(std::vector<int>& nums)
{
    if(nums.empty())
        return false;
    int sz=nums.size();
    for(int i=0;i<sz/2;++i)
    {
        if((i*2+1<sz)&&nums[i]<nums[i*2+1])  //should larger than its left child
            return false;
        if((i*2+2)&&nums[i]<nums[i*2+2])    //should add the ranges check
            return false;
    }
    return true;
}

int main()
{
    std::vector<int> nums{100,99,98,97,97,95,94};
    std::cout<<isMaxHeap(nums);
    return 0;
}