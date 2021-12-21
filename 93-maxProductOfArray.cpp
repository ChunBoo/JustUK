//given an array which has numbers,but not sure if they are positive or negative
//[-5,0,1,2,3,5],  the max product should be -5*-9*5

#include<algorithm>
#include<iostream>
#include<vector>

long getMaxProductOfArray( std::vector<int>& nums)
{
    std::sort(nums.begin(),nums.end());

    return std::max(nums[0]*nums[1]*nums[nums.size()-1],nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3]);
}


int main()
{

    std::vector<int> nums{-5,0,1,2,3,5};
    long product=getMaxProductOfArray(nums);
    std::cout<<"The max product is: "<<product<<"\n";
    return 0;
}