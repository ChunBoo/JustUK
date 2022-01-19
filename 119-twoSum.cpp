//return the index of two values which's sum is target

#include<vector>
#include<iostream>
#include<map>
std::vector<int> twoSum(std::vector<int>& nums,int target)
{
    std::vector<int> ans;
    int sz=nums.size();
    if(sz<1)
        return ans;
    std::map<int,int> nb{};

    for(int i=0;i<sz;++i)
    {
        if(nb.find(target-nums[i])==nb.end())
        {
            nb[nums[i]]=i;
        }
        else
        {
            ans.push_back(nb[target-nums[i]]);
            ans.push_back(i);
            break;
        }
    }
    return ans;
}


int main()
{
    std::vector<int> nums{1,2,3,4,5};
    int target=5;
    std::vector<int> res=twoSum(nums,target);
    for(auto i:res)
        std::cout<<i<<',';
    
    return 0;
}