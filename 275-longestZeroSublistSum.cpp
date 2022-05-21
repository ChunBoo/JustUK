//bruce force method

#include<iostream>
#include<vector>

using DT=std::vector<int>;
int longestSublist(const DT& nums)
{
    int ans=0;
    int n=nums.size();
    for(int i=0;i<n;++i)
    {
        int s=0;
        for(int j=i;j<n;++j)
        {
            s+=nums[j];
            if(s==0)
            {
                ans=std::max(ans,j-i+1);
            }
        }
    }
    return ans;
}
int longestSubListOfZeroSum(const DT& nums)
{
    int n=nums.size();
    std::map<int,int> p{}; 
    int ans=0,sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=nums[i];
        if(p.find(sum)!=p.end())
            ans=std::max(ans,i-p[sum]);
        else
            p[sum]=i;
    } 
    return ans;
}
int main()
{
    std::vector<int> nums{1,-2,-1,3};
    std::cout<<longestSublist(nums);
    return 0;
}
