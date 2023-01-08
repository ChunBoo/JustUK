#include<vector>
#include<set>
#include<map>
#include<iostream>

using VEC=std::vector<int>;
using MATRIX=std::vector<std::vector<int>>;
using SET=std::set<int>;
using GRAPH=std::map<int,VEC>;


void dfs(int cur,const GRAPH& G,SET& s)
{
    if(s.find(cur)!=s.end())
        return ;
    s.insert(cur);
    for(auto &[k,v]:G)
    {
        dfs(k,G,s);
    }
}
bool check(int n,int cur,const GRAPH& G)
{
    SET seen{};
    dfs(cur,G,seen);
    return n==(int)(seen.size());
}
bool checkSCC(MATRIX& m,int n)
{
    GRAPH G1{},G2{};
    for(auto &v:m)
    {
        G1[v[0]].push_back(v[1]);
        G2[v[1]].push_back(v[0]);
    }
        return check(n,0,G1)&&check(n,0,G2);

}

int main()
{
    int n=2;
    MATRIX m{{0,1},{1,0}};
    std::cout<<checkSCC(m,2);
}