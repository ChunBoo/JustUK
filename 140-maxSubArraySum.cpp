#include<vector>
#include<iostream>
#include<cmath>
int DPForMaxSubArraySum(const std::vector<int>& nums)
{
    int ans=nums[0];
    int sum=nums[0];
    int sz=nums.size();
    for(int i=1;i<sz;++i)
    {
        sum=std::max(nums[i],nums[i]+sum);
        ans=std::max(sum,ans);
    }
    return ans;
}

int GreedyForMaxSubArraySum(const std::vector<int>& nums)
{
    int ans=0;
    int sum=0;
    for(auto i:nums)
    {
        if(sum<0)
            sum=i;
        else
            sum=i+sum;
        ans=std::max(ans,sum);
    }
    return ans;
}


int main()
{
    std::vector<int> nums{1,2,-1,4,3};
    int dpRes=DPForMaxSubArraySum(nums);
    int greedyRes=GreedyForMaxSubArraySum(nums);
    std::cout<<dpRes<<'\n';
    std::cout<<greedyRes<<'\n';
    return 0;
}