//two pointers

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
int minSumLargerThanTarget(std::vector<int>& nums,int target)
{
    if(nums.empty())
        return 0;
    
    int ans=100,sum=0;
    std::sort(nums.begin(),nums.end());

    int sz=nums.size();
    int start=0,end=sz-1;

    while(start<end)
    {
        sum=nums[start]+nums[end];
        if(sum<=target)
        {
            start+=1;
        }
        else
        {
            ans=std::min(sum,ans);
            end-=1;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,3,4,5};
    int target=4;
    std::cout<<minSumLargerThanTarget(nums,target)<<'\n';
    return 0;
}