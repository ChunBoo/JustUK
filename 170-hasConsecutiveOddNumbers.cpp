//given a vector of positive numbers,
//return if there is three consecutive odd numbers,likes <1,3,5,7,9,2,4,6> will return true; 

#include<vector>
#include<iostream>

using DT=std::vector<int>;

bool isOdd(int val)
{
    return (val&1)==1;
}

bool hasConsecutiveOddNumbers(const DT& nums)
{
    int sz=nums.size();
    if(sz<3)
        return false;

    //two for-loops

    for(int i=2;i<sz;++i)
    {
        if(isOdd(nums[i])&&isOdd(nums[i-1])&&isOdd(nums[i-2]))
            return true;

    }
    return false;
}


bool isHasConsecutiveOddNumbers(const DT& nums)
{
    int sz=nums.size();
    if(sz<3)
        return false;

    int ans=0,oddCnt=0;

    for(int i=0;i<sz;++i)
    {
        if(isOdd(nums[i]))
        {
            oddCnt+=1;
            ans=std::max(oddCnt,ans);
        }
        else
            oddCnt=0;
    }
    return ans>=3;
}


int main()
{
    DT nums{1,3,8,7,9,2,4,6};
    // bool res=isHasConsecutiveOddNumbers(nums);
    bool res=hasConsecutiveOddNumbers(nums);
    std::cout<<res<<'\n';
    return 0;
}