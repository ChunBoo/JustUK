#include<vector>
#include<iostream>

int removeTarget(std::vector<int>& nums,int t)
{
    int j=0;
    for(auto i:nums)
    {
        if(i!=t)
        {
            nums[j]=i;
            j+=1;
        }
    }
    return j;
}

int main()
{
    std::vector<int> nums{1,2,2,3,4,2,5};
    int res=removeTarget(nums,2);
    std::cout<<res<<'\n';
    for(auto i:nums)
        std::cout<<i<<',';
    return 0;
}