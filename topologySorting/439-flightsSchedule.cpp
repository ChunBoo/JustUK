#include<set>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using SET=std::set<char>;
using VEC=std::vector<char>;
using MATRIX=std::vector<VEC>;
using MAP=std::map<char,char>;

VEC flights( MATRIX& fs)
{
    VEC ans{};
    if(fs.empty())
        return ans;
    MAP G{};
    for(auto &m:fs)
    {
        G[m[0]]=m[1];
    }
    SET Keys{};
    SET Vals{};
    for(auto &[k,v]:G)
    {
        Keys.insert(k);
        Vals.insert(v);
    }
    char start;
    for(auto &c:Keys)
    {
        if(std::find(Vals.begin(),Vals.end(),c)==Vals.end())
            start=c;
    }
    ans.push_back(start);
    while(std::find(G.begin(),G.end(),start)!=G.end())
    {
        start=G[start];
        ans.push_back(start);
    }
    return ans;
}

int main()
{
    MATRIX fs{{'a','b'},{'b','c'},{'c','d'}};
    VEC res=flights(fs);
    for(auto &v:res)
    {
        std::cout<<v<<"->";
    }
}