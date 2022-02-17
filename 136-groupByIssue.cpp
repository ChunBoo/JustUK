//given a list,we should group by it's values to each related boxes

#include<iostream>
#include<vector>
#include<algorithm>
void GroupByNumbers(std::vector<int>& nums,std::vector<std::vector<int>>& ret)
{
    if(nums.empty())
        return ;
    std::sort(nums.begin(),nums.end(),std::greater<int>());  //decreased order with std::greater
    std::vector<int> tempVec{};
    int preValue=nums[0];
    for(auto curVal:nums)
    {
        if(curVal!=preValue)
        {
            ret.push_back(tempVec);
            preValue=curVal;
            tempVec.clear();
        }
        tempVec.push_back(curVal);
    }
    if(!tempVec.empty())   //this step is important!!!!
        ret.push_back(tempVec);
}


int main()
{
    std::vector<std::vector<int>> res;
    std::vector<int> nums={1,3,1,2,4,3,4,4};
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