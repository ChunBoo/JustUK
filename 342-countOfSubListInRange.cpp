#include<iostream>
#include<vector>
#include<algorithm>

using DT=std::vector<int>;

int foo(const DT& nums, int upperValue)
{
    int ans=0,cur=0;
    for(auto &v:nums)
    {
        if(v<=upperValue)
            cur+=1;
        else
            cur=0;
        ans+=cur;
    }
    return ans;
}

int countOfSubLists(const DT& nums, int L,int H)
{
    return foo(nums,H)-foo(nums,L-1);
}


int countOfSubLists_BruceForce(const DT& nums,int L,int H)
{
    int ans=0;
    if(nums.empty())
        return 0;
    
    for(int i=0;i<nums.size();++i)
    {
        DT temp;
        temp.push_back(nums[i]);
        for(int j=i;j<nums.size();++j)
        {
            temp.push_back(nums[j]);
            int max=*std::max_element(temp.begin(),temp.end());
            // int max=std::max(temp);
            if(max>=L && max<=H)
                ans+=1;
        }
    }
    return ans;
}


int main()
{
    DT nums{0,1,5,3,4};
    // int res=countOfSubLists(nums,3,4);
    int res=countOfSubLists_BruceForce(nums,3,4);
    std::cout<<res<<'\n';
    return 0;
}