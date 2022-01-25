#include<iostream>
#include<vector>

void help(int cur,std::vector<int>& nums,std::vector<std::vector<int>>& ans)
{
    int sz=nums.size();
    if(cur==sz)
        ans.push_back(nums);
    
}


void getAllPerm(std::vector<int>& nums,std::vector<std::vector<int>>& ans)
{
    if(nums.empty())
        return ;
    
    int sz=nums.size();
    help(0,nums,ans);
}