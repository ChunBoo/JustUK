#include<vector>
#include<iostream>
#include<map>

using VEC=std::vector<int>;
using MAP=std::map<int,int>;

MAP MyCounter(const VEC& nums)
{
    MAP ans{};
    for(auto &i:nums)
        ans[i]+=1;
    return ans;
}

int largestNumber(const VEC& nums)
{
    int ans=-1;
    MAP c=MyCounter(nums);
    std::map<int,int>::iterator iter=c.begin();
    for(;iter!=c.end();++iter)
    {
        if(iter->second==1)
        {
            if(iter->first>ans)
                ans=iter->first;
        }
    }
    return ans;
}


int bucket(const VEC& nums)
{
    VEC b(1001,0);
    for(auto &i:nums)
        b[i]+=1;
    
    for(int i=1000;i>-1;--i)
    {
        if(b[i]==1)
            return i;
    }
    return -1;

}

int main()
{
    VEC nums{1,2,2,4,6,6};
    std::cout<<bucket(nums);
    std::cout<<largestNumber(nums);
}