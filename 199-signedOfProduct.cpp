#include<iostream>
#include<vector>

int signedOfProductValue(const std::vector<int>& nums)
{
    int negative=0;
    for(auto i:nums)
    {
        if(i==0)
            return 0;
        if(i<0)
            negative+=1;
    }
    return (negative&1)?-1:1;
}


int main()
{
    std::vector<int> values{1,2,3,-4,-5};
    std::cout<<signedOfProductValue(values);
    return 0;
}