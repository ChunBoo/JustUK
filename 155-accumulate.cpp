#include<vector>
#include<iostream>

std::vector<int> accumulate(std::vector<int>& nums)
{
    int sz=nums.size();
    
    std::vector<int> ans(sz,0);
    if(sz==0)
        return ans;
    int sum=0;
    for(int i=0;i<sz;++i)
    {
        sum+=nums[i];
        ans[i]=sum;
    }
    return ans;
}


int main()
{
    std::vector<int> nums{1,2,3,4,5};
    std::vector<int> res=accumulate(nums);
    for(auto i: res)
        std::cout<<i<<',';
    return 0;
}