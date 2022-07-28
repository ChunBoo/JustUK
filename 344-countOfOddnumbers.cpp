#include<string>
#include<cmath>
#include<vector>
#include<iostream>

using DT=std::vector<int>;

bool isOddDigits(int x)
{
    std::string sVal=std::to_string(x);
    return sVal.size()%2;
}

bool isOddDigitsMath(int x)
{
    return static_cast<int>(std::log10(x)+1) %2;
}

int countOfOddDigits(const DT& nums)
{
    if(nums.empty())
        return 0;
    int ans=0;
    for(auto &v:nums)
    {
        if(isOddDigitsMath(v))
            ans++;
    }
    return ans;
}

int main()
{
    DT nums{1235,4,23,1};
    int res=countOfOddDigits(nums);
    std::cout<<res;
    return 0;
}