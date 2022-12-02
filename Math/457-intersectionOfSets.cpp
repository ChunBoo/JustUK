#include<set>
#include<iostream>
#include<algorithm>

#include<vector>

using S=std::set<int>;
using MATRIX=std::vector<std::vector<int>>;
using VEC=std::vector<int>;

VEC intersectionOfArrays(const MATRIX& m)
{
    VEC ans{};
    if(m.empty())
        return ans;
    VEC tmp1{};
    VEC tmp2{};
    // S a=S(m[0]);
    int n=m.size();
    for(int i=0;i<n-1;++i)
    {
        std::set_intersection(m[i].begin(),m[i].end(),m[i+1].begin(),m[i+1].end(),std::back_inserter(tmp1)); //inserter
    }
    std::sort(tmp1.begin(),tmp1.end());
    return tmp1;
}

int main()
{
    MATRIX m{{7,34,45,10,12,27,13},{27,21,45,10,12,13}};
    VEC res=intersectionOfArrays(m);
    for(auto &d:res)
        std::cout<<d<<",";
}


