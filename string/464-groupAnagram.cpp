#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>  //for std::sort
using STR=std::string;
using VEC=std::vector<STR>;
using MAP=std::map<STR,VEC>;
using MATRIX=std::vector<std::vector<STR>>;
// void _counter()

MATRIX groupString(const VEC& s)
{
    MAP data{};
    MATRIX res{};
    for(auto _s:s)
    {
        STR tmp=_s;
        std::sort(tmp.begin(),tmp.end());
        data[tmp].push_back(_s);
    }
    
    for(auto &[k,v]:data)
    {
        res.push_back(v);
    }
    return res;
}

int main()
{
    VEC strs{"eat","tea","tan","ate","nat","bat"};
    MATRIX ans=groupString(strs);
    for(auto &ss:ans)
    {
        std::cout<<'\n';
        for(auto &s:ss)
            std::cout<<s<<',';
    }
}