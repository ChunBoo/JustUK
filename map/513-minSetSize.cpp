#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using VEC=std::vector<int>;
using MAP=std::map<int,int>;

MAP Counter(const VEC& nums)
{
    MAP d{};
    for(auto &i:nums)
        d[i]+=1;
    return d;
}
int minSetSize(const VEC& nums)
{
    int n=nums.size();
    MAP d{Counter(nums)};

    VEC vals{};
    for(auto &[k,v]:d)
        vals.push_back(v);
    std::sort(vals.begin(),vals.end(),std::greater<int>());  //sort the vector from large to smaller
    int ans=0,t=0;
    for(auto i:vals)
    {
        t+=i;
        ans+=1;
        if(t+t>=n)
            return ans;
    }
    return 0;
}


int main()
{
    VEC arr{3,3,3,3,5,5,5,2,2,7};
    std::cout<<minSetSize(arr);
}