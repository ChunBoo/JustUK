#include<vector>
#include<iostream>

int flip2zero(const std::vector<int>& nums)
{
    int count=0;
    for(auto i:nums)
    {
        if(i==1&&((count&1)==0))   //operator of == is higher than &
            count+=1;
        if(i==0&&((count&1)==1))
            count+=1;
    }
    return count;
}

int main()
{
    std::vector<int> l{1,0,0,1,0};
    std::cout<<flip2zero(l);
    return 0;
}