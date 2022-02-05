//given a list,we should group by it's values to each related boxes

#include<iostream>
#include<vector>

void GroupByNumbers(const std::vector<int>& nums,std::vector<std::vector<int>>& ret)
{
    if(nums.empty())
        return ;

    std::vector<int> curBox;
    int previous=nums[0];
    for(auto i:nums)
    {
        if(i!=previous)
        {
            ret.push_back(curBox);
            previous=i;
            curBox.clear();
        }
        curBox.push_back(i);
    }
    if(!curBox.empty())
        ret.push_back(curBox);
}


int main()
{
    std::vector<std::vector<int>> res;
    std::vector<int> nums={1,1,1,2,2,3,4,4};
    GroupByNumbers(nums,res);
    if(!res.empty())
    {
        for(auto i:res)
        {
            for(auto j:i)
                std::cout<<j<<',';
            std::cout<<'\n';
        }
    }
    return 0;
}