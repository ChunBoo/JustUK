#include<vector>
#include<iostream>

using DT=std::vector<int>;


void insertionSorting(DT& nums)  //insert the largest/smallest value into the selected section
{
    if(nums.empty())
        return ;
    
    int sz=nums.size();
    for(int i=1;i<sz;++i)
    {
        int minIdx=i-1,key=nums[i];  //we should save the nums[i] as one copy for following comparison, since it will be changed later
    
        while(minIdx>=0&&nums[minIdx]>=key)  //minIdx>=0&&nums[minIdx]>=nums[i] is wrong,should be minIdx>=0&&nums[minIdx]>=key
        {
            nums[minIdx+1]=nums[minIdx];
            minIdx--;
        }
        nums[minIdx+1]=key;
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