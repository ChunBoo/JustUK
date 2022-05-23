//given a array with some integers, return the longest sublist's length when those sublists sum is zero

#include<iostream>
#include<vector>
#include<map>

using DT=std::vector<int>;
int longestSublist(const DT& nums)
{

}

int longestSubListOfZeroSum(const DT& nums)  //prefix sum of array
{
    int sz=nums.size();
    std::map<int,int> p{};
    int sum=0,ans=0;
    for(int i=0;i<sz;++i)
    {
        sum+=nums[i];
        if(p.find(sum)!=p.end())  //found
            ans=std::max(ans,i-p[sum]);
        p[sum]=i;
    }
    return ans;
}
int main()
{
    std::vector<int> nums{1,-2,-1,2,1};
    std::cout<<longestSubListOfZeroSum(nums);
    return 0;
}
