#include<iostream>
#include<vector>
//given a list numbers, contains positive ,zero and negative numbers,return the sign of the product
int signedOfProductValue(const std::vector<int>& nums)
{
    int negative=0;
    for(auto v:nums)
    {
        if(v==0)
            return 0;
        else if(v<0)
            negative+=1;
    }
    return (negative&1)?-1:1;
}


int main()
{
    std::vector<int> values{1,2,0,4,5};
    std::cout<<signedOfProductValue(values);
    return 0;
}