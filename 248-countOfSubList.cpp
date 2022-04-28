#include<vector>
#include<iostream>
#include<map>
//return the count of sublist which has some header and tail.

<<<<<<< HEAD
int count2(std::vector<int>& nums)
{
    int sz=nums.size();
    int ans=0;
=======
int countWithTwoLoops(std::vector<int>& nums)
{
    int sz=nums.size(),ans=0;
>>>>>>> f50d01437f9913d3dc963b247d59c71cd592406e
    for(int L=0;L<sz;++L)
    {
        for(int R=L;R<sz;++R)
        {
            if(nums[L]==nums[R])
                ans+=1;
        }
    }
    return ans;
}


}
int countOfSubList(std::vector<int>& nums)
{
    int ans=0;
    std::map<int,int> seen{};
    for(auto i:nums)
    {
        seen[i]+=1;
        ans+=seen[i];
    }
    return ans;
}

int main()
{
    std::vector<int> nums{1,2,3,5,1};
<<<<<<< HEAD
    std::cout<<count2(nums);
=======
    std::cout<<countWithTwoLoops(nums);
>>>>>>> f50d01437f9913d3dc963b247d59c71cd592406e
    return 0;
}