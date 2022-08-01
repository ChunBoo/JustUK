#include<iostream>
#include<vector>


using DT=std::vector<int>;


void selectSorting(DT& nums)
{
    if(nums.empty())
        return ;

    int sz=nums.size();

    for(int i=0;i<sz;++i)
    {
        int minIdx=i;
        for(int j=i+1;j<sz;++j)
        {
            if(nums[j]<nums[minIdx])
                minIdx=j;
        }
        int tmp=nums[i];
        nums[i]=nums[minIdx];
        nums[minIdx]=tmp;
    }
}

int main()
{
    DT nums{3,5,2,9,1,6};
    selectSorting(nums);
    for(auto i:nums)
        std::cout<<i<<',';
    return 0;
}