#include<vector>
#include<iostream>

using DT=std::vector<int>;


void insertionSorting(DT& nums)
{
    int sz=nums.size();
    if(sz==0)
        return;
    
    for(int i=1;i<sz;++i)
    {
        int key=nums[i],j=i-1;
        while((j>=0) && (key>nums[j]))
        {
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=key;
    }
}

int main()
{
    DT nums{3,5,2,9,1,6};
    insertionSorting(nums);
    for(auto i:nums)
        std::cout<<i<<',';
    return 0;
}