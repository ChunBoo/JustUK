//given one array,return the maximum value
#include<vector>
#include<iostream>

using DT=std::vector<int>;

int myMax(const DT& nums)
{
    
    int sz=nums.size(),mid=sz/2;
    if(sz==1)
        return nums[0];

    DT leftArray=DT(nums.begin(),nums.begin()+mid);
    DT rightArray=DT(nums.begin()+mid,nums.end());
    int leftMax=myMax(leftArray),rightMax=myMax(rightArray);
    if(leftMax<rightMax)
        return rightMax;
    return leftMax; 
}

int main()
{
    DT nums{2,16,23,4,9,0};
    std::cout<<myMax(nums);
    return 0;
}