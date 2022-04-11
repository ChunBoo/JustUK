//
#include<map>
#include<iostream>
#include<vector>
#include<algorithm>
int mGCD(int a,int b)
{
    while(b)
    {
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
bool checkCanBeGroup(std::vector<int>& nums)
{
    if(nums.empty())
        return true;
    std::map<int,int> m{};
    for(auto i:nums)
        m[i]+=1;
    std::vector<int> v{};
    for(auto i:m)
        v.push_back(i.second);
    
    int ans=v[0];
    for(auto i:v)
    {
        ans=mGCD(ans,i);
    }
    return ans>1;
}

bool checkCanBeGroup2(std::vector<int>& nums)
{
    if(nums.empty())
        return true;
    std::map<int,int> m{};
    for(auto i:nums)
        m[i]+=1;
    std::vector<int> v{};
    for(auto i:m)
        v.push_back(i.second);
    
    int ans=v[0];
    int minVal=INT_MAX;
    for(auto i:v)
    {
        minVal=std::min(i,minVal);
    }
    if(minVal<=1)
        return false;
    for(auto i:v)
    {
        if((i%minVal)!=0)
            return false;
    }
    return true;
}
int main()
{
    std::vector<int> nums{1,1,2,2,5,5};
    std::cout<<checkCanBeGroup2(nums);
    return 0;
}