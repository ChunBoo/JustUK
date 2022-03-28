//given a n bottles, which 3x empty bottles can exchange 1 new bottle
#include<iostream>

int drink(int bottles)
{
    int ans=bottles;
    while(bottles>=3)
    {
        int exchanges=bottles/3;
        ans+=exchanges;
        bottles=bottles%3+exchanges;
    }
    return ans;
}

int main()
{
    std::cout<<drink(9)<<'\n';
    return 0;
}