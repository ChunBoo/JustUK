#include<iostream>
#include<vector>

using VEC=std::vector<int>;

using MATRIX=std::vector<std::vector<int>>;
void f(const VEC& nums, MATRIX&  res,VEC& cur,int i)
{
    int n=nums.size();
    if(i==n)
    {
        VEC tmp=VEC{cur.begin(),cur.end()};
        res.push_back(tmp);
        return ;  //this line can not be ignored
    }
    VEC tmp1=VEC{cur.begin(),cur.end()};
    f(nums,res,tmp1,i+1);
    cur.push_back(nums[i]);
    VEC tmp2=VEC{cur.begin(),cur.end()};

    f(nums,res,tmp2,i+1);
}

MATRIX subSets(const VEC& nums)
{
    MATRIX ans{};
    VEC cur{};
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