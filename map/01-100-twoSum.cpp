#include<map>
#include<iostream>
#include<vector>

using VEC=std::vector<int>;
using std::cout;

using MAP=std::map<int,int>;


VEC twoSum(const VEC& nums,int target)
{
    MAP d{};
    VEC ans{};
    int n=nums.size();
    for(int i=0;i<n;++i)
    {
        int cur=nums[i];
        if(d.find(target-cur)!=d.end())
        {
            ans.push_back(d[target-cur]);
            ans.push_back(i);
            return ans;
        }
        d[cur]=i;
    }
    return ans;
}

int main()
{
    VEC nums{-1,-2,-3,-4,-5};
    VEC res=twoSum(nums,-8);
    for(auto &v:res)
        cout<<v<<',';
}