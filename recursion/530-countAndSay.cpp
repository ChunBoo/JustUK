#include<iostream>
#include<string>
#include<vector>
#include<map>

using std::cout;
using STR=std::string;
using VEC=std::vector<char>;
using MAP=std::map<char,VEC>;  //'1':2




MAP groupBy(const STR& s)
{
    MAP ans{};
    if(s.empty())
        return ans;
    char pre=s[0];
    int len=s.size();
    for(int i=1;i<len;++i)
    {
        char cur=s[i];
        if(pre)
        ans[c].push_back(c)
    }
}

STR f(int n)
{
    if(n==1)
        return "1";
    
}

STR countAndSay(int n)
{

}