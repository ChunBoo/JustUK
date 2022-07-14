#include<map>  //to record the count of unique numbers
#include<vector>
#include<iostream>


int sumOfUniqueNumbers(std::vector<int>& nums)
{
    int sz=nums.size();
    if(sz==0)
        return 0;
    int ans=0;
    std::map<int,int> m{};
    for(auto i:nums)
        m[i]+=1;
    for(auto i:m)
    {
        if(i.second==1)
            ans+=i.first;
    }
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,2,1,1,3,4};
    std::cout<<sumOfUniqueNumbers(nums);
    return 0;
}