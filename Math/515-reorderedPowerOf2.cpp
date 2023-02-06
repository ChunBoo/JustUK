#include<iostream>
#include<string>
#include<algorithm>  //for std::swap
#include<vector>
using std::cout;
using STR=std::string;
using VEC=std::vector<STR>;
void permutations(STR s,int l,int r,VEC& sList)
{
    if(l==r)
        // return s;
        sList.push_back(s);
    for(int i=l;i<r;++i)
    {
        std::swap(s[i],s[l]);
        permutations(s,l+1,r,sList);
        std::swap(s[i],s[l]);
    }
}

bool reorderedPowerOf2(STR s)
{
    VEC v{};
    permutations(s,0,s.size()-1,v);
    for(auto &ss:v)
    {
        int sv=std::stoll(ss);
        if(ss[0]!='0' &&(sv&(sv-1))==0)
            return true;
    }
    return false;
}

int main()
{
    STR s="254";
    cout<<reorderedPowerOf2(s);
}

// int main()
// {

// }