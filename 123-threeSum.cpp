// given a list of numbers,return the value if we can get three elements sum is equal to target

#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
std::vector<int> getThreeSum2(const std::vector<int>& nums, int target)
{
    std::vector<int> ret{};
    int sz=nums.size();

    if(sz<3)
        return ret;
    std::map<int,int> nb{};

    for(int i=0;i<sz;++i)
    {
        if(nb.find(nums[i])==nb.end()) //did not found
        {
            nb[nums[i]]=i;
        }
        int newTarget=target-nums[i];
        for(int j=i+1;j<sz;++j)
        {
            if(nb.find(newTarget-nums[j])==nb.end())
            {
                nb[nums[j]]=j;
            }
            else
            {
                if(j!=nb[newTarget-nums[j]])
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    ret.push_back(nb[newTarget-nums[j]]);
                    return ret;
                }
            }
        }
    }
    return ret;
}


std::vector<int> getThreeSum(const std::vector<int>& nums, int target)
{
    std::vector<int> ret{};
    int sz=nums.size();

    if(sz<3)
        return ret;

    for(int i=0;i<sz;++i)
    {
        int j=i+1;
        int k=sz-1;
        while(j<k)
        {
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==target)
            {
                ret.push_back(i);
                ret.push_back(j);
                ret.push_back(k);
                // return ret;
            }
            else if (sum<target)
            {
                j+=1;
            }
            else
                k-=1;
        }
    }
    return ret;
}


int main()
{
    std::vector<int> nums{1,2,3,4,5};
    int target=6;
    std::vector<int> res=getThreeSum2(nums,target);
    std::sort(res.begin(),res.end());

    for(auto i:res)
        std::cout<<i<<'-';

    return 0;
}