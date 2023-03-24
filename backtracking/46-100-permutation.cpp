#include<iostream>
#include<vector>
#include<algorithm>


class Solution {
public:
    void dfs(std::vector<int>& nums,std::vector<std::vector<int>>& ans,std::vector<int> cur)
    {
        if(cur.size()==nums.size())
        {
            ans.push_back(cur);
            return;
        }
        for(auto v:nums)
        {
            if(std::find(cur.begin(),cur.end(),v)!=cur.end())
                continue;
            else
            {
                cur.push_back(v);
                dfs(nums,ans,cur);
                cur.pop_back();
            }
        }
    }
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
       std:: vector<std::vector<int>> ans{};
        std::vector<int> cur{};
        dfs(nums,ans,cur);
        return ans;
    }
};

int main()
{
    std::vector<int> nums{1,2,3};
    std::vector<std::vector<int>> res=Solution().permute(nums);

}