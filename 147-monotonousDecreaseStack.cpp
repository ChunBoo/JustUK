#include<iostream>
#include<list>
#include<vector>
std::list<int> getBuilding(const std::vector<int>& nums)
{
    std::list<int> ans;
    int sz=nums.size();
    if(sz==0)
        return ans;

    for(int i=0;i<sz;++i)
    {
        int cur=nums[i];
        while(!ans.empty()&&nums[ans.back()]<=cur)
        {
            ans.pop_back();
        }
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    std::vector<int> nums{3,4,4,2,1};
    std::list<int> res=getBuilding(nums);
    for(auto i:res)
    {
        std::cout<<i<<"->"<<nums[i]<<' ';
    }
    return 0;
}