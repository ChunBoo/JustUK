#include<map>
#include<iostream>
#include<vector>

using VEC=std::vector<int>;
using MAP=std::map<int,int>;

bool canPartition(const VEC& nums,int k)
{
    int sz=nums.size();
    if(sz&1)
        return false;
    
    MAP s{};
    for(auto &i:nums)
    {
        s[i%k]+=1;
    }
    if(s[0]&1)
        return false;
    
    for(int i=1;i<s.size();++i)
    {
        if(s[i]!=s[k-i])
            return false;
    }
    return true;
}

bool canPartitionByK(const VEC& nums,int k)
{
    int n=nums.size();
    if(n&1)
        return false;
    MAP s{};
    int c=0;
    for(auto &v:nums)
    {
        int a=v%k;
        int b=k-a;
        if(s[a]>0)
        {
            s[a]-=1;
            c-=1;
        }
        else
        {
            s[b]+=1;
            c+=1;
        }
    }
    return c==0;
}

int main()
{
    VEC nums{1,2,4,8};
    std::cout<<canPartition(nums,3);
    std::cout<<canPartitionByK(nums,3);
}