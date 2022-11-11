#include<iostream>
#include<vector>

using VEC=std::vector<int>;

using MATRIX=std::vector<std::vector<int>>;
void f(const VEC& nums, MATRIX&  res,VEC& cur,int i)
{
    int n=nums.size();
    if(i==n)
    {
        res.push_back(cur);
        return;
    }
    VEC tmp{cur.begin(),cur.end()};
    f(nums,res,tmp,i+1);
    cur.push_back(nums[i]);
    VEC tmp2{cur.begin(),cur.end()};
    f(nums,res,tmp2,i+1);
}

MATRIX subSets(const VEC& nums)
{
    MATRIX ans{};
    int n=nums.size();
    if(n==0)
        return ans;
    VEC cur;
    f(nums,ans,cur,0);
    return ans;
}

int main()
{
    VEC nums{1,2,3};
    MATRIX res=subSets(nums);
    for(auto &v:res)
    {
        std::cout<<'\n';
        for(auto &d:v)
            std::cout<<d<<',';
    }
}