#include<string>
#include<iostream>
#include<algorithm>
/*
You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.
*/
//need to check the std::find
using STR=std::string;


STR largestGoodInteger( STR nums)
{
    STR ans{};
    for(int c=9;c>=0;--c)
    {
        char i=c+'0';   //char(9)=='\t'
        STR tmp(3,c+'0');
        auto isFound=nums.find(tmp);  //std::string::find(),return std::string::size_t
        // auto isFound=std::find(nums.begin(),nums.end(),tmp);// can not work,
        // as std::find() will return iterator
        if(isFound!=std::string::npos) //std::string::npos is -1
            return tmp;
    }
    return ans;
}

int main()
{
    STR nums{"6777133339"};
    std::cout<<largestGoodInteger(nums);
}