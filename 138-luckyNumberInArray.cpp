//get the largest lucky number from a array
//e.g. [1,2,2,3,3,3,4,4],will return 3,if not found,then return -1

#include<iostream>
#include<vector>
#include<algorithm>

int getLargestLuckyNumber(std::vector<int>& nums)
{
    if(nums.empty())
        return -1;
    std::sort(nums.begin(),nums.end(),std::greater<int>());
    int cnt=0;
    int sz=nums.size();
    for(int i=0;i<sz;++i)
    {
        cnt+=1;
        if(nums[i]!=nums[i+1])
        {
            if(cnt==nums[i])
            {
                return cnt;
            }
            cnt=0;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> nums{1,2,2,3,3,3,4,4,4,4};
    int luckyValue=getLargestLuckyNumber(nums);
    std::cout<<luckyValue<<'\n';
    return 0;
}