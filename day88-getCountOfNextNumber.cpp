//给定一个数组，找出有多少个数字的下一个数值是在该数组中

#include<iostream>
#include<set>
#include<vector>

int getNextNumberCount(std::vector<int>& nums)
{
    if(nums.empty())
        return 0;
    
    std::set<int> s{};
    for(auto i:nums)
        s.insert(i);
    int ans=0;
    for(int i=0;i<nums.size();++i)
    {
        int nextValue=nums[i]+1;
        if(s.find(nextValue)!=s.end())
            ans+=1;
    }
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,3,5,7};
    int count=getNextNumberCount(nums);
    std::cout<<"Result is: "<<count<<'\n';
    return 0;
}