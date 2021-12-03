//add one for the number with link list,likes[1,2,3]+1==[1,2,4]
#include "linkNode.h"
#include<iostream>
#include<vector>
void pluseOneForAListNumber(std::vector<int>& num)
{
    int carry=0;
    int sz=num.size()-1;
    num[sz]+=1;
    for(int i=sz;i>=0;--i)
    {
        num[i]+=carry;
        carry=num[i]/10;
        num[i]%=10;
        if(carry==0)
            break;
    }
    if(carry)
    {
        std::vector<int>::iterator it=num.begin();
        num.insert(it,carry);
    }
}



int main()
{
    std::vector<int> nums{9,9,9};
    pluseOneForAListNumber(nums);
    for(auto i:nums)
        std::cout<<i<<' ';
    return 0;
}