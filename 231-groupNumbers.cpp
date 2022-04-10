//
#include<map>
#include<iostream>
#include<vector>

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
    std::map<int,int> m{};
    for(auto i:nums)
        m[i]+=1;
    std::vector<int> group{};
    for(auto i:m)
    {
        group.push_back(i.second);
    }
    int ans=group[0];
    for(auto i:group)
    {
        ans=mGCD(ans,i);
    }
    return ans>1;
}
int main()
{
    std::vector<int> nums{1,1,2,2,5,5};
    std::cout<<checkCanBeGroup(nums);
    return 0;
}