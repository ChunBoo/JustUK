//给定一个数组，找出有多少个数字的下一个数值是在该数组中

#include<iostream>
#include<set>
#include<vector>
#include<map>
int getNextNumberCount(std::vector<int>& nums)
{
    if(nums.empty())
        return 0;
    
    std::map<int,int> m{};
    for(auto i:nums)
    {
        if(m.find(i)==m.end())
        {
            m[i]=1;
        }
        else
            m[i]+=1;
    }
    int ans=0;
    for(int i=0;i<nums.size();++i)
    {
        int nextValue=nums[i]+1;
        if(m.find(nextValue)!=m.end())
            ans+=m[nextValue];
    }
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,2,3,5,7};
    int count=getNextNumberCount(nums);
    std::cout<<"Result is: "<<count<<'\n';
    return 0;
}