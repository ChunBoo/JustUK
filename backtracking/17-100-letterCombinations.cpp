#include<iostream>
#include<string>
#include<vector>

using std::cout;
using STR=std::string;
using VEC=std::vector<STR>;

void foo(STR cur,int begin,VEC& res,const STR& d,const VEC& mm)
{
    if(begin==d.size())
    {
        res.push_back(cur);
        return ;
    }
    for(auto &c:mm[begin])
    {
        foo(cur+c,begin+1,res,d,mm);
    }
}

VEC letCombination(const STR& digits)
{
    int n=digits.size();
    VEC ans{};
    VEC m{"abc","def"};
    foo("",0,ans,digits,m);
    return ans;
}

int main()
{
    VEC ret=letCombination("23");
    for(auto s:ret)
        cout<<s<<',';
}