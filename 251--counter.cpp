#include<string>
#include<iostream>
#include<map>

std::map<char,int> counterRes(std::string& val)
{
    std::map<char,int> res{};
    for(auto i:val)
    {
        res[i]+=1;
    }
    return res;
}

int main()
{
    std::string val{"abcc"};
    std::map<char,int> res=counterRes(val);
    for(auto i:res)
    {
        std::cout<<i.first<<"-->"<<i.second<<'\n';

    }
    return 0;
}

