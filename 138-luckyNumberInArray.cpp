//get the largest lucky number from a array
//e.g. [1,2,2,3,3,3,4,4],will return 3

#include<iostream>
#include<vector>
#include<algorithm>

int getLargestLuckyNumber(std::vector<int>& nums)
{
    std::sort(nums.begin(),nums.end(),std::greater<int>());
    int sz=nums.size();

    int ans=0;
    int c=0;
    for(int i=0;i<sz;++i)
    {
        c+=1;
        if(nums[i]!=nums[i+1])//(i==sz-1)||
        {
            if(c==nums[i])
                return c;
            c=0;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> nums{1,2,2,3,3,3,4,4};
    int luckyValue=getLargestLuckyNumber(nums);
    std::cout<<luckyValue<<'\n';
    return 0;
}