#include<iostream>
#include<vector>

std::vector<int> merge(std::vector<int>& left,std::vector<int>& right)
{
    std::vector<int> ret;
    int lsz=left.size();
    int rsz=right.size();
    int lidx=0,ridx=0;

    while(lidx<lsz && ridx<rsz)
    {
        if(left[lidx]<=right[ridx])
        {
            ret.push_back(left[lidx]);
            lidx++;
        }
        else
        {
            ret.push_back(right[ridx]);
            ridx++;
        }
    }
    if(lidx<lsz)
    {
        for(;lidx<lsz;++lidx)
        {
            ret.push_back(left[lidx]);
        }
    }
    if(ridx<rsz)
    {
        for(;ridx<rsz;++ridx)
            ret.push_back(right[ridx]);
    }
    return ret;
}

std::vector<int> mergeSort(std::vector<int>& nums)
{
    if(nums.size()==1||nums.empty())
        return nums;

    int mid=nums.size()/2;

    std::vector<int> left;
    std::vector<int> right;

    for(int i=0;i<mid;++i)
        left.push_back(nums[i]);
    for(std::size_t i=mid;i<nums.size();++i)
        right.push_back(nums[i]);
    
    left=mergeSort(left);
    right=mergeSort(right);

    return merge(left,right);
}



int main()
{
    std::vector<int> nums{3,2,5,9,2,4,1};
    std::vector<int> ret=mergeSort(nums);
    for(auto i:ret)
        std::cout<<i<<"-";
    return 0;
}