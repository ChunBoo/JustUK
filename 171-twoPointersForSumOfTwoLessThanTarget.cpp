//given a vector of numbers,and the target value;
//return the maximum value of two numbers sum which less than target value

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
int twoPointersForMaxSumOfTwoLessThanTarget(std::vector<int>& nums,int target)
{
    if(nums.empty())
        return 0;
    std::sort(nums.begin(),nums.end());

    int sz=nums.size();
    int i=0,j=sz-1;
    int ans=0;
    while(i<j)
    {
        int cur=nums[i]+nums[j];
        if(cur<target)
        {
            ans=std::max(cur,ans);
            i+=1;
        }
        else
            j-=1;
    }
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,3,4,5,6};
    int target=5;
    std::cout<<twoPointersForMaxSumOfTwoLessThanTarget(nums,target)<<'\n';
    return 0;
}