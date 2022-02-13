//ajacent list is a Graph
//[[1,2],[3,4],[],[],[]]
// 0-->1-->3
// |   |
// V   V
// 2   4


#include<vector>
#include<iostream>

using std::cout;
using std::vector;

std::vector<std::vector<int>> reverseGraph(const vector<vector<int>>& nums)
{
       int sz=nums.size();
       std::vector<std::vector<int>> ans(sz,vector<int>(0));
    if(nums.empty())
        return ans;

 
    for(int i=0;i<sz;++i)
    {
        for(auto j:nums[i])
        {
            ans[j].push_back(i);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> nums{{1,2},{3,4},{},{},{}};
    vector<vector<int>> res=reverseGraph(nums);
    for(auto i:res)
    {
        for(auto j:i)
        {
            std::cout<<j<<',';
        }
        std::cout<<'\n';
    }
    return 0;
}