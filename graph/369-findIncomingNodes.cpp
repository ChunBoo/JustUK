#include<map>
#include<iostream>
#include<set>
#include<vector>

using VEC=std::vector<char>;
using MAP=std::map<char,char>;
VEC findEntryOfGraph(MAP& G)
{
    std::set<char> seen{};
    std::map<char,int> counter{};
    for( auto &[k,v]:G)
    {
        seen.insert(k);
        seen.insert(v);
        counter[v]+=1;
    }
    VEC ans{};
    for(auto &c:seen)
    {
        if(counter[c]==0)
            ans.push_back(c);
    }
    return ans;
}

int main()
{
    MAP edges{{'A','B'},{'B','C'},{'D','C'}};
    // edges['A']='B';
    // edges['B']='C';
    // edges['D']='C';
    VEC res=findEntryOfGraph(edges);
    for(auto i:res)
        std::cout<<i<<',';
}


