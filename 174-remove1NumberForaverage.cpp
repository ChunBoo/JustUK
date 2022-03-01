//given one vector of numbers,remove one number of it
//return true if the remaining numbers average is equal to target 
#include<vector>
#include<iostream>
#include<numeric>
bool isCanBeAverage(std::vector<int>& nums,int sz,int target)
{
    int sum=0;
    // int sz=nums.size();
    if(sz<=0)
        return false;
    sum=std::accumulate(nums.begin(),nums.end(),0);
    for(int i=0;i<sz;++i)
    {
        if(nums[i]==(sum-target*(sz-1)))
            return true;
    }
    return false;
}

int main()
{
    std::vector<int> nums{1,2,3,10};
    // int nums[]={1,2,3,10};
    std::cout<<isCanBeAverage(nums,4,2);
    return 0;
}