#include<map>
#include<iostream>
#include<set>
#include<vector>

using VEC=std::vector<int>;
using MAP=std::map<char,char>;
VEC findEntryOfGraph(MAP& G)
{
    std::set<int> s{};

    VEC ans{};
    std::map<char,int> tmp{};
    std::map<char,char>::iterator iter=G.begin();
    for(;iter!=G.end();++iter)
    {
        s.insert(iter->first);
        s.insert(iter->second);
        tmp[iter->second]++;
    }
    
    std::set<int>::iterator siter=s.begin();
    for(;siter!=s.end();++siter)
    {
        if(tmp[*siter]==0)
            ans.push_back(*siter);
    }
    return ans;
}

int main()
{
    MAP edges;
    edges['A']='B';
    edges['B']='C';
    edges['D']='C';
    VEC res=findEntryOfGraph(edges);
    for(char i:res)
        std::cout<<i;
}


