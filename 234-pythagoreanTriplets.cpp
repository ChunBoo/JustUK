#include<vector>
#include<iostream>
#include<cmath>
std::vector<std::vector<int>> pythagoreanTriplets(int val)
{
    std::vector<std::vector<int>> ans{};
    for(int a=1;a<=val;++a)
    {
        for(int b=1;b<a;++b)
        {
            int c=int(std::sqrt(a*a+b*b));
            if((c*c==a*a+b*b)&&c<=val)
            {
                std::vector<int> tmp{a,b,c};
                ans.push_back(tmp);
            }
        }
    }
    return ans;
}

int main()
{
    std::vector<std::vector<int>> ret=pythagoreanTriplets(10);
    if(ret.empty())
        std::cout<<"result is empty.\n";
    if(!ret.empty())
    {
        for(auto i:ret)
        {
            for(auto v:i)
            {
                std::cout<<v<<',';
            }
            std::cout<<'\n';
        }
    }
    return 0;
}