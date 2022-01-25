//given a sorted array

#include<iostream>
#include<vector>

int bs(const std::vector<int>& nums,int left,int right,int target)
{
    if(left>right)
        return 0;

    while(left<=right)
    {
        int mid=(left+right)/2;
        if(nums[mid]==target)
            return mid;
        if(nums[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return 0;
}

int main()
{
    std::vector<int> nums{0,1,2,3,4,5,6,7};
    int sz=nums.size();
    for(int i=0;i<sz;++i)
    {
        int foundIndex=bs(nums,i+1,sz,5-nums[i]);
        if(foundIndex)
        {
            std::cout<<"Found the target number, index are:"<<i<<","<<foundIndex<<'\n';
        }
    }
    return 0;
}