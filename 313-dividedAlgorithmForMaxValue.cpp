#include<vector>
#include<iostream>

using DT=std::vector<int>;

int myMax(const DT& nums)
{
    int sz=nums.size();
    if(sz==1)
        return nums[0];
    
    int mid=sz/2;
    auto leftNums=std::vector<int>(nums.begin(),nums.begin()+mid);
    auto rightNums=std::vector<int>(nums.begin()+mid,nums.end());

    int leftMax=myMax(leftNums),rightMax=myMax(rightNums);
    if(leftMax>rightMax)
        return leftMax;
    return rightMax;
}

int main()
{
    DT nums{2,16,1110,3,4,9,0};
    std::cout<<myMax(nums);
    return 0;
}